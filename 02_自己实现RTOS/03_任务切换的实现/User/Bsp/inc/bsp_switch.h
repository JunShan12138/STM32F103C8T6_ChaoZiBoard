
#ifndef __BSP_SWITCH_H__
#define __BSP_SWITCH_H__

#include <stdint.h>

typedef enum
{
    SW_NONE = 0,
    SW8_DOWN
}switch_status_e;

void bsp_switch_init(void);
switch_status_e bsp_switch_scan(uint8_t mode);

#endif

