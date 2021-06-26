#include "UART.h"
#include "RCCRegisterControl.h"
#include "GPIODefinitions.h"

// THE CLOCK CTR UPCOUNTS ALL THE WAY TO AUTO_RELOAD. (0 - AUTO RELOAD)
void enable_uart5_tx(uint32_t UE_BIT, uint8_t M_BIT, uint8_t STOP_BITS, uint32_t BAUD_RATE)
{
	// SET RCC USART CLOCK
	*(volatile uint32_t*)(RCC_BASE + RCC_APB2ENR_OFFSET) |= (1<<14) | (1<<2) | 0x1;

	// SET GPIO OUTPUT MODE AND CONFIG TO USE UART
	set_gpio_crh(GPIOA_BASE, 0x0, 0x1U, 0x4U);
	*(volatile uint32_t*)(GPIOA_BASE + GPIOx_CRH_OFFSET) |= 

	// ENABLE USART BIT.
	*(volatile uint32_t*)(USART1 + USART_CR1) |= (1<<13);
	// LEAVE M AND STOP BIT(s) AS IS.

	// SET BAUD RATE IN BRR
	*(volatile uint32_t*)(USART1 + USART_BRR) = 0x1D4C;
	// SET TE TO SEND IDLE FRAME AS FIRST XMISSION
	*(volatile uint32_t*)(USART1 + USART_CR1) |= (1<<3);
	//WRITE DATA TO USART_DR REG
	*(volatile uint32_t*)(USART1 + USART_DR) = 'a';
	//WAIT FOR USART_DR REG TC=1 WHICH INDICDATES LAST FROM COMPLETE
}
