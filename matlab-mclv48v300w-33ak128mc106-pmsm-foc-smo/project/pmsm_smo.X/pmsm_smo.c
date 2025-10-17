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
 * File: pmsm_smo.c
 *
 * Code generated for Simulink model 'pmsm_smo'.
 *
 * Model version                  : 14.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 24 11:27:34 2025
 */

#include "pmsm_smo.h"
#include <stdint.h>
#include "pmsm_smo_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <stdbool.h>
#include "pmsm_smo_types.h"
#include "zero_crossing_types.h"
#include <float.h>

/* Named constants for Chart: '<S88>/Calibration State' */
#define pmsm_smo_IN_Calibration        ((uint8_t)1U)
#define pmsm_smo_IN_Done               ((uint8_t)1U)
#define pmsm_smo_IN_Init               ((uint8_t)2U)
#define pmsm_smo_IN_Init_Lock          ((uint8_t)2U)
#define pmsm_smo_IN_NO_ACTIVE_CHILD    ((uint8_t)0U)
#define pmsm_smo_IN_ipsOffsetCalib     ((uint8_t)3U)

/* Named constants for Chart: '<S93>/Rotor Locking' */
#define pmsm_smo_IN_Init_g             ((uint8_t)1U)
#define pmsm_smo_IN_Lock               ((uint8_t)2U)

/* Named constants for Chart: '<S94>/Error Checking' */
#define pmsm_smo_IN_Start              ((uint8_t)2U)
#define pmsm_smo_IN_ThetaOffsetCalib   ((uint8_t)3U)

/* Named constants for Chart: '<S82>/System Control' */
#define pmsm_smo_IN_CurrOffsetCalib    ((uint8_t)1U)
#define pmsm_smo_IN_Prepare            ((uint8_t)3U)
#define pmsm_smo_IN_Run                ((uint8_t)4U)

/* Block signals and states (default storage) */
DW_pmsm_smo_T pmsm_smo_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_pmsm_smo_T pmsm_smo_PrevZCX;

/* Real-time model */
static RT_MODEL_pmsm_smo_T pmsm_smo_M_;
RT_MODEL_pmsm_smo_T *const pmsm_smo_M = &pmsm_smo_M_;
void __attribute__((__interrupt__,__nocontext__)) _AD2CH2Interrupt(void)
{
  __asm__ volatile ("INC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic increment of mcuFlagRecursion */
  CCP1CON1bits.ON = 1;                 /* (re) start Timer */
  AD2CH2DATA ;                         /* remove cause of interrupt */

  {
    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
      unsigned int Flags3 : 1;
      unsigned int Flags4 : 1;
      unsigned int Flags5 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
      unsigned int Flags3 : 1;
      unsigned int Flags4 : 1;
      unsigned int Flags5 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      unsigned int Task1;              /* 0.0005s periodic task. Max value is 10 */
      unsigned int Task2;              /* 0.001s periodic task. Max value is 20 */
      unsigned int Task3;              /* 0.0015s periodic task. Max value is 30 */
      unsigned int Task4;              /* 0.1s periodic task. Max value is 2000 */
      unsigned int Task5;              /* 0.5s periodic task. Max value is 10000 */
    } static taskCounter __attribute__ ((near)) = {
      .Task1 = 1                       /* Offset is 0 (10 + 1 - 0 including pre-decrement */
      , .Task2 = 1                     /* Offset is 0 (20 + 1 - 0 including pre-decrement */
      , .Task3 = 1                     /* Offset is 0 (30 + 1 - 0 including pre-decrement */
      , .Task4 = 1                     /* Offset is 0 (2000 + 1 - 0 including pre-decrement */
      , .Task5 = 1                     /* Offset is 0 (10000 + 1 - 0 including pre-decrement */
    };

    _AD2CH2IF = 0;                     /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint16_t) 10;/* 0.0005s periodic task. Max value is 10 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
      if (Overrun.Flags1) {
        MCHP_MCU_Overload.b.task1 = 1U;/* Set overload bit for tid 1 */
      }
    }

    taskCounter.Task2--;               /* Decrement task internal counter */
    if (taskCounter.Task2 == 0) {      /* task dropped on overload */
      taskCounter.Task2 = (uint16_t) 20;/* 0.001s periodic task. Max value is 20 */
      event.Flags2 = 1U;               /* Flag tag to be executed */
      if (Overrun.Flags2) {
        MCHP_MCU_Overload.b.task2 = 1U;/* Set overload bit for tid 2 */
      }
    }

    taskCounter.Task3--;               /* Decrement task internal counter */
    if (taskCounter.Task3 == 0) {      /* task dropped on overload */
      taskCounter.Task3 = (uint16_t) 30;/* 0.0015s periodic task. Max value is 30 */
      event.Flags3 = 1U;               /* Flag tag to be executed */
      if (Overrun.Flags3) {
        MCHP_MCU_Overload.b.task3 = 1U;/* Set overload bit for tid 3 */
      }
    }

    taskCounter.Task4--;               /* Decrement task internal counter */
    if (taskCounter.Task4 == 0) {      /* task dropped on overload */
      taskCounter.Task4 = (uint16_t) 2000;/* 0.1s periodic task. Max value is 2000 */
      event.Flags4 = 1U;               /* Flag tag to be executed */
      if (Overrun.Flags4) {
        MCHP_MCU_Overload.b.task4 = 1U;/* Set overload bit for tid 4 */
      }
    }

    taskCounter.Task5--;               /* Decrement task internal counter */
    if (taskCounter.Task5 == 0) {      /* task dropped on overload */
      taskCounter.Task5 = (uint16_t) 10000;/* 0.5s periodic task. Max value is 10000 */
      event.Flags5 = 1U;               /* Flag tag to be executed */
      if (Overrun.Flags5) {
        MCHP_MCU_Overload.b.task5 = 1U;/* Set overload bit for tid 5 */
      }
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    pmsm_smo_step0();

    /* Get model outputs here */
    if (_AD2CH2IF ) {
      /* ensure atomic mcuFlagRecursion--; The value cannot reach 0 here, do not stop the timer */
      __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */
      MCHP_MCU_Overload.b.task0 = 1U;  /* Set overload bit for tid 0 */
      return;                          /* Will re-enter into the interrupt */
    }

    /* Re-Enable Interrupt. IPL value is 2 at this point */
    __asm__ volatile ( "XOR #%[pos], SR" : : [pos] "i" (3<<5) );/* Enable Scheduler re-entrant interrupt. Lower IPL from 2 to 1 */

    /* Step the model for any subrate */
    /* ---------- Handle Task 1 ---------- */
    if (Overrun.Flags1) {
      /* ensure atomic mcuFlagRecursion--; The value cannot reach 0 here, do not stop the timer */
      __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */

      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags1) {             /* Execute task tid 1 */
      Overrun.Flags1 = 1U;
      event.Flags1 = 0U;

      {
        uint16_t Tmp_TMR;
        Tmp_TMR = (uint16_t) CCP1TMR;  /* Read Timer value */
        MCHP_MCULoadResult[0] = Tmp_TMR - MCHP_MCULoadPreviousTimerValue[0];
        MCHP_MCULoadPreviousTimerValue[0] = Tmp_TMR;
      }

      pmsm_smo_step1();

      /* Get model outputs here */
    }

    Overrun.Flags1 = 0U;

    /* ---------- Handle Task 2 ---------- */
    if (Overrun.Flags2) {
      /* ensure atomic mcuFlagRecursion--; The value cannot reach 0 here, do not stop the timer */
      __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */

      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags2) {             /* Execute task tid 2 */
      Overrun.Flags2 = 1U;
      event.Flags2 = 0U;
      pmsm_smo_step2();

      /* Get model outputs here */
    }

    Overrun.Flags2 = 0U;

    /* ---------- Handle Task 3 ---------- */
    if (Overrun.Flags3) {
      /* ensure atomic mcuFlagRecursion--; The value cannot reach 0 here, do not stop the timer */
      __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */

      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags3) {             /* Execute task tid 3 */
      Overrun.Flags3 = 1U;
      event.Flags3 = 0U;
      pmsm_smo_step3();

      /* Get model outputs here */
    }

    Overrun.Flags3 = 0U;

    /* ---------- Handle Task 4 ---------- */
    if (Overrun.Flags4) {
      /* ensure atomic mcuFlagRecursion--; The value cannot reach 0 here, do not stop the timer */
      __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */

      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags4) {             /* Execute task tid 4 */
      Overrun.Flags4 = 1U;
      event.Flags4 = 0U;
      pmsm_smo_step4();

      /* Get model outputs here */
    }

    Overrun.Flags4 = 0U;

    /* ---------- Handle Task 5 ---------- */
    if (Overrun.Flags5) {
      /* ensure atomic mcuFlagRecursion--; The value cannot reach 0 here, do not stop the timer */
      __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */

      /* Priority to higher rate steps interrupted */
      return;
    }

    while (event.Flags5) {             /* Execute task tid 5 */
      Overrun.Flags5 = 1U;
      event.Flags5 = 0U;
      pmsm_smo_step5();

      /* Get model outputs here */
    }

    Overrun.Flags5 = 0U;

    /* Disable Interrupt. IPL value is 1 at this point */
    __asm__ volatile ( "XOR #%[pos], SR" : : [pos] "i" (3<<5) );/* Disable Scheduler Interrupts. Rise IPL from 1 to 2 */
  }

  __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */
  if (mcuFlagRecursion == 0) {
    CCP1CON1bits.ON = 0;               /* Stop Timer */
  }
}

uint32_t plook_u32ff_evenc(float u, float bp0, float bpSpace, uint32_t maxIndex, float *fraction)
{
  float fbpIndex;
  float invSpc;
  uint32_t bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = 0.0F;
  } else {
    invSpc = 1.0F / bpSpace;
    fbpIndex = (u - bp0) * invSpc;
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_t)fbpIndex;
      *fraction = (u - ((float)(uint32_t)fbpIndex * bpSpace + bp0)) * invSpc;
    } else {
      bpIndex = maxIndex - 1U;
      *fraction = 1.0F;
    }
  }

  return bpIndex;
}

float intrp1d_fu32fl_pw(uint32_t bpIndex, float frac, const float table[])
{
  float yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

void mul_wide_u32(uint32_t in0, uint32_t in1, uint32_t *ptrOutBitsHi, uint32_t *ptrOutBitsLo)
{
  uint32_t in0Hi;
  uint32_t in0Lo;
  uint32_t in1Hi;
  uint32_t in1Lo;
  uint32_t outBitsLo;
  uint32_t productHiLo;
  uint32_t productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_t mul_u32_hiSR_round(uint32_t a, uint32_t b, uint32_t aShift)
{
  uint32_t u32_chi;
  uint32_t u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  return (uint32_t)((1U << (aShift - 1U) & u32_chi) != 0U) + (u32_chi >> aShift);
}

uint32_t mul_u32_loSR(uint32_t a, uint32_t b, uint32_t aShift)
{
  uint32_t result;
  uint32_t u32_chi;
  mul_wide_u32(a, b, &u32_chi, &result);
  return u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | result >> aShift;
}

/*
 * Output and update for atomic system:
 *    '<S117>/Two phase CRL wrap'
 *    '<S351>/Two phase CRL wrap'
 */
void pmsm_smo_TwophaseCRLwrap(float rtu_a, float rtu_b, float *rty_Alpha, float *rty_Beta)
{
  /* AlgorithmDescriptorDelegate generated from: '<S118>/a16' incorporates:
   *  Gain: '<S118>/one_by_sqrt3'
   *  Sum: '<S118>/a_plus_2b'
   */
  *rty_Alpha = rtu_a;
  *rty_Beta = ((rtu_a + rtu_b) + rtu_b) * 0.577350259F;
}

/*
 * Output and update for action system:
 *    '<S119>/D//Q Axis Priority'
 *    '<S353>/D//Q Axis Priority'
 */
void pmsm_smo_DQAxisPriority(float rtu_dqRef, float rtu_dqRef_l, float rtu_satLim, float rtu_satLimSq,
  uint16_t rtu_satMethod, float rty_dqSat[2])
{
  float rtb_Sum_d;
  float rtb_Switch_g_idx_0;
  float rtb_Switch_g_idx_1;

  /* Switch: '<S123>/Switch' incorporates:
   *  Constant: '<S128>/Constant'
   *  RelationalOperator: '<S128>/Compare'
   */
  if (rtu_satMethod == 1) {
    rtb_Switch_g_idx_0 = rtu_dqRef;
    rtb_Switch_g_idx_1 = rtu_dqRef_l;
  } else {
    rtb_Switch_g_idx_0 = rtu_dqRef_l;
    rtb_Switch_g_idx_1 = rtu_dqRef;
  }

  /* End of Switch: '<S123>/Switch' */

  /* Switch: '<S133>/Switch2' incorporates:
   *  Gain: '<S132>/Gain'
   *  RelationalOperator: '<S133>/LowerRelop1'
   *  RelationalOperator: '<S133>/UpperRelop'
   *  Switch: '<S133>/Switch'
   */
  if (rtb_Switch_g_idx_0 > rtu_satLim) {
    rtb_Switch_g_idx_0 = rtu_satLim;
  } else if (rtb_Switch_g_idx_0 < -rtu_satLim) {
    /* Switch: '<S133>/Switch' incorporates:
     *  Gain: '<S132>/Gain'
     */
    rtb_Switch_g_idx_0 = -rtu_satLim;
  }

  /* End of Switch: '<S133>/Switch2' */

  /* Sum: '<S132>/Sum' incorporates:
   *  Product: '<S132>/Product'
   */
  rtb_Sum_d = rtu_satLimSq - rtb_Switch_g_idx_0 * rtb_Switch_g_idx_0;

  /* If: '<S132>/If' incorporates:
   *  Product: '<S132>/Product2'
   *  RelationalOperator: '<S132>/Relational Operator'
   */
  if (!(rtb_Sum_d >= rtb_Switch_g_idx_1 * rtb_Switch_g_idx_1)) {
    /* Outputs for IfAction SubSystem: '<S132>/limitRef2' incorporates:
     *  ActionPort: '<S134>/Action Port'
     */
    /* Switch: '<S134>/Switch' incorporates:
     *  Gain: '<S134>/Gain'
     *  Sqrt: '<S134>/Sqrt'
     *  Switch: '<S134>/Switch1'
     */
    if (rtb_Switch_g_idx_1 >= 0.0F) {
      /* Switch: '<S134>/Switch1' incorporates:
       *  Constant: '<S134>/Constant'
       */
      if (!(rtb_Sum_d > 0.0F)) {
        rtb_Sum_d = 0.0F;
      }

      rtb_Switch_g_idx_1 = (float)sqrt(rtb_Sum_d);
    } else {
      if (!(rtb_Sum_d > 0.0F)) {
        /* Switch: '<S134>/Switch1' incorporates:
         *  Constant: '<S134>/Constant'
         */
        rtb_Sum_d = 0.0F;
      }

      rtb_Switch_g_idx_1 = -(float)sqrt(rtb_Sum_d);
    }

    /* End of Switch: '<S134>/Switch' */
    /* End of Outputs for SubSystem: '<S132>/limitRef2' */
  }

  /* End of If: '<S132>/If' */

  /* Switch: '<S123>/Switch1' incorporates:
   *  Constant: '<S129>/Constant'
   *  RelationalOperator: '<S129>/Compare'
   */
  if (rtu_satMethod == 1) {
    rty_dqSat[0] = rtb_Switch_g_idx_0;
    rty_dqSat[1] = rtb_Switch_g_idx_1;
  } else {
    rty_dqSat[0] = rtb_Switch_g_idx_1;
    rty_dqSat[1] = rtb_Switch_g_idx_0;
  }

  /* End of Switch: '<S123>/Switch1' */
}

/*
 * Output and update for action system:
 *    '<S119>/D-Q Equivalence'
 *    '<S353>/D-Q Equivalence'
 */
void pmsm_smo_DQEquivalence(float rtu_dqRef, float rtu_dqRef_m, float rtu_magSquare, float rtu_satLim, float
  rtu_satLimSq, float rty_dqSat[2])
{
  float rtb_Switch_j;

  /* If: '<S122>/If' incorporates:
   *  RelationalOperator: '<S122>/Relational Operator'
   */
  if (rtu_magSquare > rtu_satLimSq) {
    /* Outputs for IfAction SubSystem: '<S122>/Limiter' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    /* Sqrt: '<S126>/Square Root' */
    rtb_Switch_j = (float)sqrt(rtu_magSquare);

    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S126>/Constant'
     */
    if (!(rtb_Switch_j != 0.0F)) {
      rtb_Switch_j = 1.0F;
    }

    /* End of Switch: '<S126>/Switch' */

    /* Product: '<S126>/Divide' incorporates:
     *  Product: '<S126>/Product'
     */
    rty_dqSat[0] = rtu_dqRef * rtu_satLim / rtb_Switch_j;
    rty_dqSat[1] = rtu_dqRef_m * rtu_satLim / rtb_Switch_j;

    /* End of Outputs for SubSystem: '<S122>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S122>/Passthrough' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    /* SignalConversion generated from: '<S127>/dqRef' */
    rty_dqSat[0] = rtu_dqRef;
    rty_dqSat[1] = rtu_dqRef_m;

    /* End of Outputs for SubSystem: '<S122>/Passthrough' */
  }

  /* End of If: '<S122>/If' */
}

/*
 * Output and update for action system:
 *    '<S250>/If Action Subsystem'
 *    '<S266>/If Action Subsystem'
 *    '<S484>/If Action Subsystem'
 *    '<S496>/If Action Subsystem'
 */
void pmsm_smo_IfActionSubsystem(float rtu_In1, float *rty_Out1)
{
  float tmp;

  /* DataTypeConversion: '<S253>/Convert_uint16' */
  tmp = (float)floor(rtu_In1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (float)fmod(tmp, 65536.0);
  }

  /* Sum: '<S253>/Sum' incorporates:
   *  DataTypeConversion: '<S253>/Convert_back'
   *  DataTypeConversion: '<S253>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (float)(tmp < 0.0F ? (int32_t)(int16_t)-(int16_t)(uint16_t)-tmp : (int32_t)(int16_t)
    (uint16_t)tmp);
}

/*
 * Output and update for action system:
 *    '<S250>/If Action Subsystem1'
 *    '<S266>/If Action Subsystem1'
 *    '<S484>/If Action Subsystem1'
 *    '<S496>/If Action Subsystem1'
 */
void pmsm_smo_IfActionSubsystem1(float rtu_In1, float *rty_Out1)
{
  float tmp;

  /* DataTypeConversion: '<S254>/Convert_uint16' */
  if (rtu_In1 < 0.0F) {
    tmp = (float)ceil(rtu_In1);
  } else {
    tmp = (float)floor(rtu_In1);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (float)fmod(tmp, 65536.0);
  }

  /* Sum: '<S254>/Sum' incorporates:
   *  DataTypeConversion: '<S254>/Convert_back'
   *  DataTypeConversion: '<S254>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (float)(tmp < 0.0F ? (int32_t)(int16_t)-(int16_t)(uint16_t)-tmp : (int32_t)(int16_t)
    (uint16_t)tmp);
}

/*
 * Output and update for atomic system:
 *    '<S112>/Two inputs CRL'
 *    '<S348>/Two inputs CRL'
 */
void pmsm_smo_TwoinputsCRL(float rtu_Ds, float rtu_Qs, float rtu_sin, float rtu_cos, float *rty_Alpha, float
  *rty_Beta)
{
  /* AlgorithmDescriptorDelegate generated from: '<S247>/a16' incorporates:
   *  Product: '<S247>/dcos'
   *  Product: '<S247>/dsin'
   *  Product: '<S247>/qcos'
   *  Product: '<S247>/qsin'
   *  Sum: '<S247>/sum_alpha'
   *  Sum: '<S247>/sum_beta'
   */
  *rty_Alpha = rtu_Ds * rtu_cos - rtu_Qs * rtu_sin;
  *rty_Beta = rtu_Qs * rtu_cos + rtu_Ds * rtu_sin;
}

/*
 * Output and update for atomic system:
 *    '<S114>/Two inputs CRL'
 *    '<S349>/Two inputs CRL'
 */
void pmsm_smo_TwoinputsCRL_e(float rtu_Alpha, float rtu_Beta, float rtu_sine, float rtu_cos, float *rty_Ds,
  float *rty_Qs)
{
  /* AlgorithmDescriptorDelegate generated from: '<S262>/a16' incorporates:
   *  Product: '<S262>/acos'
   *  Product: '<S262>/asin'
   *  Product: '<S262>/bcos'
   *  Product: '<S262>/bsin'
   *  Sum: '<S262>/sum_Ds'
   *  Sum: '<S262>/sum_Qs'
   */
  *rty_Ds = rtu_Alpha * rtu_cos + rtu_Beta * rtu_sine;
  *rty_Qs = rtu_Beta * rtu_cos - rtu_Alpha * rtu_sine;
}

/* Output and update for atomic system: '<S283>/Speed Control' */
void pmsm_smo_SpeedControl(float rtu_Speed_Meas, float rtu_RunCmd, float rtu_Speed_Ref, float *rty_IdqRef,
  float *rty_IdqRef_f, DW_SpeedControl_pmsm_smo_T *localDW)
{
  float rtb_DeadZone;
  float rtb_IProdOut;
  float rtb_Sum_n;
  int8_t tmp;
  int8_t tmp_0;
  bool rtb_LogicalOperator_ej;

  /* Constant: '<S285>/Constant' */
  *rty_IdqRef = 0.0F;

  /* Sum: '<S345>/Add1' incorporates:
   *  Product: '<S345>/Product'
   *  Product: '<S345>/Product1'
   *  UnitDelay: '<S345>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = rtu_Speed_Ref * 0.03F + 0.97F * localDW->UnitDelay_DSTATE;

  /* Sum: '<S286>/Sum' incorporates:
   *  UnitDelay: '<S345>/Unit Delay'
   */
  rtb_IProdOut = localDW->UnitDelay_DSTATE - rtu_Speed_Meas;

  /* Logic: '<S286>/Logical Operator' */
  rtb_LogicalOperator_ej = !(rtu_RunCmd != 0.0F);

  /* DiscreteIntegrator: '<S325>/Integrator' incorporates:
   *  Constant: '<S286>/Ki2'
   */
  if (rtb_LogicalOperator_ej || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* Sum: '<S334>/Sum' incorporates:
   *  Constant: '<S286>/Kp1'
   *  DiscreteIntegrator: '<S325>/Integrator'
   *  Product: '<S330>/PProd Out'
   */
  rtb_Sum_n = rtb_IProdOut * 0.001354F + localDW->Integrator_DSTATE;

  /* DeadZone: '<S317>/DeadZone' incorporates:
   *  Saturate: '<S332>/Saturation'
   */
  if (rtb_Sum_n > 4.83661032F) {
    rtb_DeadZone = rtb_Sum_n - 4.83661032F;
    *rty_IdqRef_f = 4.83661032F;
  } else {
    if (rtb_Sum_n >= -4.83661032F) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = rtb_Sum_n - -4.83661032F;
    }

    if (rtb_Sum_n < -4.83661032F) {
      *rty_IdqRef_f = -4.83661032F;
    } else {
      *rty_IdqRef_f = rtb_Sum_n;
    }
  }

  /* End of DeadZone: '<S317>/DeadZone' */

  /* Product: '<S322>/IProd Out' incorporates:
   *  Constant: '<S286>/Ki1'
   */
  rtb_IProdOut *= 3.332E-5F;

  /* Switch: '<S315>/Switch1' incorporates:
   *  Constant: '<S315>/Clamping_zero'
   *  Constant: '<S315>/Constant'
   *  Constant: '<S315>/Constant2'
   *  RelationalOperator: '<S315>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S315>/Switch2' incorporates:
   *  Constant: '<S315>/Clamping_zero'
   *  Constant: '<S315>/Constant3'
   *  Constant: '<S315>/Constant4'
   *  RelationalOperator: '<S315>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S315>/Switch' incorporates:
   *  Constant: '<S315>/Clamping_zero'
   *  Constant: '<S315>/Constant1'
   *  Logic: '<S315>/AND3'
   *  RelationalOperator: '<S315>/Equal1'
   *  RelationalOperator: '<S315>/Relational Operator'
   *  Switch: '<S315>/Switch1'
   *  Switch: '<S315>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S325>/Integrator' incorporates:
   *  Switch: '<S315>/Switch'
   */
  localDW->Integrator_DSTATE += rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_t)rtb_LogicalOperator_ej;
}

float rt_modf_snf(float u0, float u1)
{
  float q;
  float y;
  bool yEq;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    y = (float)fmod(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > (float)floor(u1))) {
      q = (float)fabs(u0 / u1);
      yEq = !((float)fabs(q - (float)floor(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function for TID0 */
void pmsm_smo_step0(void)              /* Sample time: [5.0E-5s, 0.0s] */
{
  /* local block i/o variables */
  bool rtb_BTN2;
  double rtb_Divide;
  double rtb_Gain;
  double rtb_Gain4;
  double rtb_Product1_c;
  double rtb_Product_an;
  double rtb_Product_d;
  double rtb_Product_dx;
  double rtb_Product_f;
  float rtb_I_ab[2];
  float rtb_Merge_m[2];
  float absInXVar;
  float absInYVar;
  float rtb_Add2_a;
  float rtb_Product_il_idx_2;
  float rtb_RateTransition2_f;
  float rtb_Saturation_e;
  float rtb_Sum1_a;
  float rtb_Switch1_idx_0;
  float rtb_UnitDelay2_idx_3;
  float rtb_algDD_o2;
  float uVarXTmp;
  int32_t rtb_Offset_Value[2];
  int32_t qY;
  uint32_t DiscreteTimeIntegrator;
  uint32_t tmp;
  uint16_t rtb_FixPtSum1;
  int8_t tmp_0;
  int8_t tmp_1;
  uint8_t quadrantInfo;
  bool CurrOffsetMeas;
  bool isReciprocal;
  bool rtb_Compare_gy;
  bool rtb_Compare_h;
  bool rtb_LogicalOperator_b;
  bool rtb_LogicalOperator_lb;
  OpMode rtb_Mode;
  ZCEventType zcEvent;
  static const float tableData_c[16] = { 0.0F, 0.010594652F, 0.0210962314F, 0.0314164795F, 0.0414761603F,
    0.0512081906F, 0.0605594702F, 0.0694913715F, 0.0779791325F, 0.0860104337F, 0.0935835242F, 0.100705102F,
    0.107388355F, 0.113651067F, 0.11951407F, 0.125F };

  float rtb_Sum1_d_tmp;
  bool guard1;
  bool guard2;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [5.0E-5s, 0.0s] to Sample time: [0.001s, 0.0s]  */
  (pmsm_smo_M->Timing.RateInteraction.TID0_2)++;
  if ((pmsm_smo_M->Timing.RateInteraction.TID0_2) > 19) {
    pmsm_smo_M->Timing.RateInteraction.TID0_2 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [5.0E-5s, 0.0s] to Sample time: [0.0015s, 0.0s]  */
  (pmsm_smo_M->Timing.RateInteraction.TID0_3)++;
  if ((pmsm_smo_M->Timing.RateInteraction.TID0_3) > 29) {
    pmsm_smo_M->Timing.RateInteraction.TID0_3 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [5.0E-5s, 0.0s] to Sample time: [0.1s, 0.0s]  */
  (pmsm_smo_M->Timing.RateInteraction.TID0_4)++;
  if ((pmsm_smo_M->Timing.RateInteraction.TID0_4) > 1999) {
    pmsm_smo_M->Timing.RateInteraction.TID0_4 = 0;
  }

  /* S-Function (MCHP_Digital_Input): '<S1>/SW1' */
  /* MCHP_Digital_Input Block: <S1>/SW1/Output */
  rtb_Compare_h = PORTDbits.RD9;       /* Read pin D9 */

  /* Outputs for Triggered SubSystem: '<S522>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S523>/Trigger'
   */
  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  zcEvent = rt_R32ZCFcn(FALLING_ZERO_CROSSING,&pmsm_smo_PrevZCX.TriggeredSubsystem_Trig_ZCE_h,
                        ((float)rtb_Compare_h));
  if (zcEvent != NO_ZCEVENT) {
    /* Logic: '<S523>/NOT' incorporates:
     *  Delay: '<S523>/Delay'
     */
    pmsm_smo_DW.bitsForTID0.NOT = !pmsm_smo_DW.bitsForTID0.Delay_DSTATE_a;

    /* Update for Delay: '<S523>/Delay' */
    pmsm_smo_DW.bitsForTID0.Delay_DSTATE_a = pmsm_smo_DW.bitsForTID0.NOT;
  }

  /* End of Outputs for SubSystem: '<S522>/Triggered Subsystem' */

  /* Chart: '<S82>/System Control' incorporates:
   *  DataTypeConversion: '<S522>/Data Type Conversion1'
   *  UnitDelay: '<S76>/Unit Delay'
   */
  if (pmsm_smo_DW.temporalCounter_i1_d < 16383) {
    pmsm_smo_DW.temporalCounter_i1_d++;
  }

  if (pmsm_smo_DW.is_active_c6_pmsm_smo == 0) {
    pmsm_smo_DW.is_active_c6_pmsm_smo = 1U;
    pmsm_smo_DW.temporalCounter_i1_d = 0U;
    pmsm_smo_DW.is_c6_pmsm_smo = pmsm_smo_IN_Init;
    rtb_Mode = Inactive;
    pmsm_smo_DW.bitsForTID0.CurrOffsetMeas = true;
  } else {
    switch (pmsm_smo_DW.is_c6_pmsm_smo) {
     case pmsm_smo_IN_CurrOffsetCalib:
      rtb_Mode = Inactive;
      pmsm_smo_DW.bitsForTID0.CurrOffsetMeas = false;
      if (pmsm_smo_DW.bitsForTID0.NOT) {
        pmsm_smo_DW.is_c6_pmsm_smo = pmsm_smo_IN_Prepare;
        rtb_Mode = Prepare;
      }
      break;

     case pmsm_smo_IN_Init:
      rtb_Mode = Inactive;
      pmsm_smo_DW.bitsForTID0.CurrOffsetMeas = true;
      if (pmsm_smo_DW.temporalCounter_i1_d >= 10000) {
        pmsm_smo_DW.is_c6_pmsm_smo = pmsm_smo_IN_CurrOffsetCalib;
        rtb_Mode = Inactive;
        pmsm_smo_DW.bitsForTID0.CurrOffsetMeas = false;
      }
      break;

     case pmsm_smo_IN_Prepare:
      rtb_Mode = Prepare;
      if (pmsm_smo_DW.bitsForTID0.NOT && pmsm_smo_DW.bitsForTID0.UnitDelay_DSTATE_f) {
        pmsm_smo_DW.is_c6_pmsm_smo = pmsm_smo_IN_Run;
        rtb_Mode = Run;
      } else if (!pmsm_smo_DW.bitsForTID0.NOT) {
        pmsm_smo_DW.is_c6_pmsm_smo = pmsm_smo_IN_CurrOffsetCalib;
        rtb_Mode = Inactive;
        pmsm_smo_DW.bitsForTID0.CurrOffsetMeas = false;
      }
      break;

     default:
      /* case IN_Run: */
      rtb_Mode = Run;
      if (!pmsm_smo_DW.bitsForTID0.NOT) {
        pmsm_smo_DW.is_c6_pmsm_smo = pmsm_smo_IN_Prepare;
        rtb_Mode = Prepare;
      }
      break;
    }
  }

  /* End of Chart: '<S82>/System Control' */

  /* DataStoreWrite: '<S82>/Data Store Write' */
  CurrOffsetMeas = pmsm_smo_DW.bitsForTID0.CurrOffsetMeas;

  /* Outputs for Enabled SubSystem: '<S81>/Init' incorporates:
   *  EnablePort: '<S87>/Enable'
   */
  /* RelationalOperator: '<S85>/Compare' incorporates:
   *  Constant: '<S85>/Constant'
   *  Constant: '<S87>/Constant10'
   *  DataTypeConversion: '<S76>/Data Type Conversion3'
   */
  if (rtb_Mode == Inactive) {
    pmsm_smo_DW.Constant10_c[0] = 0.0F;
    pmsm_smo_DW.Constant10_c[1] = 0.0F;
    pmsm_smo_DW.Constant10_c[2] = 0.0F;
  }

  /* End of RelationalOperator: '<S85>/Compare' */
  /* End of Outputs for SubSystem: '<S81>/Init' */

  /* RateTransition: '<S7>/Rate Transition1' */
  qY = pmsm_smo_DW.RateTransition1_ActiveBufIdx << 1;
  rtb_Offset_Value[0] = pmsm_smo_DW.RateTransition1_Buffer_h[qY];
  rtb_Offset_Value[1] = pmsm_smo_DW.RateTransition1_Buffer_h[qY + 1];

  /* S-Function (MCHP_ADC_HS_12b): '<S6>/ADC HS 12b dsPICA1' */
  pmsm_smo_DW.ADCHS12bdsPICA1_o1 = (uint16_t) (AD1CH0DATA >> 16);/* Read AD1 for AN0 */
  pmsm_smo_DW.ADCHS12bdsPICA1_o2 = (uint16_t) (AD2CH0DATA >> 16);/* Read AD2 for AN1 */
  pmsm_smo_DW.ADCHS12bdsPICA1_o3 = (uint16_t) (AD2CH1DATA >> 16);/* Read AD2 for AN7 */
  pmsm_smo_DW.ADCHS12bdsPICA1_o4 = (uint16_t) (AD2CH2DATA >> 16);/* Read AD2 for AN9 */

  /* Sum: '<S7>/Average and Sign reverse' */
  if (rtb_Offset_Value[0] < pmsm_smo_DW.ADCHS12bdsPICA1_o1 + INT32_MIN) {
    qY = INT32_MIN;
  } else {
    qY = rtb_Offset_Value[0] - pmsm_smo_DW.ADCHS12bdsPICA1_o1;
  }

  if (qY > 32767) {
    qY = 32767;
  } else if (qY < -32768) {
    qY = -32768;
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Sum: '<S7>/Average and Sign reverse'
   */
  rtb_I_ab[0] = 0.000672727823F * (float)qY;

  /* Sum: '<S7>/Average and Sign reverse' */
  if (rtb_Offset_Value[1] < pmsm_smo_DW.ADCHS12bdsPICA1_o2 + INT32_MIN) {
    qY = INT32_MIN;
  } else {
    qY = rtb_Offset_Value[1] - pmsm_smo_DW.ADCHS12bdsPICA1_o2;
  }

  if (qY > 32767) {
    qY = 32767;
  } else if (qY < -32768) {
    qY = -32768;
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Sum: '<S7>/Average and Sign reverse'
   */
  rtb_I_ab[1] = 0.000672727823F * (float)qY;

  /* RateTransition: '<S511>/Rate Transition2' */
  rtb_RateTransition2_f = pmsm_smo_DW.RateTransition2_Buffer0;

  /* Abs: '<S512>/Abs' */
  rtb_Sum1_a = (float)fabs(rtb_RateTransition2_f);

  /* UnitDelay: '<S5>/Unit Delay2' */
  rtb_RateTransition2_f = pmsm_smo_DW.UnitDelay2_DSTATE[2];
  rtb_UnitDelay2_idx_3 = pmsm_smo_DW.UnitDelay2_DSTATE[3];

  /* Sum: '<S512>/Sum' incorporates:
   *  Delay: '<S512>/Delay2'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_Product_il_idx_2 = pmsm_smo_DW.Delay2_DSTATE[0] - pmsm_smo_DW.UnitDelay2_DSTATE[0];

  /* Switch: '<S515>/Switch1' incorporates:
   *  Abs: '<S515>/Abs1'
   *  Constant: '<S518>/Constant'
   *  Gain: '<S515>/Gain4'
   *  Gain: '<S515>/Gain7'
   *  RelationalOperator: '<S518>/Compare'
   *  Signum: '<S515>/Sign1'
   */
  if ((float)fabs(rtb_Product_il_idx_2) >= 1.14F) {
    /* Signum: '<S515>/Sign1' */
    if (rtIsNaNF(rtb_Product_il_idx_2)) {
      uVarXTmp = (rtNaNF);
    } else if (rtb_Product_il_idx_2 < 0.0F) {
      uVarXTmp = -1.0F;
    } else {
      uVarXTmp = (float)(rtb_Product_il_idx_2 > 0.0F);
    }

    rtb_Product_il_idx_2 = 8.61F * uVarXTmp;
  } else {
    rtb_Product_il_idx_2 *= 7.5512F;
  }

  rtb_Switch1_idx_0 = rtb_Product_il_idx_2;

  /* DiscreteIntegrator: '<S513>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S513>/Delay'
   *  Product: '<S513>/Product'
   *  Sum: '<S513>/Sum2'
   */
  absInYVar = (rtb_Product_il_idx_2 - pmsm_smo_DW.Delay_DSTATE[0]) * rtb_Sum1_a * 5.0E-5F +
    pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_f[0];
  pmsm_smo_DW.Delay_DSTATE[0] = absInYVar;

  /* DiscreteIntegrator: '<S513>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S513>/Delay3'
   *  Product: '<S513>/Product2'
   *  Sum: '<S513>/Sum3'
   */
  pmsm_smo_DW.Delay3_DSTATE[0] = (absInYVar - pmsm_smo_DW.Delay3_DSTATE[0]) * rtb_Sum1_a * 5.0E-5F +
    pmsm_smo_DW.DiscreteTimeIntegrator2_DSTATE[0];

  /* Sum: '<S512>/Sum' incorporates:
   *  Delay: '<S512>/Delay2'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_Product_il_idx_2 = pmsm_smo_DW.Delay2_DSTATE[1] - pmsm_smo_DW.UnitDelay2_DSTATE[1];

  /* Switch: '<S515>/Switch1' incorporates:
   *  Abs: '<S515>/Abs1'
   *  Constant: '<S518>/Constant'
   *  Gain: '<S515>/Gain4'
   *  Gain: '<S515>/Gain7'
   *  RelationalOperator: '<S518>/Compare'
   *  Signum: '<S515>/Sign1'
   */
  if ((float)fabs(rtb_Product_il_idx_2) >= 1.14F) {
    /* Signum: '<S515>/Sign1' */
    if (rtIsNaNF(rtb_Product_il_idx_2)) {
      uVarXTmp = (rtNaNF);
    } else if (rtb_Product_il_idx_2 < 0.0F) {
      uVarXTmp = -1.0F;
    } else {
      uVarXTmp = (float)(rtb_Product_il_idx_2 > 0.0F);
    }

    rtb_Product_il_idx_2 = 8.61F * uVarXTmp;
  } else {
    rtb_Product_il_idx_2 *= 7.5512F;
  }

  /* DiscreteIntegrator: '<S513>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S513>/Delay'
   *  Product: '<S513>/Product'
   *  Sum: '<S513>/Sum2'
   */
  absInYVar = (rtb_Product_il_idx_2 - pmsm_smo_DW.Delay_DSTATE[1]) * rtb_Sum1_a * 5.0E-5F +
    pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_f[1];
  pmsm_smo_DW.Delay_DSTATE[1] = absInYVar;

  /* DiscreteIntegrator: '<S513>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S513>/Delay3'
   *  Product: '<S513>/Product2'
   *  Sum: '<S513>/Sum3'
   */
  pmsm_smo_DW.Delay3_DSTATE[1] = (absInYVar - pmsm_smo_DW.Delay3_DSTATE[1]) * rtb_Sum1_a * 5.0E-5F +
    pmsm_smo_DW.DiscreteTimeIntegrator2_DSTATE[1];

  /* Trigonometry: '<S517>/Trigonometric Function1' incorporates:
   *  Delay: '<S513>/Delay3'
   *  Gain: '<S517>/Gain3'
   */
  if ((pmsm_smo_DW.Delay3_DSTATE[1] == 0.0F) && (-pmsm_smo_DW.Delay3_DSTATE[0] == 0.0F)) {
    absInYVar = 0.0F;
  } else {
    isReciprocal = false;
    if (-pmsm_smo_DW.Delay3_DSTATE[0] < 0.0F) {
      if (pmsm_smo_DW.Delay3_DSTATE[1] < 0.0F) {
        quadrantInfo = 3U;
      } else {
        quadrantInfo = 4U;
      }
    } else if (pmsm_smo_DW.Delay3_DSTATE[1] < 0.0F) {
      quadrantInfo = 2U;
    } else {
      quadrantInfo = 1U;
    }

    absInXVar = (float)fabs(pmsm_smo_DW.Delay3_DSTATE[1]);
    absInYVar = (float)fabs(-pmsm_smo_DW.Delay3_DSTATE[0]);
    if (absInYVar > absInXVar) {
      uVarXTmp = absInYVar;
      absInYVar = absInXVar;
      isReciprocal = true;
    } else {
      uVarXTmp = absInXVar;
    }

    DiscreteTimeIntegrator = plook_u32ff_evenc(absInYVar / uVarXTmp, 0.0F, 0.0666666701F, 15U, &absInXVar);
    absInYVar = intrp1d_fu32fl_pw(DiscreteTimeIntegrator, absInXVar, tableData_c);
    if (isReciprocal) {
      absInYVar = 0.25F - absInYVar;
    }

    if (quadrantInfo == 2) {
      absInYVar = 0.5F - absInYVar;
    } else if (quadrantInfo == 3) {
      absInYVar -= 0.5F;
    } else if (quadrantInfo == 4) {
      absInYVar = -absInYVar;
    }
  }

  /* Sum: '<S517>/Subtract' incorporates:
   *  Bias: '<S517>/Bias2'
   *  Trigonometry: '<S517>/Trigonometric Function1'
   *  UnitDelay generated from: '<S5>/Unit Delay'
   */
  absInYVar = (absInYVar * 6.28318548F + 1.244F) - pmsm_smo_DW.UnitDelay_1_DSTATE;

  /* Bias: '<S519>/Bias1' incorporates:
   *  Bias: '<S519>/Bias'
   *  Constant: '<S519>/load torque1'
   *  Math: '<S519>/Math Function'
   *  Math: '<S519>/Math Function1'
   */
  pmsm_smo_DW.Bias1 = rt_modf_snf(rt_modf_snf(absInYVar, 6.28318548F) + 3.14159274F, 6.28318548F) -
    3.14159274F;

  /* RateTransition generated from: '<S76>/Rate Transition1' */
  pmsm_smo_DW.SpeedRef = pmsm_smo_DW.RateTransition1_3_Buffer0;

  /* RateTransition generated from: '<S79>/Rate Transition14' incorporates:
   *  Bias: '<S520>/Bias'
   *  Bias: '<S520>/Bias1'
   *  Constant: '<S520>/load torque1'
   *  Delay: '<S516>/Delay1'
   *  DiscreteIntegrator: '<S516>/Discrete-Time Integrator4'
   *  Gain: '<S516>/Gain2'
   *  Gain: '<S516>/Gain3'
   *  Math: '<S520>/Math Function'
   *  Math: '<S520>/Math Function1'
   *  Product: '<S516>/Product1'
   *  Sum: '<S516>/Sum2'
   *  Sum: '<S516>/Sum4'
   *  UnitDelay: '<S516>/Unit Delay3'
   */
  pmsm_smo_DW.Delay1_DSTATE = ((rt_modf_snf(rt_modf_snf(absInYVar - pmsm_smo_DW.UnitDelay3_DSTATE, 6.28318548F)
    + 3.14159274F, 6.28318548F) - 3.14159274F) * 20000.0F - pmsm_smo_DW.Delay1_DSTATE) * (0.3F * rtb_Sum1_a) *
    5.0E-5F + pmsm_smo_DW.DiscreteTimeIntegrator4_DSTATE;

  /* Outputs for Enabled SubSystem: '<S81>/Prepare' incorporates:
   *  EnablePort: '<S88>/PreapareEnable'
   */
  /* RelationalOperator: '<S83>/Compare' incorporates:
   *  Constant: '<S83>/Constant'
   *  DataTypeConversion: '<S76>/Data Type Conversion3'
   */
  if (rtb_Mode == Prepare) {
    pmsm_smo_DW.bitsForTID0.Prepare_MODE = true;

    /* Chart: '<S88>/Calibration State' incorporates:
     *  Constant: '<S101>/Constant10'
     *  Constant: '<S102>/Constant'
     *  Constant: '<S103>/Constant'
     *  Constant: '<S104>/Constant'
     *  Constant: '<S106>/Constant1'
     *  Constant: '<S106>/Constant10'
     *  Constant: '<S106>/Constant2'
     *  Constant: '<S107>/Constant'
     *  Constant: '<S107>/Constant1'
     *  Constant: '<S108>/Constant1'
     *  Constant: '<S108>/Constant2'
     *  Constant: '<S109>/Constant10'
     *  Constant: '<S248>/offset'
     *  Constant: '<S248>/sine_table_values'
     *  Constant: '<S264>/offset'
     *  Constant: '<S264>/sine_table_values'
     *  Constant: '<S95>/Constant'
     *  Constant: '<S96>/Constant'
     *  Constant: '<S97>/Constant'
     *  Constant: '<S98>/Constant10'
     *  Constant: '<S99>/Constant2'
     *  Delay: '<S259>/Delay'
     *  Product: '<S249>/Product'
     *  Product: '<S249>/Product1'
     *  Product: '<S265>/Product'
     *  Product: '<S265>/Product1'
     *  RelationalOperator: '<S102>/Compare'
     *  RelationalOperator: '<S103>/Compare'
     *  RelationalOperator: '<S104>/Compare'
     *  RelationalOperator: '<S95>/Compare'
     *  RelationalOperator: '<S96>/Compare'
     *  RelationalOperator: '<S97>/Compare'
     *  Selector: '<S248>/Lookup'
     *  Selector: '<S264>/Lookup'
     *  Sum: '<S248>/Sum'
     *  Sum: '<S249>/Sum3'
     *  Sum: '<S249>/Sum4'
     *  Sum: '<S249>/Sum5'
     *  Sum: '<S249>/Sum6'
     *  Sum: '<S264>/Sum'
     *  Sum: '<S265>/Sum3'
     *  Sum: '<S265>/Sum4'
     *  Sum: '<S265>/Sum5'
     *  Sum: '<S265>/Sum6'
     */
    if (pmsm_smo_DW.temporalCounter_i1 < UINT32_MAX) {
      pmsm_smo_DW.temporalCounter_i1++;
    }

    guard1 = false;
    guard2 = false;
    if (pmsm_smo_DW.is_active_c3_pmsm_smo == 0) {
      pmsm_smo_DW.is_active_c3_pmsm_smo = 1U;
      pmsm_smo_DW.is_c3_pmsm_smo = pmsm_smo_IN_Init;
      pmsm_smo_DW.bitsForTID0.CalibStatus = false;
      guard2 = true;
    } else if (pmsm_smo_DW.is_c3_pmsm_smo == pmsm_smo_IN_Calibration) {
      if (!pmsm_smo_DW.bitsForTID0.NOT) {
        pmsm_smo_DW.is_Calibration_k = pmsm_smo_IN_NO_ACTIVE_CHILD;
        pmsm_smo_DW.is_c3_pmsm_smo = pmsm_smo_IN_Init;
        pmsm_smo_DW.bitsForTID0.CalibStatus = false;
        guard2 = true;
      } else {
        switch (pmsm_smo_DW.is_Calibration_k) {
         case pmsm_smo_IN_Done:
          pmsm_smo_DW.bitsForTID0.CalibStatus = true;
          guard1 = true;
          break;

         case pmsm_smo_IN_Init_Lock:
          if (pmsm_smo_DW.bitsForTID0.UnitDelay1_DSTATE_n) {
            pmsm_smo_DW.temporalCounter_i1 = 0U;
            pmsm_smo_DW.is_Calibration_k = pmsm_smo_IN_ipsOffsetCalib;
            guard1 = true;
          } else {
            guard2 = true;
          }
          break;

         default:
          /* case IN_ipsOffsetCalib: */
          if ((pmsm_smo_DW.temporalCounter_i1 >= 72000U) && pmsm_smo_DW.bitsForTID0.UnitDelay3_DSTATE_k) {
            pmsm_smo_DW.is_Calibration_k = pmsm_smo_IN_Done;
            pmsm_smo_DW.bitsForTID0.CalibStatus = true;
          }

          guard1 = true;
          break;
        }
      }
    } else {
      /* case IN_Init: */
      pmsm_smo_DW.bitsForTID0.CalibStatus = false;
      if (pmsm_smo_DW.bitsForTID0.NOT) {
        pmsm_smo_DW.is_c3_pmsm_smo = pmsm_smo_IN_Calibration;
        pmsm_smo_DW.is_Calibration_k = pmsm_smo_IN_Init_Lock;
      }

      guard2 = true;
    }

    if (guard2) {
      /* Outputs for Enabled SubSystem: '<S88>/Init_Lock' incorporates:
       *  EnablePort: '<S93>/Enable'
       */
      /* Chart: '<S93>/Rotor Locking' incorporates:
       *  DataTypeConversion: '<S522>/Data Type Conversion1'
       */
      if (pmsm_smo_DW.temporalCounter_i1_b < 32767) {
        pmsm_smo_DW.temporalCounter_i1_b++;
      }

      if (pmsm_smo_DW.is_active_c1_pmsm_smo == 0) {
        pmsm_smo_DW.is_active_c1_pmsm_smo = 1U;
        pmsm_smo_DW.is_c1_pmsm_smo = pmsm_smo_IN_Init_g;
        pmsm_smo_DW.Lock = 0U;
        pmsm_smo_DW.bitsForTID0.Init_LockStatus = false;
      } else if (pmsm_smo_DW.is_c1_pmsm_smo == pmsm_smo_IN_Init_g) {
        if (pmsm_smo_DW.bitsForTID0.NOT) {
          pmsm_smo_DW.is_c1_pmsm_smo = pmsm_smo_IN_Lock;
          pmsm_smo_DW.is_Lock = pmsm_smo_IN_Init;
          pmsm_smo_DW.Lock = 0U;
        }

        /* case IN_Lock: */
      } else if (!pmsm_smo_DW.bitsForTID0.NOT) {
        pmsm_smo_DW.is_Lock = pmsm_smo_IN_NO_ACTIVE_CHILD;
        pmsm_smo_DW.is_c1_pmsm_smo = pmsm_smo_IN_Init_g;
        pmsm_smo_DW.Lock = 0U;
        pmsm_smo_DW.bitsForTID0.Init_LockStatus = false;
      } else {
        switch (pmsm_smo_DW.is_Lock) {
         case pmsm_smo_IN_Done:
          pmsm_smo_DW.Lock = 0U;
          pmsm_smo_DW.bitsForTID0.Init_LockStatus = true;
          break;

         case pmsm_smo_IN_Init:
          pmsm_smo_DW.temporalCounter_i1_b = 0U;
          pmsm_smo_DW.is_Lock = pmsm_smo_IN_ipsOffsetCalib;
          pmsm_smo_DW.Lock = 1U;
          break;

         default:
          /* case IN_ipsOffsetCalib: */
          if (pmsm_smo_DW.temporalCounter_i1_b >= 20000) {
            pmsm_smo_DW.is_Lock = pmsm_smo_IN_Done;
          }
          break;
        }
      }

      /* End of Chart: '<S93>/Rotor Locking' */

      /* Outputs for Enabled SubSystem: '<S93>/Init' incorporates:
       *  EnablePort: '<S98>/Enable'
       */
      if (pmsm_smo_DW.Lock == 0) {
        pmsm_smo_DW.Constant10_p[0] = 0.0F;
        pmsm_smo_DW.Constant10_p[1] = 0.0F;
        pmsm_smo_DW.Constant10_p[2] = 0.0F;
      }

      /* End of Outputs for SubSystem: '<S93>/Init' */

      /* Outputs for Enabled SubSystem: '<S93>/Lock' incorporates:
       *  EnablePort: '<S99>/Enable'
       */
      if (pmsm_smo_DW.Lock == 1) {
        pmsm_smo_DW.Constant2_d[0] = 0.3F;
        pmsm_smo_DW.Constant2_d[1] = 0.2F;
        pmsm_smo_DW.Constant2_d[2] = 0.2F;
      }

      /* End of Outputs for SubSystem: '<S93>/Lock' */

      /* Outputs for Enabled SubSystem: '<S93>/Theta_Calib' incorporates:
       *  EnablePort: '<S101>/Enable'
       */
      if (pmsm_smo_DW.Lock == 2) {
        pmsm_smo_DW.Constant10[0] = 0.0F;
        pmsm_smo_DW.Constant10[1] = 0.0F;
        pmsm_smo_DW.Constant10[2] = 0.0F;
      }

      /* End of Outputs for SubSystem: '<S93>/Theta_Calib' */

      /* MultiPortSwitch: '<S93>/Multiport Switch1' incorporates:
       *  Constant: '<S101>/Constant10'
       *  Constant: '<S95>/Constant'
       *  Constant: '<S96>/Constant'
       *  Constant: '<S97>/Constant'
       *  Constant: '<S98>/Constant10'
       *  Constant: '<S99>/Constant2'
       *  RelationalOperator: '<S95>/Compare'
       *  RelationalOperator: '<S96>/Compare'
       *  RelationalOperator: '<S97>/Compare'
       */
      switch (pmsm_smo_DW.Lock) {
       case 0:
        /* MultiPortSwitch: '<S93>/Multiport Switch1' */
        pmsm_smo_DW.Vabc_g[0] = pmsm_smo_DW.Constant10_p[0];
        pmsm_smo_DW.Vabc_g[1] = pmsm_smo_DW.Constant10_p[1];
        pmsm_smo_DW.Vabc_g[2] = pmsm_smo_DW.Constant10_p[2];
        break;

       case 1:
        /* MultiPortSwitch: '<S93>/Multiport Switch1' */
        pmsm_smo_DW.Vabc_g[0] = pmsm_smo_DW.Constant2_d[0];
        pmsm_smo_DW.Vabc_g[1] = pmsm_smo_DW.Constant2_d[1];
        pmsm_smo_DW.Vabc_g[2] = pmsm_smo_DW.Constant2_d[2];
        break;

       default:
        /* MultiPortSwitch: '<S93>/Multiport Switch1' */
        pmsm_smo_DW.Vabc_g[0] = pmsm_smo_DW.Constant10[0];
        pmsm_smo_DW.Vabc_g[1] = pmsm_smo_DW.Constant10[1];
        pmsm_smo_DW.Vabc_g[2] = pmsm_smo_DW.Constant10[2];
        break;
      }

      /* End of MultiPortSwitch: '<S93>/Multiport Switch1' */
      /* End of Outputs for SubSystem: '<S88>/Init_Lock' */

      /* MultiPortSwitch: '<S88>/Multiport Switch' */
      pmsm_smo_DW.Vabc_e[0] = pmsm_smo_DW.Vabc_g[0];
      pmsm_smo_DW.Vabc_e[1] = pmsm_smo_DW.Vabc_g[1];
      pmsm_smo_DW.Vabc_e[2] = pmsm_smo_DW.Vabc_g[2];
    }

    if (guard1) {
      /* Outputs for Enabled SubSystem: '<S88>/Spin motor' incorporates:
       *  EnablePort: '<S94>/Enable'
       */
      /* Chart: '<S94>/Error Checking' incorporates:
       *  DataTypeConversion: '<S522>/Data Type Conversion1'
       *  DataTypeConversion: '<S94>/Data Type Conversion'
       *  DataTypeConversion: '<S94>/Data Type Conversion1'
       *  UnitDelay: '<S94>/Unit Delay1'
       *  UnitDelay: '<S94>/Unit Delay3'
       */
      if (pmsm_smo_DW.is_active_c4_pmsm_smo == 0) {
        pmsm_smo_DW.is_active_c4_pmsm_smo = 1U;
        pmsm_smo_DW.is_c4_pmsm_smo = pmsm_smo_IN_Init;
        pmsm_smo_DW.Openloop_Mode = 1U;
        pmsm_smo_DW.bitsForTID0.ClosedLoop_Status = false;
      } else if (pmsm_smo_DW.is_c4_pmsm_smo == pmsm_smo_IN_Calibration) {
        if (!pmsm_smo_DW.bitsForTID0.NOT) {
          pmsm_smo_DW.is_Calibration = pmsm_smo_IN_NO_ACTIVE_CHILD;
          pmsm_smo_DW.is_c4_pmsm_smo = pmsm_smo_IN_Init;
          pmsm_smo_DW.Openloop_Mode = 1U;
          pmsm_smo_DW.bitsForTID0.ClosedLoop_Status = false;
        } else {
          switch (pmsm_smo_DW.is_Calibration) {
           case pmsm_smo_IN_Done:
            pmsm_smo_DW.Openloop_Mode = 0U;
            pmsm_smo_DW.bitsForTID0.ClosedLoop_Status = true;
            break;

           case pmsm_smo_IN_Start:
            if (pmsm_smo_DW.UnitDelay1_DSTATE != 0.0F) {
              pmsm_smo_DW.is_Calibration = pmsm_smo_IN_ThetaOffsetCalib;
              pmsm_smo_DW.Openloop_Mode = 2U;
            }
            break;

           default:
            /* case IN_ThetaOffsetCalib: */
            if (pmsm_smo_DW.UnitDelay3_DSTATE_p != 0.0F) {
              pmsm_smo_DW.is_Calibration = pmsm_smo_IN_Done;
            }
            break;
          }
        }

        /* case IN_Init: */
      } else if (pmsm_smo_DW.bitsForTID0.NOT) {
        pmsm_smo_DW.is_c4_pmsm_smo = pmsm_smo_IN_Calibration;
        pmsm_smo_DW.is_Calibration = pmsm_smo_IN_Start;
        pmsm_smo_DW.Openloop_Mode = 1U;
      }

      /* End of Chart: '<S94>/Error Checking' */

      /* Outputs for Enabled SubSystem: '<S94>/Init' incorporates:
       *  EnablePort: '<S106>/Enable'
       */
      if (pmsm_smo_DW.Openloop_Mode == 0) {
        pmsm_smo_DW.bitsForTID0.Constant1_g = false;
        pmsm_smo_DW.bitsForTID0.Constant10_n = false;
        pmsm_smo_DW.Constant2_p = 0.0F;
      }

      /* End of Outputs for SubSystem: '<S94>/Init' */

      /* Outputs for Enabled SubSystem: '<S94>/SpeedCheck' incorporates:
       *  EnablePort: '<S108>/Enable'
       */
      if (pmsm_smo_DW.Openloop_Mode == 1) {
        /* RelationalOperator: '<S280>/Compare' incorporates:
         *  Abs: '<S108>/Abs'
         *  Constant: '<S280>/Constant'
         *  Delay: '<S516>/Delay1'
         *  Sum: '<S108>/Subtract'
         */
        pmsm_smo_DW.bitsForTID0.Compare_c = ((float)fabs(pmsm_smo_DW.SpeedRef - pmsm_smo_DW.Delay1_DSTATE) <=
          5.0F);
        pmsm_smo_DW.bitsForTID0.Constant1 = false;
        pmsm_smo_DW.Constant2 = 0.0F;
      }

      /* End of Outputs for SubSystem: '<S94>/SpeedCheck' */

      /* Delay: '<S113>/Delay3' incorporates:
       *  Constant: '<S103>/Constant'
       *  Constant: '<S104>/Constant'
       *  Constant: '<S106>/Constant1'
       *  Constant: '<S106>/Constant10'
       *  Constant: '<S106>/Constant2'
       *  Constant: '<S108>/Constant1'
       *  Constant: '<S108>/Constant2'
       *  Delay: '<S113>/Delay4'
       *  RelationalOperator: '<S103>/Compare'
       *  RelationalOperator: '<S104>/Compare'
       */
      if (pmsm_smo_DW.Delay4_DSTATE[0U] && (pmsm_smo_PrevZCX.Delay3_Reset_ZCE != POS_ZCSIG)) {
        pmsm_smo_DW.Delay3_DSTATE_e = 0.0F;
      }

      pmsm_smo_PrevZCX.Delay3_Reset_ZCE = pmsm_smo_DW.Delay4_DSTATE[0];

      /* Sum: '<S113>/Add3' incorporates:
       *  Constant: '<S113>/Constant5'
       *  Delay: '<S113>/Delay3'
       */
      pmsm_smo_DW.Delay3_DSTATE_e++;

      /* RelationalOperator: '<S257>/Compare' incorporates:
       *  Constant: '<S257>/Constant'
       *  Delay: '<S113>/Delay3'
       */
      rtb_Compare_gy = (pmsm_smo_DW.Delay3_DSTATE_e >= 1000.0F);

      /* Switch: '<S113>/Switch2' incorporates:
       *  Constant: '<S113>/Constant3'
       *  Constant: '<S113>/Constant6'
       */
      if (rtb_Compare_gy) {
        qY = 5;
      } else {
        qY = 0;
      }

      /* Sum: '<S113>/Add1' incorporates:
       *  Delay: '<S113>/Delay2'
       *  Switch: '<S113>/Switch2'
       */
      pmsm_smo_DW.Delay2_DSTATE_j += (float)qY;

      /* Outputs for Enabled SubSystem: '<S258>/Accumulate' incorporates:
       *  EnablePort: '<S259>/Enable'
       */
      /* Outputs for Enabled SubSystem: '<S259>/Subsystem' incorporates:
       *  EnablePort: '<S260>/Enable'
       */
      if (pmsm_smo_DW.bitsForTID0.Delay_DSTATE_i) {
        /* Switch: '<S113>/Switch1' incorporates:
         *  Constant: '<S113>/Constant2'
         *  Delay: '<S113>/Delay2'
         *  RelationalOperator: '<S113>/Relational Operator2'
         */
        if (pmsm_smo_DW.Delay2_DSTATE_j >= 500.0F) {
          uVarXTmp = 500.0F;
        } else {
          uVarXTmp = pmsm_smo_DW.Delay2_DSTATE_j;
        }

        /* SignalConversion generated from: '<S260>/Input' incorporates:
         *  Gain: '<S113>/Gain'
         *  Gain: '<S258>/scaleIn'
         *  Switch: '<S113>/Switch1'
         */
        pmsm_smo_DW.Input = 2.61799396E-5F * uVarXTmp * 0.159154937F;
      }

      /* End of Outputs for SubSystem: '<S259>/Subsystem' */

      /* Sum: '<S259>/Add' incorporates:
       *  Delay: '<S259>/Delay'
       *  UnitDelay: '<S258>/Unit Delay'
       */
      absInXVar = pmsm_smo_DW.Input + pmsm_smo_DW.UnitDelay_DSTATE_o;

      /* DataTypeConversion: '<S259>/Data Type Conversion' */
      uVarXTmp = (float)floor(absInXVar);
      if (rtIsNaNF(uVarXTmp) || rtIsInfF(uVarXTmp)) {
        rtb_Sum1_a = 0.0F;
        uVarXTmp = 0.0F;
      } else {
        rtb_Sum1_a = (float)fmod(uVarXTmp, 65536.0);
        uVarXTmp = rtb_Sum1_a;
      }

      /* Gain: '<S117>/Kbeta' incorporates:
       *  DataTypeConversion: '<S259>/Data Type Conversion'
       *  DataTypeConversion: '<S259>/Data Type Conversion1'
       */
      pmsm_smo_DW.Kbeta_l = (float)(rtb_Sum1_a < 0.0F ? (int32_t)(int16_t)-(int16_t)(uint16_t)-rtb_Sum1_a :
        (int32_t)(int16_t)(uint16_t)rtb_Sum1_a);

      /* Sum: '<S259>/Add1' incorporates:
       *  DataTypeConversion: '<S259>/Data Type Conversion'
       *  DataTypeConversion: '<S259>/Data Type Conversion1'
       *  UnitDelay: '<S258>/Unit Delay'
       */
      pmsm_smo_DW.UnitDelay_DSTATE_o = absInXVar - (float)(uVarXTmp < 0.0F ? (int32_t)(int16_t)-(int16_t)
        (uint16_t)-uVarXTmp : (int32_t)(int16_t)(uint16_t)uVarXTmp);

      /* Update for Delay: '<S259>/Delay' incorporates:
       *  Constant: '<S259>/Constant'
       */
      pmsm_smo_DW.bitsForTID0.Delay_DSTATE_i = true;

      /* End of Outputs for SubSystem: '<S258>/Accumulate' */

      /* Sum: '<S113>/Subtract' incorporates:
       *  Constant: '<S113>/Constant1'
       *  Gain: '<S258>/scaleOut'
       *  UnitDelay: '<S258>/Unit Delay'
       */
      pmsm_smo_DW.Theta_in = 6.28318548F * pmsm_smo_DW.UnitDelay_DSTATE_o - 3.14159274F;

      /* Outputs for Enabled SubSystem: '<S94>/Theta_check' incorporates:
       *  EnablePort: '<S109>/Enable'
       */
      if (pmsm_smo_DW.Openloop_Mode == 2) {
        /* Bias: '<S282>/Bias1' incorporates:
         *  Bias: '<S282>/Bias'
         *  Constant: '<S282>/load torque1'
         *  Math: '<S282>/Math Function'
         *  Math: '<S282>/Math Function1'
         *  Sum: '<S109>/Subtract1'
         */
        pmsm_smo_DW.Bias1_d = rt_modf_snf(rt_modf_snf(pmsm_smo_DW.Bias1 - pmsm_smo_DW.Theta_in, 6.28318548F) +
          3.14159274F, 6.28318548F) - 3.14159274F;

        /* Abs: '<S109>/Abs1' */
        absInXVar = (float)fabs(pmsm_smo_DW.Bias1_d);

        /* RelationalOperator: '<S281>/Compare' incorporates:
         *  Constant: '<S281>/Constant'
         */
        pmsm_smo_DW.bitsForTID0.Compare = (absInXVar <= 0.1F);
        pmsm_smo_DW.bitsForTID0.Constant10_a = true;
      }

      /* End of Outputs for SubSystem: '<S94>/Theta_check' */

      /* MultiPortSwitch: '<S94>/Multiport Switch1' incorporates:
       *  Constant: '<S102>/Constant'
       *  Constant: '<S109>/Constant10'
       *  RelationalOperator: '<S102>/Compare'
       *  UnitDelay: '<S94>/Unit Delay1'
       */
      switch (pmsm_smo_DW.Openloop_Mode) {
       case 0:
        pmsm_smo_DW.UnitDelay1_DSTATE = pmsm_smo_DW.bitsForTID0.Constant10_n;

        /* MultiPortSwitch: '<S94>/Multiport Switch2' incorporates:
         *  UnitDelay: '<S94>/Unit Delay1'
         *  UnitDelay: '<S94>/Unit Delay3'
         */
        pmsm_smo_DW.UnitDelay3_DSTATE_p = pmsm_smo_DW.bitsForTID0.Constant1_g;

        /* RateTransition generated from: '<S79>/Rate Transition14' incorporates:
         *  MultiPortSwitch: '<S94>/Multiport Switch3'
         */
        pmsm_smo_DW.UnitDelay_1_DSTATE = pmsm_smo_DW.Constant2_p;
        break;

       case 1:
        pmsm_smo_DW.UnitDelay1_DSTATE = pmsm_smo_DW.bitsForTID0.Compare_c;

        /* MultiPortSwitch: '<S94>/Multiport Switch2' incorporates:
         *  UnitDelay: '<S94>/Unit Delay1'
         *  UnitDelay: '<S94>/Unit Delay3'
         */
        pmsm_smo_DW.UnitDelay3_DSTATE_p = pmsm_smo_DW.bitsForTID0.Constant1;

        /* RateTransition generated from: '<S79>/Rate Transition14' incorporates:
         *  MultiPortSwitch: '<S94>/Multiport Switch3'
         */
        pmsm_smo_DW.UnitDelay_1_DSTATE = pmsm_smo_DW.Constant2;
        break;

       default:
        pmsm_smo_DW.UnitDelay1_DSTATE = pmsm_smo_DW.bitsForTID0.Constant10_a;

        /* MultiPortSwitch: '<S94>/Multiport Switch2' incorporates:
         *  UnitDelay: '<S94>/Unit Delay1'
         *  UnitDelay: '<S94>/Unit Delay3'
         */
        pmsm_smo_DW.UnitDelay3_DSTATE_p = pmsm_smo_DW.bitsForTID0.Compare;

        /* RateTransition generated from: '<S79>/Rate Transition14' incorporates:
         *  MultiPortSwitch: '<S94>/Multiport Switch3'
         */
        pmsm_smo_DW.UnitDelay_1_DSTATE = pmsm_smo_DW.Bias1_d;
        break;
      }

      /* End of MultiPortSwitch: '<S94>/Multiport Switch1' */

      /* Outputs for Atomic SubSystem: '<S117>/Two phase CRL wrap' */
      /* Gain: '<S117>/Kbeta' */
      pmsm_smo_TwophaseCRLwrap(rtb_I_ab[0], rtb_I_ab[1], &absInXVar, &pmsm_smo_DW.Kbeta_l);

      /* End of Outputs for SubSystem: '<S117>/Two phase CRL wrap' */

      /* Gain: '<S117>/Kalpha' */
      pmsm_smo_DW.Kalpha_j = absInXVar;

      /* Gain: '<S266>/convert_pu' incorporates:
       *  Gain: '<S250>/convert_pu'
       */
      rtb_Sum1_d_tmp = 0.159154937F * pmsm_smo_DW.Theta_in;
      rtb_Sum1_a = rtb_Sum1_d_tmp;

      /* RelationalOperator: '<S268>/Compare' incorporates:
       *  Constant: '<S268>/Constant'
       *  Gain: '<S266>/convert_pu'
       */
      rtb_Compare_h = (rtb_Sum1_d_tmp < 0.0F);

      /* If: '<S266>/If' incorporates:
       *  DataTypeConversion: '<S266>/Data Type Conversion'
       *  Gain: '<S266>/convert_pu'
       */
      if (rtb_Compare_h) {
        /* Outputs for IfAction SubSystem: '<S266>/If Action Subsystem' incorporates:
         *  ActionPort: '<S269>/Action Port'
         */
        pmsm_smo_IfActionSubsystem(rtb_Sum1_d_tmp, &rtb_Add2_a);

        /* End of Outputs for SubSystem: '<S266>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S266>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S270>/Action Port'
         */
        pmsm_smo_IfActionSubsystem1(rtb_Sum1_d_tmp, &rtb_Add2_a);

        /* End of Outputs for SubSystem: '<S266>/If Action Subsystem1' */
      }

      /* End of If: '<S266>/If' */

      /* Gain: '<S264>/indexing' */
      rtb_Add2_a *= 800.0F;

      /* DataTypeConversion: '<S264>/Get_Integer' */
      if (rtb_Add2_a < 0.0F) {
        uVarXTmp = (float)ceil(rtb_Add2_a);
      } else {
        uVarXTmp = (float)floor(rtb_Add2_a);
      }

      if (rtIsNaNF(uVarXTmp) || rtIsInfF(uVarXTmp)) {
        uVarXTmp = 0.0F;
      } else {
        uVarXTmp = (float)fmod(uVarXTmp, 65536.0);
      }

      rtb_FixPtSum1 = (uint16_t)(uVarXTmp < 0.0F ? (int32_t)(uint16_t)-(int16_t)(uint16_t)-uVarXTmp : (int32_t)
        (uint16_t)uVarXTmp);

      /* End of DataTypeConversion: '<S264>/Get_Integer' */

      /* Sum: '<S264>/Sum2' incorporates:
       *  DataTypeConversion: '<S264>/Data Type Conversion1'
       */
      uVarXTmp = rtb_Add2_a - (float)rtb_FixPtSum1;

      /* Outputs for Atomic SubSystem: '<S114>/Two inputs CRL' */
      pmsm_smo_TwoinputsCRL_e(pmsm_smo_DW.Kalpha_j, pmsm_smo_DW.Kbeta_l, (pmsm_smo_ConstP.pooled25[(int32_t)
        (rtb_FixPtSum1 + 1U)] - pmsm_smo_ConstP.pooled25[rtb_FixPtSum1]) * uVarXTmp +
        pmsm_smo_ConstP.pooled25[rtb_FixPtSum1], (pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 201U)] -
        pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 200U)]) * uVarXTmp + pmsm_smo_ConstP.pooled25
        [(int32_t)(rtb_FixPtSum1 + 200U)], &rtb_Sum1_a, &rtb_algDD_o2);

      /* End of Outputs for SubSystem: '<S114>/Two inputs CRL' */

      /* Logic: '<S121>/Logical Operator' incorporates:
       *  Constant: '<S264>/offset'
       *  Constant: '<S264>/sine_table_values'
       *  DataTypeConversion: '<S522>/Data Type Conversion1'
       *  Product: '<S265>/Product'
       *  Product: '<S265>/Product1'
       *  Selector: '<S264>/Lookup'
       *  Sum: '<S264>/Sum'
       *  Sum: '<S265>/Sum3'
       *  Sum: '<S265>/Sum4'
       *  Sum: '<S265>/Sum5'
       *  Sum: '<S265>/Sum6'
       */
      rtb_LogicalOperator_lb = !pmsm_smo_DW.bitsForTID0.NOT;

      /* DiscreteIntegrator: '<S228>/Integrator' incorporates:
       *  Constant: '<S121>/Kp1'
       */
      if (rtb_LogicalOperator_lb || (pmsm_smo_DW.Integrator_PrevResetState_n != 0)) {
        pmsm_smo_DW.Integrator_DSTATE_d = 0.0F;
      }

      /* Sum: '<S237>/Sum' incorporates:
       *  Constant: '<S107>/Constant7'
       *  Constant: '<S121>/Kp'
       *  DiscreteIntegrator: '<S228>/Integrator'
       *  Product: '<S233>/PProd Out'
       *  Sum: '<S121>/Sum'
       */
      uVarXTmp = (1.0F - rtb_algDD_o2) * 0.852F + pmsm_smo_DW.Integrator_DSTATE_d;

      /* Saturate: '<S235>/Saturation' */
      if (uVarXTmp > 13.8564062F) {
        rtb_Add2_a = 13.8564062F;
      } else if (uVarXTmp < -13.8564062F) {
        rtb_Add2_a = -13.8564062F;
      } else {
        rtb_Add2_a = uVarXTmp;
      }

      /* End of Saturate: '<S235>/Saturation' */

      /* Logic: '<S120>/Logical Operator' incorporates:
       *  DataTypeConversion: '<S522>/Data Type Conversion1'
       */
      rtb_LogicalOperator_b = !pmsm_smo_DW.bitsForTID0.NOT;

      /* DiscreteIntegrator: '<S173>/Integrator' incorporates:
       *  Constant: '<S120>/Ki1'
       */
      if (rtb_LogicalOperator_b || (pmsm_smo_DW.Integrator_PrevResetState_k != 0)) {
        pmsm_smo_DW.Integrator_DSTATE_n = 0.0F;
      }

      /* Sum: '<S182>/Sum' incorporates:
       *  Constant: '<S107>/Constant2'
       *  Constant: '<S120>/Kp'
       *  DiscreteIntegrator: '<S173>/Integrator'
       *  Product: '<S178>/PProd Out'
       *  Sum: '<S120>/Sum'
       */
      absInXVar = (0.0F - rtb_Sum1_a) * 0.852F + pmsm_smo_DW.Integrator_DSTATE_n;

      /* Saturate: '<S180>/Saturation' */
      if (absInXVar > 13.8564062F) {
        rtb_Saturation_e = 13.8564062F;
      } else if (absInXVar < -13.8564062F) {
        rtb_Saturation_e = -13.8564062F;
      } else {
        rtb_Saturation_e = absInXVar;
      }

      /* End of Saturate: '<S180>/Saturation' */

      /* Outputs for IfAction SubSystem: '<S119>/D-Q Equivalence' incorporates:
       *  ActionPort: '<S122>/Action Port'
       */
      /* If: '<S119>/If' incorporates:
       *  Constant: '<S124>/Constant3'
       *  Product: '<S124>/Product'
       *  Product: '<S125>/Product'
       *  Product: '<S125>/Product1'
       *  Sum: '<S125>/Sum1'
       *  Switch: '<S124>/Switch'
       */
      pmsm_smo_DQEquivalence(rtb_Saturation_e, rtb_Add2_a, rtb_Saturation_e * rtb_Saturation_e + rtb_Add2_a *
        rtb_Add2_a, 13.8564062F, 192.0F, rtb_Merge_m);

      /* End of Outputs for SubSystem: '<S119>/D-Q Equivalence' */

      /* DeadZone: '<S165>/DeadZone' */
      if (absInXVar > 13.8564062F) {
        absInXVar -= 13.8564062F;
      } else if (absInXVar >= -13.8564062F) {
        absInXVar = 0.0F;
      } else {
        absInXVar -= -13.8564062F;
      }

      /* End of DeadZone: '<S165>/DeadZone' */

      /* Product: '<S170>/IProd Out' incorporates:
       *  Constant: '<S107>/Constant2'
       *  Constant: '<S120>/Ki'
       *  Sum: '<S120>/Sum'
       */
      rtb_Sum1_a = (0.0F - rtb_Sum1_a) * 0.033F;

      /* Switch: '<S163>/Switch1' incorporates:
       *  Constant: '<S163>/Clamping_zero'
       *  Constant: '<S163>/Constant'
       *  Constant: '<S163>/Constant2'
       *  RelationalOperator: '<S163>/fix for DT propagation issue'
       */
      if (absInXVar > 0.0F) {
        tmp_0 = 1;
      } else {
        tmp_0 = -1;
      }

      /* Switch: '<S163>/Switch2' incorporates:
       *  Constant: '<S163>/Clamping_zero'
       *  Constant: '<S163>/Constant3'
       *  Constant: '<S163>/Constant4'
       *  RelationalOperator: '<S163>/fix for DT propagation issue1'
       */
      if (rtb_Sum1_a > 0.0F) {
        tmp_1 = 1;
      } else {
        tmp_1 = -1;
      }

      /* Switch: '<S163>/Switch' incorporates:
       *  Constant: '<S163>/Clamping_zero'
       *  Constant: '<S163>/Constant1'
       *  Logic: '<S163>/AND3'
       *  RelationalOperator: '<S163>/Equal1'
       *  RelationalOperator: '<S163>/Relational Operator'
       *  Switch: '<S163>/Switch1'
       *  Switch: '<S163>/Switch2'
       */
      if ((absInXVar != 0.0F) && (tmp_0 == tmp_1)) {
        rtb_Sum1_a = 0.0F;
      }

      /* End of Switch: '<S163>/Switch' */

      /* DeadZone: '<S220>/DeadZone' */
      if (uVarXTmp > 13.8564062F) {
        uVarXTmp -= 13.8564062F;
      } else if (uVarXTmp >= -13.8564062F) {
        uVarXTmp = 0.0F;
      } else {
        uVarXTmp -= -13.8564062F;
      }

      /* End of DeadZone: '<S220>/DeadZone' */

      /* Product: '<S225>/IProd Out' incorporates:
       *  Constant: '<S107>/Constant7'
       *  Constant: '<S121>/Ki'
       *  Sum: '<S121>/Sum'
       */
      rtb_Add2_a = (1.0F - rtb_algDD_o2) * 0.033F;

      /* Switch: '<S218>/Switch1' incorporates:
       *  Constant: '<S218>/Clamping_zero'
       *  Constant: '<S218>/Constant'
       *  Constant: '<S218>/Constant2'
       *  RelationalOperator: '<S218>/fix for DT propagation issue'
       */
      if (uVarXTmp > 0.0F) {
        tmp_0 = 1;
      } else {
        tmp_0 = -1;
      }

      /* Switch: '<S218>/Switch2' incorporates:
       *  Constant: '<S218>/Clamping_zero'
       *  Constant: '<S218>/Constant3'
       *  Constant: '<S218>/Constant4'
       *  RelationalOperator: '<S218>/fix for DT propagation issue1'
       */
      if (rtb_Add2_a > 0.0F) {
        tmp_1 = 1;
      } else {
        tmp_1 = -1;
      }

      /* Switch: '<S218>/Switch' incorporates:
       *  Constant: '<S218>/Clamping_zero'
       *  Constant: '<S218>/Constant1'
       *  Logic: '<S218>/AND3'
       *  RelationalOperator: '<S218>/Equal1'
       *  RelationalOperator: '<S218>/Relational Operator'
       *  Switch: '<S218>/Switch1'
       *  Switch: '<S218>/Switch2'
       */
      if ((uVarXTmp != 0.0F) && (tmp_0 == tmp_1)) {
        rtb_algDD_o2 = 0.0F;
      } else {
        rtb_algDD_o2 = rtb_Add2_a;
      }

      /* End of Switch: '<S218>/Switch' */

      /* RelationalOperator: '<S252>/Compare' incorporates:
       *  Constant: '<S252>/Constant'
       */
      rtb_Compare_h = (rtb_Sum1_d_tmp < 0.0F);

      /* If: '<S250>/If' incorporates:
       *  DataTypeConversion: '<S250>/Data Type Conversion'
       */
      if (rtb_Compare_h) {
        /* Outputs for IfAction SubSystem: '<S250>/If Action Subsystem' incorporates:
         *  ActionPort: '<S253>/Action Port'
         */
        pmsm_smo_IfActionSubsystem(rtb_Sum1_d_tmp, &absInXVar);

        /* End of Outputs for SubSystem: '<S250>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S250>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S254>/Action Port'
         */
        pmsm_smo_IfActionSubsystem1(rtb_Sum1_d_tmp, &absInXVar);

        /* End of Outputs for SubSystem: '<S250>/If Action Subsystem1' */
      }

      /* End of If: '<S250>/If' */

      /* Gain: '<S248>/indexing' */
      absInXVar *= 800.0F;

      /* DataTypeConversion: '<S248>/Get_Integer' */
      if (absInXVar < 0.0F) {
        uVarXTmp = (float)ceil(absInXVar);
      } else {
        uVarXTmp = (float)floor(absInXVar);
      }

      if (rtIsNaNF(uVarXTmp) || rtIsInfF(uVarXTmp)) {
        uVarXTmp = 0.0F;
      } else {
        uVarXTmp = (float)fmod(uVarXTmp, 65536.0);
      }

      rtb_FixPtSum1 = (uint16_t)(uVarXTmp < 0.0F ? (int32_t)(uint16_t)-(int16_t)(uint16_t)-uVarXTmp : (int32_t)
        (uint16_t)uVarXTmp);

      /* End of DataTypeConversion: '<S248>/Get_Integer' */

      /* Sum: '<S248>/Sum2' incorporates:
       *  DataTypeConversion: '<S248>/Data Type Conversion1'
       */
      rtb_Add2_a = absInXVar - (float)rtb_FixPtSum1;

      /* Outputs for Atomic SubSystem: '<S112>/Two inputs CRL' */
      pmsm_smo_TwoinputsCRL(-0.7F, 2.69F, (pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 1U)] -
        pmsm_smo_ConstP.pooled25[rtb_FixPtSum1]) * rtb_Add2_a + pmsm_smo_ConstP.pooled25[rtb_FixPtSum1],
                            (pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 201U)] -
        pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 200U)]) * rtb_Add2_a + pmsm_smo_ConstP.pooled25
                            [(int32_t)(rtb_FixPtSum1 + 200U)], &pmsm_smo_DW.algDD_o1_p,
                            &pmsm_smo_DW.algDD_o2_h);

      /* End of Outputs for SubSystem: '<S112>/Two inputs CRL' */

      /* Gain: '<S279>/one_by_two' incorporates:
       *  Constant: '<S107>/Constant'
       *  Constant: '<S107>/Constant1'
       *  Constant: '<S248>/offset'
       *  Constant: '<S248>/sine_table_values'
       *  Product: '<S249>/Product'
       *  Product: '<S249>/Product1'
       *  Selector: '<S248>/Lookup'
       *  Sum: '<S248>/Sum'
       *  Sum: '<S249>/Sum3'
       *  Sum: '<S249>/Sum4'
       *  Sum: '<S249>/Sum5'
       *  Sum: '<S249>/Sum6'
       */
      absInXVar = 0.5F * pmsm_smo_DW.algDD_o1_p;

      /* Gain: '<S279>/sqrt3_by_two' */
      rtb_Add2_a = 0.866025388F * pmsm_smo_DW.algDD_o2_h;

      /* Sum: '<S279>/add_b' */
      uVarXTmp = rtb_Add2_a - absInXVar;

      /* Sum: '<S279>/add_c' */
      absInXVar = (0.0F - absInXVar) - rtb_Add2_a;

      /* MinMax: '<S276>/Max' incorporates:
       *  MinMax: '<S276>/Min'
       */
      isReciprocal = rtIsNaNF(uVarXTmp);
      if ((pmsm_smo_DW.algDD_o1_p >= uVarXTmp) || isReciprocal) {
        rtb_Saturation_e = pmsm_smo_DW.algDD_o1_p;
      } else {
        rtb_Saturation_e = uVarXTmp;
      }

      /* MinMax: '<S276>/Min' */
      if ((pmsm_smo_DW.algDD_o1_p <= uVarXTmp) || isReciprocal) {
        rtb_Sum1_d_tmp = pmsm_smo_DW.algDD_o1_p;
      } else {
        rtb_Sum1_d_tmp = uVarXTmp;
      }

      /* MinMax: '<S276>/Max' incorporates:
       *  MinMax: '<S276>/Min'
       */
      rtb_Compare_h = !rtIsNaNF(absInXVar);
      if ((!(rtb_Saturation_e >= absInXVar)) && rtb_Compare_h) {
        rtb_Saturation_e = absInXVar;
      }

      /* MinMax: '<S276>/Min' */
      if ((!(rtb_Sum1_d_tmp <= absInXVar)) && rtb_Compare_h) {
        rtb_Sum1_d_tmp = absInXVar;
      }

      /* Gain: '<S276>/one_by_two' incorporates:
       *  MinMax: '<S276>/Max'
       *  MinMax: '<S276>/Min'
       *  Sum: '<S276>/Add'
       */
      rtb_Add2_a = (rtb_Saturation_e + rtb_Sum1_d_tmp) * -0.5F;

      /* Sum: '<S107>/Sum' incorporates:
       *  Constant: '<S107>/Constant4'
       *  Gain: '<S107>/One_by_Two'
       *  Gain: '<S275>/Gain'
       *  Sum: '<S275>/Add1'
       *  Sum: '<S275>/Add2'
       *  Sum: '<S275>/Add3'
       */
      pmsm_smo_DW.Sum_a[0] = (pmsm_smo_DW.algDD_o1_p + rtb_Add2_a) * 1.15470052F * 0.0360843912F + 0.5F;
      pmsm_smo_DW.Sum_a[1] = (uVarXTmp + rtb_Add2_a) * 1.15470052F * 0.0360843912F + 0.5F;
      pmsm_smo_DW.Sum_a[2] = (rtb_Add2_a + absInXVar) * 1.15470052F * 0.0360843912F + 0.5F;

      /* Update for Delay: '<S113>/Delay4' */
      pmsm_smo_DW.Delay4_DSTATE[0] = pmsm_smo_DW.Delay4_DSTATE[1];
      pmsm_smo_DW.Delay4_DSTATE[1] = rtb_Compare_gy;

      /* Update for DiscreteIntegrator: '<S228>/Integrator' */
      pmsm_smo_DW.Integrator_DSTATE_d += rtb_algDD_o2;
      pmsm_smo_DW.Integrator_PrevResetState_n = (int8_t)rtb_LogicalOperator_lb;

      /* Update for DiscreteIntegrator: '<S173>/Integrator' */
      pmsm_smo_DW.Integrator_DSTATE_n += rtb_Sum1_a;
      pmsm_smo_DW.Integrator_PrevResetState_k = (int8_t)rtb_LogicalOperator_b;

      /* End of Outputs for SubSystem: '<S88>/Spin motor' */

      /* MultiPortSwitch: '<S88>/Multiport Switch' */
      pmsm_smo_DW.Vabc_e[0] = pmsm_smo_DW.Sum_a[0];
      pmsm_smo_DW.Vabc_e[1] = pmsm_smo_DW.Sum_a[1];
      pmsm_smo_DW.Vabc_e[2] = pmsm_smo_DW.Sum_a[2];
    }

    /* End of Chart: '<S88>/Calibration State' */

    /* Update for UnitDelay: '<S88>/Unit Delay1' */
    pmsm_smo_DW.bitsForTID0.UnitDelay1_DSTATE_n = pmsm_smo_DW.bitsForTID0.Init_LockStatus;

    /* Update for UnitDelay: '<S88>/Unit Delay3' */
    pmsm_smo_DW.bitsForTID0.UnitDelay3_DSTATE_k = pmsm_smo_DW.bitsForTID0.ClosedLoop_Status;
  } else {
    pmsm_smo_DW.bitsForTID0.Prepare_MODE = false;
  }

  /* End of RelationalOperator: '<S83>/Compare' */
  /* End of Outputs for SubSystem: '<S81>/Prepare' */

  /* Outputs for Enabled SubSystem: '<S81>/Run' incorporates:
   *  EnablePort: '<S89>/Enable'
   */
  /* RelationalOperator: '<S84>/Compare' incorporates:
   *  Constant: '<S482>/offset'
   *  Constant: '<S482>/sine_table_values'
   *  Constant: '<S494>/offset'
   *  Constant: '<S494>/sine_table_values'
   *  Constant: '<S84>/Constant'
   *  DataTypeConversion: '<S76>/Data Type Conversion3'
   *  Product: '<S483>/Product'
   *  Product: '<S483>/Product1'
   *  Product: '<S495>/Product'
   *  Product: '<S495>/Product1'
   *  Selector: '<S482>/Lookup'
   *  Selector: '<S494>/Lookup'
   *  Sum: '<S482>/Sum'
   *  Sum: '<S483>/Sum3'
   *  Sum: '<S483>/Sum4'
   *  Sum: '<S483>/Sum5'
   *  Sum: '<S483>/Sum6'
   *  Sum: '<S494>/Sum'
   *  Sum: '<S495>/Sum3'
   *  Sum: '<S495>/Sum4'
   *  Sum: '<S495>/Sum5'
   *  Sum: '<S495>/Sum6'
   */
  if (rtb_Mode == Run) {
    if (!pmsm_smo_DW.Run_MODE) {
      pmsm_smo_DW.Run_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S351>/Two phase CRL wrap' */
    /* Gain: '<S351>/Kbeta' incorporates:
     *  Gain: '<S351>/Kalpha'
     */
    pmsm_smo_TwophaseCRLwrap(rtb_I_ab[0], rtb_I_ab[1], &pmsm_smo_DW.Kalpha, &pmsm_smo_DW.Kbeta);

    /* End of Outputs for SubSystem: '<S351>/Two phase CRL wrap' */

    /* RateTransition: '<S89>/Rate Transition3' incorporates:
     *  RateTransition: '<S89>/Rate Transition'
     */
    isReciprocal = (pmsm_smo_M->Timing.RateInteraction.TID0_3 == 1);
    if (isReciprocal) {
      /* RateTransition: '<S89>/Rate Transition3' */
      pmsm_smo_DW.IdqRef[0] = pmsm_smo_DW.RateTransition3_Buffer0[0];
      pmsm_smo_DW.IdqRef[1] = pmsm_smo_DW.RateTransition3_Buffer0[1];
    }

    /* End of RateTransition: '<S89>/Rate Transition3' */

    /* Gain: '<S496>/convert_pu' incorporates:
     *  Gain: '<S484>/convert_pu'
     */
    rtb_Sum1_d_tmp = 0.159154937F * pmsm_smo_DW.Bias1;

    /* RelationalOperator: '<S498>/Compare' incorporates:
     *  Constant: '<S498>/Constant'
     *  Gain: '<S496>/convert_pu'
     */
    rtb_Compare_h = (rtb_Sum1_d_tmp < 0.0F);

    /* If: '<S496>/If' incorporates:
     *  DataTypeConversion: '<S496>/Data Type Conversion'
     *  Gain: '<S496>/convert_pu'
     */
    if (rtb_Compare_h) {
      /* Outputs for IfAction SubSystem: '<S496>/If Action Subsystem' incorporates:
       *  ActionPort: '<S499>/Action Port'
       */
      pmsm_smo_IfActionSubsystem(rtb_Sum1_d_tmp, &rtb_algDD_o2);

      /* End of Outputs for SubSystem: '<S496>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S496>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S500>/Action Port'
       */
      pmsm_smo_IfActionSubsystem1(rtb_Sum1_d_tmp, &rtb_algDD_o2);

      /* End of Outputs for SubSystem: '<S496>/If Action Subsystem1' */
    }

    /* End of If: '<S496>/If' */

    /* Gain: '<S494>/indexing' */
    rtb_algDD_o2 *= 800.0F;

    /* DataTypeConversion: '<S494>/Get_Integer' */
    if (rtb_algDD_o2 < 0.0F) {
      uVarXTmp = (float)ceil(rtb_algDD_o2);
    } else {
      uVarXTmp = (float)floor(rtb_algDD_o2);
    }

    if (rtIsNaNF(uVarXTmp) || rtIsInfF(uVarXTmp)) {
      uVarXTmp = 0.0F;
    } else {
      uVarXTmp = (float)fmod(uVarXTmp, 65536.0);
    }

    rtb_FixPtSum1 = (uint16_t)(uVarXTmp < 0.0F ? (int32_t)(uint16_t)-(int16_t)(uint16_t)-uVarXTmp : (int32_t)
      (uint16_t)uVarXTmp);

    /* End of DataTypeConversion: '<S494>/Get_Integer' */

    /* Sum: '<S494>/Sum2' incorporates:
     *  DataTypeConversion: '<S494>/Data Type Conversion1'
     */
    uVarXTmp = rtb_algDD_o2 - (float)rtb_FixPtSum1;

    /* Outputs for Atomic SubSystem: '<S349>/Two inputs CRL' */
    pmsm_smo_TwoinputsCRL_e(pmsm_smo_DW.Kalpha, pmsm_smo_DW.Kbeta, (pmsm_smo_ConstP.pooled25[(int32_t)
      (rtb_FixPtSum1 + 1U)] - pmsm_smo_ConstP.pooled25[rtb_FixPtSum1]) * uVarXTmp +
      pmsm_smo_ConstP.pooled25[rtb_FixPtSum1], (pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 201U)] -
      pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 200U)]) * uVarXTmp + pmsm_smo_ConstP.pooled25
      [(int32_t)(rtb_FixPtSum1 + 200U)], &pmsm_smo_DW.algDD_o1, &pmsm_smo_DW.algDD_o2);

    /* End of Outputs for SubSystem: '<S349>/Two inputs CRL' */

    /* Sum: '<S355>/Sum' incorporates:
     *  Constant: '<S494>/offset'
     *  Constant: '<S494>/sine_table_values'
     *  Product: '<S495>/Product'
     *  Product: '<S495>/Product1'
     *  Selector: '<S494>/Lookup'
     *  Sum: '<S494>/Sum'
     *  Sum: '<S495>/Sum3'
     *  Sum: '<S495>/Sum4'
     *  Sum: '<S495>/Sum5'
     *  Sum: '<S495>/Sum6'
     */
    rtb_algDD_o2 = pmsm_smo_DW.IdqRef[1] - pmsm_smo_DW.algDD_o2;

    /* Logic: '<S355>/Logical Operator' incorporates:
     *  DataTypeConversion: '<S522>/Data Type Conversion1'
     *  Logic: '<S354>/Logical Operator'
     */
    rtb_Compare_gy = !pmsm_smo_DW.bitsForTID0.NOT;

    /* DiscreteIntegrator: '<S462>/Integrator' incorporates:
     *  Constant: '<S355>/Kp1'
     *  Logic: '<S355>/Logical Operator'
     */
    if (rtb_Compare_gy || (pmsm_smo_DW.Integrator_PrevResetState != 0)) {
      pmsm_smo_DW.Integrator_DSTATE = 0.0F;
    }

    /* Sum: '<S471>/Sum' incorporates:
     *  Constant: '<S355>/Kp'
     *  DiscreteIntegrator: '<S462>/Integrator'
     *  Product: '<S467>/PProd Out'
     */
    uVarXTmp = rtb_algDD_o2 * 0.852F + pmsm_smo_DW.Integrator_DSTATE;

    /* Saturate: '<S469>/Saturation' */
    if (uVarXTmp > 13.8564062F) {
      rtb_Add2_a = 13.8564062F;
    } else if (uVarXTmp < -13.8564062F) {
      rtb_Add2_a = -13.8564062F;
    } else {
      rtb_Add2_a = uVarXTmp;
    }

    /* End of Saturate: '<S469>/Saturation' */

    /* Sum: '<S354>/Sum' */
    rtb_Sum1_a = pmsm_smo_DW.IdqRef[0] - pmsm_smo_DW.algDD_o1;

    /* DiscreteIntegrator: '<S407>/Integrator' incorporates:
     *  Constant: '<S354>/Ki1'
     */
    if (rtb_Compare_gy || (pmsm_smo_DW.Integrator_PrevResetState_h != 0)) {
      pmsm_smo_DW.Integrator_DSTATE_e = 0.0F;
    }

    /* Sum: '<S416>/Sum' incorporates:
     *  Constant: '<S354>/Kp'
     *  DiscreteIntegrator: '<S407>/Integrator'
     *  Product: '<S412>/PProd Out'
     */
    absInXVar = rtb_Sum1_a * 0.852F + pmsm_smo_DW.Integrator_DSTATE_e;

    /* Saturate: '<S414>/Saturation' */
    if (absInXVar > 13.8564062F) {
      rtb_Saturation_e = 13.8564062F;
    } else if (absInXVar < -13.8564062F) {
      rtb_Saturation_e = -13.8564062F;
    } else {
      rtb_Saturation_e = absInXVar;
    }

    /* End of Saturate: '<S414>/Saturation' */

    /* Outputs for IfAction SubSystem: '<S353>/D-Q Equivalence' incorporates:
     *  ActionPort: '<S356>/Action Port'
     */
    /* If: '<S353>/If' incorporates:
     *  Constant: '<S358>/Constant3'
     *  Product: '<S358>/Product'
     *  Product: '<S359>/Product'
     *  Product: '<S359>/Product1'
     *  Sum: '<S359>/Sum1'
     *  Switch: '<S358>/Switch'
     */
    pmsm_smo_DQEquivalence(rtb_Saturation_e, rtb_Add2_a, rtb_Saturation_e * rtb_Saturation_e + rtb_Add2_a *
      rtb_Add2_a, 13.8564062F, 192.0F, rtb_Merge_m);

    /* End of Outputs for SubSystem: '<S353>/D-Q Equivalence' */

    /* DeadZone: '<S399>/DeadZone' */
    if (absInXVar > 13.8564062F) {
      absInXVar -= 13.8564062F;
    } else if (absInXVar >= -13.8564062F) {
      absInXVar = 0.0F;
    } else {
      absInXVar -= -13.8564062F;
    }

    /* End of DeadZone: '<S399>/DeadZone' */

    /* Product: '<S404>/IProd Out' incorporates:
     *  Constant: '<S354>/Ki'
     */
    rtb_Sum1_a *= 0.033F;

    /* Switch: '<S397>/Switch1' incorporates:
     *  Constant: '<S397>/Clamping_zero'
     *  Constant: '<S397>/Constant'
     *  Constant: '<S397>/Constant2'
     *  RelationalOperator: '<S397>/fix for DT propagation issue'
     */
    if (absInXVar > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    /* Switch: '<S397>/Switch2' incorporates:
     *  Constant: '<S397>/Clamping_zero'
     *  Constant: '<S397>/Constant3'
     *  Constant: '<S397>/Constant4'
     *  RelationalOperator: '<S397>/fix for DT propagation issue1'
     */
    if (rtb_Sum1_a > 0.0F) {
      tmp_1 = 1;
    } else {
      tmp_1 = -1;
    }

    /* Switch: '<S397>/Switch' incorporates:
     *  Constant: '<S397>/Clamping_zero'
     *  Constant: '<S397>/Constant1'
     *  Logic: '<S397>/AND3'
     *  RelationalOperator: '<S397>/Equal1'
     *  RelationalOperator: '<S397>/Relational Operator'
     *  Switch: '<S397>/Switch1'
     *  Switch: '<S397>/Switch2'
     */
    if ((absInXVar != 0.0F) && (tmp_0 == tmp_1)) {
      rtb_Sum1_a = 0.0F;
    }

    /* End of Switch: '<S397>/Switch' */

    /* DeadZone: '<S454>/DeadZone' */
    if (uVarXTmp > 13.8564062F) {
      uVarXTmp -= 13.8564062F;
    } else if (uVarXTmp >= -13.8564062F) {
      uVarXTmp = 0.0F;
    } else {
      uVarXTmp -= -13.8564062F;
    }

    /* End of DeadZone: '<S454>/DeadZone' */

    /* Product: '<S459>/IProd Out' incorporates:
     *  Constant: '<S355>/Ki'
     */
    rtb_algDD_o2 *= 0.033F;

    /* Switch: '<S452>/Switch1' incorporates:
     *  Constant: '<S452>/Clamping_zero'
     *  Constant: '<S452>/Constant'
     *  Constant: '<S452>/Constant2'
     *  RelationalOperator: '<S452>/fix for DT propagation issue'
     */
    if (uVarXTmp > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    /* Switch: '<S452>/Switch2' incorporates:
     *  Constant: '<S452>/Clamping_zero'
     *  Constant: '<S452>/Constant3'
     *  Constant: '<S452>/Constant4'
     *  RelationalOperator: '<S452>/fix for DT propagation issue1'
     */
    if (rtb_algDD_o2 > 0.0F) {
      tmp_1 = 1;
    } else {
      tmp_1 = -1;
    }

    /* Switch: '<S452>/Switch' incorporates:
     *  Constant: '<S452>/Clamping_zero'
     *  Constant: '<S452>/Constant1'
     *  Logic: '<S452>/AND3'
     *  RelationalOperator: '<S452>/Equal1'
     *  RelationalOperator: '<S452>/Relational Operator'
     *  Switch: '<S452>/Switch1'
     *  Switch: '<S452>/Switch2'
     */
    if ((uVarXTmp != 0.0F) && (tmp_0 == tmp_1)) {
      rtb_Add2_a = 0.0F;
    } else {
      rtb_Add2_a = rtb_algDD_o2;
    }

    /* End of Switch: '<S452>/Switch' */

    /* RelationalOperator: '<S486>/Compare' incorporates:
     *  Constant: '<S486>/Constant'
     */
    rtb_Compare_h = (rtb_Sum1_d_tmp < 0.0F);

    /* If: '<S484>/If' incorporates:
     *  DataTypeConversion: '<S484>/Data Type Conversion'
     */
    if (rtb_Compare_h) {
      /* Outputs for IfAction SubSystem: '<S484>/If Action Subsystem' incorporates:
       *  ActionPort: '<S487>/Action Port'
       */
      pmsm_smo_IfActionSubsystem(rtb_Sum1_d_tmp, &absInXVar);

      /* End of Outputs for SubSystem: '<S484>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S484>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S488>/Action Port'
       */
      pmsm_smo_IfActionSubsystem1(rtb_Sum1_d_tmp, &absInXVar);

      /* End of Outputs for SubSystem: '<S484>/If Action Subsystem1' */
    }

    /* End of If: '<S484>/If' */

    /* Gain: '<S482>/indexing' */
    absInXVar *= 800.0F;

    /* DataTypeConversion: '<S482>/Get_Integer' */
    if (absInXVar < 0.0F) {
      uVarXTmp = (float)ceil(absInXVar);
    } else {
      uVarXTmp = (float)floor(absInXVar);
    }

    if (rtIsNaNF(uVarXTmp) || rtIsInfF(uVarXTmp)) {
      uVarXTmp = 0.0F;
    } else {
      uVarXTmp = (float)fmod(uVarXTmp, 65536.0);
    }

    rtb_FixPtSum1 = (uint16_t)(uVarXTmp < 0.0F ? (int32_t)(uint16_t)-(int16_t)(uint16_t)-uVarXTmp : (int32_t)
      (uint16_t)uVarXTmp);

    /* End of DataTypeConversion: '<S482>/Get_Integer' */

    /* Sum: '<S482>/Sum2' incorporates:
     *  DataTypeConversion: '<S482>/Data Type Conversion1'
     */
    rtb_algDD_o2 = absInXVar - (float)rtb_FixPtSum1;

    /* Outputs for Atomic SubSystem: '<S348>/Two inputs CRL' */
    pmsm_smo_TwoinputsCRL(rtb_Merge_m[0], rtb_Merge_m[1], (pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 +
      1U)] - pmsm_smo_ConstP.pooled25[rtb_FixPtSum1]) * rtb_algDD_o2 + pmsm_smo_ConstP.pooled25[rtb_FixPtSum1],
                          (pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 201U)] -
      pmsm_smo_ConstP.pooled25[(int32_t)(rtb_FixPtSum1 + 200U)]) * rtb_algDD_o2 + pmsm_smo_ConstP.pooled25
                          [(int32_t)(rtb_FixPtSum1 + 200U)], &pmsm_smo_DW.algDD_o1_f, &pmsm_smo_DW.algDD_o2_a);

    /* End of Outputs for SubSystem: '<S348>/Two inputs CRL' */

    /* Gain: '<S509>/one_by_two' incorporates:
     *  Constant: '<S482>/offset'
     *  Constant: '<S482>/sine_table_values'
     *  Product: '<S483>/Product'
     *  Product: '<S483>/Product1'
     *  Selector: '<S482>/Lookup'
     *  Sum: '<S482>/Sum'
     *  Sum: '<S483>/Sum3'
     *  Sum: '<S483>/Sum4'
     *  Sum: '<S483>/Sum5'
     *  Sum: '<S483>/Sum6'
     */
    absInXVar = 0.5F * pmsm_smo_DW.algDD_o1_f;

    /* Gain: '<S509>/sqrt3_by_two' */
    rtb_algDD_o2 = 0.866025388F * pmsm_smo_DW.algDD_o2_a;

    /* Sum: '<S509>/add_b' */
    uVarXTmp = rtb_algDD_o2 - absInXVar;

    /* Sum: '<S509>/add_c' */
    absInXVar = (0.0F - absInXVar) - rtb_algDD_o2;

    /* MinMax: '<S506>/Max' incorporates:
     *  MinMax: '<S506>/Min'
     */
    rtb_Compare_h = rtIsNaNF(uVarXTmp);
    if ((pmsm_smo_DW.algDD_o1_f >= uVarXTmp) || rtb_Compare_h) {
      rtb_Saturation_e = pmsm_smo_DW.algDD_o1_f;
    } else {
      rtb_Saturation_e = uVarXTmp;
    }

    /* MinMax: '<S506>/Min' */
    if ((pmsm_smo_DW.algDD_o1_f <= uVarXTmp) || rtb_Compare_h) {
      rtb_Sum1_d_tmp = pmsm_smo_DW.algDD_o1_f;
    } else {
      rtb_Sum1_d_tmp = uVarXTmp;
    }

    /* MinMax: '<S506>/Max' incorporates:
     *  MinMax: '<S506>/Min'
     */
    rtb_Compare_h = rtIsNaNF(absInXVar);
    rtb_Compare_h = !rtb_Compare_h;
    if ((!(rtb_Saturation_e >= absInXVar)) && rtb_Compare_h) {
      rtb_Saturation_e = absInXVar;
    }

    /* MinMax: '<S506>/Min' */
    if ((!(rtb_Sum1_d_tmp <= absInXVar)) && rtb_Compare_h) {
      rtb_Sum1_d_tmp = absInXVar;
    }

    /* Gain: '<S506>/one_by_two' incorporates:
     *  MinMax: '<S506>/Max'
     *  MinMax: '<S506>/Min'
     *  Sum: '<S506>/Add'
     */
    rtb_algDD_o2 = (rtb_Saturation_e + rtb_Sum1_d_tmp) * -0.5F;

    /* Sum: '<S284>/Sum' incorporates:
     *  Constant: '<S284>/Constant4'
     *  Gain: '<S284>/One_by_Two'
     *  Gain: '<S505>/Gain'
     *  Sum: '<S505>/Add1'
     *  Sum: '<S505>/Add2'
     *  Sum: '<S505>/Add3'
     */
    pmsm_smo_DW.Sum[0] = (pmsm_smo_DW.algDD_o1_f + rtb_algDD_o2) * 1.15470052F * 0.0360843912F + 0.5F;
    pmsm_smo_DW.Sum[1] = (uVarXTmp + rtb_algDD_o2) * 1.15470052F * 0.0360843912F + 0.5F;
    pmsm_smo_DW.Sum[2] = (rtb_algDD_o2 + absInXVar) * 1.15470052F * 0.0360843912F + 0.5F;

    /* RateTransition: '<S89>/Rate Transition' incorporates:
     *  Delay: '<S516>/Delay1'
     */
    if (isReciprocal) {
      pmsm_smo_DW.RateTransition_Buffer = pmsm_smo_DW.Delay1_DSTATE;

      /* RateTransition: '<S89>/Rate Transition1' incorporates:
       *  DataTypeConversion: '<S522>/Data Type Conversion1'
       *  Delay: '<S516>/Delay1'
       */
      pmsm_smo_DW.RateTransition1_Buffer = pmsm_smo_DW.bitsForTID0.NOT;

      /* RateTransition: '<S89>/Rate Transition2' */
      pmsm_smo_DW.RateTransition2_Buffer = pmsm_smo_DW.SpeedRef;
    }

    /* Update for DiscreteIntegrator: '<S462>/Integrator' incorporates:
     *  Logic: '<S355>/Logical Operator'
     */
    pmsm_smo_DW.Integrator_DSTATE += rtb_Add2_a;
    pmsm_smo_DW.Integrator_PrevResetState = (int8_t)rtb_Compare_gy;

    /* Update for DiscreteIntegrator: '<S407>/Integrator' */
    pmsm_smo_DW.Integrator_DSTATE_e += rtb_Sum1_a;
    pmsm_smo_DW.Integrator_PrevResetState_h = (int8_t)rtb_Compare_gy;
  } else if (pmsm_smo_DW.Run_MODE) {
    pmsm_smo_DW.Run_MODE = false;
  }

  /* End of RelationalOperator: '<S84>/Compare' */
  /* End of Outputs for SubSystem: '<S81>/Run' */

  /* MultiPortSwitch: '<S81>/Multiport Switch1' incorporates:
   *  DataTypeConversion: '<S76>/Data Type Conversion3'
   */
  switch ((int32_t)rtb_Mode) {
   case 0:
    /* MultiPortSwitch: '<S81>/Multiport Switch1' */
    pmsm_smo_DW.Vabc[0] = pmsm_smo_DW.Constant10_c[0];
    pmsm_smo_DW.Vabc[1] = pmsm_smo_DW.Constant10_c[1];
    pmsm_smo_DW.Vabc[2] = pmsm_smo_DW.Constant10_c[2];

    /* MultiPortSwitch: '<S81>/Multiport Switch2' incorporates:
     *  Constant: '<S81>/Constant10'
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    pmsm_smo_DW.UnitDelay2_DSTATE[0] = 0.0F;
    pmsm_smo_DW.UnitDelay2_DSTATE[1] = 0.0F;
    pmsm_smo_DW.UnitDelay2_DSTATE[2] = 0.0F;
    pmsm_smo_DW.UnitDelay2_DSTATE[3] = 0.0F;
    break;

   case 1:
    /* MultiPortSwitch: '<S81>/Multiport Switch1' */
    pmsm_smo_DW.Vabc[0] = pmsm_smo_DW.Vabc_e[0];
    pmsm_smo_DW.Vabc[1] = pmsm_smo_DW.Vabc_e[1];
    pmsm_smo_DW.Vabc[2] = pmsm_smo_DW.Vabc_e[2];

    /* MultiPortSwitch: '<S81>/Multiport Switch2' incorporates:
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    pmsm_smo_DW.UnitDelay2_DSTATE[0] = pmsm_smo_DW.Kalpha_j;
    pmsm_smo_DW.UnitDelay2_DSTATE[1] = pmsm_smo_DW.Kbeta_l;
    pmsm_smo_DW.UnitDelay2_DSTATE[2] = pmsm_smo_DW.algDD_o1_p;
    pmsm_smo_DW.UnitDelay2_DSTATE[3] = pmsm_smo_DW.algDD_o2_h;
    break;

   default:
    /* MultiPortSwitch: '<S81>/Multiport Switch1' */
    pmsm_smo_DW.Vabc[0] = pmsm_smo_DW.Sum[0];
    pmsm_smo_DW.Vabc[1] = pmsm_smo_DW.Sum[1];
    pmsm_smo_DW.Vabc[2] = pmsm_smo_DW.Sum[2];

    /* MultiPortSwitch: '<S81>/Multiport Switch2' incorporates:
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    pmsm_smo_DW.UnitDelay2_DSTATE[0] = pmsm_smo_DW.Kalpha;
    pmsm_smo_DW.UnitDelay2_DSTATE[1] = pmsm_smo_DW.Kbeta;
    pmsm_smo_DW.UnitDelay2_DSTATE[2] = pmsm_smo_DW.algDD_o1_f;
    pmsm_smo_DW.UnitDelay2_DSTATE[3] = pmsm_smo_DW.algDD_o2_a;
    break;
  }

  /* End of MultiPortSwitch: '<S81>/Multiport Switch1' */

  /* RateTransition generated from: '<S79>/Rate Transition14' */
  if (pmsm_smo_DW.RateTransition14_3_semaphoreTaken == 0) {
    pmsm_smo_DW.RateTransition14_3_Buffer0[0] = rtb_I_ab[0];
    pmsm_smo_DW.RateTransition14_3_Buffer0[1] = rtb_I_ab[1];
  }

  /* RateTransition generated from: '<S79>/Rate Transition14' */
  if (pmsm_smo_DW.RateTransition14_5_semaphoreTaken == 0) {
    pmsm_smo_DW.RateTransition14_5_Buffer0[0] = pmsm_smo_DW.IdqRef[0];
    pmsm_smo_DW.RateTransition14_5_Buffer0[1] = pmsm_smo_DW.algDD_o1;
    pmsm_smo_DW.RateTransition14_5_Buffer0[2] = pmsm_smo_DW.IdqRef[1];
    pmsm_smo_DW.RateTransition14_5_Buffer0[3] = pmsm_smo_DW.algDD_o2;
  }

  /* DiscreteIntegrator: '<S512>/Discrete-Time Integrator3' incorporates:
   *  Delay: '<S512>/Delay2'
   *  Delay: '<S513>/Delay'
   *  Gain: '<S512>/Gain4'
   *  Gain: '<S512>/Gain7'
   *  Sum: '<S512>/Sum4'
   *  Switch: '<S515>/Switch1'
   */
  pmsm_smo_DW.Delay2_DSTATE[0] = (((rtb_RateTransition2_f - 0.285F * pmsm_smo_DW.Delay2_DSTATE[0]) -
    rtb_Switch1_idx_0) - pmsm_smo_DW.Delay_DSTATE[0]) * 3484.56348F * 5.0E-5F +
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_o[0];
  pmsm_smo_DW.Delay2_DSTATE[1] = (((rtb_UnitDelay2_idx_3 - 0.285F * pmsm_smo_DW.Delay2_DSTATE[1]) -
    rtb_Product_il_idx_2) - pmsm_smo_DW.Delay_DSTATE[1]) * 3484.56348F * 5.0E-5F +
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_o[1];

  /* S-Function (MCHP_PWM_HS_FEP): '<S1>/PWM_HS_FEP' */
  /* Update PWM Duty Cycle */
  PG3DC = ((unsigned int)( pmsm_smo_DW.Vabc[2] * 79984.0F ));/* Update PWM3 Duty Cycle */
  PG2DC = ((unsigned int)( pmsm_smo_DW.Vabc[1] * 79984.0F ));/* Update PWM2 Duty Cycle */
  PG1DC = ((unsigned int)( pmsm_smo_DW.Vabc[0] * 79984.0F ));/* Update PWM1 Duty Cycle */
  PG1STATbits.UPDREQ = 1;              /* synchronized UPDATE */

  /* S-Function (MCHP_ADC_HS_12b): '<S6>/ADC HS 12b dsPICA2' */
  pmsm_smo_DW.ADCHS12bdsPICA2_o1 = (uint16_t) (AD1CH5DATA >> 16);/* Read AD1 for AN3 */
  pmsm_smo_DW.ADCHS12bdsPICA2_o2 = (uint16_t) (AD1CH6DATA >> 16);/* Read AD1 for AN6 */
  pmsm_smo_DW.ADCHS12bdsPICA2_o3 = (uint16_t) (AD1CH7DATA >> 16);/* Read AD1 for AN10 */

  /* Outputs for Enabled SubSystem: '<S7>/Downsample Averaged 2000 samples remove bias' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* DataStoreRead: '<Root>/Data Store Read' */
  if (CurrOffsetMeas) {
    if (!pmsm_smo_DW.DownsampleAveraged2000samplesremovebias_MODE) {
      pmsm_smo_DW.DownsampleAveraged2000samplesremovebias_MODE = true;
    }

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     *  UnitDelay: '<S14>/Output'
     */
    CurrOffsetMeas = (pmsm_smo_DW.Output_DSTATE == 1);

    /* Switch: '<S16>/FixPt Switch' incorporates:
     *  Constant: '<S15>/FixPt Constant'
     *  Constant: '<S16>/Constant'
     *  Sum: '<S15>/FixPt Sum1'
     *  UnitDelay: '<S14>/Output'
     */
    if ((uint16_t)(pmsm_smo_DW.Output_DSTATE + 1) > 1999) {
      pmsm_smo_DW.Output_DSTATE = 0U;
    } else {
      pmsm_smo_DW.Output_DSTATE++;
    }

    /* End of Switch: '<S16>/FixPt Switch' */

    /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    if (CurrOffsetMeas) {
      pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[0] = 0U;
      pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[1] = 0U;
    }

    DiscreteTimeIntegrator = pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[0];
    tmp = pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[1];

    /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[0] = DiscreteTimeIntegrator + pmsm_smo_DW.ADCHS12bdsPICA1_o1;
    pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[1] = tmp + pmsm_smo_DW.ADCHS12bdsPICA1_o2;

    /* RateTransition: '<S12>/Rate Transition3' */
    if (pmsm_smo_M->Timing.RateInteraction.TID0_4 == 1) {
      pmsm_smo_DW.RateTransition3_Buffer_b[0] = pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[0];
      pmsm_smo_DW.RateTransition3_Buffer_b[1] = pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fc[1];
    }

    /* End of RateTransition: '<S12>/Rate Transition3' */
  } else if (pmsm_smo_DW.DownsampleAveraged2000samplesremovebias_MODE) {
    pmsm_smo_DW.DownsampleAveraged2000samplesremovebias_MODE = false;
  }

  /* End of DataStoreRead: '<Root>/Data Store Read' */
  /* End of Outputs for SubSystem: '<S7>/Downsample Averaged 2000 samples remove bias' */

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   *  UnitDelay: '<S22>/Output'
   */
  CurrOffsetMeas = (pmsm_smo_DW.Output_DSTATE_g == 1);

  /* Switch: '<S24>/FixPt Switch' incorporates:
   *  Constant: '<S23>/FixPt Constant'
   *  Constant: '<S24>/Constant'
   *  Sum: '<S23>/FixPt Sum1'
   *  UnitDelay: '<S22>/Output'
   */
  if ((uint8_t)(pmsm_smo_DW.Output_DSTATE_g + 1) > 19) {
    pmsm_smo_DW.Output_DSTATE_g = 0U;
  } else {
    pmsm_smo_DW.Output_DSTATE_g++;
  }

  /* End of Switch: '<S24>/FixPt Switch' */

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  if (CurrOffsetMeas) {
    pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fm = 0U;
  }

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator = pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fm + pmsm_smo_DW.ADCHS12bdsPICA2_o3;

  /* RateTransition: '<S9>/Rate Transition3' */
  if (pmsm_smo_M->Timing.RateInteraction.TID0_2 == 1) {
    pmsm_smo_DW.RateTransition3_Buffer = DiscreteTimeIntegrator;
  }

  /* End of RateTransition: '<S9>/Rate Transition3' */

  /* S-Function (MCHP_QEI): '<S1>/QEI1' */
  if (false == 0) {
    pmsm_smo_DW.theta_RAW = POS1CNT;   /* read QEI Position */
  } else {
    POS1CNT = 0;                       /* QEI - Reset */
    pmsm_smo_DW.theta_RAW = 0;         /* Reset : Position output is the Initialisation Value */
  }

  pmsm_smo_DW.omega_RAW = VEL1CNT;     /* Velocity Counter (Register is Reset when read) */

  /* S-Function (MCHP_Digital_Input): '<S1>/SW2' */
  /* MCHP_Digital_Input Block: <S1>/SW2/Output */
  rtb_BTN2 = PORTDbits.RD10;           /* Read pin D10 */

  /* S-Function (MCHP_MCU_OVERLOAD): '<S11>/MCU Overload' */
  /* S-Function "MCHP_MCU_OVERLOAD" Block: <S11>/MCU Overload */
  {
    uint16_t tmp = MCHP_MCU_Overload.val;
    MCHP_MCU_Overload.val ^= tmp;
               /* Multi Tasking: potential simultaneous access ==> using xor to protect from potential miss */
    pmsm_smo_DW.MCUOverload = tmp;
  }

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/LED_DIM' */
  LATCbits.LATC0 = false;

  /* Saturate: '<S42>/Saturation2' */
  if (pmsm_smo_DW.Vabc[0] > 1.0F) {
    rtb_RateTransition2_f = 1.0F;
  } else if (pmsm_smo_DW.Vabc[0] < 0.0F) {
    rtb_RateTransition2_f = 0.0F;
  } else {
    rtb_RateTransition2_f = pmsm_smo_DW.Vabc[0];
  }

  if (pmsm_smo_DW.Vabc[1] > 1.0F) {
    rtb_UnitDelay2_idx_3 = 1.0F;
  } else if (pmsm_smo_DW.Vabc[1] < 0.0F) {
    rtb_UnitDelay2_idx_3 = 0.0F;
  } else {
    rtb_UnitDelay2_idx_3 = pmsm_smo_DW.Vabc[1];
  }

  if (pmsm_smo_DW.Vabc[2] > 1.0F) {
    rtb_Product_il_idx_2 = 1.0F;
  } else if (pmsm_smo_DW.Vabc[2] < 0.0F) {
    rtb_Product_il_idx_2 = 0.0F;
  } else {
    rtb_Product_il_idx_2 = pmsm_smo_DW.Vabc[2];
  }

  /* End of Saturate: '<S42>/Saturation2' */

  /* Gain: '<S42>/Gain' incorporates:
   *  Sum: '<S42>/Sum'
   */
  rtb_Sum1_a = ((rtb_UnitDelay2_idx_3 + rtb_Product_il_idx_2) + rtb_RateTransition2_f) * 0.333333343F;

  /* Product: '<S42>/Product' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Sum: '<S42>/Sum1'
   *  Sum: '<S42>/Sum2'
   *  Sum: '<S42>/Sum3'
   *  Switch: '<S42>/Switch'
   */
  rtb_RateTransition2_f = (rtb_RateTransition2_f - rtb_Sum1_a) * 24.0F;
  rtb_UnitDelay2_idx_3 = (rtb_UnitDelay2_idx_3 - rtb_Sum1_a) * 24.0F;
  rtb_Product_il_idx_2 = (rtb_Product_il_idx_2 - rtb_Sum1_a) * 24.0F;

  /* Step: '<S39>/Step' */
  if (((pmsm_smo_M->Timing.clockTick0) * 5.0E-5) < 6.0) {
    rtb_Divide = 0.0;
  } else {
    rtb_Divide = 0.004405328835673337;
  }

  /* Sum: '<S46>/Add1' incorporates:
   *  DataTypeConversion: '<S39>/Data Type Conversion'
   *  Product: '<S46>/Product'
   *  Product: '<S46>/Product1'
   *  Step: '<S39>/Step'
   *  UnitDelay: '<S46>/Unit Delay'
   */
  pmsm_smo_DW.UnitDelay_DSTATE_k = (float)rtb_Divide * 0.01F + 0.99F * pmsm_smo_DW.UnitDelay_DSTATE_k;

  /* DiscreteIntegrator: '<S67>/Discrete-Time Integrator3' */
  if (pmsm_smo_DW.DiscreteTimeIntegrator3_IC_LOADING != 0) {
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE = 0.0;
    if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
      pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
    } else if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE < -1.0E+7) {
      pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
    }
  }

  /* Switch: '<S52>/Switch1' incorporates:
   *  Constant: '<S54>/Constant'
   *  RelationalOperator: '<S54>/Compare'
   *  UnitDelay: '<S52>/Unit Delay'
   */
  if (pmsm_smo_DW.UnitDelay_DSTATE >= -3.1415926535897931) {
    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S53>/Constant'
     *  RelationalOperator: '<S53>/Compare'
     */
    if (!(pmsm_smo_DW.UnitDelay_DSTATE <= 3.1415926535897931)) {
      /* Product: '<S65>/Product3' incorporates:
       *  Constant: '<S52>/Constant3'
       *  Sum: '<S52>/Subtract'
       */
      pmsm_smo_DW.UnitDelay_DSTATE -= 6.2831854820251465;
    }

    /* End of Switch: '<S52>/Switch' */
  } else {
    /* Product: '<S65>/Product3' incorporates:
     *  Constant: '<S52>/Constant1'
     *  Sum: '<S52>/Add1'
     */
    pmsm_smo_DW.UnitDelay_DSTATE += 6.2831854820251465;
  }

  /* End of Switch: '<S52>/Switch1' */

  /* Gain: '<S49>/Gain4' */
  rtb_Gain4 = 5.0 * pmsm_smo_DW.UnitDelay_DSTATE;

  /* Trigonometry: '<S51>/sine_cosine' */
  rtb_Product1_c = sin(rtb_Gain4);
  rtb_Gain4 = cos(rtb_Gain4);

  /* DiscreteIntegrator: '<S68>/Discrete-Time Integrator3' */
  if (pmsm_smo_DW.DiscreteTimeIntegrator3_IC_LOADING_j != 0) {
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m = 0.0;
    if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m > 1.0E+7) {
      pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m = 1.0E+7;
    } else if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m < -1.0E+7) {
      pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m = -1.0E+7;
    }
  }

  /* Signum: '<S49>/Sign' incorporates:
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
   */
  if (rtIsNaN(pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE)) {
    rtb_Divide = (rtNaN);
  } else if (pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE < 0.0) {
    rtb_Divide = -1.0;
  } else {
    rtb_Divide = (pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE > 0.0);
  }

  /* Product: '<S49>/Divide' incorporates:
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator3'
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator3'
   *  Gain: '<S63>/Gain1'
   *  Gain: '<S63>/Gain2'
   *  Product: '<S49>/Divide1'
   *  Product: '<S49>/Divide2'
   *  Product: '<S63>/Product'
   *  Product: '<S66>/Product'
   *  Signum: '<S49>/Sign'
   *  Sum: '<S49>/Sum1'
   *  Sum: '<S63>/Add'
   *  UnitDelay: '<S46>/Unit Delay'
   */
  rtb_Divide = ((((pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE * pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m *
                   0.0 + 0.0080962648292690169 * pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m) * 7.5 -
                  pmsm_smo_DW.UnitDelay_DSTATE_k) - pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE *
                 2.636875217824E-6) - 0.0 * rtb_Divide) / 7.061551833333E-6;

  /* Gain: '<S49>/Gain' incorporates:
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
   */
  rtb_Gain = 5.0 * pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE;

  /* Product: '<S65>/Product3' incorporates:
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
   *  Gain: '<S52>/Gain1'
   *  Sum: '<S52>/Add'
   */
  pmsm_smo_DW.UnitDelay_DSTATE += 5.0E-5 * pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S60>/Add' incorporates:
   *  Gain: '<S60>/Gain'
   *  Gain: '<S60>/Gain1'
   *  Gain: '<S60>/Gain4'
   */
  rtb_RateTransition2_f = (0.666666687F * rtb_RateTransition2_f + -0.333333343F * rtb_UnitDelay2_idx_3) +
    -0.333333343F * rtb_Product_il_idx_2;

  /* Sum: '<S60>/Add1' incorporates:
   *  Gain: '<S60>/Gain2'
   *  Gain: '<S60>/Gain3'
   */
  uVarXTmp = 0.577350259F * rtb_UnitDelay2_idx_3 + -0.577350259F * rtb_Product_il_idx_2;

  /* Product: '<S70>/Product' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator3'
   *  Product: '<S67>/Product'
   */
  rtb_Product_an = rtb_Gain * pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m * 0.00028698 / 0.00028698;

  /* Product: '<S71>/Product' incorporates:
   *  Constant: '<S71>/Constant'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator3'
   */
  rtb_Product_dx = pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE * 0.287 / 0.00028698;

  /* Product: '<S73>/Product' incorporates:
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator3'
   *  Product: '<S68>/Product'
   */
  rtb_Product_d = pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE * rtb_Gain * 0.00028698 / 0.00028698;

  /* Product: '<S75>/Product' incorporates:
   *  Constant: '<S75>/Constant'
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator3'
   */
  rtb_Product_f = pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m * 0.287 / 0.00028698;

  /* Update for UnitDelay: '<S76>/Unit Delay' */
  pmsm_smo_DW.bitsForTID0.UnitDelay_DSTATE_f = pmsm_smo_DW.bitsForTID0.CalibStatus;

  /* Update for UnitDelay: '<S516>/Unit Delay3' */
  pmsm_smo_DW.UnitDelay3_DSTATE = absInYVar;

  /* Update for DiscreteIntegrator: '<S516>/Discrete-Time Integrator4' incorporates:
   *  Delay: '<S516>/Delay1'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator4_DSTATE = pmsm_smo_DW.Delay1_DSTATE;

  /* Update for DiscreteIntegrator: '<S513>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S513>/Delay'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_f[0] = pmsm_smo_DW.Delay_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S513>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S513>/Delay3'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator2_DSTATE[0] = pmsm_smo_DW.Delay3_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S512>/Discrete-Time Integrator3' incorporates:
   *  Delay: '<S512>/Delay2'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_o[0] = pmsm_smo_DW.Delay2_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S513>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S513>/Delay'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_f[1] = pmsm_smo_DW.Delay_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S513>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S513>/Delay3'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator2_DSTATE[1] = pmsm_smo_DW.Delay3_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S512>/Discrete-Time Integrator3' incorporates:
   *  Delay: '<S512>/Delay2'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_o[1] = pmsm_smo_DW.Delay2_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE_fm = DiscreteTimeIntegrator;

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator3' incorporates:
   *  Product: '<S65>/Product2'
   *  Product: '<S65>/Product3'
   *  Product: '<S69>/Product'
   *  Sum: '<S65>/Add1'
   *  Sum: '<S67>/Add'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator3_IC_LOADING = 0U;
  pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE += (((rtb_RateTransition2_f * rtb_Gain4 + uVarXTmp *
    rtb_Product1_c) / 0.00028698 + rtb_Product_an) - rtb_Product_dx) * 5.0E-5;
  if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
  } else if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE < -1.0E+7) {
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S74>/Constant'
   *  Product: '<S65>/Product'
   *  Product: '<S65>/Product1'
   *  Product: '<S72>/Product'
   *  Product: '<S74>/Product'
   *  Sum: '<S65>/Add'
   *  Sum: '<S68>/Add'
   */
  pmsm_smo_DW.DiscreteTimeIntegrator3_IC_LOADING_j = 0U;
  pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m += ((((uVarXTmp * rtb_Gain4 - rtb_RateTransition2_f *
    rtb_Product1_c) / 0.00028698 - rtb_Product_d) - rtb_Gain * 0.0080962648292690169 / 0.00028698) -
    rtb_Product_f) * 5.0E-5;
  if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m > 1.0E+7) {
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m = 1.0E+7;
  } else if (pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m < -1.0E+7) {
    pmsm_smo_DW.DiscreteTimeIntegrator3_DSTATE_m = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
  pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE += 5.0E-5 * rtb_Divide;
  if (pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE > 1.0E+7) {
    pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE = 1.0E+7;
  } else if (pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE < -1.0E+7) {
    pmsm_smo_DW.DiscreteTimeIntegrator_DSTATE = -1.0E+7;
  }

  /* End of Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  pmsm_smo_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void pmsm_smo_step1(void)              /* Sample time: [0.0005s, 0.0s] */
{
  float rtb_SpeedRef_0[11];
  float rtb_Idq[4];
  float rtb_Iab[2];
  float rtb_OL_Theta;
  float rtb_SpeedRef;
  float rtb_Theta_SMO;
  int32_t i;
  uint16_t rtb_MultiportSwitch_idx_0;
  uint16_t rtb_MultiportSwitch_idx_1;
  uint8_t rtb_RateTransition15;

  /* RateTransition: '<S79>/Rate Transition15' */
  rtb_RateTransition15 = pmsm_smo_DW.RateTransition15_Buffer0;

  /* RateTransition generated from: '<S79>/Rate Transition14' */
  rtb_SpeedRef = pmsm_smo_DW.SpeedRef;

  /* RateTransition generated from: '<S79>/Rate Transition14' */
  pmsm_smo_DW.RateTransition14_3_semaphoreTaken = 1;
  rtb_Iab[0] = pmsm_smo_DW.RateTransition14_3_Buffer0[0];
  rtb_Iab[1] = pmsm_smo_DW.RateTransition14_3_Buffer0[1];
  pmsm_smo_DW.RateTransition14_3_semaphoreTaken = 0;

  /* RateTransition generated from: '<S79>/Rate Transition14' */
  rtb_Theta_SMO = pmsm_smo_DW.Bias1;

  /* RateTransition generated from: '<S79>/Rate Transition14' */
  pmsm_smo_DW.RateTransition14_5_semaphoreTaken = 1;
  rtb_Idq[0] = pmsm_smo_DW.RateTransition14_5_Buffer0[0];
  rtb_Idq[1] = pmsm_smo_DW.RateTransition14_5_Buffer0[1];
  rtb_Idq[2] = pmsm_smo_DW.RateTransition14_5_Buffer0[2];
  rtb_Idq[3] = pmsm_smo_DW.RateTransition14_5_Buffer0[3];
  pmsm_smo_DW.RateTransition14_5_semaphoreTaken = 0;

  /* RateTransition generated from: '<S79>/Rate Transition14' */
  rtb_OL_Theta = pmsm_smo_DW.Theta_in;

  /* Outputs for Atomic SubSystem: '<S79>/Subsystem Reference' */
  /* MultiPortSwitch: '<S526>/Multiport Switch' incorporates:
   *  Constant: '<S526>/Ia_Pos'
   *  Constant: '<S526>/Iab'
   *  Constant: '<S526>/Id control'
   *  Constant: '<S526>/Iq control'
   *  Constant: '<S526>/speed control'
   */
  switch (rtb_RateTransition15) {
   case 1:
    rtb_MultiportSwitch_idx_0 = 1U;
    rtb_MultiportSwitch_idx_1 = 2U;
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = 3U;
    rtb_MultiportSwitch_idx_1 = 4U;
    break;

   case 3:
    rtb_MultiportSwitch_idx_0 = 6U;
    rtb_MultiportSwitch_idx_1 = 7U;
    break;

   case 4:
    rtb_MultiportSwitch_idx_0 = 8U;
    rtb_MultiportSwitch_idx_1 = 9U;
    break;

   default:
    rtb_MultiportSwitch_idx_0 = 3U;
    rtb_MultiportSwitch_idx_1 = 5U;
    break;
  }

  /* End of MultiPortSwitch: '<S526>/Multiport Switch' */

  /* SignalConversion generated from: '<S526>/Selector' */
  rtb_SpeedRef_0[0] = rtb_SpeedRef;
  rtb_SpeedRef_0[1] = pmsm_smo_DW.Delay1_DSTATE;
  rtb_SpeedRef_0[2] = rtb_Iab[0];
  rtb_SpeedRef_0[3] = rtb_Iab[1];
  rtb_SpeedRef_0[4] = rtb_Theta_SMO;
  rtb_SpeedRef_0[5] = rtb_Idq[0];
  rtb_SpeedRef_0[6] = rtb_Idq[1];
  rtb_SpeedRef_0[7] = rtb_Idq[2];
  rtb_SpeedRef_0[8] = rtb_Idq[3];
  rtb_SpeedRef_0[9] = pmsm_smo_DW.UnitDelay_1_DSTATE;
  rtb_SpeedRef_0[10] = rtb_OL_Theta;

  /* Selector: '<S526>/Selector' */
  rtb_Iab[0] = rtb_SpeedRef_0[rtb_MultiportSwitch_idx_0 - 1];
  rtb_Iab[1] = rtb_SpeedRef_0[rtb_MultiportSwitch_idx_1 - 1];

  /* S-Function (any2byte_svd): '<S540>/Byte Pack' */

  /* Pack: <S540>/Byte Pack */
  {
    uint32_t MW_outputPortOffset = 0U;
    uint16_t MW_inputPortWidth = 0U;

    /* Packed output data type - uint8_t */
    void* packData = &pmsm_smo_DW.BytePack[0];

    /* Packing the values of Input 1 */
    /* Input data type - float, size - 2 */
    {
      MW_inputPortWidth = (uint16_t)2 * sizeof(float);
      memcpy((void *)&(((uint8_t *)packData)[MW_outputPortOffset]), (void*)&rtb_Iab[0], MW_inputPortWidth);
    }
  }

  /* End of Outputs for SubSystem: '<S79>/Subsystem Reference' */

  /* If: '<S531>/If' incorporates:
   *  Constant: '<S531>/Constant'
   *  UnitDelay: '<S532>/Output'
   */
  if (pmsm_smo_DW.Output_DSTATE_m == 0) {
    /* Outputs for IfAction SubSystem: '<S531>/Start' incorporates:
     *  ActionPort: '<S535>/Action Port'
     */
    /* SignalConversion generated from: '<S535>/UART Tx' incorporates:
     *  Constant: '<S535>/End'
     */
    pmsm_smo_DW.TmpSignalConversionAtUARTTxInport1_b[0] = 83U;
    for (i = 0; i < 8; i++) {
      pmsm_smo_DW.TmpSignalConversionAtUARTTxInport1_b[i + 1] = pmsm_smo_DW.BytePack[i];
    }

    /* End of SignalConversion generated from: '<S535>/UART Tx' */

    /* S-Function (MCHP_UART_Tx): '<S535>/UART Tx' */
    /* MCHP_UART_Tx Block: <S535>/UART Tx/Outputs */
    {
      unsigned int Tmp;
      Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);/* head - tail - 1 */
      Tmp = Tmp & (Tx_BUFF_SIZE_UART1 - 1);
                                   /* Modulo Buffer Size (Buffer Size is 2^n). Tmp is the buffer free space */

      {
        unsigned int i1 = 0;
        unsigned int LocalTail = MCHP_UART1_Tx.tail;
                                   /* Tail is a volatile variable. Use local variable to speed-up execution */
        const uint8_t *u0 = &pmsm_smo_DW.TmpSignalConversionAtUARTTxInport1_b[0] ;
        if (Tmp >= 9)                  /* Does buffer can contains all char to be sent ? */
        {
          Tmp = 9 ;                    /* If so, set tmp to the number of char to be sent */
        }         /* Otherwise, send only the number of char which can be contained within the buffer (Tmp) */

        while (i1 < Tmp) {
          MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
          LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_UART1 - 1);
          i1= i1 + 1;
        }

        MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
      }

      {
        unsigned int LocalHead;
        int cpu_ipl_switchVar;
        cpu_ipl_switchVar = __builtin_write_DISICTL(5);/* mimic Tx interrupt, disable Tx & thread switching interrupts */
        LocalHead = MCHP_UART1_Tx.head;
                                   /* Head is a volatile variable. Use local variable to speed-up execution */
        while ((0U == U1STATbits.TXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXB buffer is not full */
        {
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          U1TXB = MCHP_UART1_Tx.buffer[LocalHead++];
          LocalHead &= (Tx_BUFF_SIZE_UART1-1);
        }

        MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
        __builtin_write_DISICTL(cpu_ipl_switchVar);/* stop mimic UART TX interrupt IPL level */
      }
    }
  } else if (pmsm_smo_DW.Output_DSTATE_m == 119) {
    /* Outputs for IfAction SubSystem: '<S531>/End' incorporates:
     *  ActionPort: '<S534>/Action Port'
     */
    for (i = 0; i < 8; i++) {
      /* SignalConversion generated from: '<S534>/UART Tx' */
      pmsm_smo_DW.TmpSignalConversionAtUARTTxInport1[i] = pmsm_smo_DW.BytePack[i];
    }

    /* SignalConversion generated from: '<S534>/UART Tx' incorporates:
     *  Constant: '<S534>/Start'
     */
    pmsm_smo_DW.TmpSignalConversionAtUARTTxInport1[8] = 69U;

    /* S-Function (MCHP_UART_Tx): '<S534>/UART Tx' */
    /* MCHP_UART_Tx Block: <S534>/UART Tx/Outputs */
    {
      unsigned int Tmp;
      Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);/* head - tail - 1 */
      Tmp = Tmp & (Tx_BUFF_SIZE_UART1 - 1);
                                   /* Modulo Buffer Size (Buffer Size is 2^n). Tmp is the buffer free space */

      {
        unsigned int i1 = 0;
        unsigned int LocalTail = MCHP_UART1_Tx.tail;
                                   /* Tail is a volatile variable. Use local variable to speed-up execution */
        const uint8_t *u0 = &pmsm_smo_DW.TmpSignalConversionAtUARTTxInport1[0] ;
        if (Tmp >= 9)                  /* Does buffer can contains all char to be sent ? */
        {
          Tmp = 9 ;                    /* If so, set tmp to the number of char to be sent */
        }         /* Otherwise, send only the number of char which can be contained within the buffer (Tmp) */

        while (i1 < Tmp) {
          MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
          LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_UART1 - 1);
          i1= i1 + 1;
        }

        MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
      }

      {
        unsigned int LocalHead;
        int cpu_ipl_switchVar;
        cpu_ipl_switchVar = __builtin_write_DISICTL(5);/* mimic Tx interrupt, disable Tx & thread switching interrupts */
        LocalHead = MCHP_UART1_Tx.head;
                                   /* Head is a volatile variable. Use local variable to speed-up execution */
        while ((0U == U1STATbits.TXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXB buffer is not full */
        {
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          U1TXB = MCHP_UART1_Tx.buffer[LocalHead++];
          LocalHead &= (Tx_BUFF_SIZE_UART1-1);
        }

        MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
        __builtin_write_DISICTL(cpu_ipl_switchVar);/* stop mimic UART TX interrupt IPL level */
      }
    }
  } else {
    /* Outputs for IfAction SubSystem: '<S531>/Data' incorporates:
     *  ActionPort: '<S533>/Action Port'
     */
    /* S-Function (MCHP_UART_Tx): '<S533>/UART Tx' */
    /* MCHP_UART_Tx Block: <S533>/UART Tx/Outputs */
    {
      unsigned int Tmp;
      Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);/* head - tail - 1 */
      Tmp = Tmp & (Tx_BUFF_SIZE_UART1 - 1);
                                   /* Modulo Buffer Size (Buffer Size is 2^n). Tmp is the buffer free space */

      {
        unsigned int i1 = 0;
        unsigned int LocalTail = MCHP_UART1_Tx.tail;
                                   /* Tail is a volatile variable. Use local variable to speed-up execution */
        const uint8_t *u0 = &pmsm_smo_DW.BytePack[0] ;
        if (Tmp >= 8)                  /* Does buffer can contains all char to be sent ? */
        {
          Tmp = 8 ;                    /* If so, set tmp to the number of char to be sent */
        }         /* Otherwise, send only the number of char which can be contained within the buffer (Tmp) */

        while (i1 < Tmp) {
          MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
          LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_UART1 - 1);
          i1= i1 + 1;
        }

        MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
      }

      {
        unsigned int LocalHead;
        int cpu_ipl_switchVar;
        cpu_ipl_switchVar = __builtin_write_DISICTL(5);/* mimic Tx interrupt, disable Tx & thread switching interrupts */
        LocalHead = MCHP_UART1_Tx.head;
                                   /* Head is a volatile variable. Use local variable to speed-up execution */
        while ((0U == U1STATbits.TXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXB buffer is not full */
        {
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          U1TXB = MCHP_UART1_Tx.buffer[LocalHead++];
          LocalHead &= (Tx_BUFF_SIZE_UART1-1);
        }

        MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
        __builtin_write_DISICTL(cpu_ipl_switchVar);/* stop mimic UART TX interrupt IPL level */
      }
    }
  }

  /* End of If: '<S531>/If' */

  /* Switch: '<S537>/FixPt Switch' incorporates:
   *  Constant: '<S536>/FixPt Constant'
   *  Constant: '<S537>/Constant'
   *  Sum: '<S536>/FixPt Sum1'
   *  UnitDelay: '<S532>/Output'
   */
  if ((uint8_t)(pmsm_smo_DW.Output_DSTATE_m + 1) > 119) {
    pmsm_smo_DW.Output_DSTATE_m = 0U;
  } else {
    pmsm_smo_DW.Output_DSTATE_m++;
  }

  /* End of Switch: '<S537>/FixPt Switch' */

  /* S-Function (MCHP_MCU_LOAD): '<S11>/MCU Load' */
  /* S-Function "MCHP_MCU_LOAD" Block: <S11>/MCU Load */
  pmsm_smo_DW.MCULoad = MCHP_MCULoadResult[0];
}

/* Model step function for TID2 */
void pmsm_smo_step2(void)              /* Sample time: [0.001s, 0.0s] */
{
  float rateLimiterRate;
  float rtb_Gain1_l;

  /* Gain: '<S1>/Gain4' incorporates:
   *  Gain: '<S9>/Gain'
   *  RateTransition: '<S9>/Rate Transition3'
   */
  rtb_Gain1_l = 1.52587891E-5F * (float)(uint16_t)mul_u32_hiSR_round(3435973837U,
    pmsm_smo_DW.RateTransition3_Buffer, 4U);

  /* RateLimiter: '<S522>/Rate Limiter1' */
  rateLimiterRate = rtb_Gain1_l - pmsm_smo_DW.PrevY;
  if (rateLimiterRate > 0.0005F) {
    rtb_Gain1_l = pmsm_smo_DW.PrevY + 0.0005F;
  } else if (rateLimiterRate < -0.0002F) {
    rtb_Gain1_l = pmsm_smo_DW.PrevY - 0.0002F;
  }

  pmsm_smo_DW.PrevY = rtb_Gain1_l;

  /* End of RateLimiter: '<S522>/Rate Limiter1' */

  /* Gain: '<S522>/Gain1' */
  rtb_Gain1_l *= 1516.34204F;

  /* Saturate: '<S522>/Saturation' */
  if (rtb_Gain1_l > 2274.51318F) {
    rtb_Gain1_l = 2274.51318F;
  } else if (rtb_Gain1_l < 261.799377F) {
    rtb_Gain1_l = 261.799377F;
  }

  /* End of Saturate: '<S522>/Saturation' */

  /* RateTransition generated from: '<S76>/Rate Transition1' */
  pmsm_smo_DW.RateTransition1_3_Buffer0 = rtb_Gain1_l;

  /* RateTransition: '<S511>/Rate Transition2' */
  pmsm_smo_DW.RateTransition2_Buffer0 = rtb_Gain1_l;
}

/* Model step function for TID3 */
void pmsm_smo_step3(void)              /* Sample time: [0.0015s, 0.0s] */
{
  /* Outputs for Enabled SubSystem: '<S81>/Run' incorporates:
   *  EnablePort: '<S89>/Enable'
   */
  if (pmsm_smo_DW.Run_MODE) {
    /* Outputs for Atomic SubSystem: '<S283>/Speed Control' */
    /* RateTransition: '<S89>/Rate Transition3' incorporates:
     *  RateTransition: '<S89>/Rate Transition'
     *  RateTransition: '<S89>/Rate Transition1'
     *  RateTransition: '<S89>/Rate Transition2'
     */
    pmsm_smo_SpeedControl(pmsm_smo_DW.RateTransition_Buffer, pmsm_smo_DW.RateTransition1_Buffer,
                          pmsm_smo_DW.RateTransition2_Buffer, &pmsm_smo_DW.RateTransition3_Buffer0[0],
                          &pmsm_smo_DW.RateTransition3_Buffer0[1], &pmsm_smo_DW.SpeedControl);

    /* End of Outputs for SubSystem: '<S283>/Speed Control' */
  }

  /* End of Outputs for SubSystem: '<S81>/Run' */
}

/* Model step function for TID4 */
void pmsm_smo_step4(void)              /* Sample time: [0.1s, 0.0s] */
{
  int32_t i;
  bool rtb_Compare_e;

  /* S-Function (MCHP_UART_Rx): '<S524>/UART Rx' */
  /* MCHP_UART_Rx Block: <S524>/UART Rx/Outputs */
  /* Circular Buffer implementation for UART1 */
  /* Circular Buffer implementation for UART1 */
  {                                    /* Start of Rx reception block */
    unsigned int n = 0;
    if (0U == U1STATbits.RXBE) {       /* Flush internal UART buffer */
      unsigned int Tmp;
      int cpu_ipl_switchVar;
      cpu_ipl_switchVar = __builtin_write_DISICTL(6);/* mimic Rx interrupt, disable Tx & thread switching interrupts */

      {
        unsigned int LocalTail = MCHP_UART1_Rx.tail;
        Tmp = ~(LocalTail - MCHP_UART1_Rx.head);/* head - tail - 1 */
        Tmp &= (Rx_BUFF_SIZE_UART1 - 1);
        /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_UART1)	<==> Rx_BUFF_SIZE_UART1 - (head - tail) - 1*/
        _U1RXIF = 0;                   /* Reset interrupt */
        while (0U == U1STATbits.RXBE) {
          if (0U != Tmp) {
            Tmp--;
            MCHP_UART1_Rx.buffer[LocalTail++] = ((uint8_t) U1RXB);
            LocalTail = (LocalTail) & (Rx_BUFF_SIZE_UART1 - 1);
          } else {
            do
              ((uint8_t) U1RXB);
            while (0U == U1STATbits.RXBE);
            break;
          }
        }

        MCHP_UART1_Rx.tail = LocalTail;/* push back volatile variable */
      }

      __builtin_write_DISICTL(cpu_ipl_switchVar);/* stop mimic UART RX interrupt IPL level */
    }

    {                                  /* Fill-in buffer */
      int i1;
      uint8_t *y0 = &pmsm_smo_DW.UARTRx_o2[0] ;
      for (i1 = 0; i1 < 8 ; i1++) {
        if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head) {
          y0[i1] = (uint8_t) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
          MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_UART1 - 1);
          n += 1;                      /* Number of character received */
        } else {                       /* Buffer is empty */
          if (1U == U1STATbits.RXFOIF )
            U1STATbits.RXFOIF = 0;     /* U1 Buffer Overflow cleared */
          break;                       /* Break loop if buffer is empty */
        }
      }                                /* end for loop */
    }                                  /* end code-block to fill-in buffer */

    pmsm_smo_DW.UARTRx_o1 = n;         /* Number of char received */
  }                                    /* end of Rx reception block */

  /* RelationalOperator: '<S528>/Compare' incorporates:
   *  Constant: '<S528>/Constant'
   *  DataTypeConversion: '<S524>/Data Type Conversion'
   */
  rtb_Compare_e = (pmsm_smo_DW.UARTRx_o1 >= 8);

  /* Outputs for Triggered SubSystem: '<S524>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S529>/Trigger'
   */
  if (rtb_Compare_e && (pmsm_smo_PrevZCX.TriggeredSubsystem_Trig_ZCE != POS_ZCSIG)) {
    for (i = 0; i < 8; i++) {
      /* SignalConversion generated from: '<S529>/In1' */
      pmsm_smo_DW.In1[i] = pmsm_smo_DW.UARTRx_o2[i];
    }
  }

  pmsm_smo_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Compare_e;

  /* End of Outputs for SubSystem: '<S524>/Triggered Subsystem' */

  /* RateTransition: '<S79>/Rate Transition15' */
  pmsm_smo_DW.RateTransition15_Buffer0 = pmsm_smo_DW.In1[3];

  /* Outputs for Enabled SubSystem: '<S7>/Downsample Averaged 2000 samples remove bias' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (pmsm_smo_DW.DownsampleAveraged2000samplesremovebias_MODE) {
    /* Gain: '<S12>/Gain2' incorporates:
     *  Gain: '<S12>/Gain1'
     *  RateTransition: '<S12>/Rate Transition3'
     */
    pmsm_smo_DW.Offset_Value_int32[0] = (int32_t)(mul_u32_loSR(274877907U,
      pmsm_smo_DW.RateTransition3_Buffer_b[0], 23U) >> 16);
    pmsm_smo_DW.Offset_Value_int32[1] = (int32_t)(mul_u32_loSR(274877907U,
      pmsm_smo_DW.RateTransition3_Buffer_b[1], 23U) >> 16);
  }

  /* End of Outputs for SubSystem: '<S7>/Downsample Averaged 2000 samples remove bias' */

  /* RateTransition: '<S7>/Rate Transition1' */
  pmsm_smo_DW.RateTransition1_Buffer_h[(pmsm_smo_DW.RateTransition1_ActiveBufIdx == 0) << 1] =
    pmsm_smo_DW.Offset_Value_int32[0];
  pmsm_smo_DW.RateTransition1_Buffer_h[1 + ((pmsm_smo_DW.RateTransition1_ActiveBufIdx == 0) << 1)] =
    pmsm_smo_DW.Offset_Value_int32[1];
  pmsm_smo_DW.RateTransition1_ActiveBufIdx = (int8_t)(pmsm_smo_DW.RateTransition1_ActiveBufIdx == 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S3>/Output'
   */
  rtb_Compare_e = (pmsm_smo_DW.Output_DSTATE_a != 0);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/LED_2' */
  LATCbits.LATC9 = rtb_Compare_e;

  /* Switch: '<S37>/FixPt Switch' incorporates:
   *  Constant: '<S36>/FixPt Constant'
   *  Sum: '<S36>/FixPt Sum1'
   *  UnitDelay: '<S3>/Output'
   */
  pmsm_smo_DW.Output_DSTATE_a = (uint8_t)((uint8_t)(pmsm_smo_DW.Output_DSTATE_a + 1) & 1);
}

/* Model step function for TID5 */
void pmsm_smo_step5(void)              /* Sample time: [0.5s, 0.0s] */
{
  bool rtb_DataTypeConversion_l;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  rtb_DataTypeConversion_l = (pmsm_smo_DW.Output_DSTATE_b != 0);

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/LED_1' */
  LATDbits.LATD5 = rtb_DataTypeConversion_l;

  /* Switch: '<S35>/FixPt Switch' incorporates:
   *  Constant: '<S34>/FixPt Constant'
   *  Sum: '<S34>/FixPt Sum1'
   *  UnitDelay: '<S2>/Output'
   */
  pmsm_smo_DW.Output_DSTATE_b = (uint8_t)((uint8_t)(pmsm_smo_DW.Output_DSTATE_b + 1) & 1);
}

/* Model initialize function */
void pmsm_smo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(double));

  /* Set task counter limit used by the static main program */
  (pmsm_smo_M)->Timing.TaskCounters.cLimit[0] = 1;
  (pmsm_smo_M)->Timing.TaskCounters.cLimit[1] = 10;
  (pmsm_smo_M)->Timing.TaskCounters.cLimit[2] = 20;
  (pmsm_smo_M)->Timing.TaskCounters.cLimit[3] = 30;
  (pmsm_smo_M)->Timing.TaskCounters.cLimit[4] = 2000;
  (pmsm_smo_M)->Timing.TaskCounters.cLimit[5] = 10000;

  /* Start for S-Function (MCHP_ADC_HS_12b): '<S6>/ADC HS 12b dsPICA1' */

  /* ADC configurations Commons to all ADC blocks */
  /* ADC frequency is 80.0MHz - Tad = 12.5ns */
  {
    /* Config AD1 */
    AD1CONBITS R_AD1CON = { 0 };

    R_AD1CON.BUFEN = 0U;               /* Analog Input Buffer Enable bit */
    R_AD1CON.TSTLOCK = 1;              /* Lock test mode */
    R_AD1CON.SIDL = 0;                 /* continue in Idle */
    R_AD1CON.VREFMOD = 1U;             /* Verf is 2.5 to 3V (val 0)  3.0 to 3.6V (val 1) */
    R_AD1CON.RPTCNT = 0;
    AD1CONbits = R_AD1CON;             /* Write AD1 Configuration bits */

    /* Config AD2 */
    AD2CONBITS R_AD2CON = { 0 };

    R_AD2CON.BUFEN = 0U;               /* Analog Input Buffer Enable bit */
    R_AD2CON.TSTLOCK = 1;              /* Lock test mode */
    R_AD2CON.SIDL = 0;                 /* continue in Idle */
    R_AD2CON.VREFMOD = 1U;             /* Verf is 2.5 to 3V (val 0)  3.0 to 3.6V (val 1) */
    R_AD2CON.RPTCNT = 0;
    AD2CONbits = R_AD2CON;             /* Write AD2 Configuration bits */
  }

  _AD2CH2IP = 2;                       /* Set Interrupt priority for tasking */
  _AD2CH2IF = 0;                       /* Reset pending interrupt */
  _AD2CH2IE = 1;                       /* Enable Interrupt which trig the base rate time step */

  /* Configure ADC1 Channels */
  {
    AD1CH0CONBITS R_AD1CH0CON = { 0 }; /* Channel 0 */

    R_AD1CH0CON.PINSEL = 0U;           /* ADC1 CH0 pin AN0 */
    R_AD1CH0CON.SAMC = 2U;             /* Sampling Time 56.25ns */
    R_AD1CH0CON.DIFF = 0U;             /* 1 for signed */
    R_AD1CH0CON.LEFT = 1U;             /* 1 for left aligned result */
    R_AD1CH0CON.TRG1SRC = 4U;          /* Trigger + offset: 0.0us */
    AD1CH0CONbits = R_AD1CH0CON;       /* Write ADC1 CH0 Config */
  }

  /* Configure ADC2 Channels */
  {
    AD2CH0CONBITS R_AD2CH0CON = { 0 }; /* Channel 0 */

    AD2CH1CONBITS R_AD2CH1CON = { 0 }; /* Channel 1 */

    AD2CH2CONBITS R_AD2CH2CON = { 0 }; /* Channel 2 */

    R_AD2CH0CON.PINSEL = 1U;           /* ADC2 CH0 pin AN1 */
    R_AD2CH0CON.SAMC = 2U;             /* Sampling Time 56.25ns */
    R_AD2CH0CON.DIFF = 0U;             /* 1 for signed */
    R_AD2CH0CON.LEFT = 1U;             /* 1 for left aligned result */
    R_AD2CH0CON.TRG1SRC = 4U;          /* Trigger + offset: 0.0us */
    AD2CH0CONbits = R_AD2CH0CON;       /* Write ADC2 CH0 Config */
    R_AD2CH1CON.PINSEL = 7U;           /* ADC2 CH1 pin AN7 */
    R_AD2CH1CON.SAMC = 2U;             /* Sampling Time 56.25ns */
    R_AD2CH1CON.DIFF = 0U;             /* 1 for signed */
    R_AD2CH1CON.LEFT = 1U;             /* 1 for left aligned result */
    R_AD2CH1CON.TRG1SRC = 4U;          /* Trigger + offset: 0.06875us */
    AD2CH1CONbits = R_AD2CH1CON;       /* Write ADC2 CH1 Config */
    R_AD2CH2CON.PINSEL = 9U;           /* ADC2 CH2 pin AN9 */
    R_AD2CH2CON.SAMC = 2U;             /* Sampling Time 56.25ns */
    R_AD2CH2CON.DIFF = 0U;             /* 1 for signed */
    R_AD2CH2CON.LEFT = 1U;             /* 1 for left aligned result */
    R_AD2CH2CON.TRG1SRC = 4U;          /* Trigger + offset: 0.1375us */
    AD2CH2CONbits = R_AD2CH2CON;       /* Write ADC2 CH2 Config */
  }

  /* ADC is enabled within last ADC block configuration code */

  /* Start for S-Function (MCHP_PWM_HS_FEP): '<S1>/PWM_HS_FEP' */

  /* Set initial Dead Time */
  PG1DTBITS R_PG1DT = { 0 };

  R_PG1DT.DTH = 3200U;                 /* 1.0E-6s */
  R_PG1DT.DTL = 3200U;                 /* 1.0E-6s */
  PG1DTbits = R_PG1DT;                 /* Write Dead Time */
  PG2DTBITS R_PG2DT = { 0 };

  R_PG2DT.DTH = 3200U;                 /* 1.0E-6s */
  R_PG2DT.DTL = 3200U;                 /* 1.0E-6s */
  PG2DTbits = R_PG2DT;                 /* Write Dead Time */
  PG3DTBITS R_PG3DT = { 0 };

  R_PG3DT.DTH = 3200U;                 /* 1.0E-6s */
  R_PG3DT.DTL = 3200U;                 /* 1.0E-6s */
  PG3DTbits = R_PG3DT;                 /* Write Dead Time */

  /* Set initial PWM Period */
  PG3PER = 79984U;                     /* 5.0E-5s */
  PG2PER = 79984U;                     /* 5.0E-5s */
  PG1PER = 79984U;                     /* 5.0E-5s */

  /* Set initial PWM Duty Cycles */
  PG3DC = 40000U;                      /* 2.5E-5s */
  PG2DC = 40000U;                      /* 2.5E-5s */
  PG1DC = 40000U;                      /* 2.5E-5s */

  /* Set Trigger (for ADC) initial values */
  PG1TRIGA = 0U;                       /* Trigger A (0.0s) for PWM 1 */

  /* Set PWM settings for each channels */
  {
    /* non volatile temp variable to precompute settings */
    PG1CONBITS R_PG1CON = { 0 };

    PG2CONBITS R_PG2CON = { 0 };

    PG3CONBITS R_PG3CON = { 0 };

    PG1IOCONBITS R_PG1IOCON = { 0 };

    PG2IOCONBITS R_PG2IOCON = { 0 };

    PG3IOCONBITS R_PG3IOCON = { 0 };

    PG1EVTBITS R_PG1EVT = { 0 };

    /* PGxCON */
    R_PG1CON.SOCS = 0;                 /* Start of Cycle is Local EOC */
    R_PG1CON.MSTEN = 1;                /* Broadcast set of UPDREQ & EOC to other PWMs */
    R_PG1CON.UPDMOD = 0;               /* PWM Update (00 next cycle, 01 Immedite) */
    R_PG1CON.MODSEL = 4 ;              /* PWM mode */
    R_PG1CON.CLKSEL = 1;               /* Clock Selection */
    R_PG1CON.ON = 0;                   /* PWM Generator is disabled */
    PG1CONbits = R_PG1CON;             /* -- WRITE CONFIG -- */
    R_PG2CON.SOCS = 1;                 /* Start of Cycle sync with 1-4 => PG1 PG4 - PG5 PG8 */
    R_PG2CON.UPDMOD = 2;               /* PWM Slave Update (2 next cycle, 3 immediate) */
    R_PG2CON.MODSEL = 4 ;              /* PWM mode */
    R_PG2CON.CLKSEL = 1;               /* Clock Selection */
    R_PG2CON.ON = 0;                   /* PWM Generator is disabled */
    PG2CONbits = R_PG2CON;             /* -- WRITE CONFIG -- */
    R_PG3CON.SOCS = 1;                 /* Start of Cycle sync with 1-4 => PG1 PG4 - PG5 PG8 */
    R_PG3CON.UPDMOD = 2;               /* PWM Slave Update (2 next cycle, 3 immediate) */
    R_PG3CON.MODSEL = 4 ;              /* PWM mode */
    R_PG3CON.CLKSEL = 1;               /* Clock Selection */
    R_PG3CON.ON = 0;                   /* PWM Generator is disabled */
    PG3CONbits = R_PG3CON;             /* -- WRITE CONFIG -- */

    /* PGxIOCON */
    R_PG1IOCON.PENL = 1;               /* Enable PWMxL */
    R_PG1IOCON.PENH = 1;               /* Enable PWMxH */
    PG1IOCONbits = R_PG1IOCON;         /* -- WRITE CONFIG -- */
    R_PG2IOCON.PENL = 1;               /* Enable PWMxL */
    R_PG2IOCON.PENH = 1;               /* Enable PWMxH */
    PG2IOCONbits = R_PG2IOCON;         /* -- WRITE CONFIG -- */
    R_PG3IOCON.PENL = 1;               /* Enable PWMxL */
    R_PG3IOCON.PENH = 1;               /* Enable PWMxH */
    PG3IOCONbits = R_PG3IOCON;         /* -- WRITE CONFIG -- */

    /* PGxEVT */
    R_PG1EVT.ADTR1EN1 = 1;             /* PWM1 TRIG A is trig src for ADC Trig 1 */
    PG1EVTbits = R_PG1EVT;             /* -- WRITE CONFIG -- */
  }

  {                                    /* Shared Settings for all PWM channels */
    PCLKCONBITS R_PCLKCON = { 0 };

    R_PCLKCON.MCLKSEL = 1;             /* Select Clkgen 5 as clock source for PWM */
    PCLKCONbits = R_PCLKCON;
  }

  /* Start for S-Function (MCHP_OP_AMP): '<S1>/Op-Amp' */
  {                                    /* Configure Op-Amp */
    AMP1CON1BITS R_AMP1CON1 = { 0 };

    AMP2CON1BITS R_AMP2CON1 = { 0 };

    AMP3CON1BITS R_AMP3CON1 = { 0 };

    R_AMP1CON1.AMPEN = 1;              /* Enable Op-Amp 1 */
    R_AMP1CON1.HPEN = 1;               /* Enable High Bandwidth */
    AMP1CON1bits = R_AMP1CON1;
    R_AMP2CON1.AMPEN = 1;              /* Enable Op-Amp 2 */
    R_AMP2CON1.HPEN = 1;               /* Enable High Bandwidth */
    AMP2CON1bits = R_AMP2CON1;
    R_AMP3CON1.AMPEN = 1;              /* Enable Op-Amp 3 */
    R_AMP3CON1.HPEN = 1;               /* Enable High Bandwidth */
    AMP3CON1bits = R_AMP3CON1;
  }

  /* Start for S-Function (MCHP_Master): '<S1>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <S1>/Microchip Master */

  /* Start for S-Function (MCHP_ADC_HS_12b): '<S6>/ADC HS 12b dsPICA2' */

  /* Configure ADC1 Channels */
  {
    AD1CH5CONBITS R_AD1CH5CON = { 0 }; /* Channel 5 */

    AD1CH6CONBITS R_AD1CH6CON = { 0 }; /* Channel 6 */

    AD1CH7CONBITS R_AD1CH7CON = { 0 }; /* Channel 7 */

    R_AD1CH5CON.PINSEL = 3U;           /* ADC1 CH5 pin AN3 */
    R_AD1CH5CON.SAMC = 4U;             /* Sampling Time 106.24999999999999ns */
    R_AD1CH5CON.DIFF = 0U;             /* 1 for signed */
    R_AD1CH5CON.LEFT = 1U;             /* 1 for left aligned result */
    R_AD1CH5CON.TRG1SRC = 4U;          /* Trigger + offset: 0.06875us */
    AD1CH5CONbits = R_AD1CH5CON;       /* Write ADC1 CH5 Config */
    R_AD1CH6CON.PINSEL = 6U;           /* ADC1 CH6 pin AN6 */
    R_AD1CH6CON.SAMC = 4U;             /* Sampling Time 106.24999999999999ns */
    R_AD1CH6CON.DIFF = 0U;             /* 1 for signed */
    R_AD1CH6CON.LEFT = 1U;             /* 1 for left aligned result */
    R_AD1CH6CON.TRG1SRC = 4U;          /* Trigger + offset: 0.1875us */
    AD1CH6CONbits = R_AD1CH6CON;       /* Write ADC1 CH6 Config */
    R_AD1CH7CON.PINSEL = 10U;          /* ADC1 CH7 pin AN10 */
    R_AD1CH7CON.SAMC = 4U;             /* Sampling Time 106.24999999999999ns */
    R_AD1CH7CON.DIFF = 0U;             /* 1 for signed */
    R_AD1CH7CON.LEFT = 1U;             /* 1 for left aligned result */
    R_AD1CH7CON.TRG1SRC = 4U;          /* Trigger + offset: 0.30624999999999997us */
    AD1CH7CONbits = R_AD1CH7CON;       /* Write ADC1 CH7 Config */
  }

  /* Configure ADC2 Channels */
  {
  }

  /* Enabling ADCs */
  AD1CONbits.ON = 1;                   /* enable ADC1 */
  AD2CONbits.ON = 1;                   /* enable ADC2 */
  while (AD1CONbits.ADRDY == 0) ;      /* wait when it is ready */
  while (AD2CONbits.ADRDY == 0) ;      /* wait when it is ready */

  /* Start for S-Function (MCHP_QEI): '<S1>/QEI1' */

  /* Initialize QEI 1 Peripheral */
  QEI1LEC = 0x00;                      /* Lower bound */
  QEI1GEC = 0x03E7;                    /* Upper bound */
  QEI1IOC = 0x7800;
  QEI1CON = 0x9800;

  /* Start for S-Function (MCHP_UART_Config): '<S1>/UART Configuration J11 - XPRO1' */

  /* MCHP_UART_Config Block for UART 2: <S1>/UART Configuration J11 - XPRO1/Initialize */
  U2BRG = 0x18;                        /* Baud rate: 2000000 (+0.00%) */
  U2CON = 0x828080B0;
  U2STAT = 0x15008000;

  /* Configure UART2 using Tx Interruption */
  _U2TXIP = 5;                         /*  Tx Interrupt priority set to 5 */
  _U2TXIF = 0;                         /*  */
  _U2TXIE = 1;                         /* Enable Interrupt */

  /* Configure UART2 Rx Interruption for <S1>/UART Configuration J11 - XPRO1 */
  _U2RXIP = 6;                         /* Rx Interrupt priority set to 6 */
  _U2RXIF = 0;                         /*  */
  _U2RXIE = 1;                         /* Enable Interrupt */

  /* Start for S-Function (MCHP_UART_Config): '<S1>/UART Configuration J16 - Micro USB' */

  /* MCHP_UART_Config Block for UART 1: <S1>/UART Configuration J16 - Micro USB/Initialize */
  U1BRG = 0xD9;                        /* Baud rate: 921600 (+0.01%) */
  U1CON = 0x8A808030;
  U1STAT = 0x8000;

  /* Configure UART1 using Tx Interruption */
  _U1TXIP = 5;                         /*  Tx Interrupt priority set to 5 */
  _U1TXIF = 0;                         /*  */
  _U1TXIE = 1;                         /* Enable Interrupt */

  /* Configure UART1 Rx Interruption for <S1>/UART Configuration J16 - Micro USB */
  _U1RXIP = 6;                         /* Rx Interrupt priority set to 6 */
  _U1RXIF = 0;                         /*  */
  _U1RXIE = 1;                         /* Enable Interrupt */

  /* Start for S-Function (MCHP_MCU_LOAD): '<S11>/MCU Load' */
  CCP1TMR = 0;   /* Initialize CCP TIMER 1 Value to 0. CCP TIMER 1 is enabled only when the mcu is not idle */
  pmsm_smo_PrevZCX.Delay3_Reset_ZCE = POS_ZCSIG;
  pmsm_smo_PrevZCX.TriggeredSubsystem_Trig_ZCE_h = UNINITIALIZED_ZCSIG;
  pmsm_smo_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Discrete-Time Integrator3' */
  pmsm_smo_DW.DiscreteTimeIntegrator3_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator3' */
  pmsm_smo_DW.DiscreteTimeIntegrator3_IC_LOADING_j = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S81>/Prepare' */
  /* SystemInitialize for Enabled SubSystem: '<S88>/Init_Lock' */
  /* SystemInitialize for Enabled SubSystem: '<S93>/Lock' */
  /* Start for Constant: '<S99>/Constant2' */
  pmsm_smo_DW.Constant2_d[0] = 0.3F;
  pmsm_smo_DW.Constant2_d[1] = 0.2F;
  pmsm_smo_DW.Constant2_d[2] = 0.2F;

  /* End of SystemInitialize for SubSystem: '<S93>/Lock' */
  /* End of SystemInitialize for SubSystem: '<S88>/Init_Lock' */

  /* SystemInitialize for Enabled SubSystem: '<S88>/Spin motor' */
  /* InitializeConditions for Delay: '<S113>/Delay4' */
  pmsm_smo_DW.Delay4_DSTATE[0] = true;
  pmsm_smo_DW.Delay4_DSTATE[1] = true;

  /* InitializeConditions for Delay: '<S113>/Delay2' */
  pmsm_smo_DW.Delay2_DSTATE_j = 5.0F;

  /* SystemInitialize for Enabled SubSystem: '<S94>/Theta_check' */
  /* Start for Constant: '<S109>/Constant10' */
  pmsm_smo_DW.bitsForTID0.Constant10_a = true;

  /* End of SystemInitialize for SubSystem: '<S94>/Theta_check' */
  /* End of SystemInitialize for SubSystem: '<S88>/Spin motor' */
  /* End of SystemInitialize for SubSystem: '<S81>/Prepare' */
  /* SystemInitialize for Enabled SubSystem: '<S7>/Downsample Averaged 2000 samples remove bias' */
  /* SystemInitialize for Gain: '<S12>/Gain2' incorporates:
   *  Outport: '<S12>/Out1'
   */
  pmsm_smo_DW.Offset_Value_int32[0] = 32768;
  pmsm_smo_DW.Offset_Value_int32[1] = 32768;

  /* End of SystemInitialize for SubSystem: '<S7>/Downsample Averaged 2000 samples remove bias' */
}

/* Model terminate function */
void pmsm_smo_terminate(void)
{
  /* Terminate for S-Function (MCHP_PWM_HS_FEP): '<S1>/PWM_HS_FEP' */

  /* Stop PWMs */
  PG1CONbits.ON = 0;                   /* disable PWM Generator 1 */
  PG2CONbits.ON = 0;                   /* disable PWM Generator 2 */
  PG3CONbits.ON = 0;                   /* disable PWM Generator 3 */

  /* Terminate for S-Function (MCHP_UART_Config): '<S1>/UART Configuration J11 - XPRO1' */
  while (0U == U2STATbits.TXMTIF) ;    /* Wait until all byte are sent */

  /* Terminate for S-Function (MCHP_UART_Config): '<S1>/UART Configuration J16 - Micro USB' */
  while (0U == U1STATbits.TXMTIF) ;    /* Wait until all byte are sent */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
