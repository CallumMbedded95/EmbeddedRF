#include <stdint.h>
#include "GPIODefinitions.h"
#include "RCCRegisterControl.h"
#include "Timer.h"
//#include "UART.h"

#define RCC_IOPBEN (1<<3)

#define GPIOB_CRH *(volatile uint32_t *)(GPIO::GPIOB_Base + GPIO::GPIOx_CRH_OFFSET)

int main (void)
{
	set_apb2rstr(RCC_IOPBEN);

	//GPIO::set_gpio_crh(GPIO::GPIOB_Base, 0x0, 0x1U, 0x10U);
	//GPIO::set_gpio_crh(GPIO::GPIOB_Base, 0x0, 0x1U, 0x14U);
	//GPIO::set_gpio_crh(GPIO::GPIOB_Base, 0x0, 0x1U, 0x18U);
	//GPIO::set_gpio_crh(GPIO::GPIOB_Base, 0x0, 0x1U, 0x1CU);
	
	GPIO::Init_GPIO_CRx(GPIO::GPIOB_Base);	
	Set_GPIO_CRH(GPIO::GPIOB_Base, GPIO::GPIO_CRx_CNF_O::GenPushPull, GPIO::GPIO_CRx_MOD::Out10MHz, GPIO::CRx_GPIO::GPIO_Pin_12);
	Set_GPIO_CRH(GPIO::GPIOB_Base, GPIO::GPIO_CRx_CNF_O::GenPushPull, GPIO::GPIO_CRx_MOD::Out10MHz, GPIO::CRx_GPIO::GPIO_Pin_13);

	tim2_enable_clock(0xFF);
		
	while (1)
	{
		// Testing TIM2 Reg is configured correctly.
		// If the ctr is above 5000 then assume the clock is running. Toggle GPIO Pin13
		//if (get_tim2_clock_ctr() > 5000)
			//GPIO::set_gpio_odr(GPIO::GPIOB_Base, 0x1U, 0xDU);
		GPIO::Set_GPIO_BSRR(GPIO::GPIOB_Base, 0x1U, GPIO::BSRR_GPIO::GPIO_Pin_12);
		GPIO::Set_GPIO_BSRR(GPIO::GPIOB_Base, 0x1U, GPIO::BSRR_GPIO::GPIO_Pin_13);
		GPIO::Set_GPIO_BSRR(GPIO::GPIOB_Base, 0x1U, GPIO::BSRR_GPIO::GPIO_Pin_14);
	
	}
}
