#include <stdint.h>

// Register Port enable address.
#define RCC_BASE 0x40021000
// Offset register which enables GPIO input/output mode (0/1)
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
// Bit field value to set for the RCC_APB2ENR to set GPIO PB_12 to output.
#define RCC_IOPBEN (1<<3)
#define GPIOB12 (1UL<<12)

// GPIO Input/Output read/write start address for each port letter.
#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
#define GPIOC_BASE 0x40011000
#define GPIOD_BASE 0x40011400
#define GPIOE_BASE 0x40011800
#define GPIOF_BASE 0x40011C00
#define GPIOG_BASE 0x40012000

// Offset port for settings regarding GPIO PB_13
#define GPIOx_CRH_OFFSET 0x04
#define GPIOx_ODR_OFFSET 0x0C

#define GPIOB_CRH *(volatile uint32_t *)(GPIOB_BASE + GPIOx_CRH_OFFSET)
#define GPIOB_ODR *(volatile uint32_t *)(GPIOB_BASE + GPIOx_ODR_OFFSET)

void main (void)
{
	// Directly change the GPIO register to have bit 3 to output (PB12)
	RCC_APB2ENR |=  RCC_IOPBEN;
	GPIOB_CRH &= 0xFFF0FFFF;
	GPIOB_CRH |= 0x00010000;

	while (1)
	{
		GPIOB_ODR |= GPIOB12;
		for (int i=0;i<500000;i++);
		GPIOB_ODR &= ~GPIOB_ODR;
		for (int i=0;i<500001;i++);
	}
}
