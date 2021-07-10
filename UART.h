#ifndef UART_H
#define UART_H

#include <stdio.h>

#define UART5 	0x40005000
#define UART4	0x40004c00
#define USART3	0x40004800
#define USART2	0x40004400
#define USART1 	0x40013800

//#define USART_SR		0x00
//#define USART_DR		0X04
//#define USART_BRR		0x08
//#define USART_CR1		0x0C
//#define USART_CR2		0x10

struct UxART
{
  uint32_t SR;
  uint32_t DR;
  uint32_t BRR;
  uint32_t CR1;
  uint32_t CR2;
  uint32_t CR3;
  uint32_t GTPR;
};

enum USART_CR1 : uint16_t
{
    SBK = 0x0001,
    RWU = 0x0002,
    RE = 0x0004,
    TE = 0x0008,
    IDLEIE = 0x0010,
    RXNEIE = 0x0020,
    TCIE = 0x0040,
    TXEIE = 0x0080,
    PEIE = 0x0100,
    PS = 0x0200,
    PCE = 0x0400,
    WAKE = 0x0800,
    M = 0x1000,
    UE = 0x2000
};

// THE CLOCK CTR UPCOUNTS ALL THE WAY TO AUTO_RELOAD. (0 - AUTO RELOAD)
void enable_uart5_tx(uint32_t UE_BIT, uint8_t M_BIT, uint8_t STOP_BITS, uint32_t BAUD_RATE);

void Enable_UART(uint32_t Base_Addr, uint32_t Baud_Rate);

void UART_Tx_Data(uint32_t Base_Addr, uint32_t Data);

#endif
