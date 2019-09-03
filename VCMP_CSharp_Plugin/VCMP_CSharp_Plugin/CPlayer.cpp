#include "stdafx.h"
#include "CPlayer.h"

VCMPCSharpPlugin::CPlayer::CPlayer(int ID)
{
	
}

void VCMPCSharpPlugin::CPlayer::Kick()
{
	api->KickPlayer(this->ID);
}

void VCMPCSharpPlugin::CPlayer::Ban()
{
	api->BanPlayer(this->ID);
}

VCMPCSharpPlugin::CPlayer^ VCMPCSharpPlugin::CPlayer::FindPlayer(int ID)
{
	for (int i = 0; i < api->GetMaxPlayers(); i++)
	{
		if (api->IsPlayerConnected(i) == 1)
		{
			if (ID == i) return %CPlayer(i);
		}
	}
}

VCMPCSharpPlugin::CPlayer^ VCMPCSharpPlugin::CPlayer::FindPlayer(String ^ Name)
{
	int id = api->GetPlayerIdFromName(CLIStringToCharA(Name));
	if (id == -1) return nullptr;
	else return %CPlayer(id);
}

bool VCMPCSharpPlugin::CPlayer::PlayerStreamedToPlayer(CPlayer ^ p)
{
	if (p->Connected == false) return false;
	return api->IsPlayerStreamedForPlayer(p->ID,this->ID);
}

bool VCMPCSharpPlugin::CPlayer::WorldCompatible(int world)
{
	return api->IsPlayerWorldCompatible(this->ID,world);
}

void VCMPCSharpPlugin::CPlayer::ForceSpawn()
{
	api->ForcePlayerSpawn(this->ID);
}

void VCMPCSharpPlugin::CPlayer::ForceSelect()
{
	api->ForcePlayerSelect(this->ID);
}

VCMPCSharpPlugin::CPlayer::operator bool()
{
	return api->IsPlayerConnected(this->ID);
}

VCMPCSharpPlugin::CPlayer::operator int()
{
	return this->ID;
}
