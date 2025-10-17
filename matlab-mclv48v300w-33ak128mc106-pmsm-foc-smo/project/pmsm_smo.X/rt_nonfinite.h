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
 * File: rt_nonfinite.h
 *
 * Code generated for Simulink model 'pmsm_smo'.
 *
 * Model version                  : 14.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 24 11:27:34 2025
 */

#ifndef rt_nonfinite_h_
#define rt_nonfinite_h_
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#define NOT_USING_NONFINITE_LITERALS   1

extern double rtInf;
extern double rtMinusInf;
extern double rtNaN;
extern float rtInfF;
extern float rtMinusInfF;
extern float rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern bool rtIsInf(double value);
extern bool rtIsInfF(float value);
extern bool rtIsNaN(double value);
extern bool rtIsNaNF(float value);
typedef struct {
  struct {
    uint32_t wordH;
    uint32_t wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_t wordL;
    uint32_t wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    float wordLreal;
    uint32_t wordLuint;
  } wordL;
} IEEESingle;

#endif                                 /* rt_nonfinite_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
