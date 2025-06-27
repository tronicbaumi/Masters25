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
//#undef OPEN_LOOP_FUNCTIONING
//#undef TORQUE_MODE
//#define INTERNAL_OPAMP_CONFIG
//#undef SINGLE_SHUNT
///*Motor Selection : 1 = Hurst DMA0204024B101(AC300022: Hurst300 or Long Hurst)
//                    2 = Hurst DMB0224C10002(AC300020: Hurst075 or Short Hurst)*/
//#define MOTOR  3
// </editor-fold>    
    
// <editor-fold defaultstate="collapsed" desc="HEADER FILES ">
#include <math.h>
#include <stdint.h>
    

// </editor-fold>
  
// <editor-fold defaultstate="expanded" desc="DEFINITIONS/CONSTANTS ">    
/** Constants */
//
#define LOOPTIME_SEC                                  0.00005f
#define PWMFREQUENCY                                  1/LOOPTIME_MICROSEC
#define DEADTIME_MICROSEC                             1.0f
#define LOOPTIME_MICROSEC                             (LOOPTIME_SEC * 1000000.0f)

// </editor-fold>

#ifdef __cplusplus
}
#endif

#endif	/* end of __USERPARMS_H */
