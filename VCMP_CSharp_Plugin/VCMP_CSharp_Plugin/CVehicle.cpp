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

void VCMPCSharpPlugin::CVehicle::Respawn()
{
	if (this->Valid) api->RespawnVehicle(this->ID);
}

void VCMPCSharpPlugin::CVehicle::Explode()
{
	if (this->Valid) api->ExplodeVehicle(this->ID);
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::CVehicle::GetVehicleSpeed(bool relative)
{
	if (this->Valid)
	{
		float* x = nullptr, * y = nullptr, * z = nullptr;
		api->GetVehicleSpeed(this->ID, x, y, z,relative);
		return gcnew Vector(*x, *y, *z);
	}
	else return Vector::Zero;
}

void VCMPCSharpPlugin::CVehicle::SetVehicleSpeed(Vector^ speed,bool relative)
{
	if (this->Valid) api->SetVehicleSpeed(this->ID, speed->x, speed->y, speed->z, false, relative);
}

void VCMPCSharpPlugin::CVehicle::AddVehicleSpeed(Vector^ speed,bool relative)
{
	if (this->Valid) api->SetVehicleSpeed(this->ID, speed->x, speed->y, speed->z, true, relative);
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::CVehicle::GetVehicleTurnSpeed(bool relative)
{
	if (this->Valid)
	{
		float* x = nullptr, * y = nullptr, * z = nullptr;
		api->GetVehicleTurnSpeed(this->ID, x, y, z, relative);
		return gcnew Vector(*x, *y, *z);
	}
	else return Vector::Zero;
}

void VCMPCSharpPlugin::CVehicle::SetVehicleTurnSpeed(Vector^ speed,bool relative)
{
	if (this->Valid) api->SetVehicleTurnSpeed(this->ID, speed->x, speed->y, speed->z, false, relative);
}

void VCMPCSharpPlugin::CVehicle::AddVehicleTurnSpeed(Vector^ speed, bool relative)
{
	if (this->Valid) api->SetVehicleTurnSpeed(this->ID, speed->x, speed->y, speed->z, true, relative);
}

void VCMPCSharpPlugin::CVehicle::Delete()
{
	api->DeleteVehicle(this->ID);
}

int VCMPCSharpPlugin::CVehicle::GetPartStatus(int part)
{
	if (this->Valid) return api->GetVehiclePartStatus(this->ID, part);
	else return 0;
}

void VCMPCSharpPlugin::CVehicle::SetPartStatus(int part, int state)
{
	if (this->Valid) api->SetVehiclePartStatus(this->ID, part, state);
}

int VCMPCSharpPlugin::CVehicle::GetTyreStatus(int part)
{
	if (this->Valid) return api->GetVehicleTyreStatus(this->ID, part);
	else return 0;
}

void VCMPCSharpPlugin::CVehicle::SetTyreStatus(int part, int state)
{
	if (this->Valid) api->SetVehicleTyreStatus(this->ID, part, state);
}

void VCMPCSharpPlugin::CVehicle::ResetAllVehicleHandlings()
{
	api->ResetAllVehicleHandlings();
}

bool VCMPCSharpPlugin::CVehicle::HandlingModelRuleExists(int model, int rule)
{
	api->ExistsHandlingRule(model, rule);
}

void VCMPCSharpPlugin::CVehicle::SetModelHandlingRule(int model, int rule, double v)
{
	api->SetHandlingRule(model, rule, v);
}

double VCMPCSharpPlugin::CVehicle::GetModelHandlingRule(int model, int rule)
{
	return api->GetHandlingRule(model, rule);
}

void VCMPCSharpPlugin::CVehicle::ResetModelHandlingRule(int model, int rule)
{
	api->ResetHandlingRule(model, rule);
}

void VCMPCSharpPlugin::CVehicle::ResetModelHandling(int model)
{
	api->ResetHandling(model);
}

bool VCMPCSharpPlugin::CVehicle::HandlingRuleExists(int rule)
{
	if (this->Valid) return api->ExistsInstHandlingRule(this->ID, rule);
	else return false;
}

void VCMPCSharpPlugin::CVehicle::SetHandlingRule(int rule, double v)
{
	if (this->Valid) api->SetInstHandlingRule(this->ID, rule, v);
}

double VCMPCSharpPlugin::CVehicle::GetHandlingRule(int rule, double v)
{
	if (this->Valid) api->GetInstHandlingRule(this->ID, rule);
}

void VCMPCSharpPlugin::CVehicle::ResetHandlingRule(int rule)
{
	if (this->Valid) api->ResetInstHandlingRule(this->ID, rule);
}

void VCMPCSharpPlugin::CVehicle::ResetHandlingRules()
{
	if (this->Valid) api->ResetInstHandling(this->ID);
}
