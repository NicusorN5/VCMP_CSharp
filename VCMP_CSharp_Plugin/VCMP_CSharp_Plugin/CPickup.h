#pragma once
#include "Common.h"
#include "Vector.h"

namespace VCMPCSharpPlugin
{
	public ref class CPickup
	{
		int _id;
	public:
		CPickup(int id);
		CPickup(int model, int world, int quantity, Vector^ pos, uint8_t alpha, bool autom);
		property int ID
		{
			int get()
			{
				return _id;
			}
		}
	};
}

