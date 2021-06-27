#include "GPIODefinitions.h"

void GPIO::Init_GPIO_CRx(uint32_t GPIOx_Base_Addr)
{
	// Set CRH and CRL to zero.
	GPIOx_REG(GPIOx_Base_Addr)->CRH = 0x0;
	GPIOx_REG(GPIOx_Base_Addr)->CRL = 0x0; 
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

void GPIO::Set_GPIO_ODR(uint32_t GPIOx_Base_Addr, uint8_t SetBit, uint8_t GPIO_Num)
{
	GPIOx_REG(GPIOx_Base_Addr)->ODR = GPIOx_REG(GPIOx_Base_Addr)->ODR & ~(1 << GPIO_Num) | (SetBit << GPIO_Num);
}

void GPIO::Set_GPIO_BSRR(uint32_t GPIOx_Base_Addr, uint8_t SetReset, uint16_t GPIO_Num)
{
	GPIOx_REG(GPIOx_Base_Addr)->BSRR = SetReset ? GPIO_Num : GPIO_Num << 16U;
}
