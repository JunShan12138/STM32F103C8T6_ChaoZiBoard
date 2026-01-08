
#include "bsp.h"

uint32_t HCLKFreq;
uint32_t PCLK1Freq;
uint32_t PCLK2Freq;

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
    system_clock_init_hsi();
    
    HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCODIV_1);

    SystemCoreClockUpdate();

    HCLKFreq  = HAL_RCC_GetHCLKFreq();
    PCLK1Freq = HAL_RCC_GetPCLK1Freq();
    PCLK2Freq = HAL_RCC_GetPCLK2Freq();


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




