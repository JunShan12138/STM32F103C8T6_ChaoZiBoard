
#include "bsp.h"


/***************************************************************************************************
 * @fn      system_clock_init_hsi
 *
 * @brief   使用HSI配置系统时钟
 *
 * @param   无
 *
 * @return  无
 */
void system_clock_init_hsi(void)
{
    RCC_OscInitTypeDef RCC_OscInit;
    RCC_PLLInitTypeDef RCC_PLLInit;
    RCC_ClkInitTypeDef RCC_ClkInit;

    /* 配置PLL */
    RCC_PLLInit.PLLState  = RCC_PLL_ON;  /* 打开PLL */
    RCC_PLLInit.PLLSource = RCC_PLLSOURCE_HSI_DIV2;  /* PLL时钟源选择HSI二分频 */
    RCC_PLLInit.PLLMUL    = RCC_PLL_MUL16;

    /* 时钟源选择 */
    RCC_OscInit.OscillatorType      = RCC_OSCILLATORTYPE_HSI;  /* 振荡源类型 */ 
    RCC_OscInit.HSEState            = RCC_HSE_OFF;  /* 关闭外部高速振荡源 */
    RCC_OscInit.HSEPredivValue      = RCC_HSE_PREDIV_DIV1;
    RCC_OscInit.LSEState            = RCC_LSE_OFF;  /* 关闭外部低速振荡源 */
    RCC_OscInit.HSIState            = RCC_HSI_ON;   /* 打开内部高速振荡源 */
    RCC_OscInit.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;  /* HSI微调值 */
    RCC_OscInit.LSIState            = RCC_LSI_OFF;  /* 关闭内部低速振荡源 */
    RCC_OscInit.PLL                 = RCC_PLLInit;          
    HAL_RCC_OscConfig(&RCC_OscInit);

    /* 时钟配置 */
    RCC_ClkInit.ClockType      = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
                                 RCC_CLOCKTYPE_PCLK1  | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInit.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInit.AHBCLKDivider  = RCC_SYSCLK_DIV1;  /* AHB分频系数 */
    RCC_ClkInit.APB1CLKDivider = RCC_HCLK_DIV2;    /* APB1分频系数 */
    RCC_ClkInit.APB2CLKDivider = RCC_HCLK_DIV1;    /* APB2分频系数 */
    HAL_RCC_ClockConfig(&RCC_ClkInit, FLASH_LATENCY_2);

    SystemCoreClockUpdate();
}


/***************************************************************************************************
 * @fn      system_clock_init_hse
 *
 * @brief   使用HSE配置系统时钟
 *
 * @param   无
 *
 * @return  无
 */
void system_clock_init_hse(void)
{
    RCC_OscInitTypeDef RCC_OscInit;
    RCC_PLLInitTypeDef RCC_PLLInit;
    RCC_ClkInitTypeDef RCC_ClkInit;

    /* 配置PLL */
    RCC_PLLInit.PLLState  = RCC_PLL_ON;  /* 打开PLL */
    RCC_PLLInit.PLLSource = RCC_PLLSOURCE_HSE;  /* PLL时钟源选择HSE */
    RCC_PLLInit.PLLMUL    = RCC_PLL_MUL9;

    /* 时钟源选择 */
    RCC_OscInit.OscillatorType      = RCC_OSCILLATORTYPE_HSE;  /* 振荡源类型 */ 
    RCC_OscInit.HSEState            = RCC_HSE_ON;  /* 打开外部高速振荡源 */
    RCC_OscInit.HSEPredivValue      = RCC_HSE_PREDIV_DIV1;
    RCC_OscInit.LSEState            = RCC_LSE_OFF;  /* 关闭外部低速振荡源 */
    RCC_OscInit.HSIState            = RCC_HSI_OFF;   /* 关闭内部高速振荡源 */
    RCC_OscInit.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;  /* HSI微调值 */
    RCC_OscInit.LSIState            = RCC_LSI_OFF;  /* 关闭内部低速振荡源 */
    RCC_OscInit.PLL                 = RCC_PLLInit;          
    HAL_RCC_OscConfig(&RCC_OscInit);

    /* 时钟配置 */
    RCC_ClkInit.ClockType      = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
                                 RCC_CLOCKTYPE_PCLK1  | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInit.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInit.AHBCLKDivider  = RCC_SYSCLK_DIV1;  /* AHB分频系数 */
    RCC_ClkInit.APB1CLKDivider = RCC_HCLK_DIV2;    /* APB1分频系数 */
    RCC_ClkInit.APB2CLKDivider = RCC_HCLK_DIV1;    /* APB2分频系数 */
    HAL_RCC_ClockConfig(&RCC_ClkInit, FLASH_LATENCY_2);

    SystemCoreClockUpdate();
}


