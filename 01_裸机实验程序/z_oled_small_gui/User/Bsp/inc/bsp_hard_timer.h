#ifndef __BSP_HARD_TIMER_H__
#define __BSP_HARD_TIMER_H__

#include <stdint.h>

extern TIM_HandleTypeDef tim1;
extern TIM_HandleTypeDef tim2;
extern TIM_HandleTypeDef tim3;
extern TIM_HandleTypeDef tim4;

void timer1_init(uint16_t arr, uint16_t psc, uint8_t rep);
void timer2_init(uint16_t arr, uint16_t psc);
void timer3_init(uint16_t arr, uint16_t psc);
void timer4_init(uint16_t arr, uint16_t psc);

#endif  /* __BSP_HARD_TIMER_H__ */
