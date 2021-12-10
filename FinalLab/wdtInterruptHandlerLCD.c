#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "switchesLCD.h"
#include "buzzer.h"
#include "game.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  /* const u_int secondLimit = 250; */
  /* static u_int musicCount = 0; */
  /* static u_int gameCount = 0; */
  /* static u_int gameIndex = 0; */

  /* musicCount++; */
  /* gameCount++; */
  
  /* if (presentShapes){ */
  /*   if (gameCount == 1) */
  /*     draw_lvl_shapes(gameShapes[gameIndex++]); */
  /*   if (musicCount >= 21){ */
  /*     fanfare(); */
  /*     musicCount = 0; */
  /*   } */
  /*   if (gameCount >= 125) */
  /*     clear_lvl(); */
  /*   if (gameCount >= secondLimit) */
  /*     gameCount = 0; */
  /* } */
  /* else */
  /*   if (musicCount >= 21){ */
  /*     fanfare(); */
  /*     musicCount = 0; */
  /*   } */
}
