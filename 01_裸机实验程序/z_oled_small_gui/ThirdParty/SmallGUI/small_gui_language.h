#ifndef __SMALL_GUI_LANGUAGE_H__
#define __SMALL_GUI_LANGUAGE_H__

#include "small_gui_type.h" 

void gui_show_img(GUI_INT32 x, GUI_INT32 y, 
                  GUI_INT32 hang, GUI_INT32 lie, 
                  const GUI_UINT8 *p, GUI_MODE type);

void gui_show_font_string(GUI_INT32 x, GUI_INT32 y, 
                          GUI_CHAR *p, GUI_FONT_SIZE font_size,
                          GUI_MODE type);

#endif

