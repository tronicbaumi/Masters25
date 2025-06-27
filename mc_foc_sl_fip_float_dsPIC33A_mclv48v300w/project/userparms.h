// <editor-fold defaultstate="collapsed" desc="Description/Instruction ">
/**
 * @file userparms.h
 *
 * @brief This file has definitions to be configured by the user for spinning
 * motor using field oriented control.
 *
 * Board : MCLV-48V-300W + dsPIC33AK128MC106 MC DIM
 *
 */
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Disclaimer ">

/*******************************************************************************
* SOFTWARE LICENSE AGREEMENT
* 
* © [2024] Microchip Technology Inc. and its subsidiaries
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

#ifndef __USERPARMS_H
#define __USERPARMS_H

#ifdef __cplusplus
extern "C" {
#endif

// <editor-fold defaultstate="expanded" desc="DEFINITIONS/MACROS ">   

#define INTERNAL_OPAMP_CONFIG

// </editor-fold>    
    
// <editor-fold defaultstate="collapsed" desc="HEADER FILES ">
#include <math.h>
#include <stdint.h>
    
    
typedef union
{
    struct
    {
        /** Run motor indication flag */
        unsigned RunMotor:1;
        /** Open loop/closed loop indication flag */
        unsigned OpenLoop:1;
        /** Mode changed indication flag - from open to closed loop */
        unsigned ChangeMode:1;
        /** Field weakening indication */
        unsigned ChangeSpeed:1;
        /** Unused bits */
        unsigned    :28;
    }bits;
    uint32_t Word;
} UGF_T;

    
    
//ChB#if MOTOR == 1
//    #include "hurst300.h"
//#elif MOTOR == 2
//    #include "hurst075.h"
//#elif MOTOR == 3
//    #include "ACT57BLF02.h"
//#else
////ChB    #include "hurst300.h" 
//#endif
// </editor-fold>
  
// <editor-fold defaultstate="expanded" desc="DEFINITIONS/CONSTANTS ">    
/** Constants */
    
#define LOOPTIME_SEC                                  0.00005f
#define PWMFREQUENCY                                  1/LOOPTIME_MICROSEC
#define DEADTIME_MICROSEC                             1.0f
#define LOOPTIME_MICROSEC                             (LOOPTIME_SEC * 1000000.0f)
/* encoder */
#define PULSE_PER_REV   1024               // ENCODER Pulses
#define N_P             4                   // Electrical Pole-Pairs
#define QEI_FACT        65536/((PULSE_PER_REV/N_P))
#define QEI_FACT_MECH   65536/(PULSE_PER_REV)
    
#define SPEED_SAMPLE_FREQ   100             /*In 1/seconds*/
#define MAX_SPEED   3500                    /*rpm*/
    

// </editor-fold>

#ifdef __cplusplus
}
#endif

#endif	/* end of __USERPARMS_H */
