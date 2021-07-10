#include "UART.h"
#include "RCCRegisterControl.h"
#include "GPIODefinitions.h"

volatile UxART* UART_Register(uint32_t Base_Addr)
{
  return (volatile UxART*)Base_Addr;
}

void Enable_UART(uint32_t Base_Addr, uint32_t Baud_Rate)
{
  volatile UxART* UART = UART_Register(Base_Addr);
  
  // Reset and enable.
  UART->CR1 = 0x0;
  UART->CR1 |= USART_CR1::UE;
  UART->CR1 |= USART_CR1::TE;
  UART->BRR = 0x1D4C;
  UART->DR = 'a';
}

void UART_Tx_Data(uint32_t Base_Addr, uint32_t Data)
{
  volatile UxART* UART = UART_Register(Base_Addr);
  UART->DR = 'a';
}
