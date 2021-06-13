#ifndef RCC_REGISTER_CONTROL_H
#define RCC_REGISTER_CONTROL_H

#include <stdint.h>

// RCC (Control/Timing enablers for ADC, GPIO, TIM, etc). Page 99.
#define RCC_BASE 0x40021000

#define RCC_CR_OFFSET 	0x00
#define RCC_CFGR_OFFSET 0x04
#define RCC_CIR_OFFSET	0x08
#define RCC_APB2RSTR_OFFSET	0x0C
#define RCC_APB1RSTR_OFFSET	0x10
#define RCC_AHBENR_OFFSET	0x14
#define RCC_APB2ENR_OFFSET	0x18
#define RCC_APB1ENR_OFFSET	0x1C
#define RCC_BDCR_OFFSET		0x20

void set_apb2rstr(uint32_t RCC_REG);

#endif