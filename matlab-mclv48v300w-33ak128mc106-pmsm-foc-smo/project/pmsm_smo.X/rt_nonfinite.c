/*
 * Third Party Support License -- for use only to support products
 * interfaced to MathWorks software under terms specified in your
 * company's restricted use license agreement.
 *
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.60 (28-May-2025)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: rt_nonfinite.c
 *
 * Code generated for Simulink model 'pmsm_smo'.
 *
 * Model version                  : 14.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 24 11:27:34 2025
 */

#include "rtGetNaN.h"
#include "rtGetInf.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "rt_nonfinite.h"
#define NumBitsPerChar                 8U

double rtInf;
double rtMinusInf;
double rtNaN;
float rtInfF;
float rtMinusInfF;
float rtNaNF;

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
bool rtIsInf(double value)
{
  return (bool)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
bool rtIsInfF(float value)
{
  return (bool)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
bool rtIsNaN(double value)
{
  bool result = (bool) 0;
  size_t bitsPerReal = sizeof(double) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((float)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      double fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (bool)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                    ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                     (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
bool rtIsNaNF(float value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (bool)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
