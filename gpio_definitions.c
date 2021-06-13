#include "gpio_definitions.h"

void set_gpio_crh(uint32_t GPIOx_ADDR, uint8_t CNF, uint8_t MOD, uint8_t GPIO_NUM)
{
	
	//uint8_t 	_CNF_MOD_ = (CNF << 2) | MOD;
	//uint32_t 	_GPIOx_SETTINGS_ = _CNF_MOD_ << GPIO_NUM
	//*(volatile uint32_t *) (GPIOx_ADDR + GPIO_x_CRH_OFFSET) |= _GPIOx_SETTINGS_;
};