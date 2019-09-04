#pragma once
#include "VCMP.h"
#include "Common.h"
#include "CPlayer.h"

namespace VCMPCSharpPlugin
{
	public ref class CVehicle
	{
		CVehicle();
	public:
		CVehicle(int id) : ID(id) {};
		int ID;
		property bool Valid
		{
			bool get()
			{
				return api->CheckEntityExists(vcmpEntityPool::vcmpEntityPoolVehicle, this->ID);
			}
		}
		//CPlayer ^GetPlayerFromSlot();
	};
}
