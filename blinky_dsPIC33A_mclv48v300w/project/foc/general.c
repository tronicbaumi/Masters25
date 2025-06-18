// <editor-fold defaultstate="collapsed" desc="Description/Instruction ">
/**
 * @file general.c
 *
 * @brief This module implements the algebraic equations
 *
 * Component: GENERAL
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

#include "general.h"

// </editor-fold>

// <editor-fold defaultstate="expanded" desc="INTERFACE FUNCTIONS ">

/**
* <B> Function: SaturateFloat( float * const, const float, const float) </B>
*
* @brief Function saturates a float value between the minimum and maximum values.
* 
* @param pointer to the input.
* @param minimum value.
* @param maximum value.
* @return none.
* 
* @example
* <CODE> SaturateFloat( &x, -1.0f, 0.0f ); </CODE>
*
*/
void SaturateFloat( float * const input, const float min, const float max  )
{
    if( max < (*input ))
    {
        *input = max;
    }
    else if( min > (*input ))
    {
        *input = min;
    }
    else
    {

    }
}
/**
* <B> Function: SquareFloat(const float ) </B>
*
* @brief Function returns square of a floating point variable.
* 
* @param floating point value.
* @return square of the floating point input.
* 
* @example
* <CODE> SquareFloat(x); </CODE>
*
*/
float SquareFloat(const float x)
{
    return ( x * x );
}
/**
* <B> Function:  LowPassFilter (float ,float ,float * ) </B>
*
* @brief Function runs 1st order backward Euler filter operation on the input.
*        
* @param input signal
* @param Filter coefficient value
* @param pointer to output signal
*
* @example
* <CODE> LowPassFilter (input, filterCoeff,*output); </CODE>
*
*/

void LowPassFilter (float input,float filterCoeff,float* output)
{
	*output = *output+ ((input - *output) * filterCoeff) ;
}

// </editor-fold>