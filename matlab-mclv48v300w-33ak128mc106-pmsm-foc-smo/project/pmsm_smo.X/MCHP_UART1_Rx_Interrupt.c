#include "pmsm_smo.h"
#include "pmsm_smo_private.h"

MCHP_UART1_RxStr MCHP_UART1_Rx = { .head = 0, .tail = 0 };/* UART1 Rx FIFO */

void __attribute__((__interrupt__,__context__)) _U1RXInterrupt(void)
{
  unsigned int Tmp;
  __asm__ volatile ("INC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic increment of mcuFlagRecursion */
  CCP1CON1bits.ON = 1;                 /* (re) start Timer */
  Tmp = ~(MCHP_UART1_Rx.tail - MCHP_UART1_Rx.head);/* head - tail - 1 */
  Tmp &= (Rx_BUFF_SIZE_UART1-1);
  /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_UART1) ; tmp <~ Rx_BUFF_SIZE_UART1 - (head - tail) - 1*/
  _U1RXIF = 0;                         /*  */
  while (0U == U1STATbits.RXBE) {
    if (Tmp--) {
      MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.tail] = ((uint8_t) U1RXB);
      MCHP_UART1_Rx.tail = (MCHP_UART1_Rx.tail+1) & (Rx_BUFF_SIZE_UART1-1);
    } else {
      do
        ((uint8_t) U1RXB);
      while (0U == U1STATbits.RXBE);
      break;
    }
  }

  if (1U == U1STATbits.RXFOIF )
    U1STATbits.RXFOIF = 0;             /* U1 Buffer Overflow cleared */
  __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */
  if (mcuFlagRecursion == 0) {
    CCP1CON1bits.ON = 0;               /* Stop Timer */
  }
}
