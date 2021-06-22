#ifndef UART_H
#define UART_H

#include <stdio.h>

#define UART5 	0x40005000
#define UART4	0x40004c00
#define USART3	0x40004800
#define USART2	0x40004400
#define USART1 	0x40013800

#define USART_SR		0x00
#define USART_DR		0X04
#define USART_BRR		0x08
#define USART_CR1		0x0C
#define USART_CR2		0x10


// THE CLOCK CTR UPCOUNTS ALL THE WAY TO AUTO_RELOAD. (0 - AUTO RELOAD)
void enable_uart5_tx(uint32_t UE_BIT, uint8_t M_BIT, uint8_t STOP_BITS, uint32_t BAUD_RATE);

#endif