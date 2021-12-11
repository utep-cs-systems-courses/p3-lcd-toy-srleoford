#include <msp430.h>
#include "game.h"

int is_level_done(void){
  return (pIndex == level);
}
