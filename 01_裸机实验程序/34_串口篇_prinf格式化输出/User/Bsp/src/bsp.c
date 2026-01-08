
#include "bsp.h"


/***************************************************************************************************
 * @fn      bsp_init
 *
 * @brief   板级支持包初始化
 *
 * @param   无  
 *
 * @return  无
 */
void bsp_init(void)
{   
    HAL_Init();

    /* 配置系统时钟 */
    system_clock_init_hse();

//    /* 初始化LED */
//    bsp_led_init();

//    /* 按键初始化 */
//    bsp_switch_init();

    /* 串口初始化 */
   uart1_init(921600);
   uart2_init(921600);
   uart3_init(921600);
}

/***************************************************************************************************
 * @fn      bsp_idle
 *
 * @brief   系统空闲时执行的函数 
 * 
 * @param   无
 *
 * @return  无 
 */
void bsp_idle(void) 
{
    
}

/***************************************************************************************************
 * @fn      bsp_period_run_1ms
 *
 * @brief   每一毫秒执行这个函数
 *
 * @param   无  
 *
 * @return  无 
 */
void bsp_period_run_1ms(void)
{
    
}

/***************************************************************************************************
 * @fn      bsp_period_run_10ms
 *
 * @brief   每十毫秒执行这个函数
 *
 * @param   无  
 *
 * @return  无 
 */
void bsp_period_run_10ms(void)
{
    
}




