#include "RCCRegisterControl.h"

void RCC::Set_APB2ENR(uint32_t RCC_Bit)
{
	RCC::RCC_Register(RCC::RCC_BASE)->APB2ENR |= RCC_Bit;
}
