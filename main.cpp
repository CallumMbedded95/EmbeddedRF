#include <stdint.h>
#include "GPIODefinitions.h"
#include "RCCRegisterControl.h"
#include "Timer.h"
//#include "UART.h"

#define RCC_IOPBEN (1<<3)

#define GPIOB_CRH *(volatile uint32_t *)(GPIODefinitions::GPIOB_BASE + GPIODefinitions::GPIOx_CRH_OFFSET)

int main (void)
{
	set_apb2rstr(RCC_IOPBEN);
	GPIOB_CRH &= 0x0000FFFF;

	GPIODefinitions::set_gpio_crh(GPIODefinitions::GPIOB_BASE, 0x0, 0x1U, 0x10U);
	GPIODefinitions::set_gpio_crh(GPIODefinitions::GPIOB_BASE, 0x0, 0x1U, 0x14U);
	GPIODefinitions::set_gpio_crh(GPIODefinitions::GPIOB_BASE, 0x0, 0x1U, 0x18U);
	GPIODefinitions::set_gpio_crh(GPIODefinitions::GPIOB_BASE, 0x0, 0x1U, 0x1CU);

	tim2_enable_clock(0xFF);

	// Simply turn on PIN12
	GPIODefinitions::set_gpio_odr(GPIODefinitions::GPIOB_BASE, 0x1U, 0xCU);
	
	while (1)
	{
		// Testing TIM2 Reg is configured correctly.
		// If the ctr is above 5000 then assume the clock is running. Toggle GPIO Pin13
		if (get_tim2_clock_ctr() > 5000)
			GPIODefinitions::set_gpio_odr(GPIODefinitions::GPIOB_BASE, 0x1U, 0xDU);
		GPIODefinitions::set_gpio_odr(GPIODefinitions::GPIOB_BASE, 0x1U, 0xCU);
		GPIODefinitions::set_gpio_odr(GPIODefinitions::GPIOB_BASE, 0x1U, 0xDU);
		GPIODefinitions::set_gpio_odr(GPIODefinitions::GPIOB_BASE, 0x1U, 0xEU);
		GPIODefinitions::set_gpio_odr(GPIODefinitions::GPIOB_BASE, 0x1U, 0xFU);

		for (int i=0;i<5000000;i++);
		//*(volatile uint32_t*)(UART5 + USART_CR1) |= (1<<3);
		//WRITE DATA TO USART_DR REG
		//*(volatile uint32_t*)(UART5 + USART_DR) = 'a';
	}
}
