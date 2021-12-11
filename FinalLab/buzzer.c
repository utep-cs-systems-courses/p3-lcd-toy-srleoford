#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switchesLCD.h"

static enum {wrong = 8000, right = 2000, Ab = 4200, c = 3323, Bb = 3730} notes;

extern int musicState, buzzRightState, buzzWrongState;


void buzzer_init(){
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void fanfare(void){
  
  switch (musicState){
  case 0:
    buzzer_set_period(0);
    break;
  case 1: case 3: case 5: case 7: case 8: case 9: case 10:
  case 11: case 25: case 26: case 27: case 31: case 32:
  case 33: case 34: case 35: case 36: case 37:case 38:
  case 39: case 40: case 41:
    buzzer_set_period(c);
    musicState++;
    break;
  case 13: case 14: case 15: case 16: case 17:
    buzzer_set_period(Ab);
    musicState++;
    break;
  case 19: case 20: case 21: case 22: case 23: case 29:
    buzzer_set_period(Bb);
    musicState++;
    break;
  case 2: case 4: case 6: case 12: case 18: case 24: case 28:
  case 30: case 42: 
    buzzer_set_period(0);
    musicState++;
    break;
  default:
    musicState = 0;
    break;
  }
}

void wrongBuzz(void){
  switch(buzzWrongState){
  case 1:
    buzzer_set_period(wrong);
    buzzWrongState++;
    break;
  default:
    buzzer_set_period(0);
    buzzWrongState = 0;
    break;
  }
}

void rightBuzz(void){
  switch(buzzRightState){
  case 1:
    buzzer_set_period(right);
    buzzRightState++;
    break;
  default:
    buzzer_set_period(0);
    buzzRightState = 0;
    break;
  }
}
