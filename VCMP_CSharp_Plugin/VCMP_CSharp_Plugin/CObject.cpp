#include "stdafx.h"
#include "CObject.h"
#include"Common.h"


VCMPCSharpPlugin::CObject::CObject(int id)
{
	_id = id;
}

VCMPCSharpPlugin::CObject::CObject(int model, int world, Vector^ pos, int alpha)
{
	_id = api->CreateObject(model, world, pos->x, pos->y, pos->z, alpha);
}