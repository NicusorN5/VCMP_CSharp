#include "stdafx.h"
#include "CPickup.h"

VCMPCSharpPlugin::CPickup::CPickup(int id)
{
	_id = id;
}

VCMPCSharpPlugin::CPickup::CPickup(int model, int world,int quantity, Vector^ pos,uint8_t alpha,bool autom)
{
	_id = api->CreatePickup(model, world, quantity, pos->x, pos->y, pos->z, alpha, autom);
}
