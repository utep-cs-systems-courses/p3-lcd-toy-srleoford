#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "switchesLCD.h"
#include "buzzer.h"
#include "game.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void __interrupt_vec(WDT_VECTOR) WDT(){
  
  static u_int musicCount = 0;
  static u_int gameCount = 0;
  static u_int gameIndex = 0;
  static u_int buzzCount = 0;

  buzzCount++;
  if (buzzCount >= 10){
    wrongBuzz();
    rightBuzz();
    buzzCount = 0;
  }
  
  musicCount++;
  if (musicCount >= 21){
      fanfare();
      musicCount = 0;
    }

  gameCount++;
  if (presentShapes && level < 11){
    if (gameCount == 1)
  	draw_lvl_shapes(gameShapes[gameIndex++]);
    if (gameCount >= 20)
      clear_lvl();
    if (gameCount >= 25){
      gameCount = 0;
      if (gameIndex == level)
  	presentShapes = gameIndex = 0;
    }
  }
}
