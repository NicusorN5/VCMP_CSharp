#include "stdafx.h"
#include "CVehicle.h"


VCMPCSharpPlugin::CVehicle::CVehicle()
{

}

VCMPCSharpPlugin::CVehicle::CVehicle(int Model, int world, Vector pos, float rotation, int c1, int c2)
{
	this->ID = api->CreateVehicle(Model, world, pos.x, pos.y, pos.z, rotation, c1, c2);
}

VCMPCSharpPlugin::CPlayer^ VCMPCSharpPlugin::CVehicle::GetOccupant(int slot)
{
	throw gcnew System::NotImplementedException();
	// TODO: insert return statement here
}
