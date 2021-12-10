#include <stdlib.h>
#include "game.h"
#include "draw_shapes.h"
#include "buzzer.h"

int inputShapes[10];
int gameShapes[10] = {1, 2, 0, 0, 1, 3, 2, 1, 1, 0};
int matchShapes[10];

/* Keeps track of what level the player is on */
int level;

/* Signals when the game needs to show the shapes to the player */
int presentShapes;

/* Index needed for storing players' shapes */
int pIndex;

/* Start new game, reinitialize with new random shapes into gameShapes */
int init_game(void){
  for (int i = 0; i < 10; i++){
    inputShapes[i] = -1;
    matchShapes[i] = -1;
  }
  
  level = 1;
  pIndex = 0;
  presentShapes = 1;

  draw_button_rectangle();
  draw_button_triangle();
  draw_button_X();
  draw_button_circle();

  draw_matching_shapes(matchShapes);
  draw_scoreboard(matchShapes);
}

void storeShape(int input){
  inputShapes[pIndex++] = input;
}

void level_up(void){
  level++;
  for (int i = 0; i < level; i++)
    inputShapes[i] = matchShapes[i] = -1;
}

/* Checks for match for the moment of input for buzzer */
int isMatch(){
  return inputShapes[pIndex] == gameShapes[pIndex];
}

/* Checks for matched shapes before the level changes */
void check_match_shapes(void){
  for (int i = 0; i < level; i++){
    if (inputShapes[i] == gameShapes[i])
      matchShapes[i] = 1;
    else
      matchShapes[i] = 0;
  }
}

void update_game(void){
  check_match_shapes();
  draw_matching_shapes(matchShapes);
  draw_scoreboard(matchShapes);
  
  if (pIndex == level-1){
    level_up();
    pIndex = 0;
    draw_matching_shapes(matchShapes);
    draw_scoreboard(matchShapes);
  }
}


