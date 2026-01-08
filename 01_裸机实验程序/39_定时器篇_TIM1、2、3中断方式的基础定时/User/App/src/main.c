
#include "bsp.h"

static uint8_t _number1;

int main(void)
{
    bsp_init();

    while (1)
    {
        /* 定时器1有更新 */
        if (__HAL_TIM_GET_FLAG(&tim1, TIM_FLAG_UPDATE))
        {
            /* 清定时器1更新标志 */
            __HAL_TIM_CLEAR_FLAG(&tim1, TIM_FLAG_UPDATE);

            DEBUG_LOG("定时器1定时时间到: %d\r\n", _number1++);

            if (_number1 == 5)
            {
                HAL_TIM_Base_Stop(&tim1);
                HAL_TIM_Base_DeInit(&tim1);
            }
        }

        // /* 定时器2有更新 */
        // if (__HAL_TIM_GET_FLAG(&tim2, TIM_FLAG_UPDATE))
        // {
        //     /* 清定时器2更新标志 */
        //     __HAL_TIM_CLEAR_FLAG(&tim2, TIM_FLAG_UPDATE);

        //     DEBUG_LOG("定时器2定时时间到\r\n");
        // }

        // /* 定时器3有更新 */
        // if (__HAL_TIM_GET_FLAG(&tim3, TIM_FLAG_UPDATE))
        // {
        //     /* 清定时器3更新标志 */
        //     __HAL_TIM_CLEAR_FLAG(&tim3, TIM_FLAG_UPDATE);

        //     DEBUG_LOG("定时器3定时时间到\r\n");
        // }

        // /* 定时器4有更新 */
        // if (__HAL_TIM_GET_FLAG(&tim4, TIM_FLAG_UPDATE))
        // {
        //     /* 清定时器4更新标志 */
        //     __HAL_TIM_CLEAR_FLAG(&tim4, TIM_FLAG_UPDATE);

        //     DEBUG_LOG("定时器4定时时间到\r\n");
        // }
    }
}


