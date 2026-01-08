
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

    HAL_TIM_Base_Start(&tim1);
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

    HAL_TIM_Base_Start(&tim2);
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

    HAL_TIM_Base_Start(&tim3);
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

    HAL_TIM_Base_Start(&tim4);
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
    }
    else if (htim->Instance == TIM2)
    {
        __HAL_RCC_TIM2_CLK_ENABLE();  /* 开定时器2时钟 */
    }
    else if (htim->Instance == TIM3)
    {
        __HAL_RCC_TIM3_CLK_ENABLE();  /* 开定时器3时钟 */
    }
    else if (htim->Instance == TIM4)
    {
        __HAL_RCC_TIM4_CLK_ENABLE();  /* 开定时器4时钟 */
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
    }
    else if (htim->Instance == TIM2)
    {
        __HAL_RCC_TIM2_CLK_DISABLE();  /* 关定时器2时钟 */
    }
    else if (htim->Instance == TIM3)
    {
        __HAL_RCC_TIM3_CLK_DISABLE();  /* 关定时器3时钟 */
    }
    else if (htim->Instance == TIM4)
    {
        __HAL_RCC_TIM4_CLK_DISABLE();  /* 关定时器4时钟 */
    }
}
