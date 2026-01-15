
#include "bsp.h"


TIM_HandleTypeDef tim1;
TIM_HandleTypeDef tim2;
TIM_HandleTypeDef tim3;
TIM_HandleTypeDef tim4;

/***************************************************************************************************
 * @fn      timer1_init
 *
 * @brief   定时器1初始化
 *
 * @param   arr 寄存器arr（的值
 * @param   psc 寄存器psc（预分频）的值
 * @param   rep 重复计数值
 *
 * @return  无 
 */
void timer1_init(uint16_t arr, uint16_t psc, uint8_t rep)
{
    tim1.Instance               = TIM1;
    tim1.Init.Prescaler         = psc;  /* 预分频值 */
    tim1.Init.CounterMode       = TIM_COUNTERMODE_UP;  /* 计数模式：向上计数 */
    tim1.Init.Period            = arr;  /* 自动重装载值 */
    tim1.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;  /* 时钟分频因子：1分频 */
    tim1.Init.RepetitionCounter = rep;  /* 重复计数值  */
    tim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;  /* 自动重装载值，预装载使能位 */
    HAL_TIM_Base_Init(&tim1);
    __HAL_TIM_CLEAR_FLAG(&tim1, TIM_FLAG_UPDATE);
    HAL_TIM_Base_Start_IT(&tim1);
}


/***************************************************************************************************
 * @fn      timer2_init
 *
 * @brief   定时器2初始化
 *
 * @param   arr 寄存器arr（的值
 * @param   psc 寄存器psc（预分频）的值
 *
 * @return  无 
 */
void timer2_init(uint16_t arr, uint16_t psc)
{
    tim2.Instance               = TIM2;
    tim2.Init.Prescaler         = psc;  /* 预分频值 */
    tim2.Init.CounterMode       = TIM_COUNTERMODE_UP;  /* 计数模式：向上计数 */
    tim2.Init.Period            = arr;  /* 自动重装载值 */
    tim2.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;  /* 时钟分频因子：1分频 */
    tim2.Init.RepetitionCounter = 0;  /* 重复计数值  */
    tim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;  /* 自动重装载值，预装载使能位 */
    HAL_TIM_Base_Init(&tim2);
    __HAL_TIM_CLEAR_FLAG(&tim2, TIM_FLAG_UPDATE);
    HAL_TIM_Base_Start_IT(&tim2);
}

/***************************************************************************************************
 * @fn      timer3_init
 *
 * @brief   定时器3初始化
 *
 * @param   arr 寄存器arr（的值
 * @param   psc 寄存器psc（预分频）的值
 *
 * @return  无 
 */
void timer3_init(uint16_t arr, uint16_t psc)
{
    tim3.Instance               = TIM3;
    tim3.Init.Prescaler         = psc;  /* 预分频值 */
    tim3.Init.CounterMode       = TIM_COUNTERMODE_UP;  /* 计数模式：向上计数 */
    tim3.Init.Period            = arr;  /* 自动重装载值 */
    tim3.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;  /* 时钟分频因子：1分频 */
    tim3.Init.RepetitionCounter = 0;  /* 重复计数值  */
    tim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;  /* 自动重装载值，预装载使能位 */
    HAL_TIM_Base_Init(&tim3);
    __HAL_TIM_CLEAR_FLAG(&tim3, TIM_FLAG_UPDATE);
    HAL_TIM_Base_Start_IT(&tim3);
}

/***************************************************************************************************
 * @fn      timer4_init
 *
 * @brief   定时器4初始化
 *
 * @param   arr 寄存器arr（的值
 * @param   psc 寄存器psc（预分频）的值
 *
 * @return  无 
 */
void timer4_init(uint16_t arr, uint16_t psc)
{
    tim4.Instance               = TIM4;
    tim4.Init.Prescaler         = psc;  /* 预分频值 */
    tim4.Init.CounterMode       = TIM_COUNTERMODE_UP;  /* 计数模式：向上计数 */
    tim4.Init.Period            = arr;  /* 自动重装载值 */
    tim4.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;  /* 时钟分频因子：1分频 */
    tim4.Init.RepetitionCounter = 0;  /* 重复计数值  */
    tim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;  /* 自动重装载值，预装载使能位 */
    HAL_TIM_Base_Init(&tim4);
    __HAL_TIM_CLEAR_FLAG(&tim4, TIM_FLAG_UPDATE);
    HAL_TIM_Base_Start_IT(&tim4);
}

/***************************************************************************************************
 * @fn      HAL_TIM_Base_MspInit
 *
 * @brief   定时器初始化时要做的操作
 *
 * @param   htim 定时器总控制结构体
 *
 * @return  无 
 */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)
    {
        __HAL_RCC_TIM1_CLK_ENABLE();  /* 开定时器1时钟 */

        /* 设置中断优先级 */
        HAL_NVIC_SetPriority(TIM1_UP_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(TIM1_UP_IRQn);
    }
    else if (htim->Instance == TIM2)
    {
        __HAL_RCC_TIM2_CLK_ENABLE();  /* 开定时器2时钟 */

        /* 设置中断优先级 */
        HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(TIM2_IRQn);
    }
    else if (htim->Instance == TIM3)
    {
        __HAL_RCC_TIM3_CLK_ENABLE();  /* 开定时器3时钟 */

        /* 设置中断优先级 */
        HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(TIM3_IRQn);
    }
    else if (htim->Instance == TIM4)
    {
        __HAL_RCC_TIM4_CLK_ENABLE();  /* 开定时器4时钟 */

        /* 设置中断优先级 */
        HAL_NVIC_SetPriority(TIM4_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(TIM4_IRQn);
    }
}

/***************************************************************************************************
 * @fn      HAL_TIM_Base_MspDeInit
 *
 * @brief   定时器去初始化时要做的操作
 *
 * @param   htim 定时器总控制结构体
 *
 * @return  无 
 */
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)
    {
        __HAL_RCC_TIM1_CLK_DISABLE();  /* 关定时器1时钟 */
        HAL_NVIC_DisableIRQ(TIM1_UP_IRQn);
    }
    else if (htim->Instance == TIM2)
    {
        __HAL_RCC_TIM2_CLK_DISABLE();  /* 关定时器2时钟 */
        HAL_NVIC_DisableIRQ(TIM2_IRQn);
    }
    else if (htim->Instance == TIM3)
    {
        __HAL_RCC_TIM3_CLK_DISABLE();  /* 关定时器3时钟 */
        HAL_NVIC_DisableIRQ(TIM3_IRQn);
    } 
    else if (htim->Instance == TIM4)
    {
        __HAL_RCC_TIM4_CLK_DISABLE();  /* 关定时器4时钟 */
        HAL_NVIC_DisableIRQ(TIM4_IRQn);
    }
}

extern volatile uint32_t g_timer_count;


/***************************************************************************************************
 * @fn      HAL_TIM_PeriodElapsedCallback
 *
 * @brief   更新中断处理函数
 *
 * @param   无
 *
 * @return  无 
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)
    {
        BSP_LOG("定时器1定时时间到\r\n");
    }
    else if (htim->Instance == TIM2)
    {
        BSP_LOG("定时器2定时时间到\r\n");
        systick_isr();
        HAL_IncTick();
    }
    else if (htim->Instance == TIM3)
    {
        BSP_LOG("定时器3定时时间到\r\n");
    }
    else if (htim->Instance == TIM4)
    {
        BSP_LOG("定时器4定时时间到\r\n");
    }
}

/***************************************************************************************************
 * @fn      TIM1_UP_IRQHandler
 *
 * @brief   定时器1更新中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void TIM1_UP_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&tim1);
}

/***************************************************************************************************
 * @fn      TIM2_IRQHandler
 *
 * @brief   定时器2中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&tim2);
}

/***************************************************************************************************
 * @fn      TIM3_IRQHandler
 *
 * @brief   定时器3中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&tim3);
}

/***************************************************************************************************
 * @fn      TIM4_IRQHandler
 *
 * @brief   定时器4中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void TIM4_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&tim4);
}
