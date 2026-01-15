#include "os_rtos.h"

os_task_t *p_current_task;
os_task_t *p_next_task;
os_task_t *p_task_table[2];


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
    *(--stack) = ((ulong_t) (1 << 24));  /* SPSR寄存器的值 */
    *(--stack) = ((ulong_t) (entry));   /* PC寄存器的值 */
    
    /* 寄存器的序号 */
    *(--stack) = ((ulong_t) (0x14));  
    *(--stack) = ((ulong_t) (0x12));
    *(--stack) = ((ulong_t) (0x03));
    *(--stack) = ((ulong_t) (0x02));
    *(--stack) = ((ulong_t) (0x01));
    
    /* 保存任务参数 */
    *(--stack) = ((ulong_t) (param));
    
    *(--stack) = ((ulong_t) (0x11));
    *(--stack) = ((ulong_t) (0x10));
    *(--stack) = ((ulong_t) (0x09));
    *(--stack) = ((ulong_t) (0x08));
    *(--stack) = ((ulong_t) (0x07));
    *(--stack) = ((ulong_t) (0x06));
    *(--stack) = ((ulong_t) (0x05));
    *(--stack) = ((ulong_t) (0x04));
    
    task->stack = stack;
}




/***************************************************************************************************
 * @fn      os_task_schedule
 *
 * @brief   调度器切换任务
 *
 * @param   无 
 *
 * @return  无 
 */
void os_task_schedule(void)
{
    if (p_current_task == p_task_table[0])
    {
        p_next_task = p_task_table[1];
    }
    else
    {
        p_next_task = p_task_table[0];
    }

    os_task_switch();
}

