#include <stdlib.h>
#include "draw_shapes.h"
#include "buzzer.h"

extern int inputShapes[10];
extern int gameShapes[10];
extern int matchShapes[10];

/* Keeps track of what level the player is on */
extern int level;

/* Signals when the game needs to show the shapes to the player */
extern int presentShapes;

/* Start new game, reinitialize with new random shapes into gameShapes */
int init_game(void);

/* Takes in input from player and stores into inputShapes */
void storeShape(int input);

/* Increases level of the game */
void level_up(void);

/* Checks for matching shapes of input & game shapes*/
void check_match_shapes(void);
