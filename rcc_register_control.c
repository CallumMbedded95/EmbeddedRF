#include "rcc_register_control.h"

// SET TIMING FOR GPIO PORTB
void set_apb2rstr(uint32_t RCC_REG)
{
	*(volatile uint32_t *)(RCC_BASE + RCC_APB2ENR_OFFSET) |= RCC_REG;
}