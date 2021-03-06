#include "draw_shapes.h"
#include "buzzer.h"

extern int inputShapes[10];
extern int gameShapes[10];
extern int matchShapes[10];

/* Keeps track of what level the player is on */
extern int level;

/* Signals when the game needs to show the shapes to the player */
extern int presentShapes;

/* Index for storing players' shapes */
extern int pIndex;

/* Index for displaying shapes */
extern int gameIndex;

/* Keeps track of game score across all levels */
extern int gameScore;

/* Start new game, reinitialize with new random shapes into gameShapes */
int init_game(void);

/* Takes in input from player and stores into inputShapes */
void storeShape(int input);

/* Increases level of the game */
void level_up(void);

/* Checks for matching shapes of input & game shapes*/
void check_match_shapes(void);

/* Updates the gameScore for the entire game*/
void update_score(void);

/* Checks if the player is at the end of the level */
/* int is_level_done(void); */

/* Updates the game with redrawing the scoreboard and matchShapes, level up, and reset
pIndex if there are no more shapes to take in. */
void update_game(void);
