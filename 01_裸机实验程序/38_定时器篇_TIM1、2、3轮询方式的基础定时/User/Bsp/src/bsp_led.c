
#include "bsp.h"

#define LED4_PORT   GPIOB
#define LED4_PIN    GPIO_PIN_0  



/***************************************************************************************************
 * @fn      bsp_led_init
 *
 * @brief   初始化LED指示灯
 *
 * @param   无
 *
 * @return  无
 */
void bsp_led_init(void)
{
    GPIO_InitTypeDef GPIO_Init;

    /* 使能GPIOB时钟 */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* 先关闭指示灯 */
    HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_SET);

    /* 配置引脚 */
    GPIO_Init.Pin   = LED4_PIN;
    GPIO_Init.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pull  = GPIO_NOPULL;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED4_PORT, &GPIO_Init);
}

/***************************************************************************************************
 * @fn      bsp_led_on
 *
 * @brief   点亮LED指示灯
 *
 * @param   无
 *
 * @return  无
 */
void bsp_led_on(void)
{
    HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_RESET);
}

/***************************************************************************************************
 * @fn      bsp_led_off
 *
 * @brief   熄灭LED指示灯
 *
 * @param   无
 *
 * @return  无
 */
void bsp_led_off(void)
{
    HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_SET);
}

/***************************************************************************************************
 * @fn      bsp_led_toggle
 *
 * @brief   翻转LED指示灯
 *
 * @param   无
 *
 * @return  无
 */
void bsp_led_toggle(void)
{
    HAL_GPIO_TogglePin(LED4_PORT, LED4_PIN);
}

