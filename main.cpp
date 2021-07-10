#include <stdint.h>
#include "GPIODefinitions.h"
#include "RCCRegisterControl.h"
#include "Timer.h"
#include "UART.h"

int main (void)
{
	RCC::Set_APB2ENR(RCC::APB2ENR::IOPB_EN);
	
	GPIO::Init_GPIO_CRx(GPIO::GPIOB_Base);	
	Set_GPIO_CRH(GPIO::GPIOB_Base, GPIO::GPIO_CRx_CNF_O::GenPushPull, GPIO::GPIO_CRx_MOD::Out10MHz, GPIO::CRx_GPIO::GPIO_Pin_12);
	Set_GPIO_CRH(GPIO::GPIOB_Base, GPIO::GPIO_CRx_CNF_O::GenPushPull, GPIO::GPIO_CRx_MOD::Out10MHz, GPIO::CRx_GPIO::GPIO_Pin_13);

	//tim2_enable_clock(0xFF);

	Enable_UART((uint32_t)UART5, (uint32_t)0);

	RCC::RCC_Register(RCC::RCC_BASE)->APB1ENR |= RCC::APB1ENR::USART5_EN;
		
	while (1)
	{
	  //if (get_tim2_clock_ctr() > 5000)
	  //GPIO::Set_GPIO_BSRR(GPIO::GPIOB_Base, 0x1U, GPIO::BSRR_GPIO::GPIO_Pin_12);
	  //GPIO::Set_GPIO_BSRR(GPIO::GPIOB_Base, 0x1U, GPIO::BSRR_GPIO::GPIO_Pin_13);
	  //GPIO::Set_GPIO_BSRR(GPIO::GPIOB_Base, 0x1U, GPIO::BSRR_GPIO::GPIO_Pin_14);
	  UART_Tx_Data((uint32_t)UART5, (uint32_t)'a');
	}
}
