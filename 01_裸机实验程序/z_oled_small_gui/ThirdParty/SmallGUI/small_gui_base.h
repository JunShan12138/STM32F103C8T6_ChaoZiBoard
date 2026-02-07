#ifndef __SMALL_GUI_BASE_H__
#define __SMALL_GUI_BASE_H__

#include "small_gui_type.h" 

void gui_init(void);

void gui_set_point(GUI_INT32 x, GUI_INT32 y);

void gui_clear_point(GUI_INT32 x, GUI_INT32 y);

GUI_BOOL gui_read_point(GUI_INT32 x, GUI_INT32 y);

void gui_refresh(void);

#endif

