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
 * File: pmsm_smo_main.c
 *
 * Code generated for Simulink model 'pmsm_smo'.
 *
 * Model version                  : 14.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul 24 11:27:34 2025
 */

/* Set Fuses Options */

#pragma config FWDT_WDTEN = SW
#pragma config FICD_JTAGEN = OFF

#define MCHP_isMainFile
#include "pmsm_smo.h"
#include "pmsm_smo_private.h"

/* Microchip Global Variables */
volatile uint16_t MCHP_MCULoadResult[1] __attribute__ ((near)) ;
volatile uint16_t MCHP_MCULoadPreviousTimerValue[1] __attribute__ ((near)) ;
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
} volatile MCHP_MCU_Overload;

volatile unsigned int mcuFlagRecursion __attribute__ ((near)) = 0;/* Solver mode : MultiTasking */
int main()
{
  /* Initialize model */
  union {
    uint32_t u32 ;
    OSCCTRLBITS bits;
  } volatile U_OSCCTRL;

  U_OSCCTRL.u32 = ((OSCCTRL >> 8) & 0x0000E7);/* Keep track of current Oscillators runnings */
  OSCCFGBITS R_OSCCFG = { 0 };

  U_OSCCTRL.bits.POSCEN = 1;           /* Enable Primary Crystal/Resonator Oscillator */
  R_OSCCFG.POSCIOFNC = 0;              /* CLKO output disabled */
  R_OSCCFG.POSCMD = 0;                 /* External Clock */
  OSCCFGbits = R_OSCCFG;               /* Write Oscillator Configuration  */
  OSCCTRL = U_OSCCTRL.u32;             /* Enable Oscillators */

  /* Switch to Selected Oscillator */
  CLK1CONBITS R_CLK1CON = { 0 };

  R_CLK1CON.ON = 1;
  R_CLK1CON.NOSC = 3;                  /* Select clock source Primary  */
  R_CLK1CON.OSWEN = 1;                 /* Enable clock switching  */
  CLK1DIVBITS R_CLK1DIV = { .INTDIV = 0, .FRACDIV = 0 };/* No 1:1 division on CLK1 */

  CLK1DIVbits = R_CLK1DIV;
  R_CLK1CON.DIVSWEN = 1;
  CLK1CONbits = R_CLK1CON;             /* Write Config, switching to Primary */
  while (CLK1CONbits.OSWEN) ;          /* wait for sys_clk switching completed */

  /*---------------------------*/
  /* --- PLL Configuration --- */
  /*---------------------------*/
  /*  PLL Clock source FPLLI set to Primary run at 8.0E+6 Hz      */
  /*                                                                     */
  /*  FOSC (Oscillator output frequency),FCY (Device Operating Frequency)*/
  /*  FVCO (VCO Output Frequency )is:                                    */
  /*          ( FPLLI * M)                                               */
  /*  FVCO = -------------- = 1.2E+9 Hz                                  */
  /*                N1                                                   */
  /*                                                                     */
  /*          (FPLLI * M)                                                */
  /*  FPLL = --------------  = 2.0E+8 Hz                                 */
  /*         (N1 * N2 * N3)                                              */
  /*                                                                     */
  /*  Fsys  = 200.0MHz                                                   */
  /*                                                                     */
  /*  M = PLL1DIVbits.PLLFBDIV = 150 (PLL feedback divider :PLL multiplier)*/
  /*  N1 = PLL1DIVbits.PLLPRE = 1 (PLL Phase detector: PLL pre-scaler)*/
  /*  N2 = PLL1DIVbits.POSTDIV1 = 6 (PLL output divider 1)           */
  /*  N3 = PLL1DIVbits.POSTDIV2 = 1 (PLL output divider 2)           */
  /*---------------------------*/
  PLL1DIVBITS R_PLL1DIV = { 0 };

  R_PLL1DIV.PLLFBDIV = 150;            /* M = 150 */
  R_PLL1DIV.PLLPRE = 1;                /* N1 = 1 */
  R_PLL1DIV.POSTDIV1 = 6;              /* N2 = 6 */
  R_PLL1DIV.POSTDIV2 = 1;              /* N3 = 1 */
  PLL1DIVbits = R_PLL1DIV;             /* Write PLL config (16815713) */
  OSCCTRLbits.PLL1EN = 1;              /* Enable PLL 1 */
  PLL1CONBITS R_PLL1CON = { 0 };

  R_PLL1CON.NOSC = 3;                  /* PLL clock source is Primary */
  R_PLL1CON.ON = 1;
  R_PLL1CON.OSWEN = 1;                 /* Start Clock switch */
  PLL1CONbits = R_PLL1CON;             /* Write PLL1CON register */
  while (PLL1CONbits.OSWEN) ;          /* Wait for end of clock switch */
  PLL1CONbits.PLLSWEN = 1;             /* Enable PLL feedback multiplier */
  while (PLL1CONbits.PLLSWEN == 1) ;
  PLL1CONbits.FOUTSWEN = 1;            /* Enable Feedback Divider */

  /* Configure Pins as Analog or Digital */
  /* Configure Remappables Pins */
  RPINR7 = 0x2827;
  RPINR9 = 0x003D002C;
  RPOR10 = 0x00090000;
  RPOR14 = 0x0B000000;

  /* Configure Digitals I/O directions */
  TRISC = 0xFDFE;                      /* Port input (1) / output (0) */
  TRISD = 0xFFDF;                      /* Port input (1) / output (0) */

  /* Continue clock settings */
  while (PLL1CONbits.PLLSWEN == 1) ;
  while (PLL1CONbits.CLKRDY == 0) ;
  R_CLK1CON.NOSC = 5;                  /* Select PLL1 Fout source */
  R_CLK1CON.OSWEN = 1;                 /* Enable clock switching  */
  CLK1CONbits = R_CLK1CON;             /* Write Config, switching to Primary */

  /* Configure Peripherals clocks */
  {
    /* Temp variables */
    CLK5DIVBITS R_CLK5DIV = { .INTDIV = 0, .FRACDIV = 0 };/* 1:1.0 division on CLK5 */

    CLK5CONBITS R_CLK5CON = { 0 };

    CLK6DIVBITS R_CLK6DIV = { .INTDIV = 1, .FRACDIV = 256 };/* 1:2.5 division on CLK6 */

    CLK6CONBITS R_CLK6CON = { 0 };

    CLK8DIVBITS R_CLK8DIV = { .INTDIV = 0, .FRACDIV = 0 };/* 1:1.0 division on CLK8 */

    CLK8CONBITS R_CLK8CON = { 0 };

    CLK9DIVBITS R_CLK9DIV = { .INTDIV = 0, .FRACDIV = 0 };/* 1:1.0 division on CLK9 */

    CLK9CONBITS R_CLK9CON = { 0 };

    CLK12DIVBITS R_CLK12DIV = { .INTDIV = 0, .FRACDIV = 0 };/* 1:1.0 division on CLK12 */

    CLK12CONBITS R_CLK12CON = { 0 };

    /* clkgen5 ( 200.0 MHz) used for PWM  */
    CLK5DIVbits = R_CLK5DIV;           /* Write Integer and fractional Divider (1:1.0) */
    R_CLK5CON.ON = 1;
    R_CLK5CON.DIVSWEN = 1;
    R_CLK5CON.NOSC = 5;                /* input oscillator is  Primary  */
    R_CLK5CON.OSWEN = 1;               // enable PLL switch
    CLK5CONbits = R_CLK5CON;           /* Write clkgen5 config, switching to Primary */

    /* clkgen6 ( 80.0 MHz) used for ADC  */
    CLK6DIVbits = R_CLK6DIV;           /* Write Integer and fractional Divider (1:2.5) */
    R_CLK6CON.ON = 1;
    R_CLK6CON.DIVSWEN = 1;
    R_CLK6CON.NOSC = 5;                /* input oscillator is  Primary  */
    R_CLK6CON.OSWEN = 1;               // enable PLL switch
    CLK6CONbits = R_CLK6CON;           /* Write clkgen6 config, switching to Primary */

    /* clkgen8 ( 200.0 MHz) used for UART  */
    CLK8DIVbits = R_CLK8DIV;           /* Write Integer and fractional Divider (1:1.0) */
    R_CLK8CON.ON = 1;
    R_CLK8CON.DIVSWEN = 1;
    R_CLK8CON.NOSC = 5;                /* input oscillator is  Primary  */
    R_CLK8CON.OSWEN = 1;               // enable PLL switch
    CLK8CONbits = R_CLK8CON;           /* Write clkgen8 config, switching to Primary */

    /* clkgen9 ( 200.0 MHz) used for SPI  */
    CLK9DIVbits = R_CLK9DIV;           /* Write Integer and fractional Divider (1:1.0) */
    R_CLK9CON.ON = 1;
    R_CLK9CON.DIVSWEN = 1;
    R_CLK9CON.NOSC = 5;                /* input oscillator is  Primary  */
    R_CLK9CON.OSWEN = 1;               // enable PLL switch
    CLK9CONbits = R_CLK9CON;           /* Write clkgen9 config, switching to Primary */

    /* clkgen12 ( 200.0 MHz) used for CPP_REFO1  */
    CLK12DIVbits = R_CLK12DIV;         /* Write Integer and fractional Divider (1:1.0) */
    R_CLK12CON.ON = 1;
    R_CLK12CON.DIVSWEN = 1;
    R_CLK12CON.NOSC = 5;               /* input oscillator is  Primary  */
    R_CLK12CON.OSWEN = 1;              // enable PLL switch
    CLK12CONbits = R_CLK12CON;         /* Write clkgen12 config, switching to Primary */
  }

  while (CLK1CONbits.OSWEN) ;          /* wait for sys_clk switching completed */
  while (CLK5CONbits.OSWEN) ;          /* Wait for clkgen5 (PWM) switch */
  while (CLK6CONbits.OSWEN) ;          /* Wait for clkgen6 (ADC) switch */
  while (CLK8CONbits.OSWEN) ;          /* Wait for clkgen8 (UART) switch */
  while (CLK9CONbits.OSWEN) ;          /* Wait for clkgen9 (SPI) switch */
  while (CLK12CONbits.OSWEN) ;         /* Wait for clkgen12 (CPP_REFO1) switch */
  while (CLK5CONbits.DIVSWEN) ;        /* Wait for clkgen5 (PWM) divider */
  while (CLK6CONbits.DIVSWEN) ;        /* Wait for clkgen6 (ADC) divider */
  while (CLK8CONbits.DIVSWEN) ;        /* Wait for clkgen8 (UART) divider */
  while (CLK9CONbits.DIVSWEN) ;        /* Wait for clkgen9 (SPI) divider */
  while (CLK12CONbits.DIVSWEN) ;       /* Wait for clkgen12 (CPP_REFO1) divider */

  /* Initialize model */
  pmsm_smo_initialize();

  /* Configure Timers */
  /* --- SCC TIMER 1 --- */
  CCP1CON1 = 0;                        /* Stop SCC Timer 1 and resets control register */
  CCP1PR = 0xFFFF;                     /* Period */
  CCP1RB = 0xFFFF;                     /* Trigger Event in sync with Period */
  CCP1CON1 = 0x0104;                   /* Set timer Prescaler and Mode Output Capture, use clkgen 12 */

  /* Enable Time-step */
  /* Turning ON the PWM Generator 1;
     Thus starting all the PWM modules in unison */
  PG2CONbits.ON = 1;                   /* Enable PWM Generator 2 */
  PG3CONbits.ON = 1;                   /* Enable PWM Generator 3 */
  PG1CONbits.ON = 1;                   /* Enable PWM 1, update sync with all PWMs */

  /* Main Loop */
  for (;;) ;

  /* Terminate model */
  pmsm_smo_terminate();
}                                      /* end of main() */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
