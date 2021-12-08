#include <msp430.h>
#include <libTimer.h>
#include "draw_shapes.h"
#include "buzzer.h"
#include "switchesLCD.h"
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

  draw_button_rectangle();
  draw_button_triangle();
  draw_button_X();
  draw_button_circle();

  draw_matching_shapes(matchShapes);
  clear_lvl();
  draw_scoreboard(matchShapes);
  
  enableWDTInterrupts();

  or_sr(0x18);	/**< CPU off , GIE on*/
}
