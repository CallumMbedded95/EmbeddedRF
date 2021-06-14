#include <stdint.h>
#include "timer.h"
#include "rcc_register_control.h"

void tim2_enable_clock(uint16_t AUTO_RELOAD)
{
	// Set the RCC Clock enable bit first.
	*(volatile uint32_t *)(RCC_BASE + RCC_APB1ENR_OFFSET) |= 0x1;
	*(volatile uint32_t *)(TIM2_ADDR + TIMx_ARR_OFFSET) |= AUTO_RELOAD;
	*(volatile uint32_t *)(TIM2_ADDR + TIMx_CR1_OFFSET) |= 0x1U;
}

int32_t get_tim2_clock_ctr()
{
	return *(volatile uint32_t *)(TIM2_ADDR + TIMx_CNT_OFFSET);
}