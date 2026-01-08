
#include "bsp.h"


#define SW_PORT   GPIOC
#define SW_PIN    GPIO_PIN_13

/* 读取按键当前的电平 */
#define SW8_IN()   HAL_GPIO_ReadPin(SW_PORT, SW_PIN)


/***************************************************************************************************
 * @fn      bsp_switch_init
 *
 * @brief   按键初始化
 *
 * @param   无
 *
 * @return  无
 */
void bsp_switch_init(void)
{
    GPIO_InitTypeDef GPIO_Init;

    /* 使能GPIOB时钟 */
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* 配置引脚 */
    GPIO_Init.Pin   = SW_PIN;
    GPIO_Init.Mode  = GPIO_MODE_INPUT;
    GPIO_Init.Pull  = GPIO_NOPULL;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(SW_PORT, &GPIO_Init);
}

/***************************************************************************************************
 * @fn      bsp_switch_init
 *
 * @brief   按键初始化
 *
 * @param   mode 0：按下执行；1：抬起执行
 *
 * @return  SW8_DOWN 按键SW8触发
 */
switch_status_e bsp_switch_scan(uint8_t mode)
{
//    uint32_t i;
    switch_status_e status = SW_NONE;

    if (SW8_IN() == 1)
    {
//        for (i = 0; i < 0x7FFF; i++)
//        {
//            if (SW8_IN() == 0)
//            {
//                return SW_NONE;
//            }
//        }

//        if (mode == 0)
//        {
//            status = SW8_DOWN;
//        }
        status = SW8_DOWN;
    }
    else
    {
        status = SW_NONE;
    }
    
    return status;
}

