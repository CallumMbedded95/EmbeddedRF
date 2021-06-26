#include "GPIODefinitions.h"

// DOES NOT SET BIT TO ZERO IF REG WAS ALREADY SET TO ONE // FIX
void GPIODefinitions::set_gpio_crh(uint32_t GPIOx_ADDR, uint8_t CNF, uint8_t MOD, uint8_t GPIO_NUM)
{	
	uint8_t 	_CNF_MOD_ = (CNF << 2) | MOD;
	uint32_t 	_GPIOx_SETTINGS_ = _CNF_MOD_ << GPIO_NUM;
	*(volatile uint32_t *)(GPIOx_ADDR + GPIOx_CRH_OFFSET) |= _GPIOx_SETTINGS_;
}

void GPIODefinitions::set_gpio_odr(uint32_t GPIOx_ADDR, uint8_t OUT, uint8_t GPIO_NUM)
{
	volatile uint32_t* ODR_DATA = (volatile uint32_t *)(GPIOx_ADDR + GPIOx_ODR_OFFSET);
	// SET THE BIT WE'RE INTERESTED IN TO ZERO THEN OR WITH REQUESTED OUTPUT BIT.
	*ODR_DATA = *ODR_DATA & ~(1 << GPIO_NUM) | (OUT << GPIO_NUM);
}
