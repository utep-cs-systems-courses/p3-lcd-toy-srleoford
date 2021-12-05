#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "buzzer.h"
#include "switchesLCD.h"

int gameShapes[] = {1, 1, 0, 1, 1, 1, 0, 1, -1, -1};

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main(void)
{
  configureClocks();
  lcd_init();
  clearScreen(COLOR_GRAY);
  init_shapes();
  buzzer_init();
  switch_init();
  
  draw_button_triangle();
  draw_button_circle();
  draw_button_rectangle();
  draw_button_X();

  //draw_matching_shapes(gameShapes);

  //draw_scoreboard(gameShapes);
  
  enableWDTInterrupts();

  or_sr(0x18);	/**< CPU off , GIE on*/
}
