#ifndef __SMALL_GUI_H__
#define __SMALL_GUI_H__


#define MAX_X_POS   128  /* 横向显示尺寸 */
#define MAX_Y_POS   64   /* 纵向显示尺寸 */

#define GUI_ARR_SIZE(__ARRAY)    ((sizeof(__ARRAY)) / (sizeof(__ARRAY[0])))


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#include "small_gui_type.h" 
#include "small_gui_base.h"
#include "small_gui_menu.h"
#include "small_gui_graphics.h"
#include "small_gui_language.h"
#include "small_gui_font.h"


#endif

