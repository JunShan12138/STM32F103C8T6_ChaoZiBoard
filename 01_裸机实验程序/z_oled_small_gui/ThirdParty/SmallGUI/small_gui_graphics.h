#ifndef __SMALL_GUI_GRAPHICS_H__
#define __SMALL_GUI_GRAPHICS_H__

#include "small_gui_type.h" 

/* 绘制线段 */
void gui_draw_line(GUI_INT32 s_x, GUI_INT32 s_y, 
                   GUI_INT32 e_x, GUI_INT32 e_y, GUI_MODE type);

/* 绘制矩形 */
void gui_draw_rectangle(GUI_INT32 x, GUI_INT32 y, 
                        GUI_INT32 width, GUI_INT32 heigth, 
                        GUI_BOOL is_fill, GUI_MODE type);

/* 绘制三角形 */
void gui_draw_triangle(GUI_INT32 x0, GUI_INT32 y0, 
                       GUI_INT32 x1, GUI_INT32 y1, 
                       GUI_INT32 x2, GUI_INT32 y2, 
                       GUI_BOOL is_fill, GUI_MODE type);

/* 绘制圆形 */
void gui_draw_circle(GUI_INT32 x, GUI_INT32 y, 
                     GUI_INT32 radius, GUI_BOOL is_fill, GUI_MODE type);

/* 绘制椭圆形 */
void gui_draw_ellipse(GUI_INT32 x, GUI_INT32 y, 
                      GUI_INT32 a, GUI_INT32 b, 
                      GUI_BOOL is_fill, GUI_MODE type);

void gui_draw_arc(GUI_INT32 x, GUI_INT32 y, 
                  GUI_INT32 radius, GUI_INT32 start_angle,
                  GUI_INT32 end_angle,  GUI_BOOL is_fill, GUI_MODE type);


#endif

