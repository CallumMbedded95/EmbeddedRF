#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stdlib.h"
#include "stdarg.h"
#include <stdint.h>

#define DEBUG_UART USART1
#define delay for(int i=0;i<5000000;++i)

//static void printMsg(char *msg, ...);
static void printMsg();

int main()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; //RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_USART1EN | 
	// GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1;
	// GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);

	// USART1->BRR = 0x1D4C;
	// USART1->CR1 |= USART_CR1_TE;
	// USART1->CR1 |= USART_CR1_UE;

	GPIOB->CRH |= GPIO_CRH_MODE12_1;
	GPIOB->CRH &= ~(GPIO_CRH_CNF12_1 | GPIO_CRH_CNF12_0);
	GPIOB->ODR |= GPIO_ODR_ODR12;


	while(1)
	{
		//printMsg();

		delay;
	}
}

void printMsg()
{
	char buff[100];

	for (int i =0;i<100;++i)
	{
		USART1->DR = 'a';
		while ( !(USART1->SR & USART_SR_TXE));
	}
}