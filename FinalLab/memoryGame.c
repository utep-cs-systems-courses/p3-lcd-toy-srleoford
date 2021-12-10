#include <msp430.h>
#include <libTimer.h>
#include "draw_shapes.h"
#include "buzzer.h"
#include "switchesLCD.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "game.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main(void)
{
  configureClocks();
  lcd_init();
  clearScreen(bgColor);
  init_shapes();
  buzzer_init();
  switch_init();
  init_game();
  
  enableWDTInterrupts();

  or_sr(0x18);	/**< CPU off , GIE on*/
}
