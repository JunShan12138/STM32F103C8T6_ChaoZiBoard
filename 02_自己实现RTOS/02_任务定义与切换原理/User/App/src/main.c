
#include "bsp.h"
#include "os_type.h"

#define NVIC_INT_CTRL       0xE000ED04  /* 控制寄存器的地址 */ 
#define NVIC_PENDSV_SET     0x10000000
#define NVIC_SYS_PRI2       0xE000ED22  /* 寄存器地址 */
#define NVIC_PENDSV_PRI     0x0000000F

#define  MEM32(addr)       (*(volatile unsigned long *)(addr))
#define  MEM8(addr)        (*(volatile unsigned char *)(addr))

typedef struct 
{
    unsigned long *stack;
}block_t;

block_t *p_block;
block_t g_block;

volatile int g_flag;

#define STACK_SIZE    1024
unsigned long g_stack_buffer[STACK_SIZE];

/* 任务句柄 */
os_task_t g_task1;
os_task_t g_task2;

/* 任务1的栈 */
#define TASK1_STACK_SIZE    1024
os_task_stack_t g_task1_env[TASK1_STACK_SIZE];

/* 任务2的栈 */
#define TASK2_STACK_SIZE    1024
os_task_stack_t g_task2_env[TASK1_STACK_SIZE];

void task1(void *param)
{
    for (;;)
    {

    }
}

void task2(void *param)
{
    for (;;)
    {

    }
}

/***************************************************************************************************
 * @fn      os_task_init
 *
 * @brief   任务初始化
 *
 * @param   task 任务句柄
 * @param   entry 任务服务函数接口
 * @param   param 任务的参数
 * @param   stack 任务栈
 *
 * @return  无 
 */
void os_task_init(os_task_t *task, void(*entry)(void *), void *param, os_task_stack_t *stack)
{
    task->stack = stack;
}

void trigger_pend_svc(void)
{
    MEM8(NVIC_SYS_PRI2)  = NVIC_PENDSV_PRI;
    MEM32(NVIC_INT_CTRL) = NVIC_PENDSV_SET;
}

int main(void)
{
    bsp_init();

    g_block.stack = &g_stack_buffer[STACK_SIZE];
    p_block = &g_block;

    os_task_init(&g_task1, task1, (void *)0x11111111, &g_task1_env[TASK1_STACK_SIZE]);
    os_task_init(&g_task2, task2, (void *)0x22222222, &g_task2_env[TASK2_STACK_SIZE]);


    while (1)
    {
        g_flag = 0;
        bsp_delay_ms(100);
        g_flag = 1;
        bsp_delay_ms(100);
        trigger_pend_svc();
    }
}


