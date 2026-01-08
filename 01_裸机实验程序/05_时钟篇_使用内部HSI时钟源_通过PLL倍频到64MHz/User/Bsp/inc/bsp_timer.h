#ifndef __BSP_TIMER_H__
#define __BSP_TIMER_H__

#include <stdint.h>

int32_t bsp_get_run_time(void);
int32_t bsp_check_run_time(int32_t last_time);

void bsp_delay_ms(uint32_t n);
void bsp_delay_us(uint32_t n);

void systick_isr(void);

#endif  /* __BSP_TIMER_H__ */
