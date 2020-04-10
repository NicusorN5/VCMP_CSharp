#include "stdafx.h"
#include "CVehicle.h"


VCMPCSharpPlugin::CVehicle::CVehicle()
{

}

VCMPCSharpPlugin::CVehicle::CVehicle(int Model, int world, Vector pos, float rotation, int c1, int c2)
{
	this->_id = api->CreateVehicle(Model, world, pos.x, pos.y, pos.z, rotation, c1, c2);
}


VCMPCSharpPlugin::CPlayer^ VCMPCSharpPlugin::CVehicle::GetOccupant(int slot)
{
	if (this->Valid)
	{
		return gcnew CPlayer(api->GetVehicleOccupant(this->ID, slot));
	}
	return nullptr;
}

