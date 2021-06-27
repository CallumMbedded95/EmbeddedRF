#ifndef GPIO_DEFINITIONS_H
#define GPIO_DEFINITIONS_H

#include <stdint.h>

// GPIOx PORTx BASE ADDRESSES.
namespace GPIO
{
	constexpr uint32_t GPIOA_BASE	= 0x40010800;
	constexpr uint32_t GPIOB_BASE 	= 0x40010C00;
	constexpr uint32_t GPIOC_BASE 	= 0x40011000;
	constexpr uint32_t GPIOD_BASE 	= 0x40011400;
	constexpr uint32_t GPIOE_BASE 	= 0x40011800;
	constexpr uint32_t GPIOF_BASE 	= 0x40011C00;
	constexpr uint32_t GPIOG_BASE 	= 0x40012000;

	// GPIO PORT SETTINGS (PAGE 171-174).
	constexpr uint32_t GPIOx_CRL_OFFSET	= 0x00;	// PORT CONFIGURATION REGISTER LOW
	constexpr uint32_t GPIOx_CRH_OFFSET 	= 0x04;	// PORT CONFIGURATION REGISTER HIGH
	constexpr uint32_t GPIOx_IDR_OFFSET 	= 0x08;	// PORT INPUT DATA REGISTER
	constexpr uint32_t GPIOx_ODR_OFFSET 	= 0x0C;	// PORT OUTPUT DATA REGISTER
	constexpr uint32_t GPIOx_BSRR_OFFSET 	= 0x10;	// PORT BIT SET/RESET REGISTER
	constexpr uint32_t GPIOx_BRR_OFFSET 	= 0x14;	// PORT BIT RESET REGISTER
	constexpr uint32_t GPIOx_LCKR_OFFSET 	= 0x18;	// PORT CONFIG LOCK REGISTER

	// GPIO Pin Values used for BSRR Set/Reset.
	namespace BSRR_GPIO
	{
		constexpr uint16_t GPIO_Pin_0 = 0x0001;
		constexpr uint16_t GPIO_Pin_1 = 0x0002;
		constexpr uint16_t GPIO_Pin_2 = 0x0004;
		constexpr uint16_t GPIO_Pin_3 = 0x0008;
		constexpr uint16_t GPIO_Pin_4 = 0x0010;
		constexpr uint16_t GPIO_Pin_5 = 0x0020;
		constexpr uint16_t GPIO_Pin_6 = 0x0040;
		constexpr uint16_t GPIO_Pin_7 = 0x0080;
		constexpr uint16_t GPIO_Pin_8 = 0x0100;
		constexpr uint16_t GPIO_Pin_9 = 0x0200;
		constexpr uint16_t GPIO_Pin_10 = 0x0400;
		constexpr uint16_t GPIO_Pin_11 = 0x0800;
		constexpr uint16_t GPIO_Pin_12 = 0x1000;
		constexpr uint16_t GPIO_Pin_13 = 0x2000;
		constexpr uint16_t GPIO_Pin_14 = 0x4000;
		constexpr uint16_t GPIO_Pin_15 = 0x8000;
	};

	// GPIO Pin values used in CRH/CRL	
	namespace CRx_GPIO
	{
		constexpr uint32_t GPIO_Pin_0 = 0x00;
		constexpr uint32_t GPIO_Pin_1 = 0x04;
		constexpr uint32_t GPIO_Pin_2 = 0x08;
		constexpr uint32_t GPIO_Pin_3 = 0x0C;
		constexpr uint32_t GPIO_Pin_4 = 0x10;
		constexpr uint32_t GPIO_Pin_5 = 0x14;
		constexpr uint32_t GPIO_Pin_6 = 0x18;
		constexpr uint32_t GPIO_Pin_7 = 0x1C;
		constexpr uint32_t GPIO_Pin_8 = 0x00;
		constexpr uint32_t GPIO_Pin_9 = 0x04;
		constexpr uint32_t GPIO_Pin_10 = 0x08;
		constexpr uint32_t GPIO_Pin_11 = 0x0C;
		constexpr uint32_t GPIO_Pin_12 = 0x10;
		constexpr uint32_t GPIO_Pin_13 = 0x14;
		constexpr uint32_t GPIO_Pin_14 = 0x18;
		constexpr uint32_t GPIO_Pin_15 = 0x1C;
	
	}	

	using GPIOx_Register =
	struct 
	{
		uint32_t CRL;
		uint32_t CRH; 
		uint32_t IDR;
		uint32_t ODR;
		uint32_t BSRR;
		uint16_t BRR;
		uint32_t LCKR;
	};

	// Two bit input state enum.
	enum GPIO_CRx_CNF_I : uint8_t
	{
		Analog = 0x00,
		FloatInput = 0x01,
		InputPullUp = 0x02
	};

	enum GPIO_CRx_CNF_O : uint8_t
	{
		GenPushPull = 0x00,
		GenOpenDrain = 0x01,
		AltPushPull = 0x02,
		AltOpenDrain = 0x03,
	};

	enum GPIO_CRx_MOD : uint8_t
	{
		Input = 0x0,
		Out10MHz = 0x1,
		Out2MHz = 0x2,
		Out50MHz = 0x3
	};

	// Returns the GPIOx Register struct for a given GPIO base.
	constexpr volatile GPIOx_Register* GPIOx_REG(uint32_t GPIOx_BASE)
	{
		return reinterpret_cast<GPIOx_Register*>(GPIOx_BASE);	
	} 

	// GIVEN A BASE GPIO ADDRESS, GPIO NUM, CNF AND MOD STRINGS,SETS THE CRH REGISTER.;
	void set_gpio_crh(uint32_t GPIOx_ADDR, uint8_t CNF, uint8_t MOD, uint8_t GPIO_NUM);

	// Sets the GPIO Output Data Register based on GPIO Num inputted and Output to set.
	void Set_GPIO_ODR(uint32_t GPIOx_Base_Addr, uint8_t Out, uint8_t GPIO_Num);

	// Set/Resets the GPIO Pin.
	void Set_GPIO_BSRR(uint32_t GPIOx_Base_Addr, uint8_t Out, uint16_t GPIO_Num);

	void Set_GPIO_CRL(uint32_t GPIOx_Base_Addr, uint8_t CNF, uint8_t MOD, uint32_t GPIO_NUM);

	void Set_GPIO_CRH(uint32_t GPIOx_Base_Addr, uint8_t CNF, uint8_t MOD, uint32_t GPIO_NUM);

	// GIVEN A BASE GPIO ADDRESS, GPIO NUM AND THE OUTPUT VALUE, SET THE GPIO OUTPUT BIT.
	void set_gpio_odr(uint32_t GPIOx_ADDR, uint8_t OUT, uint8_t GPIO_NUM);
};

#endif
