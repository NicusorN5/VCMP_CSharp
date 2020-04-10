#include "stdafx.h"
#include "CCheckPoint.h"


VCMPCSharpPlugin::CCheckPoint::CCheckPoint(int id)
{
	_id = id;
}
VCMPCSharpPlugin::CCheckPoint::CCheckPoint(int world,bool issphere,Vector^ pos,Color^ color,uint8_t alpha,float R)
{
	_id = api->CreateCheckPoint(-1, world, issphere, pos->x, pos->y, pos->z, color->Red, color->Green, color->Blue, alpha, R);
}
