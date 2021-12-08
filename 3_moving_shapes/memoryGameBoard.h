#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

/* Keeps track of score for memory game */
int score;

/* Keeps track of shapes, 1 = square, 2 = triangle, 3 = X, and 4 = circle */
int history[10];

/* Keeps track of how many shapes are correct so far. 1 = match, 0 = non-match */
int currentShapes[10];

/* Draws the shapes on top of the buttons for interface/player */
void drawButtonShapes(void);

/* Simply draw text line 'Score: XXX', 'XXX' correspond to score 0-100 */
void drawScoreboard(void);

/* Draw matched/non-matched shapes represented by numbers 1-4 */
void drawMatchedShapes(int currentShapes[]);

/* Initialize game with zero score and shapes drawn */
void initGame();
