#ifndef __BSP_H__
#define __BSP_H__


#define __BSP_DEBUG__
#define __DEBUG_LOG__   //开启调试日志

#define  ENABLE_INT()     __set_PRIMASK(0)  /* 使能全局中断 */
#define  DISABLE_INT()    __set_PRIMASK(1)  /* 禁止全局中断 */

#ifdef __BSP_DEBUG__
    // #define BSP_LOG(format, ...) rt_kprintf(format, ##__VA_ARGS__)
    #define BSP_LOG(format, ...)   uart1_printf(format, ##__VA_ARGS__)
#else
    #define BSP_LOG(format, ...)
#endif

#ifdef __DEBUG_LOG__
    // #define DEBUG_LOG(format, ...) rt_kprintf(format, ##__VA_ARGS__)
    #define DEBUG_LOG(format, ...)   uart1_printf(format, ##__VA_ARGS__)
#else
    #define DEBUG_LOG(format, ...)
#endif


void bsp_init(void);
void bsp_idle(void);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "stm32f1xx_hal.h"

#include "bsp_timer.h"
#include "bsp_cpu_clock.h"
#include "bsp_led.h"
#include "bsp_switch.h"
#include "bsp_uart.h"
#include "bsp_hard_timer.h"

#endif /* __BSP_H__ */

