/* ************************************************************************** */
/** X2CMain.c

  @Company
    Microchip Technology

  @Summary
 Implementation of X2C In and Outport connections

 */
/* ************************************************************************** */
#include <xc.h>
#include "X2CMain.h"
#include "X2C.h"
#include "../userparms.h"
#include "../hal/measure.h"
#include "../hal/pwm.h"
#include "../foc/clarke_park.h"
#include "../foc/control.h"
#include "../foc/estim_qei.h"
#include "../hal/port_config.h"
#include "qei.h"
#include "X2CMain.h"

#ifndef X2C_H
#warning "Please generate the code from the model!"
#endif

    static int16_t CpuLoad;
//    static uint16_t POS1CNTtemp;

    volatile int16_t offset_AN1_IA=0, offset_AN4_IB=0;

    extern MCAPP_MEASURE_T measureInputs;
    extern MC_ABC_T vabc,iabc;
    extern UGF_T uGF;

int16_t GetQEIVel(void)
{
  static int32_t vel_temp = (60*(int32_t)(PWMFREQUENCY/SPEED_SAMPLE_FREQ)*(int32_t)INT16_MAX)/((int32_t)MAX_SPEED*(int32_t)PULSE_PER_REV);
  static uint16_t SampleTimeDivider = 0;
  static int16_t Speed;
  
  
  SampleTimeDivider++;  /* Sample time 10ms SAMPLE_FREQ */
  if(SampleTimeDivider >= (100))    
  {
      SampleTimeDivider = 0;
      //Speed = (int16_t)(VEL1CNT*vel_temp);
      Speed = VEL1CNT*9;
  }
  return Speed;
}    
    
void UpdateInports(void) {

    /*
     * Pass the peripheral values to model Inports
     * if (PORTA & 1) { 
     *    x2cModel.inports.bInport = INT16_MAX;
     * }else {
     *    x2cModel.inports.bInport = 0;
     * }
     * 
     * The following inputs of the model can be used:
      x2cModel.inports.bCPU_LOAD = Scaling*A_PeripheralVariable
      x2cModel.inports.bI_a = Scaling*A_PeripheralVariable
      x2cModel.inports.bI_b = Scaling*A_PeripheralVariable
      x2cModel.inports.bI_sum = Scaling*A_PeripheralVariable
      x2cModel.inports.bQEI_POS = Scaling*A_PeripheralVariable
      x2cModel.inports.bQEI_VEL = Scaling*A_PeripheralVariable
      x2cModel.inports.bSW1 = Scaling*A_PeripheralVariable
      x2cModel.inports.bSW2 = Scaling*A_PeripheralVariable
      x2cModel.inports.bV_POT = Scaling*A_PeripheralVariable

     */
    
    if(uGF.bits.ChangeSpeed) x2cModel.inports.bSW1 = false;
    else  x2cModel.inports.bSW1 = true;
    
    
    if(1 == uGF.bits.RunMotor){
        
        x2cModel.inports.bSW2 = INT16_MAX;
        
    }else{
        x2cModel.inports.bSW2 = 0;        
    }
    x2cModel.inports.bI_a = measureInputs.current.Ia; //Compensated FIP 
    //x2cModel.inports.bI_a =  iabc.a;                //Compensated Float
    
    x2cModel.inports.bI_b = measureInputs.current.Ib;//Compensated FIP 
    //x2cModel.inports.bI_b =  iabc.b;               //Compensated Float
    
    x2cModel.inports.bV_POT = (measureInputs.potValue-2048)<<2;   

    //Encoder caculation QEI not supported by AN1292
    x2cModel.inports.bQEI_POS = (int16_t) (__builtin_mulss(POS1CNT, QEI_FACT_MECH))+*x2cModel.outports.bQEI_OFFSET;
    x2cModel.inports.bQEI_VEL = GetQEIVel();
    
    x2cModel.inports.bCPU_LOAD = CpuLoad;   

}

void UpdateOutports(void) {
    
    /*
     * Pass model outports to peripherals e.g.:
     * 
     * if (*x2cModel.outports.bOutport) {  // if model Outport differ than zero 
     *    LATB |= 1; // set LATB0 
     * } else {
     *    LATB &= ~1; // clear LATB0
     * }    
     * 
     * The following outputs of the model can be used:
      A_PeripheralVariable = *x2cModel.outports.bEstimated_angle*Scaling
      A_PeripheralVariable = *x2cModel.outports.bEstimated_speed*Scaling
      A_PeripheralVariable = *x2cModel.outports.bHOME_INIT*Scaling
      A_PeripheralVariable = *x2cModel.outports.bLED1*Scaling
      A_PeripheralVariable = *x2cModel.outports.bLED2*Scaling
      A_PeripheralVariable = *x2cModel.outports.bPWM1*Scaling
      A_PeripheralVariable = *x2cModel.outports.bPWM2*Scaling
      A_PeripheralVariable = *x2cModel.outports.bPWM3*Scaling
     */   
    
    
    if(uGF.bits.RunMotor == 1)  
    {
        /* Clear position counter on Home init */
        if (*x2cModel.outports.bHOME_INIT > 0) { 
            QEI_Initialize(); //*x2cModel.outports.bHOME_INIT;
            StartQEI();  
        }
        //! PDC1 must be updated last, it triggers the other updates!
        PWM_PDC3 = ((LOOPTIME_TCY>>1) + (int16)(__builtin_mulss(*x2cModel.outports.bPWM1, (LOOPTIME_TCY>>1))>>15));     
        PWM_PDC2 = ((LOOPTIME_TCY>>1) + (int16)(__builtin_mulss(*x2cModel.outports.bPWM3, (LOOPTIME_TCY>>1))>>15));            
        PWM_PDC1 = ((LOOPTIME_TCY>>1) + (int16)(__builtin_mulss(*x2cModel.outports.bPWM2, (LOOPTIME_TCY>>1))>>15));

  
    }
    else
    {
        /* if run motor command is not activated */   
        
        PWM_TRIGA = ADC_SAMPLING_POINT;
#ifdef SINGLE_SHUNT
        SINGLE_SHUNT_TRIGGER1 = LOOPTIME_TCY>>2;
        SINGLE_SHUNT_TRIGGER2 = LOOPTIME_TCY>>1;
        PWM_PHASE3 = MIN_DUTY;
        PWM_PHASE2 = MIN_DUTY;
        PWM_PHASE1 = MIN_DUTY;
#endif
        PWM_PDC3  = MIN_DUTY;
        PWM_PDC2  = MIN_DUTY;
        PWM_PDC1  = MIN_DUTY;
    }    

    

//    

//    
//    if (*x2cModel.outports.bLED1) {
//        LED1_SetHigh();
//    }
//    else {
//        LED1_SetLow();
//    }    
//    
//    if (*x2cModel.outports.bLED2) {
//        LED2_SetHigh();
//    }
//    else {
//        LED2_SetLow();
//    }

}
/**
 * Calls the inports update function
 * Then run model calculation
 * Last read model outports and update the peripherals
*/
/*
 * The selected model update mode is manual.
 * The X2C_Task() have to be called manually!
 * Note:
 * The model X2C sample time frequency must be the same 
 * as the X2C_X2C_Task() call frequency. 
*/

 void X2C_Task (void)
 {
    LED1 = 1;
    UpdateInports();
    X2C_Update();
    UpdateOutports();
    LED1 = 0;
}


/* *****************************************************************************
 End of File
 */
