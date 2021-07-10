#include <stdint.h>
#include "Common.h"

#ifndef RCC_REGISTER_CONTROL_H
#define RCC_REGISTER_CONTROL_H

namespace RCC
{
	// RCC (Control/Timing enablers for ADC, GPIO, TIM, etc). Page 99.
	constexpr uint32_t RCC_BASE 		= 0x40021000;

	constexpr uint32_t RCC_CR_OFFSET 	= 0x00;
	constexpr uint32_t RCC_CFGR_OFFSET 	= 0x04;
	constexpr uint32_t RCC_CIR_OFFSET	= 0x08;
	constexpr uint32_t RCC_APB2RSTR_OFFSET	= 0x0C;
	constexpr uint32_t RCC_APB1RSTR_OFFSET	= 0x10;
	constexpr uint32_t RCC_AHBENR_OFFSET	= 0x14;
	constexpr uint32_t RCC_APB2ENR_OFFSET	= 0x18;
	constexpr uint32_t RCC_APB1ENR_OFFSET	= 0x1C;
	constexpr uint32_t RCC_BDCR_OFFSET	= 0x20;

	using RCC_Register_Type =
	struct {
		uint32_t CR;
		uint32_t CFGR;
		uint32_t CIR;
		uint32_t APB2RSTR;
		uint32_t APB1RSTR;
		uint32_t AHBENR;
		uint32_t APB2ENR;
		uint32_t APB1ENR;
		uint32_t BDCR;	
	};
	
        enum APB1ENR : uint32_t
	{
	  TIM2_EN = 	0x0001,
	  TIM3_EN = 	0x0002,
	  TIM4_EN = 	0x0004,
	  TIM5_EN = 	0x0008,
	  TIM6_EN = 	0x0010,
	  TIM7_EN =	0x0020,
	  WWD_GEN = 	0x0800,
	  SPI2_EN = 	0x4000,
	  SPI3_EN = 	0x8000,
	  USART2_EN = 0x20000,
	  USART3_EN = 0x40000,
	  USART4_EN = 0x80000,
	  USART5_EN = 0x100000,
	  I2C1_EN = 	0x200000,
	  I2C2_EN = 	0x400000,
	  CAN1_EN = 	0x2000000,
	  CAN2_EN = 	0x4000000,
	  BKP_EN = 	0x8000000,
	  PWR_EN = 	0x10000000,
	  DAC_EN = 	0x20000000,
	};

	enum APB1STR : uint32_t
	{
	  TIM2_RST = 	0x0001,
	  TIM3_RST = 	0x0002,
	  TIM4_RST = 	0x0004,
	  TIM5_RST = 	0x0008,
	  TIM6_RST = 	0x0010,
	  TIM7_RST =	0x0020,
	  TIM12_RST = 	0x0040,
	  TIM13_RST = 	0x0080,
	  TIM14_RST = 	0x0100,
	  WWDG_RST = 0x0800,
	  SPI2_RST = 0x4000,
	  SPI3_RST = 0x8000,
	  USART2_RST = 0x20000,
	  USART3_RST = 	0x40000,
	  UART4_RST = 	0x80000,
	  UART5_RST = 	0x100000,
	  I2C1_RST = 	0x200000,
	  I2C2_RST = 	0x400000,
	  USB_RST= 	0x800000,
	  CAN_RST = 	0x2000000,
	  BKP_RST = 0x8000000,
	  PWR_RST = 0x10000000,
	  DAC_RST = 0x20000000
	  };

	namespace APB2RSTR
	{
		constexpr uint32_t AFIO_RST 	= 0x0001;
		constexpr uint32_t IOPA_RST 	= 0x0004;
		constexpr uint32_t IOPB_RST 	= 0x0008;
		constexpr uint32_t IOPC_RST 	= 0x0010;
		constexpr uint32_t IOPD_RST 	= 0x0020;
		constexpr uint32_t IOPE_RST 	= 0x0040;
		constexpr uint32_t ADC1_RST 	= 0x0200;
		constexpr uint32_t ADC2_RST 	= 0x0400;
		constexpr uint32_t TIM1_RST 	= 0x0800;
		constexpr uint32_t SPI1_RST 	= 0x1000;
		constexpr uint32_t USART1_RST 	= 0x4000;
	}

	namespace APB2ENR
	{
		constexpr uint32_t AFIO_EN 	= 0x000001;
		constexpr uint32_t IOPA_EN 	= 0x000004;
		constexpr uint32_t IOPB_EN 	= 0x000008;
		constexpr uint32_t IOPC_EN 	= 0x000010;
		constexpr uint32_t IOPD_EN 	= 0x000020;
		constexpr uint32_t IOPE_EN 	= 0x000040;
		constexpr uint32_t IOPF_EN 	= 0x000080;
		constexpr uint32_t IOPG_EN 	= 0x000100;
		constexpr uint32_t ADC1_EN 	= 0x000200;
		constexpr uint32_t ADC2_EN 	= 0x000400;
		constexpr uint32_t TIM1_EN 	= 0x000800;
		constexpr uint32_t SPI1_EN 	= 0x001000;
		constexpr uint32_t TIM8_EN 	= 0x002000;
		constexpr uint32_t UART1_EN 	= 0x004000;
		constexpr uint32_t ADC3_EN 	= 0x008000;
		constexpr uint32_t TIM9_EN 	= 0x080000; 
		constexpr uint32_t TIM10_EN 	= 0x100000;
		constexpr uint32_t TIM11_EN 	= 0x200000;
	}

	constexpr volatile RCC_Register_Type* RCC_Register(uint32_t RCC_Base)
	{
		Common::GetRegister<RCC_Register_Type>(RCC_Base);
	}
	
	void Set_APB2ENR(uint32_t RCC_Bit);
};

#endif
