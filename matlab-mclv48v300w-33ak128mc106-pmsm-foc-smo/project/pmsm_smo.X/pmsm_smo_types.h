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
 * File: pmsm_smo_types.h
 *
 * Code generated for Simulink model 'pmsm_smo'.
 *
 * Model version                  : 14.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 24 11:27:34 2025
 */

#ifndef pmsm_smo_types_h_
#define pmsm_smo_types_h_
#include <stdint.h>
#ifndef DEFINED_TYPEDEF_FOR_OpMode_
#define DEFINED_TYPEDEF_FOR_OpMode_

typedef enum {
  Inactive = 0,                        /* Default value */
  Prepare,
  Run
} OpMode;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_pmsm_smo_T RT_MODEL_pmsm_smo_T;

#endif                                 /* pmsm_smo_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
