#ifndef COMMON_H
#define COMMON_H

namespace Common
{
	template<typename T>
	constexpr volatile T* GetRegister(uint32_t Register_Address)
	{
		return reinterpret_cast<volatile T*>(Register_Address);
	}
}

#endif
