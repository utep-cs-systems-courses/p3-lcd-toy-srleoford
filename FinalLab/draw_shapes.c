#include <msp430.h>
#include <stdio.h>
#include <string.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

/* Default positions for shapes for buttons */
#define INTERFACE_Y_POS 140
#define INTERFACE_X_POS_ONE (screenWidth/5)
#define INTERFACE_X_POS_TWO ((screenWidth/5) * 2) + 3
#define INTERFACE_X_POS_THREE ((screenWidth/5) * 3) + 3
#define INTERFACE_X_POS_FOUR ((screenWidth/5) * 4) + 3


/* Default positions for correct/incorrect shapes */
#define HISTORY_X_POS (screenWidth/11)
#define HISTORY_Y_POS 40

/* Default positions for displaying sequence of shapes of level */
#define LEVEL_Y_POS 90
#define LEVEL_X_POS screenWidth/2


circle buttonCir, correct, lvlCir;
rectangle buttonRect, noShape, lvlRect;
triangle buttonTri, lvlTri;
ex buttonX, incorrect, lvlX;

u_int bgColor = COLOR_GRAY;

void init_shapes(void){
  /* Shapes to be used will be the same size */

  /* Vars for rectangles */
  buttonRect.rect_x = INTERFACE_X_POS_ONE;
  buttonRect.rect_y = INTERFACE_Y_POS;
  buttonRect.rect_inner_x = buttonRect.rect_x + 2;
  buttonRect.rect_inner_y = buttonRect.rect_y + 2;
  buttonRect.height = 24;
  buttonRect.width = 24;
  buttonRect.color = COLOR_HOT_PINK;

  //To be used for shapes not yet stored in history
  noShape.rect_x = 0;
  noShape.rect_y = HISTORY_Y_POS;
  noShape.rect_inner_x = noShape.rect_x + 1;
  noShape.rect_inner_y = noShape.rect_y + 1;
  noShape.height = 12;
  noShape.width = 12;
  noShape.color = COLOR_BLUE;

  //Square to draw for the level
  lvlRect.rect_x = LEVEL_X_POS;
  lvlRect.rect_y = LEVEL_Y_POS;
  lvlRect.rect_inner_x = lvlRect.rect_x + 2;
  lvlRect.rect_inner_y = lvlRect.rect_y + 2;
  lvlRect.height = 50;
  lvlRect.width = 50;
  lvlRect.color = COLOR_HOT_PINK;
  
  /* Vars for circles */
  buttonCir.cir_x = INTERFACE_X_POS_FOUR;
  buttonCir.cir_y = INTERFACE_Y_POS;
  buttonCir.inner_cir_x = buttonCir.cir_x + 2;
  buttonCir.inner_cir_y = buttonCir.cir_y + 2;
  buttonCir.r = 12;
  buttonCir.color = COLOR_FIREBRICK;

  //To be used for display to show player how many are correct
  correct.cir_x = 0;
  correct.cir_y = 0;
  correct.inner_cir_x = 0;
  correct.inner_cir_x = 0;
  correct.r = 6;
  correct.color = COLOR_DARK_GREEN;

  //Circle to draw for the level
  lvlCir.cir_x = LEVEL_X_POS;
  lvlCir.cir_y = LEVEL_Y_POS;
  lvlCir.inner_cir_x = lvlCir.inner_cir_x + 2;
  lvlCir.inner_cir_y = lvlCir.inner_cir_y + 2;
  lvlCir.r = 25;
  lvlCir.color = COLOR_FIREBRICK;
  
  /* Vars for triangles */
  buttonTri.tri_x = INTERFACE_X_POS_TWO;
  buttonTri.tri_y = INTERFACE_Y_POS;
  buttonTri.height = 24;
  buttonTri.base = 24;
  buttonTri.color = COLOR_SPRING_GREEN;

  //Triangle to draw for level
  lvlTri.tri_x = LEVEL_X_POS;
  lvlTri.tri_y = LEVEL_Y_POS;
  lvlTri.height = 50;
  lvlTri.base = 50;
  lvlTri.color = COLOR_SPRING_GREEN;

  /* Vars for 'X's */
  buttonX.outWidth = 24;
  buttonX.inWidth = 22;
  buttonX.outHeight = 24;
  buttonX.inHeight = 22;
  buttonX.line_x1 = INTERFACE_X_POS_THREE - (buttonX.outWidth/2);
  buttonX.line_x2 = INTERFACE_X_POS_THREE - (buttonX.inWidth/2);
  buttonX.line_y1 = INTERFACE_Y_POS - (buttonX.inHeight/2);
  buttonX.line_y2 = INTERFACE_Y_POS - (buttonX.outHeight/2);
  buttonX.color = COLOR_NAVY;

  //To be used for display to show player how many are incorrect
  incorrect.outWidth = 12;
  incorrect.inWidth = 10;
  incorrect.outHeight = 12;
  incorrect.inHeight = 10;
  incorrect.line_x1 = 0;
  incorrect.line_x2 = 0;
  incorrect.line_y1 = 0;
  incorrect.line_y2 = 0;
  incorrect.color = COLOR_RED;

  //X to draw for the level
  lvlX.outWidth = 50;
  lvlX.inWidth = 48;
  lvlX.outHeight = 50;
  lvlX.inHeight = 48;
  lvlX.line_x1 = LEVEL_X_POS - (lvlX.outWidth/2);
  lvlX.line_x2 = LEVEL_X_POS - (lvlX.inWidth/2);
  lvlX.line_y1 = LEVEL_Y_POS - (lvlX.inHeight/2);
  lvlX.line_y2 = LEVEL_Y_POS - (lvlX.outHeight/2);
  lvlX.color = COLOR_NAVY;
}

void draw_button_rectangle(void){
  int x = buttonRect.rect_x - (buttonRect.width/2);
  int y = buttonRect.rect_y - (buttonRect.height/2);

  for(int i = 0; i < 2; i++)
    drawRectOutline(x + i, y + i, buttonRect.width - (i * 2), buttonRect.height - (i * 2), buttonRect.color);
}

void draw_button_outline_rectangle(void){
  
  int x = buttonRect.rect_x - (buttonRect.width/2);
  int y = buttonRect.rect_y - (buttonRect.height/2);
  
  drawRectOutline(x, y, buttonRect.width, buttonRect.height, COLOR_BLACK);
}

void erase_button_outline_rectangle(void){
  
  int x = buttonRect.rect_x - (buttonRect.width/2);
  int y = buttonRect.rect_y - (buttonRect.height/2);
  
  drawRectOutline(x, y, buttonRect.width, buttonRect.height, buttonRect.color);
}

void draw_rectangle(rectangle rect){
  rect.old_rect_x = rect.rect_x - (rect.width/2);
  rect.old_rect_y = rect.rect_y - (rect.width/2);
  
  int x = rect.rect_x - (rect.width/2);
  int y = rect.rect_y - (rect.height/2);
  int dX = rect.rect_inner_x - rect.rect_x;
  int dY = rect.rect_inner_y - rect.rect_y;
  int dWidth = rect.width - (dX * 2);
  int dHeight = rect.height - (dY * 2);

  fillRectangle(x, y, rect.width, rect.height, rect.color);
  fillRectangle(x + dX, y + dY , dWidth, dHeight, bgColor);
}

void draw_button_triangle(void){

  int step;

  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < buttonTri.height; step++) {
    // left side of triangle
    u_char start_col = buttonTri.tri_x - (step / 2);
    // right side of triangle
    u_char end_col   = buttonTri.tri_x + (step / 2);
    fillRectangle(buttonTri.tri_x - (step / 2) + 1, (buttonTri.tri_y - (buttonTri.height/2) - 1) + step, (end_col - start_col), 2, buttonTri.color);
  }

  // Redraw triangle but fill smaller triangle inside
  // first triangle to create an outline of triangle
  // and not a fill
  for (step = 0; step < buttonTri.height - 2; step++) {
    // left side of triangle
    u_char start_col = buttonTri.tri_x - (step / 2) + 2;
    // right side of triangle
    u_char end_col   = buttonTri.tri_x + (step / 2) - 2;
    fillRectangle(buttonTri.tri_x - (step / 2) + 3, (buttonTri.tri_y - (buttonTri.height/2) - 1) + step, (end_col - start_col), 2, bgColor);
  }
}

void draw_button_outline_triangle(void){

  int step;
  int x = buttonTri.tri_x;
  int y = buttonTri.tri_y;
  
  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < buttonTri.height + 2; step++) {
    // left side of triangle
    u_char start_col = buttonTri.tri_x - (step / 2);
    // right side of triangle
    u_char end_col   = buttonTri.tri_x + (step / 2);
    fillRectangle(start_col + 1, (buttonTri.tri_y - (buttonTri.height/2) - 2) + step, 1, 1, COLOR_BLACK);
    fillRectangle(end_col, (buttonTri.tri_y - (buttonTri.height/2) - 2) + step, 1, 1, COLOR_BLACK);
  }
  fillRectangle(x - (step/2) + 2, y - (buttonTri.height/2) + step - 2, buttonTri.base, 1, COLOR_BLACK);
}

void erase_button_outline_triangle(void){

  int step;
  int x = buttonTri.tri_x;
  int y = buttonTri.tri_y;
  
  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < buttonTri.height + 2; step++) {
    // left side of triangle
    u_char start_col = buttonTri.tri_x - (step / 2);
    // right side of triangle
    u_char end_col   = buttonTri.tri_x + (step / 2);
    fillRectangle(start_col + 1, (buttonTri.tri_y - (buttonTri.height/2) - 2) + step, 1, 1, bgColor);
    fillRectangle(end_col, (buttonTri.tri_y - (buttonTri.height/2) - 2) + step, 1, 1, bgColor);
  }
  fillRectangle(x - (step/2) + 2, y - (buttonTri.height/2) + step - 2, buttonTri.base, 1, bgColor);
}

void draw_triangle(triangle tri){
  tri.old_tri_x = tri.tri_x;
  tri.old_tri_y = tri.tri_y;
  
  int step;

  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < tri.height; step++) {
    // left side of triangle
    u_char start_col = tri.tri_x - (step / 2);
    // right side of triangle
    u_char end_col   = tri.tri_x + (step / 2);
    fillRectangle(tri.tri_x - (step / 2) + 1, (tri.tri_y - (tri.height/2) - 1) + step, (end_col - start_col), 2, tri.color);
  }

  // Redraw triangle but fill smaller triangle inside
  // first triangle to create an outline of triangle
  // and not a fill
  for (step = 0; step < tri.height - 2; step++) {
    // left side of triangle
    u_char start_col = tri.tri_x - (step / 2) + 2;
    // right side of triangle
    u_char end_col   = tri.tri_x + (step / 2) - 2;
    fillRectangle(tri.tri_x - (step / 2) + 3, (tri.tri_y - (tri.height/2) - 1) + step, (end_col - start_col), 2, bgColor);
  }
}

void draw_button_circle(void){
  
  int x_coord = buttonCir.cir_x;
  int y_coord = buttonCir.cir_y;
  int r = buttonCir.r;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  drawLines(x_coord, y_coord, x_point, y_point, buttonCir.color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, buttonCir.color);
  }

  // Redraw the inner circle and fill to create outline of circle
  x_coord = buttonCir.cir_x;
  y_coord = buttonCir.cir_y;
  r = buttonCir.r - 2;
  // first point will be the very top;
  x_point = 0;
  y_point = r;
  decision = 3 - (2 * r);

  drawLines(x_coord, y_coord, x_point, y_point, buttonCir.color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, bgColor);
  }
  // fill the last left over, the line in the direct middle of the circle with bgColor
  drawHorizontalLine(buttonCir.cir_x - r, buttonCir.cir_x + r, buttonCir.cir_y, bgColor);
}

void draw_button_outline_circle(void){
  
  int x_coord = buttonCir.cir_x;
  int y_coord = buttonCir.cir_y;
  int r = buttonCir.r;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  drawPixel(x_coord, y_coord - y_point, COLOR_BLACK);
  drawPixel(x_coord, y_coord + y_point, COLOR_BLACK);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    // Top left
    drawPixel(x_coord-x_point, y_coord-y_point, COLOR_BLACK);
    drawPixel(x_coord-y_point, y_coord-x_point, COLOR_BLACK);
    // Top right
    drawPixel(x_coord+x_point, y_coord-y_point, COLOR_BLACK);
    drawPixel(x_coord+y_point, y_coord-x_point, COLOR_BLACK);
    // Bottom left
    drawPixel(x_coord-x_point, y_coord+y_point, COLOR_BLACK);
    drawPixel(x_coord-y_point, y_coord+x_point, COLOR_BLACK);
    // Bottom right
    drawPixel(x_coord+x_point, y_coord+y_point, COLOR_BLACK);
    drawPixel(x_coord+y_point, y_coord+x_point, COLOR_BLACK);
  }
  drawPixel(x_coord + r, y_coord, COLOR_BLACK);
  drawPixel(x_coord - r, y_coord, COLOR_BLACK);
}

void erase_button_outline_circle(void){
  
  int x_coord = buttonCir.cir_x;
  int y_coord = buttonCir.cir_y;
  int r = buttonCir.r;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  drawPixel(x_coord, y_coord - y_point, buttonCir.color);
  drawPixel(x_coord, y_coord + y_point, buttonCir.color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    // Top left
    drawPixel(x_coord-x_point, y_coord-y_point, buttonCir.color);
    drawPixel(x_coord-y_point, y_coord-x_point, buttonCir.color);
    // Top right
    drawPixel(x_coord+x_point, y_coord-y_point, buttonCir.color);
    drawPixel(x_coord+y_point, y_coord-x_point, buttonCir.color);
    // Bottom left
    drawPixel(x_coord-x_point, y_coord+y_point, buttonCir.color);
    drawPixel(x_coord-y_point, y_coord+x_point, buttonCir.color);
    // Bottom right
    drawPixel(x_coord+x_point, y_coord+y_point, buttonCir.color);
    drawPixel(x_coord+y_point, y_coord+x_point, buttonCir.color);
  }
  drawPixel(x_coord + r, y_coord, buttonCir.color);
  drawPixel(x_coord - r, y_coord, buttonCir.color);
}

void draw_circle(circle cir){
  cir.old_cir_x = cir.cir_x;
  cir.old_cir_y = cir.cir_y;
  
  int x_coord = cir.cir_x;
  int y_coord = cir.cir_y;
  int r = cir.r;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  drawLines(x_coord, y_coord, x_point, y_point, cir.color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, cir.color);
  }

  // Redraw the inner circle and fill to create outline of circle
  x_coord = cir.cir_x;
  y_coord = cir.cir_y;
  r = cir.r - 2;
  // first point will be the very top;
  x_point = 0;
  y_point = r;
  decision = 3 - (2 * r);

  drawLines(x_coord, y_coord, x_point, y_point, cir.color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, bgColor);
  }
  // fill the last left over, the line in the direct middle of the circle with bgColor
  drawHorizontalLine(cir.cir_x - r, cir.cir_x + r, cir.cir_y, bgColor);
}

void draw_button_X(void){

  int i;
  int lineLength = (buttonX.line_x2 - buttonX.line_x1) + buttonX.inWidth;
  int x1 = buttonX.line_x1;
  int x2 = buttonX.line_x2;
  int y1 = buttonX.line_y1;
  int y2 = buttonX.line_y2;
  
  for (i = 1; i < lineLength; i++){
    // Draw 1st line from top left to bottom right
    drawPixel(x1 + i, y1 + i, buttonX.color);
    // Draw 2nd line from top left to bottom right
    drawPixel(x2 + i, y2 + i, buttonX.color);
    // Draw 3rd line from bottom left to top right, mirror over X-axis of 1st line
    drawPixel(x1 + i, (y1 + buttonX.inHeight) - i, buttonX.color);
    // Draw 4th line from bottom left to top right, mirror over X-axis of 2nd line
    drawPixel(x2 + i, (y2 + buttonX.outHeight) - i, buttonX.color);
    if (i < lineLength - 1){
      //Fill between lines 1 and 2
      drawPixel(x1 + 1 + i, y1 + i, buttonX.color);
      //Fill between lines 3 and 4
      drawPixel(x1 + 1 + i, (y1 + buttonX.inHeight) - i, buttonX.color);
    }
  }
}

void draw_button_outline_X(void){

  int i;
  int lineLength = (buttonX.line_x2 - buttonX.line_x1) + buttonX.inWidth;
  int x1 = buttonX.line_x1-1;
  int x2 = buttonX.line_x2;
  int y1 = buttonX.line_y1;
  int y2 = buttonX.line_y2-1;
  int top_left_x = x1 + 2;
  int top_left_y = y1;
  int top_right_x = top_left_x + buttonX.outWidth - 1;
  int top_right_y = top_left_y;
  int bottom_left_x = top_left_x;
  int bottom_left_y = y1 + buttonX.inHeight;
  int bottom_right_x = top_right_x - 1;
  int bottom_right_y = bottom_left_y;
  
  for (i = 1; i < (lineLength/2)+1; i++){
    /* Drawing left half of outline */
    // Draw 1st line, left/top to center
    drawPixel(x1 + i, y1 + i, COLOR_BLACK);
    // Draw 2nd line, top/left to center
    drawPixel(x2 + i, y2 + i, COLOR_BLACK);
    // Draw 3rd line, left/bottom to center
    drawPixel(x1 + i, (y1 + buttonX.inHeight) - i, COLOR_BLACK);
    // Draw 4th line, bottom/left to center
    drawPixel(x2 + i, (y2 + buttonX.outHeight+2) - i, COLOR_BLACK);

    /* Drawing right half of outline */
    // Draw 1st line, right/top to center
    drawPixel(x1 - i + buttonX.outWidth + 2, y1 + i, COLOR_BLACK);
    // Draw 2nd line, top/right to center
    drawPixel(x2 - i + buttonX.inWidth, y2 + i, COLOR_BLACK);
    // Draw 3rd line, right/bottom to center
    drawPixel(x1 - i + buttonX.outWidth + 2, (y1 + buttonX.inHeight) - i, COLOR_BLACK);
    // Draw 4th line, bottom/right to center
    drawPixel(x2 - i + buttonX.inWidth, (y2 + buttonX.outHeight+2) - i, COLOR_BLACK);
  }
  drawPixel(top_left_x, top_left_y, COLOR_BLACK);
  drawPixel(top_right_x, top_right_y, COLOR_BLACK);
  drawPixel(bottom_right_x, bottom_right_y, COLOR_BLACK);
  drawPixel(bottom_left_x, bottom_left_y, COLOR_BLACK);
}

void erase_button_outline_X(void){

  int i;
  int lineLength = (buttonX.line_x2 - buttonX.line_x1) + buttonX.inWidth;
  int x1 = buttonX.line_x1-1;
  int x2 = buttonX.line_x2;
  int y1 = buttonX.line_y1;
  int y2 = buttonX.line_y2-1;
  int top_left_x = x1 + 2;
  int top_left_y = y1;
  int top_right_x = top_left_x + buttonX.outWidth - 1;
  int top_right_y = top_left_y;
  int bottom_left_x = top_left_x;
  int bottom_left_y = y1 + buttonX.inHeight;
  int bottom_right_x = top_right_x - 1;
  int bottom_right_y = bottom_left_y;
  
  for (i = 1; i < (lineLength/2)+1; i++){
    /* Drawing left half of outline */
    // Draw 1st line, left/top to center
    drawPixel(x1 + i, y1 + i, bgColor);
    // Draw 2nd line, top/left to center
    drawPixel(x2 + i, y2 + i, bgColor);
    // Draw 3rd line, left/bottom to center
    drawPixel(x1 + i, (y1 + buttonX.inHeight) - i, bgColor);
    // Draw 4th line, bottom/left to center
    drawPixel(x2 + i, (y2 + buttonX.outHeight+2) - i, bgColor);

    /* Drawing right half of outline */
    // Draw 1st line, right/top to center
    drawPixel(x1 - i + buttonX.outWidth + 2, y1 + i, bgColor);
    // Draw 2nd line, top/right to center
    drawPixel(x2 - i + buttonX.inWidth, y2 + i, bgColor);
    // Draw 3rd line, right/bottom to center
    drawPixel(x1 - i + buttonX.outWidth + 2, (y1 + buttonX.inHeight) - i, bgColor);
    // Draw 4th line, bottom/right to center
    drawPixel(x2 - i + buttonX.inWidth, (y2 + buttonX.outHeight+2) - i, bgColor);
  }
  drawPixel(top_left_x, top_left_y, bgColor);
  drawPixel(top_right_x, top_right_y, bgColor);
  drawPixel(bottom_right_x, bottom_right_y, bgColor);
  drawPixel(bottom_left_x, bottom_left_y, bgColor);
}  

void draw_X(ex x){
  x.old_line_x1 = x.line_x1;
  x.old_line_x2 = x.line_x2;
  x.old_line_y1 = x.line_y1;
  x.old_line_y2 = x.line_y2;
  
  int i;
  int lineLength = (x.line_x2 - x.line_x1) + x.inWidth;
  
  /* Draw the 1st line from top left to bottom right */
  /* Draw the 2nd line from top left to bottom right */
  /* Draw the 3rd line from bottom left to top right */
  for (i = 1; i < lineLength; i++){
    // Draw 1st line from top left to bottom right
    drawPixel(x.line_x1 + i, x.line_y1 + i, x.color);
    // Draw 2nd line from top left to bottom right
    drawPixel(x.line_x2 + i, x.line_y2 + i, x.color);
    // Draw 3rd line from bottom left to top right, mirror over X-axis of 1st line
    drawPixel(x.line_x1 + i, (x.line_y1 + x.inHeight) - i, x.color);
    // Draw 4th line from bottom left to top right, mirror over X-axis of 2nd line
    drawPixel(x.line_x2 + i, (x.line_y2 + x.outHeight) - i, x.color);
    // Fill in between lines
    if (i < lineLength - 1){
      //Fill between lines 1 and 2
      drawPixel(x.line_x1 + 1 + i, x.line_y1 + i, x.color);
      //Fill between lines 3 and 4
      drawPixel(x.line_x1 + 1 + i, (x.line_y1 + x.inHeight) - i, x.color);
    }
  }
}

void drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR)
{
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
} 

void drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color){
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void draw_matching_shapes(int gameShapes[]){
  int pos = HISTORY_X_POS;
  int size = 10;
  // correct is circle, incorrect is X
  
  for (int i = 0; i < size; i++){
    switch (gameShapes[i]){
    case 1:
      correct.cir_x = (pos * i) + 10;
      correct.cir_y = HISTORY_Y_POS;
      correct.inner_cir_x = correct.cir_x + 12;
      correct.inner_cir_y = correct.cir_y + 2;
      draw_circle(correct);
      break;
    case 0:
      incorrect.line_x1 = pos * i - (incorrect.outWidth/2) + 10;
      incorrect.line_x2 = pos * i - (incorrect.inWidth/2) + 10;
      incorrect.line_y1 = HISTORY_Y_POS - (incorrect.inHeight/2);
      incorrect.line_y2 = HISTORY_Y_POS - (incorrect.outHeight/2);
      draw_X(incorrect);
      break;
    default:
      noShape.rect_x = (pos * i) + 10;
      noShape.rect_inner_x = noShape.rect_x + 2;
      noShape.rect_inner_y = noShape.rect_y + 2;
      draw_rectangle(noShape);
      break;
    }
  }
}

void draw_lvl_shapes(int shape){
  switch(shape){
  case 0:
    clear_lvl();
    draw_rectangle(lvlRect);
    break;
  case 1:
    clear_lvl();
    draw_triangle(lvlTri);
    break;
  case 2:
    clear_lvl();
    draw_X(lvlX);
    break;
  case 3:
    clear_lvl();
    draw_circle(lvlCir);
    break;
  default:
    clear_lvl();
    break;
  }
  
}

void clear_lvl(void){
  fillRectangle(0, LEVEL_Y_POS-25, screenWidth, 51, bgColor);
}

void draw_scoreboard(int gameShapes[]){

  int size = 10;
  int i;
  int count = 0;
  
  for (i = 0; i < size; i++)
    if (gameShapes[i] == 1)
      count++;
  count *= 10;

  char scoreboard[20] = "Score: ";
  char score[10];
  sprintf(score, "%d", count);
  strcat(scoreboard, score);
  
  drawString5x7(5, 5, scoreboard, COLOR_WHITE, COLOR_BLACK);  
}
