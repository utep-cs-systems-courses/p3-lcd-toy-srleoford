#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <lcdutils.h>

typedef struct rect_st {
  int rect_x;
  int rect_y;
  int old_rect_x;
  int old_rect_y;
  int rect_inner_x;
  int rect_inner_y;
  u_char height;
  u_char width;
  u_int color;
} rectangle;

typedef struct cir_st {
  int cir_x;
  int cir_y;
  int old_cir_x;
  int old_cir_y;
  int inner_cir_x;
  int inner_cir_y;
  int r;
  u_int color;
} circle;

typedef struct tri_st {
  int tri_x;
  int tri_y;
  int old_tri_x;
  int old_tri_y;
  int inner_tri_x;
  int inner_tri_y;
  int height;
  int base;
  u_int color;
} triangle;

/* Drawing a filled 'X' using four slanted lines and only filling in between lines */
typedef struct x_st {
  int line_x1;
  int line_x2;
  int line_y1;
  int line_y2;
  int old_line_x1;
  int old_line_x2;
  int old_line_y1;
  int old_line_y2;
  int outWidth;
  int inWidth;
  int outHeight;
  int inHeight;
  u_int color;
} ex;

extern u_int bgColor;

/* draws a rectangle for interface button*/
void draw_button_rectangle(void);

/* draws a rectangle for generic location */
void draw_rectangle(rectangle rect);

/* draws a triangle for interface button*/
void draw_button_triangle(void);

/* draws a triangle for generic location */
void draw_triangle(triangle tri);

/* draws a circle for interface button */
void draw_button_circle(void);

/* draws a circle for generic location */
void draw_circle(circle cir);

/* draws an 'X' for interface button */
void draw_button_X(void);

/* draws an 'X' for generic location */
void draw_X(ex x);

/* draws one line horizontally */
void drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR);

/* draws lines top, bottom, and sides of x_coord, y_coord */
void drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color);

void init_shapes(void);

/* Erase everything at the 'level' display area */
void clear_lvl(void);

/* Draws the outline for interface buttons */
void draw_button_outline_rectangle(void);
void draw_button_outline_triangle(void);
void draw_button_outline_X(void);
void draw_button_outline_circle(void);

/* Erases the outline for interface buttons */
void erase_button_outline_rectangle(void);
void erase_button_outline_triangle(void);
void erase_button_outline_X(void);
void erase_button_outline_circle(void);

/* Draws history of matching shapes for player */
void draw_matching_shapes(int gameShapes[]);

/* Draws scoreboard for player */
void draw_scoreboard(int matchShapes[]);

/* Draws congrats for player */
void draw_congrats(void);

/* Draws loss for player */
void draw_lose_game(void);

/* Draws display shapes for current lvl for player */
void draw_lvl_shapes(int shape);

void itoa2(int n, char s[]);
void reverse(char s[]);

extern circle buttonCir, correct, lvlCir;
extern rectangle buttonRect, noShape, lvlRect;
extern triangle buttonTri, lvlTri;
extern ex buttonX, incorrect, lvlX;

#endif // _DRAW_SHAPES_H_
