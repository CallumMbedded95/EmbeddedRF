#include <stdint.h>
#include "gpio_definitions.h"
#include "rcc_register_control.h"

#define RCC_IOPBEN (1<<3)

#define GPIOB_CRH *(volatile uint32_t *)(GPIOB_BASE + GPIOx_CRH_OFFSET)

void main (void)
{
	set_apb2rstr(RCC_IOPBEN);
	GPIOB_CRH &= 0x0000FFFF;

	set_gpio_crh(GPIOB_BASE, 0x0, 0x1U, 0x10U);
	set_gpio_crh(GPIOB_BASE, 0x0, 0x1U, 0x14U);
	set_gpio_crh(GPIOB_BASE, 0x0, 0x1U, 0x18U);
	set_gpio_crh(GPIOB_BASE, 0x0, 0x1U, 0x1CU);
	while (1)
	{		
		set_gpio_odr(GPIOB_BASE, 0x1U, 0xCU);
		set_gpio_odr(GPIOB_BASE, 0x1U, 0xDU);
		set_gpio_odr(GPIOB_BASE, 0x1U, 0xEU);
		set_gpio_odr(GPIOB_BASE, 0x1U, 0xFU);
		for (int i=0;i<2500000;i++);
		//GPIOB_ODR &= ~GPIOB_ODR;
		set_gpio_odr(GPIOB_BASE, 0x0U, 0xCU);
		for (int i=0;i<2500000;i++);
	}
}
