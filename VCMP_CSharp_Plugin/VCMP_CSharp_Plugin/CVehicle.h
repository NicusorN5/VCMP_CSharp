#pragma once
#include "VCMP.h"
#include "Common.h"
#include "CPlayer.h"
#include "Vector.h"

namespace VCMPCSharpPlugin
{
	ref class CPlayer;
	public ref class CVehicle
	{
		int _id;
		CVehicle();
	public:
		CVehicle(int id) : _id(id) {};
		CVehicle(int Model, int world, Vector pos, float rotation, int c1, int c2);
		property int ID
		{
			int get()
			{
				return _id;
			}
		}
		property bool Valid
		{
			bool get()
			{
				return api->CheckEntityExists(vcmpEntityPool::vcmpEntityPoolVehicle, this->ID);
			}
		}
		
		property CPlayer^ Driver
		{
			CPlayer^ get()
			{
				if (this->Valid) return gcnew CPlayer(api->GetVehicleOccupant(this->ID, 0));
				else return nullptr;
			}
			void set(CPlayer^ plr)
			{
				if (this->Valid)
				{
					api->PutPlayerInVehicle(plr->ID, this->ID, 0, 1, 1);
				}
			}
		}
		CPlayer^ GetOccupant(int slot);
		
	};
}