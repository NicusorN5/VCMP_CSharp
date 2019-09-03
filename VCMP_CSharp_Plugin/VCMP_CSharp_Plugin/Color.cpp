#include "stdafx.h"
#include "Color.h"

uint32_t VCMPCSharpPlugin::Color::ToUint()
{
	return 65536 * this->Red + 256 * this->Green + this->Blue;
}

VCMPCSharpPlugin::Color ^VCMPCSharpPlugin::Color::FromUInt(uint32_t v)
{
	Color^ r;
	r->Red = (v >> 16) & 0xFF;
	r->Green = (v >> 8) & 0xFF;
	r->Blue = v & 0xFF;
	return r;
}
