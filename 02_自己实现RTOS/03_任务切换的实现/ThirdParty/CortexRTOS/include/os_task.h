
#ifndef __OS_TASK_H__
#define __OS_TASK_H__

extern os_task_t *p_current_task;
extern os_task_t *p_next_task;
extern os_task_t *p_task_table[2];

void os_task_init(os_task_t *task, void(*entry)(void *), void *param, os_task_stack_t *stack);

void os_task_schedule(void);

#endif
