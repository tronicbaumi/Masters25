// <editor-fold defaultstate="collapsed" desc="Description/Instruction ">
/**
* @file pmsm.c
*
* @brief This is the main entry to the application.
*
* Component: APPLICATION
*
*/
// </editor-fold>
 
// <editor-fold defaultstate="collapsed" desc="Disclaimer ">
 
/*******************************************************************************
* SOFTWARE LICENSE AGREEMENT
* 
* � [2024] Microchip Technology Inc. and its subsidiaries
* 
* Subject to your compliance with these terms, you may use this Microchip 
* software and any derivatives exclusively with Microchip products. 
* You are responsible for complying with third party license terms applicable to
* your use of third party software (including open source software) that may 
* accompany this Microchip software.
* 
* Redistribution of this Microchip software in source or binary form is allowed 
* and must include the above terms of use and the following disclaimer with the
* distribution and accompanying materials.
* 
* SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
* APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
* MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL 
* MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR 
* CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO
* THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE 
* POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY
* LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL
* NOT EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS
* SOFTWARE
*
* You agree that you are solely responsible for testing the code and
* determining its suitability.  Microchip has no obligation to modify, test,
* certify, or support the code.
*
*******************************************************************************/
// </editor-fold>
 
// <editor-fold defaultstate="collapsed" desc="HEADER FILES ">
 
#include <xc.h>
#include <stdio.h>
#include <math.h>

#include "userparms.h"
#include "board_service.h"
#include "control.h"
#include "estim.h"
#include "foc/estim_qei.h"
#include "pi.h"
#include "svm.h"
#include "clarke_park.h"
#include "fdweak.h"
#include "singleshunt.h"
 
#include "x2cmodel/X2CMain.h"
#include "x2cmodel/X2CUtils.h"

// </editor-fold>
 
// <editor-fold defaultstate="collapsed" desc=" Global Variables ">
 
MCAPP_MEASURE_T measureInputs;
CTRL_PARM_T CtrlParm;
MOTOR_STARTUP_DATA_T motorStartUpData;
UGF_T uGF;

MC_PIPARMIN_T     piInputIq;
MC_PIPARMOUT_T    piOutputIq;
MC_PIPARMIN_T     piInputId;   
MC_PIPARMOUT_T    piOutputId;
MC_PIPARMIN_T     piInputOmega;    
MC_PIPARMOUT_T    piOutputOmega;
MC_SINCOS_T sincosTheta;
MC_ALPHABETA_T valphabeta,ialphabeta;
MC_DQ_T vdq,idq;
MC_ABC_T vabc,iabc;
MC_DUTYCYCLEOUT_T pwmDutycycle;
SINGLE_SHUNT_PARM_T singleShuntParam;

float pwmPeriod;
float thetaElectricalOpenLoop;
int32_t heartBeatCount = 0;
 
// </editor-fold>
 
// <editor-fold defaultstate="collapsed" desc=" Function Declarations ">

void CalculateParkAngle(void);
void DoControl( void );
void InitControlParameters(void);
void ResetParameters(void);
void ResetPeripherals(void);

// </editor-fold>

// <editor-fold defaultstate="expanded" desc="INTERFACE FUNCTIONS ">

/**
* <B> Function: int main (void)  </B>
*
* @brief main() function,entry point of the application.
*
*/
int main(void) 
{
    InitOscillator();       
    SetupGPIOPorts();
    
    /* LED1 is turned on here, and toggled in Timer1 Interrupt */
    LED1 = 1; 
    
    /* Initialize Diagnostics and Board Service */
    X2C_Initialize();
   
    /* Initialize Peripherals */
    InitPeripherals();
    
    ResetPeripherals();
    
    ClearPWMPCIFault();
    EnablePWMOutputs();
    
        /** Set Override Data on all PWM outputs */
    /* 0b00 = State for PWM3H,L, if Override is Enabled */
    PG3IOCONbits.OVRDAT = 0;
    /* 0b00 = State for PWM2H,L, if Override is Enabled */
    PG2IOCONbits.OVRDAT = 0; 
    /* 0b00 = State for PWM1H,L, if Override is Enabled */
    PG1IOCONbits.OVRDAT = 0;  

    /* 1 = OVRDAT<1> provides data for output on PWM3H */
    PG3IOCONbits.OVRENH = 1; 
    /* 1 = OVRDAT<0> provides data for output on PWM3L */
    PG3IOCONbits.OVRENL = 1; 
    
    /* 1 = OVRDAT<1> provides data for output on PWM2H */
    PG2IOCONbits.OVRENH = 1;
    /* 1 = OVRDAT<0> provides data for output on PWM2L */
    PG2IOCONbits.OVRENL = 1; 
    
    /* 1 = OVRDAT<1> provides data for output on PWM1H */
    PG1IOCONbits.OVRENH = 1;  
    /* 1 = OVRDAT<0> provides data for output on PWM1L */
    PG1IOCONbits.OVRENL = 0;    

    while(1)
    {
        X2C_Communicate();
    } 
}
/**
* <B> Function: ADCInterrupt() </B>
*
* @brief Does speed calculation and executes the vector update loop.
* The ADC sample and conversion is triggered by the PWM period.
* The speed calculation assumes a fixed time interval between calculations.
*        
* @param none.
* @return none.
* 
* @example
* <CODE> ADCInterrupt(); </CODE>
*
*/
void __attribute__((__interrupt__, no_auto_psv))ADCInterrupt(void)
{   
    X2C_Task();  
    ADCInterruptFlagClear;
}

/**
* <B> Function: ResetPeripherals()     </B>
*
* @brief Function to resets the peripherals ; ADC trigger points,Duty cycle
*        
* @param none.
* @return none.
* 
* @example
* <CODE> ResetPeripherals();        </CODE>
*
*/
void ResetPeripherals(void)
{
    /* Make sure ADC does not generate interrupt while initializing parameters*/
	DisableADCInterrupt();
    PWM_TRIGA = ADC_SAMPLING_POINT;
    /* Re initialize the duty cycle to minimum value */
    PWM_PDC3 = MIN_DUTY;
    PWM_PDC2 = MIN_DUTY;
    PWM_PDC1 = MIN_DUTY;
    
    DisablePWMOutputs();
    
    /* Initialize measurement parameters */
    MCAPP_MeasureCurrentInit(&measureInputs);
    /* Enable ADC interrupt and begin main loop timing */
    ADCInterruptFlagClear;
    EnableADCInterrupt();
}
/**
* <B> Function: _PWMInterrupt()     </B>
*
* @brief Function to handle PWM Fault Interrupt from PCI
*        
* @param none.
* @return none.
* 
* @example
* <CODE> _PWMInterrupt();        </CODE>
*
*/
void __attribute__((__interrupt__,no_auto_psv)) _PWMInterrupt()
{
//    ResetParameters();
    ResetPeripherals();
    ClearPWMPCIFault();
    ClearPWMIF(); 
}
/**
* <B> Function: _T1Interrupt()     </B>
*
* @brief Function to handle Timer1 Interrupt. Timer1 is configured for 1 ms.
* LED1 is toggled at a rate of 250 ms as a Heartbeat LED.
*        
* @param none.
* @return none.
* 
* @example
* <CODE> _T1Interrupt();        </CODE>
*
*/
void __attribute__((__interrupt__, no_auto_psv))_T1Interrupt(void)
{
    
    if (heartBeatCount < HEART_BEAT_LED_COUNT)
    {
        heartBeatCount += 1;
    }
    else
    {
        heartBeatCount = 0;
        if(LED1 == 1)
        {
//            LED1 = 0;
        }
        else
        {
//            LED1 = 1;
        }
    }
    
    TIMER1_InterruptFlagClear();
}
// </editor-fold>

