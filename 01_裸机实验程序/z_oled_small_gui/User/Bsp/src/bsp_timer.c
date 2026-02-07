
#include "bsp.h"

volatile uint32_t g_delay_count = 0;
volatile int32_t g_run_time = 0;
// volatile uint32_t ulHighFrequencyTimerTicks = 0;

/***************************************************************************************************
 * @fn      bsp_get_run_time
 *
 * @brief   获取CPU运行时间，单位1ms。最长可以表示 24.85天，如果运行时间超过这个数，则必须考虑溢出问题
 *
 * @param   无
 *
 * @return   CPU运行时间，单位1ms 
 */
int32_t bsp_get_run_time(void)
{
    int32_t runtime;

    DISABLE_INT();  /* 关中断 */

    runtime = g_run_time;  /* 这个变量在Systick中断中被改写，因此需要关中断进行保护 */

    ENABLE_INT();  /* 开中断 */

    return runtime;
}


/***************************************************************************************************
 * @fn      bsp_check_run_time
 *
 * @brief   计算当前运行时间和给定时刻之间的差值。处理了计数器循环。
 *
 * @param  last_time 上个时刻
 *
 * @return  当前时间和过去时间的差值，单位1ms 
 */
int32_t bsp_check_run_time(int32_t last_time)
{
    int32_t now_time;
    int32_t time_diff;

    DISABLE_INT();  /* 关中断 */

    now_time = g_run_time;  /* 这个变量在Systick中断中被改写，因此需要关中断进行保护 */

    ENABLE_INT();  /* 开中断 */

    if (now_time >= last_time)
    {
        time_diff = now_time - last_time;
    }
    else
    {
        time_diff = 0x7FFFFFFF - last_time + now_time;
    }

    return time_diff;
}



/***************************************************************************************************
 * @fn      bsp_delay_ms
 *
 * @brief   ms级延迟，延迟精度为正负1ms
 *
 * @param   n : 延迟长度，单位1 ms。 n 应大于2
 *
 * @return  无 
 */
void bsp_delay_ms(uint32_t n)
{
    g_delay_count = 0;
    
    while (g_delay_count < n)
    {
        bsp_idle();
    }
}


/***************************************************************************************************
 * @fn      bsp_delay_us
 *
 * @brief   us级延迟。 必须在systick定时器启动后才能调用此函数
 *
 * @param   n : 延迟长度，单位1 us
 *
 * @return  无 
 */
void bsp_delay_us(uint32_t n)
{
    uint32_t ticks;
    uint32_t told;
    uint32_t tnow;
    uint32_t tcnt = 0;
    uint32_t reload;
       
    reload = SysTick->LOAD;                
    ticks = n * (SystemCoreClock / 1000000);  /* 需要的节拍数 */  
    
    tcnt = 0;
    told = SysTick->VAL;  /* 刚进入时的计数器值 */

    while (1)
    {
        tnow = SysTick->VAL;    
        if (tnow != told)
        {    
            /* SYSTICK是一个递减的计数器 */    
            if (tnow < told)
            {
                tcnt += told - tnow;    
            }
            /* 重新装载递减 */
            else
            {
                tcnt += reload - tnow + told;    
            }        
            told = tnow;

            /* 时间超过/等于要延迟的时间,则退出 */
            if (tcnt >= ticks)
            {
                break;
            }
        }  
    }
} 

/***************************************************************************************************
 * @fn      systick_isr
 *
 * @brief   SysTick中断服务程序，每隔1ms进入1次
 *
 * @param   无  
 *
 * @return  无 
 */
extern void bsp_period_run_1ms(void);
extern void bsp_period_run_10ms(void);
extern __IO uint32_t g_delay_count;
void systick_isr(void)
{
    static uint8_t s_count = 0;
    
    /* 全局运行时间每1ms增1 */
    g_run_time++;
    if (g_run_time == 0x7FFFFFFF)  /* 这个变量是 int32_t 类型，最大数为 0x7FFFFFFF */
    {
        g_run_time = 0;
    }

    /* ms延时累加 */
    if (g_delay_count < 0xFFFFFFFF)
        g_delay_count++;

    bsp_period_run_1ms();  /* 每隔1ms调用一次此函数，此函数在 bsp.c */
 
    if (++s_count >= 10)
    {
        s_count = 0;

        bsp_period_run_10ms();  /* 每隔10ms调用一次此函数，此函数在 bsp.c */
    }
    
//    ulHighFrequencyTimerTicks++;
}


/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void)
{
    systick_isr();
    HAL_IncTick();
}


