#pragma once
#include "Common.h"
#include "Vector.h"
#include "Color.h"
namespace VCMPCSharpPlugin
{
	public ref class CCheckPoint
	{
		int _id;
	public:
		CCheckPoint(int id);
		CCheckPoint(int world, bool issphere, Vector^ pos, Color^ color, uint8_t alpha, float R);
		property int ID
		{
			int get()
			{
				return _id;
			}
		}
	};
}

