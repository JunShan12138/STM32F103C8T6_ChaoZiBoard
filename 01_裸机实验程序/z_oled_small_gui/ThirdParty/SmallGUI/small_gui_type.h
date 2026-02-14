#ifndef __SMALL_GUI_TYPE_H__
#define __SMALL_GUI_TYPE_H__

#include <stdint.h>  


typedef unsigned int    GUI_UINT32;
typedef unsigned short  GUI_UINT16;
typedef unsigned char   GUI_UINT8;

typedef int             GUI_INT32;
typedef short           GUI_INT16;
typedef char            GUI_INT8;
typedef char            GUI_CHAR;

typedef enum {GUI_FALSE = 0, GUI_TRUE = !GUI_FALSE} GUI_BOOL;

typedef enum {GUI_SPECIAL, GUI_NORMAL} GUI_MODE;

typedef enum 
{
    GUI_FONT_8x8 = 1, 
    GUI_FONT_8x16
}GUI_FONT_SIZE;

#endif

