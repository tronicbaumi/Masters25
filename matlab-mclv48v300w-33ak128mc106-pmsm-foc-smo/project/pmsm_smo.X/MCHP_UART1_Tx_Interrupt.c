#include "pmsm_smo.h"
#include "pmsm_smo_private.h"

/* Declare UART1 Tx Circular Buffer Structure */
MCHP_UART1_TxStr MCHP_UART1_Tx = { .head = 0, .tail = 0 };/* UART1 Tx FIFO */

void __attribute__((__interrupt__,__context__)) _U1TXInterrupt(void)
{
  unsigned int LocalHead;
  __asm__ volatile ("INC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic increment of mcuFlagRecursion */
  CCP1CON1bits.ON = 1;                 /* (re) start Timer */
  LocalHead = MCHP_UART1_Tx.head;  /* Head is a volatile variable. Use local variable to speed-up execution */
  _U1TXIF = 0;                         /* Clear Interrupt Flag */
  while ((0U == U1STATbits.TXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
  {
    U1TXB = MCHP_UART1_Tx.buffer[LocalHead++];
    LocalHead &= (Tx_BUFF_SIZE_UART1-1);
  }

  MCHP_UART1_Tx.head = LocalHead;      /* Push back volatile variable */
  __asm__ volatile ("DEC %[MyVar]" : [MyVar] "+m" (mcuFlagRecursion) );/* ensure atomic decrement of mcuFlagRecursion */
  if (mcuFlagRecursion == 0) {
    CCP1CON1bits.ON = 0;               /* Stop Timer */
  }
}
