#include <msp430.h>
#include "switchesLCD.h"
#include "buzzer.h"
#include "draw_shapes.h"
#include "game.h"

char switch1_state_down, switch2_state_down, switch3_state_down, switch4_state_down, switch_state_changed;

/* update he interrupt sense bits so 
   interrupts are fired when a switch changes
   position */
static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);	// if switch up, sense down
  P2IES &= (p2val | ~SWITCHES);	// if switch down, sense up
  return p2val;
}

/* setup switches */
void switch_init(){  
  P2REN |=  SWITCHES;		// enables resistors for switches
  P2IE  |=  SWITCHES;		// enable interrupts from switches
  P2OUT |=  SWITCHES;		// turn on switches so we can read them
  P2DIR &= ~SWITCHES;		// set switch pins to input
  switch_update_interrupt_sense();
  //game_update();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  // Switch reads 0 when down, we want to reverse
  // that so the state variable is 1 when down
  switch1_state_down = (p2val & SW1) ? 0 : 1;
  switch2_state_down = (p2val & SW2) ? 0 : 1;
  switch3_state_down = (p2val & SW3) ? 0 : 1;
  switch4_state_down = (p2val & SW4) ? 0 : 1;
  
  if (switch1_state_down){
    draw_button_outline_rectangle();
  }
  else {
    erase_button_outline_rectangle();
  }
  
  if (switch2_state_down){
    draw_button_outline_triangle();
  }
  else{
    erase_button_outline_triangle();
  }

  if (switch3_state_down){
    draw_button_outline_X();
  }
  else{
    erase_button_outline_X();
  }

  if (switch4_state_down){
    draw_button_outline_circle();
  }
  else{
    erase_button_outline_circle();
  }
}
