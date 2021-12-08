#include <stdlib.h>
#include "game.h"
#include "draw_shapes.h"
#include "buzzer.h"

int inputShapes[10];
int gameShapes[10];
int matchShapes[10];

/* Keeps track of what level the player is on */
int level;

/* Signals when the game needs to show the shapes to the player */
int presentShapes;

/* Start new game, reinitialize with new random shapes into gameShapes */
int init_game(void){
  for (int i = 0; i < 10; i++){
    inputShapes[i] = -1;
    gameShapes[i] = (rand() % 4)+1;
    matchShapes[i] = -1;
  }
  level = 1;
  presentShapes = 1;

  draw_button_rectangle();
  draw_button_triangle();
  draw_button_X();
  draw_button_circle();

  draw_matching_shapes(matchShapes);
  clear_lvl();
  draw_scoreboard(matchShapes);
}

void storeShape(int input){
  inputShapes[level-1] = input;
}

void level_up(void){
  level++;
}

/* Checks for matched shapes before the level changes */
void check_match_shapes(void){
  for (int i = 0; i < level; i++)
    if (inputShapes[i] == gameShapes[i])
      matchShapes[i] = 1;
    else
      matchShapes[i] = 0;
}



