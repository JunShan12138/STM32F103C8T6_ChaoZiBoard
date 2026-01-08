/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-07-24     Tanek        the first version
 * 2018-11-12     Ernest Chen  modify copyright
 */
 
#include <stdint.h>
#include <rthw.h>
#include <rtthread.h>
#include "board.h"
//#include "bsp.h"
#include "gd32f10x.h"                   // Device header




rt_sem_t g_finsh_sem = RT_NULL;



// Updates the variable SystemCoreClock and must be called 
// whenever the core clock is changed during program execution.
extern void SystemCoreClockUpdate(void);

// Holds the system core clock, which is the system clock 
// frequency supplied to the SysTick timer and the processor 
// core clock.
extern uint32_t SystemCoreClock;

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 1024 * 4
static uint32_t rt_heap[RT_HEAP_SIZE];  // heap default size: 4K(1024 * 4)
RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif



/**
 * This function will initial your board.
 */
void rt_hw_board_init()
{
//    /* System Clock Update */
//    SystemCoreClockUpdate();
    
    /* System Tick Configuration */
    SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);

    bsp_init_uart_log();

    /* Call components board initial (use INIT_BOARD_EXPORT()) */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif

    /* 创建一个动态信号量，初始值是0 */
    g_finsh_sem = rt_sem_create("finsh", 0, RT_IPC_FLAG_FIFO);
}

void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

void rt_hw_console_output(const char *str)
{
    rt_size_t i = 0, size = 0;
    char a = '\r';

    size = rt_strlen(str);

    rt_enter_critical();

    for (i = 0; i < size; i++)
    {
        if (*(str + i) == '\n')
        {
            usart_data_transmit(USART0, (uint8_t)a);
            while (usart_flag_get(USART0, USART_FLAG_TBE) == RESET)
            {}
        }

        usart_data_transmit(USART0, str[i]);
        while (usart_flag_get(USART0, USART_FLAG_TBE) == RESET)
        {}
    }

    rt_exit_critical();
}


//char rt_hw_console_getchar(void)
//{
//    int ch = -1;
//    
//    /* 获取到信号量则 */ 
//    rt_sem_take(g_finsh_sem, RT_WAITING_FOREVER);
//    ch = usart_data_receive(USART0);

//    return ch;
//}

