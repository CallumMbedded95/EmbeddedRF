#include "GPIODefinitions.h"

void GPIO::set_gpio_crh(uint32_t GPIOx_ADDR, uint8_t CNF, uint8_t MOD, uint8_t GPIO_NUM)
{	
	uint8_t 	_CNF_MOD_ = (CNF << 2) | MOD;
	uint32_t 	_GPIOx_SETTINGS_ = _CNF_MOD_ << GPIO_NUM;
	*(volatile uint32_t *)(GPIOx_ADDR + GPIOx_CRH_OFFSET) |= _GPIOx_SETTINGS_;
}

void GPIO::Set_GPIO_CRH(uint32_t GPIOx_Base_Addr, uint8_t CNF, uint8_t MOD, uint32_t GPIO_NUM)
{	
	uint32_t CNF_MOD = (CNF << 2) | MOD;
	GPIOx_REG(GPIOx_Base_Addr)->CRH |= (CNF_MOD << GPIO_NUM); 
}

void GPIO::Set_GPIO_CRL(uint32_t GPIOx_Base_Addr, uint8_t CNF, uint8_t MOD, uint32_t GPIO_NUM)
{	uint32_t CNF_MOD = (CNF << 2) | MOD;
	GPIOx_REG(GPIOx_Base_Addr)->CRL |= (CNF_MOD << GPIO_NUM); 	
}

void GPIO::set_gpio_odr(uint32_t GPIOx_ADDR, uint8_t OUT, uint8_t GPIO_NUM)
{
	volatile uint32_t* ODR_DATA = (volatile uint32_t *)(GPIOx_ADDR + GPIOx_ODR_OFFSET);
	// SET THE BIT WE'RE INTERESTED IN TO ZERO THEN OR WITH REQUESTED OUTPUT BIT.
	*ODR_DATA = *ODR_DATA & ~(1 << GPIO_NUM) | (OUT << GPIO_NUM);
}

void GPIO::Set_GPIO_ODR(uint32_t GPIOx_Base_Addr, uint8_t Out, uint8_t GPIO_Num)
{
	GPIOx_REG(GPIOx_Base_Addr)->ODR = GPIOx_REG(GPIOx_Base_Addr)->ODR & ~(1 << GPIO_Num) | (Out << GPIO_Num);
}

void GPIO::Set_GPIO_BSRR(uint32_t GPIOx_Base_Addr, uint8_t SetReset, uint16_t GPIO_Num)
{
	GPIOx_REG(GPIOx_Base_Addr)->BSRR = SetReset ? GPIO_Num : GPIO_Num << 16U;
}
