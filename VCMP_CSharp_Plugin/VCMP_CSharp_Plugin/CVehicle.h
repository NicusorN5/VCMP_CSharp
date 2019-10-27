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
		CVehicle(int Model, int world, Vector pos, float rotation, int c1, int c2);
		int ID;
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