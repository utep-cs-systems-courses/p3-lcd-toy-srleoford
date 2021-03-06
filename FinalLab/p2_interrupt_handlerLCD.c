#include <msp430.h>
#include "switchesLCD.h"

/* Switches are on P2 (S1, S2, S3, S4) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      // did a button cause this interrupt?
    P2IFG &= ~SWITCHES;		      // clear pending sw interrupts
    switch_interrupt_handler();	      // single handler for all switches
  }
}
