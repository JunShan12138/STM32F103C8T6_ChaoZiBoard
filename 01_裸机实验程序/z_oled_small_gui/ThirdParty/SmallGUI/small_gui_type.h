#ifndef __SMALL_GUI_TYPE_H__
#define __SMALL_GUI_TYPE_H__

#include <stdint.h>  

/* 类型重定向 */
typedef unsigned int    GUI_UINT32;
typedef unsigned short  GUI_UINT16;
typedef unsigned char   GUI_UINT8;

typedef int    GUI_INT32;
typedef short  GUI_INT16;
typedef char   GUI_INT8;

typedef enum {GUI_FALSE = 0, GUI_TRUE = !GUI_FALSE} GUI_BOOL;

#endif

