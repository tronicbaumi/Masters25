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
//#include "../hal/measure.h"
#include "../hal/pwm.h"
#include "../hal/port_config.h"
#include "board_service.h"
#include "X2CMain.h"

#ifndef X2C_H
#warning "Please generate the code from the model!"
#endif

    static int16_t CpuLoad;
   
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
       
    if( PORTDbits.RD9 == 1)x2cModel.inports.bSW1 = INT16_MAX;
    else  x2cModel.inports.bSW1 = 0;

    if( PORTDbits.RD10 == 1)x2cModel.inports.bSW2 = INT16_MAX;
    else  x2cModel.inports.bSW2 = 0;     

    x2cModel.inports.bV_POT = (ADCBUF_POT-2048)<<4;   
  
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
    
    
    
        PWM_PDC1 = ((LOOPTIME_TCY>>1) + (int16)(__builtin_mulss(*x2cModel.outports.bPWM1, (LOOPTIME_TCY>>1))>>15));     
        PWM_PDC2 = ((LOOPTIME_TCY>>1) + (int16)(__builtin_mulss(0, (LOOPTIME_TCY>>1))>>15));            
        PWM_PDC3 = ((LOOPTIME_TCY>>1) + (int16)(__builtin_mulss(0, (LOOPTIME_TCY>>1))>>15));

    
    if (*x2cModel.outports.bLED1) {
        LED1=true;
    }
    else {
        LED1=false;
    }    
    
    if (*x2cModel.outports.bLED2) {
        LED2=true;
    }
    else {
        LED2=false;
    }

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
    TIMER1_CounterClear();
 //   LED1 = true;
    UpdateInports();
    X2C_Update();
    UpdateOutports();
 //   LED1 = false;
    CpuLoad =  (int16_t)(TIMER1_CounterRead()*32768/5000);
 }

/* *****************************************************************************
 End of File
 */
