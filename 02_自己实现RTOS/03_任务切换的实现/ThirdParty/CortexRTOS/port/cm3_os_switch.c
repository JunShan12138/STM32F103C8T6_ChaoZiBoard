
#include "os_rtos.h"
#include "bsp.h"


#define NVIC_INT_CTRL    0xE000ED04  /* 寄存器地址 */
#define NVIC_PENDSVSET   0x10000000  /* 寄存器值 */
#define NVIC_SYSPRI2     0xE000ED22  /* 寄存器地址 */
#define NVIC_PENDSV_PRI  0x000000FF  /* 寄存器值 */

#define MEM32(addr)      (*(volatile ulong_t *)(addr))
#define MEM8(addr)       (*(volatile uint8_t *)(addr))


/***************************************************************************************************
 * @fn      PendSV_Handler
 *
 * @brief   PendSV终端服务函数，用来切换任务
 *
 * @param   无
 *
 * @return  无
 */
__asm void PendSV_Handler(void)
{
    IMPORT p_current_task   
    IMPORT p_next_task 
    
    MRS R0, PSP
    CBZ R0, PendSVHandler_nosave
    
    STMDB R0!, {R4-R11}  
    
    LDR R1, =p_current_task
    LDR R1, [R1]
    STR R0, [R1]
    
PendSVHandler_nosave
    LDR R0, =p_current_task
    LDR R1, =p_next_task
    LDR R2, [R1]
    STR R2, [R0]
    
    LDR R0, [R2]
    LDMIA R0!, {R4-R11}
    
    MSR PSP, R0
    ORR LR, LR, #0x04
    BX LR
}

/***************************************************************************************************
 * @fn      os_task_run_first
 *
 * @brief   运行第一个任务
 *
 * @param   无
 *
 * @return  无
 */
void os_task_run_first(void)
{
    __set_PSP(0);

    MEM8(NVIC_SYSPRI2) = NVIC_PENDSV_PRI;  /* 设置优先级 */
    MEM32(NVIC_INT_CTRL) = NVIC_PENDSVSET;  /* 触发PendSV */
}

/***************************************************************************************************
 * @fn      os_task_switch
 *
 * @brief   触发PendSV异常，以切换任务
 *
 * @param   无
 *
 * @return  无
 */
void os_task_switch(void)
{
    MEM32(NVIC_INT_CTRL) = NVIC_PENDSVSET;  /* 触发PendSV */
}


