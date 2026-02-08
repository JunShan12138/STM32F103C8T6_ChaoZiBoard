#ifndef __SMALL_GUI_BASE_H__
#define __SMALL_GUI_BASE_H__

#include "small_gui_type.h" 


/* 底层接口，屏幕的初始化 */ 
void gui_init(void);

/* 底层接口，设置一个点 */
void gui_set_point(GUI_INT32 x, GUI_INT32 y, GUI_MODE type);

/* 底层接口，清除一个点 */
void gui_clear_point(GUI_INT32 x, GUI_INT32 y, GUI_MODE type);

/* 底层接口，读取一个点的状态 */ 
GUI_BOOL gui_read_point(GUI_INT32 x, GUI_INT32 y, GUI_MODE type);

/* 底层接口，刷新屏幕 */
void gui_refresh(void);

/* 底层接口，清屏 */
void gui_clear_all(GUI_MODE type);

/* 底层接口，清除一个区域 */
void gui_clear_area(GUI_INT32 x, GUI_INT32 y, GUI_INT32 width, GUI_INT32 height, GUI_MODE type);

#endif

