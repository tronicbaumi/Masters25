// <editor-fold defaultstate="collapsed" desc="Description/Instruction ">
/**
 * @file singleshunt.c
 *
 * @brief This module implements Single Shunt Reconstruction Algorithm
 *
 * Component: SINGLE SHUNT
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

#include <stdint.h>
#include <stdbool.h>
#include <xc.h>

#include "pwm.h"
#include "singleshunt.h"

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STATIC FUNCTIONS ">

inline static void SingleShunt_CalculateSwitchingTime(SINGLE_SHUNT_PARM_T *,
                                                                       float);

// </editor-fold>

// <editor-fold defaultstate="expanded" desc="INTERFACE FUNCTIONS ">

/**
* <B> Function: SingleShunt_InitializeParameters(SINGLE_SHUNT_PARM_T *)</B>
*
* @brief Function to initialize variables in Single Shunt structure.
*
* @param Pointer to the data structure containing Single Shunt parameters.
* @return none.
* 
* @example
* <CODE> SingleShunt_InitializeParameters(&singleShunt); </CODE>
*
*/
void SingleShunt_InitializeParameters(SINGLE_SHUNT_PARM_T *pSingleShunt)
{
    /* Set minimum window time to measure current through single shunt */
	pSingleShunt->tcrit = SSTCRIT;
    /* Set delay due to dead time and slew rate etc.*/
	pSingleShunt->tDelaySample = SS_SAMPLE_DELAY;
    /*Trigger  values of Bus Current Samples made equal to zero */
    pSingleShunt->trigger1 = 0.0;
    pSingleShunt->trigger2 = 0.0;
    /*Initial  values of Bus Current Samples made equal to zero */
    pSingleShunt->Ibus1 = 0;
    pSingleShunt->Ibus2 = 0;
}
/**
* <B> Function: SingleShunt_CalculateSpaceVectorPhaseShifted(MC_ABC_T *,
*                                           uint16_t,SINGLE_SHUNT_PARM_T *) </B>
*
* @brief Function to calculate Va,Vb and Vc.
*
* @param Pointer to the data structure containing Va,Vb & Vc
* @param PWM Period
* @param Pointer to the data structure containing Single Shunt parameters.
* 
* @return none.
* @example
* <CODE> SingleShunt_CalculateSpaceVectorPhaseShifted(&abc,
*                                              pwmPeriod,&singleShunt); </CODE>
*
*/
void SingleShunt_CalculateSpaceVectorPhaseShifted(MC_ABC_T *abc,
                                    float iPwmPeriod,
                                    SINGLE_SHUNT_PARM_T *pSingleShunt)
{
    asm volatile("push  CORCON");
    CORCON = 0x00E2;
    
    MC_DUTYCYCLEOUT_T *pdcout1 = &pSingleShunt->pwmDutycycle1;
    MC_DUTYCYCLEOUT_T *pdcout2 = &pSingleShunt->pwmDutycycle2;   
    if (abc->a >= 0)
    {
        /* (xx1) */
        if (abc->b >= 0)
        {
            /* (x11)
             * Must be Sector 3 since Sector 7 not allowed
             * Sector 3: (0,1,1)  0-60 degrees */
            pSingleShunt->sectorSVM  = 3; 
            pSingleShunt->T1 = abc->a;
            pSingleShunt->T2 = abc->b;
            SingleShunt_CalculateSwitchingTime(&singleShuntParam,iPwmPeriod);
            pdcout1->dutycycle1 = pSingleShunt->Ta1;
            pdcout1->dutycycle2 = pSingleShunt->Tb1;
            pdcout1->dutycycle3 = pSingleShunt->Tc1;
            pdcout2->dutycycle1 = pSingleShunt->Ta2;
            pdcout2->dutycycle2 = pSingleShunt->Tb2;
            pdcout2->dutycycle3 = pSingleShunt->Tc2;
        }
        else
        {
            /* (x01) */
            if (abc->c >= 0)
            {
                /* Sector 5: (1,0,1)  120-180 degrees */
                pSingleShunt->sectorSVM  = 5;
                pSingleShunt->T1 = abc->c;
                pSingleShunt->T2 = abc->a;
                SingleShunt_CalculateSwitchingTime(&singleShuntParam,iPwmPeriod);
                pdcout1->dutycycle1 = pSingleShunt->Tc1;
                pdcout1->dutycycle2 = pSingleShunt->Ta1;
                pdcout1->dutycycle3 = pSingleShunt->Tb1;
                pdcout2->dutycycle1 = pSingleShunt->Tc2;
                pdcout2->dutycycle2 = pSingleShunt->Ta2;
                pdcout2->dutycycle3 = pSingleShunt->Tb2;
            }
            else
            {
                /* Sector 1: (0,0,1)  60-120 degrees */
                pSingleShunt->sectorSVM  = 1;
                pSingleShunt->T1 = -abc->c;
                pSingleShunt->T2 = -abc->b;
                SingleShunt_CalculateSwitchingTime(&singleShuntParam,iPwmPeriod);
                pdcout1->dutycycle1 = pSingleShunt->Tb1;
                pdcout1->dutycycle2 = pSingleShunt->Ta1;
                pdcout1->dutycycle3 = pSingleShunt->Tc1;
                pdcout2->dutycycle1 = pSingleShunt->Tb2;
                pdcout2->dutycycle2 = pSingleShunt->Ta2;
                pdcout2->dutycycle3 = pSingleShunt->Tc2;
            }
        }
    }
    else
    {
        /* (xx0) */
        if (abc->b >= 0)
        {
            /* (x10) */
            if (abc->c >= 0)
            {
                /* Sector 6: (1,1,0)  240-300 degrees */
                pSingleShunt->sectorSVM  = 6;
                pSingleShunt->T1 = abc->b;
                pSingleShunt->T2 = abc->c;
                SingleShunt_CalculateSwitchingTime(&singleShuntParam,iPwmPeriod);
                pdcout1->dutycycle1 = pSingleShunt->Tb1;
                pdcout1->dutycycle2 = pSingleShunt->Tc1;
                pdcout1->dutycycle3 = pSingleShunt->Ta1;
                pdcout2->dutycycle1 = pSingleShunt->Tb2;
                pdcout2->dutycycle2 = pSingleShunt->Tc2;
                pdcout2->dutycycle3 = pSingleShunt->Ta2;
            }
            else
            {
                /* Sector 2: (0,1,0)  300-0 degrees */
                pSingleShunt->sectorSVM  = 2;
                pSingleShunt->T1 = -abc->a;
                pSingleShunt->T2 = -abc->c;
                SingleShunt_CalculateSwitchingTime(&singleShuntParam,iPwmPeriod);
                pdcout1->dutycycle1 = pSingleShunt->Ta1;
                pdcout1->dutycycle2 = pSingleShunt->Tc1;
                pdcout1->dutycycle3 = pSingleShunt->Tb1;
                pdcout2->dutycycle1 = pSingleShunt->Ta2;
                pdcout2->dutycycle2 = pSingleShunt->Tc2;
                pdcout2->dutycycle3 = pSingleShunt->Tb2;
            }
        }
        else
        {
            /* (x00)
             * Must be Sector 4 since Sector 0 not allowed
             * Sector 4: (1,0,0)  180-240 degrees */
            pSingleShunt->sectorSVM  = 4;
            pSingleShunt->T1 = -abc->b;
            pSingleShunt->T2 = -abc->a;
            SingleShunt_CalculateSwitchingTime(&singleShuntParam,iPwmPeriod);
            pdcout1->dutycycle1 = pSingleShunt->Tc1;
            pdcout1->dutycycle2 = pSingleShunt->Tb1;
            pdcout1->dutycycle3 = pSingleShunt->Ta1;
            pdcout2->dutycycle1 = pSingleShunt->Tc2;
            pdcout2->dutycycle2 = pSingleShunt->Tb2;
            pdcout2->dutycycle3 = pSingleShunt->Ta2;
        }
    }
    /* Calculate two triggers for the ADC that will fall in between PWM
        so a valid measurement is done using a single shunt resistor.
        tDelaySample is added as a delay so no erroneous measurement is taken*/
	/*Additional delay to trigger 1*/
    pSingleShunt->trigger1 = (iPwmPeriod+ pSingleShunt->tDelaySample);
    pSingleShunt->trigger1 = pSingleShunt->trigger1 - ((pSingleShunt->Ta1 + pSingleShunt->Tb1)/2.0) ;
    /*Additional delay to trigger 2*/
    pSingleShunt->trigger2 = (iPwmPeriod+  pSingleShunt->tDelaySample);
    pSingleShunt->trigger2 = pSingleShunt->trigger2 - ((pSingleShunt->Tb1 + pSingleShunt->Tc1)/2.0) ;
    
    SINGLE_SHUNT_TRIGGER1 = singleShuntParam.trigger1;
    SINGLE_SHUNT_TRIGGER2 = singleShuntParam.trigger2;

    asm volatile("pop  CORCON");

}
/**
* <B> Function: SingleShunt_CalculateSwitchingTime(SINGLE_SHUNT_PARM_T *,
*                                                                 uint16_t) </B>
*
* @brief Function to calculate SVM T1,T2 and T0.
*
* @param Pointer to the data structure containing Single Shunt parameters.
* @param PWM Period
* @return none.
* 
* @example
* <CODE> SingleShunt_CalculateSpaceVectorPhaseShifted(&singleShunt,
*                                                           pwmPeriod); </CODE>
*
*/
inline static void SingleShunt_CalculateSwitchingTime(SINGLE_SHUNT_PARM_T *pSingleShunt,
        float iPwmPeriod)
{
	
    /* First of all, calculate times corresponding to actual Space Vector
	   modulation output. */

    pSingleShunt->T1 = iPwmPeriod * pSingleShunt->T1;
    pSingleShunt->T2 = iPwmPeriod * pSingleShunt->T2;
    pSingleShunt->T7 = (iPwmPeriod-pSingleShunt->T1-pSingleShunt->T2)/2;

	/* If PWM counter is already counting down, in which case any modification to 
        duty cycles will take effect until PWM counter starts counting up again. 
        This is why the correction of any modifications done during PWM Timer is
        Counting down  will be updated here so that it takes effect during PWM Counter
        counting up.
        If PWM counter is already counting up, in which case any modification to 
        duty cycles will take effect until PWM reaches the maximum value and 
        starts counting down. Modification to pattern is done here if times
        T1 or T2 are lesser than tcrit. Change in duty cycle will take effect
        until PWM timer starts counting down.


     If T1 is greater than the minimum measurement window tcrit,
     then no modification to the pattern is needed.*/
    if (pSingleShunt->T1 > pSingleShunt->tcrit)
    {
        pSingleShunt->Tc1 = pSingleShunt->T7;
        pSingleShunt->Tc2 = pSingleShunt->T7;
    }
    /* If PWM Timer is counting down and there is not enough time to measure 
    current through single shunt, that is when T1 is lesser than tcrit, 
    then modify pattern by adding a minimum time of  tcrit and compensate the added 
    value by subtracting it from T1 which will take effect when PWM Counter 
    is counting up  */
    else
    {
        pSingleShunt->Tc1 = pSingleShunt->T7 - (pSingleShunt->tcrit-pSingleShunt->T1);
        pSingleShunt->Tc2 = pSingleShunt->T7 + (pSingleShunt->tcrit-pSingleShunt->T1);
    }
    pSingleShunt->Tb1 = pSingleShunt->T7 + pSingleShunt->T1;
    pSingleShunt->Tb2 = pSingleShunt->Tb1;
     /*If T2 is greater than the minimum measurement window tcrit,
     then no modification to the pattern is needed.*/
    if (pSingleShunt->T2 > pSingleShunt->tcrit)
    {
        pSingleShunt->Ta1 = pSingleShunt->Tb1 + pSingleShunt->T2;
        pSingleShunt->Ta2 = pSingleShunt->Ta1;
    }
     /* If PWM Timer is counting down and there is not enough time to measure 
    current through single shunt, that is when T2 is lesser than tcrit, 
    then modify pattern by adding a minimum time of  tcrit and compensate the added 
    value by subtracting it from T2 which will take effect when PWM Counter 
    is counting up  */
    else
    {
        pSingleShunt->Ta1 = pSingleShunt->Tb1 + pSingleShunt->tcrit;
        pSingleShunt->Ta2 = pSingleShunt->Tb2 + pSingleShunt->T2 + pSingleShunt->T2 - pSingleShunt->tcrit;
    }

}
/**
* <B> Function: SingleShunt_PhaseCurrentReconstruction(SINGLE_SHUNT_PARM_T *)</B>
*
* @brief Function to reconstruct phase currents from bus current samples.
*
* @param Pointer to the data structure containing Single Shunt parameters.
* @return none.
* 
* @example
* <CODE> SingleShunt_PhaseCurrentReconstruction(&singleShunt); </CODE>
*
*/
void SingleShunt_PhaseCurrentReconstruction(SINGLE_SHUNT_PARM_T *pSingleShunt)
{
    switch(pSingleShunt->sectorSVM)
    {
        case 1:
            pSingleShunt->Ib = pSingleShunt->Ibus1;
            pSingleShunt->Ic = -pSingleShunt->Ibus2;
            pSingleShunt->Ia = -pSingleShunt->Ic - pSingleShunt->Ib;
        break;
        case 2:
            pSingleShunt->Ia = pSingleShunt->Ibus1;
            pSingleShunt->Ib = -pSingleShunt->Ibus2;
            pSingleShunt->Ic = -pSingleShunt->Ia - pSingleShunt->Ib;
        break;
        case 3:
            pSingleShunt->Ia = pSingleShunt->Ibus1; 
            pSingleShunt->Ic = -pSingleShunt->Ibus2;
            pSingleShunt->Ib = -pSingleShunt->Ia - pSingleShunt->Ic;
        break;
        case 4:
            pSingleShunt->Ic = pSingleShunt->Ibus1; 
            pSingleShunt->Ia = -pSingleShunt->Ibus2; 
            pSingleShunt->Ib = -pSingleShunt->Ia - pSingleShunt->Ic;
        break;
        case 5:
            pSingleShunt->Ib = pSingleShunt->Ibus1; 
            pSingleShunt->Ia = -pSingleShunt->Ibus2; 
            pSingleShunt->Ic = -pSingleShunt->Ia - pSingleShunt->Ib;
        break;
        case 6:
            pSingleShunt->Ic = pSingleShunt->Ibus1; 
            pSingleShunt->Ib = -pSingleShunt->Ibus2;
            pSingleShunt->Ia = -pSingleShunt->Ic - pSingleShunt->Ib;
        break;
        default:
            pSingleShunt->Ic = 0; 
            pSingleShunt->Ib = 0;
            pSingleShunt->Ia = 0;
        break;
    }
}

// </editor-fold>
