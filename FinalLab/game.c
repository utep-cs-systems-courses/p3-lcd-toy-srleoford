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

/* Index for displaying lvl shapes */
int gameIndex;

/* Keeps track of game score across all levels */
int gameScore;

/* State for the music to sound off */
int musicState, buzzRightState, buzzWrongState;

/* Start new game, reinitialize with new random shapes into gameShapes */
int init_game(void){
  for (int i = 0; i < 10; i++)
    inputShapes[i] = matchShapes[i] = -1;

  gameScore = pIndex = gameIndex = musicState = buzzRightState = buzzWrongState = 0;
  level = 1;
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
  update_score();
  level++;
  for (int i = 0; i < level; i++)
    inputShapes[i] = matchShapes[i] = -1;
  pIndex = gameIndex = 0;
  presentShapes = 1;
}

/* Checks for matched shapes before the level changes */
void check_match_shapes(void){
  for (int i = 0; i < level; i++){
    if (inputShapes[i] == gameShapes[i] && inputShapes[i] != -1){
      matchShapes[i] = 1;
      buzzRightState = 1;
    }
    if (inputShapes[i] != gameShapes[i] && inputShapes[i] != -1){
      matchShapes[i] = 0;
      buzzWrongState = 1;
    }
  }
}

/* int is_level_done(void){ */
/*   return pIndex == level; */
/* } */

void update_score(void){
  for (int i = 0; i < level; i++)
    if (matchShapes[i] == 1)
      gameScore += 10;
}

void update_game(void){
  check_match_shapes();
  draw_matching_shapes(matchShapes);
  
  if (is_level_done()){
    level_up();
    draw_scoreboard(matchShapes);
    draw_matching_shapes(matchShapes);
  }
  
  if (gameScore == 550){
    musicState = 1;
    for (int i = 0; i < 10; i++)
      matchShapes[i] = 1;
    draw_matching_shapes(matchShapes);
    fillRectangle(0, 125, screenWidth, 30, bgColor);
    draw_congrats();
  }
}


