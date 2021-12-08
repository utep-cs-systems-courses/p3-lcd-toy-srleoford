#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "switchesLCD.h"
#include "buzzer.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  static int count = 0;
  count++;
  if (count >= 21){
    fanfare();
    count = 0;
  }
}
