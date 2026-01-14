
#include "bsp.h"

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

    while (1)
    {
        g_flag = 0;
        bsp_delay_ms(100);
        g_flag = 1;
        bsp_delay_ms(100);
        trigger_pend_svc();
    }
}


