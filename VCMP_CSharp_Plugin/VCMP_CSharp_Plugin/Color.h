#pragma once
#include <stdint.h>
namespace VCMPCSharpPlugin
{
	public ref class Color
	{
	public:
		Color() : Red(0), Green(0), Blue(0) {};
		Color(uint8_t r, uint8_t g, uint8_t b) : Red(r), Green(g), Blue(b) {};
		uint8_t Red, Green, Blue;
		uint32_t ToUint();
		static Color ^FromUInt(uint32_t v);
	};
}
