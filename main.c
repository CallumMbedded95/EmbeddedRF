#include "stm32f10x.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"
#include "stdint.h"

#define DEBUG_UART USART1
#define delay for(int i=0;i<500000;++i)

static void printMsg(char* msg, ...);

int main()
{
	GPIOA->CRH = 0;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_USART1EN; 
	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1;
	GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);

	//USART1->BRR = 0x1D4C; // for 72mhz clock
	USART1->BRR = 0x0341; // for 8MHz clock

	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_UE;


	while(1)
	{
		printMsg("test");

		delay;
	}
}

void printMsg(char* msg, ...)
{
	//char buff[80];
	char buff = 'a';
	//va_list args;
	//va_start(args, msg);
	//vsprintf(buff,msg,args);

	//for (int i =0;i<1;++i)
	//for (;;)
	//{
		USART1->DR = buff;
		while ( !(USART1->SR & USART_SR_TXE));
	//}
	
	GPIOB->CRH |= GPIO_CRH_MODE12_1;
	GPIOB->CRH &= ~(GPIO_CRH_CNF12_1 | GPIO_CRH_CNF12_0);
	GPIOB->ODR |= GPIO_ODR_ODR12;
}
