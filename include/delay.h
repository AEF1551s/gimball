#if !defined(DELAY_H)
#define DELAY_H

// CMSIS
#include <stm32f410rx.h>
#include <stm32f4xx.h>
// STD
#include <stdbool.h>

/*
Implements ms delay with TIM6 (General purpose 16 bit timer) and interrupts
Single counter cycle is 1ms. Counter counts till auto-reload then generates interupt.
Interrupts are only generated when counter reaches auto-reload value
Uses one-pulse mode - once counter has reached auto-reload value, time ir disabled until next delay_ms() call
With default clock configuration SYSCLK and AHB AND APB are 16Mhz (HSI clock).
Delay uses TIM6 with 16000 prescaler which makes 1 interrupt cycle 1ms. 
*/

volatile static bool flag = false;

void delayInit();
void delayMs(uint16_t ms);
#endif // DELAY_H
