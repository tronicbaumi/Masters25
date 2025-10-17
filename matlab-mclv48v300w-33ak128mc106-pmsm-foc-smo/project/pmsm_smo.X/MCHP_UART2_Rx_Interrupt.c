#include "pmsm_smo.h"
#include "pmsm_smo_private.h"

MCHP_UART2_RxStr MCHP_UART2_Rx = { .head = 0, .tail = 0 };/* UART2 Rx FIFO */

void __attribute__((__interrupt__,__context__)) _U2RXInterrupt(void)
{
  unsigned int Tmp;
  __asm__ volatile ("INC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic increment of mcuFlagRecursion */
  CCP1CON1bits.ON = 1;                 /* (re) start Timer */
  Tmp = ~(MCHP_UART2_Rx.tail - MCHP_UART2_Rx.head);/* head - tail - 1 */
  Tmp &= (Rx_BUFF_SIZE_UART2-1);
  /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_UART2) ; tmp <~ Rx_BUFF_SIZE_UART2 - (head - tail) - 1*/
  _U2RXIF = 0;                         /*  */
  while (0U == U2STATbits.RXBE) {
    if (Tmp--) {
      MCHP_UART2_Rx.buffer[MCHP_UART2_Rx.tail] = ((uint8_t) U2RXB);
      MCHP_UART2_Rx.tail = (MCHP_UART2_Rx.tail+1) & (Rx_BUFF_SIZE_UART2-1);
    } else {
      do
        ((uint8_t) U2RXB);
      while (0U == U2STATbits.RXBE);
      break;
    }
  }

  if (1U == U2STATbits.RXFOIF )
    U2STATbits.RXFOIF = 0;             /* U2 Buffer Overflow cleared */
  __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */
  if (mcuFlagRecursion == 0) {
    CCP1CON1bits.ON = 0;               /* Stop Timer */
  }
}
