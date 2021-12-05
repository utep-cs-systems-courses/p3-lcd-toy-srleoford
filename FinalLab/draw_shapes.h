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

extern u_int background_color;

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

void init_shapes(void);

extern circle buttonCir, correct, lvlCir;
extern rectangle buttonRect, noShape, lvlRect;
extern triangle buttonTri, lvlTri;
extern ex buttonX, incorrect, lvlX;

#endif // _DRAW_SHAPES_H_
