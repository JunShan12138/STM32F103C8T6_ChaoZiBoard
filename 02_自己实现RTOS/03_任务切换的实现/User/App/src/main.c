
#include "bsp.h"
#include "os_rtos.h"




os_task_t g_task1;
os_task_t g_task2;

os_task_stack_t g_task1_env[1024];
os_task_stack_t g_task2_env[1024];

volatile int g_task1_flag;
volatile int g_task2_flag;

void tiny_delay(uint32_t time)
{
    volatile uint32_t tmp = time;
    
    while(tmp--);
}



void task1_entry(void *param)
{
    for (;;)
    {
        g_task1_flag = 0;
        tiny_delay(100);
        g_task1_flag = 1;
        tiny_delay(100);

        os_task_schedule();
    }
}

void task2_entry(void *param)   
{
    for (;;)
    {
        g_task2_flag = 0;
        tiny_delay(100);
        g_task2_flag = 1;
        tiny_delay(100);

        os_task_schedule();
    }
}


int main(void)
{
    ulong_t task1_param = 123;
    ulong_t task2_param = 345;
    
    bsp_init();


    
    p_task_table[0] = &g_task1;
    p_task_table[1] = &g_task2;
    
    os_task_init(&g_task1, task1_entry, &task1_param, &g_task1_env[1024]);
    os_task_init(&g_task2, task2_entry, &task2_param, &g_task2_env[1024]);
    
    p_next_task = p_task_table[0];
    
    os_task_run_first();

   return 0;
}


