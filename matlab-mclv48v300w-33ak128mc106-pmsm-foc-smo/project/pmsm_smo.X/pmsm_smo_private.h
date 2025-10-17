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
 * File: pmsm_smo_private.h
 *
 * Code generated for Simulink model 'pmsm_smo'.
 *
 * Model version                  : 14.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 24 11:27:34 2025
 */

#ifndef pmsm_smo_private_h_
#define pmsm_smo_private_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "zero_crossing_types.h"
#include "pmsm_smo.h"
#include "pmsm_smo_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#ifndef MCHP_isMainFile

union {
  struct {
    unsigned int task0 : 1;
    unsigned int task1 : 1;
    unsigned int task2 : 1;
    unsigned int task3 : 1;
    unsigned int task4 : 1;
    unsigned int task5 : 1;
  } b;

  unsigned int val;
} extern volatile MCHP_MCU_Overload;

#endif

extern volatile unsigned int mcuFlagRecursion __attribute__ ((near)) ;
extern volatile uint16_t MCHP_MCULoadResult[] __attribute__ ((near)) ;
extern volatile uint16_t MCHP_MCULoadPreviousTimerValue[] __attribute__ ((near)) ;

/* Declare UART2 Tx Circular Buffer Structure */
extern MCHP_UART2_TxStr MCHP_UART2_Tx;
extern MCHP_UART2_RxStr MCHP_UART2_Rx;

/* Declare UART1 Tx Circular Buffer Structure */
extern MCHP_UART1_TxStr MCHP_UART1_Tx;
extern MCHP_UART1_RxStr MCHP_UART1_Rx;
extern float rt_modf_snf(float u0, float u1);
extern uint32_t plook_u32ff_evenc(float u, float bp0, float bpSpace, uint32_t maxIndex, float *fraction);
extern float intrp1d_fu32fl_pw(uint32_t bpIndex, float frac, const float table[]);
extern void mul_wide_u32(uint32_t in0, uint32_t in1, uint32_t *ptrOutBitsHi, uint32_t *ptrOutBitsLo);
extern uint32_t mul_u32_hiSR_round(uint32_t a, uint32_t b, uint32_t aShift);
extern uint32_t mul_u32_loSR(uint32_t a, uint32_t b, uint32_t aShift);
extern void pmsm_smo_TwophaseCRLwrap(float rtu_a, float rtu_b, float *rty_Alpha, float *rty_Beta);
extern void pmsm_smo_DQAxisPriority(float rtu_dqRef, float rtu_dqRef_l, float rtu_satLim, float rtu_satLimSq,
  uint16_t rtu_satMethod, float rty_dqSat[2]);
extern void pmsm_smo_DQEquivalence(float rtu_dqRef, float rtu_dqRef_m, float rtu_magSquare, float rtu_satLim,
  float rtu_satLimSq, float rty_dqSat[2]);
extern void pmsm_smo_IfActionSubsystem(float rtu_In1, float *rty_Out1);
extern void pmsm_smo_IfActionSubsystem1(float rtu_In1, float *rty_Out1);
extern void pmsm_smo_TwoinputsCRL(float rtu_Ds, float rtu_Qs, float rtu_sin, float rtu_cos, float *rty_Alpha,
  float *rty_Beta);
extern void pmsm_smo_TwoinputsCRL_e(float rtu_Alpha, float rtu_Beta, float rtu_sine, float rtu_cos, float
  *rty_Ds, float *rty_Qs);
extern void pmsm_smo_SpeedControl(float rtu_Speed_Meas, float rtu_RunCmd, float rtu_Speed_Ref, float
  *rty_IdqRef, float *rty_IdqRef_f, DW_SpeedControl_pmsm_smo_T *localDW);

#endif                                 /* pmsm_smo_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
