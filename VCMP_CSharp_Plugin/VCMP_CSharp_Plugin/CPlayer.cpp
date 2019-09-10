#include "stdafx.h"
#include "CPlayer.h"

VCMPCSharpPlugin::CPlayer::CPlayer()
{
	this->Connected = false;
}

VCMPCSharpPlugin::CPlayer::CPlayer(int ID)
{
	ID_Copy = ID;
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
	for (uint32_t i = 0; i < api->GetMaxPlayers(); i++)
	{
		if (api->IsPlayerConnected(i) == 1)
		{
			if (ID == i) return %CPlayer(i);
		}
	}
	return nullptr;
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

void VCMPCSharpPlugin::CPlayer::AddSpeed(Vector ^ s)
{
	api->AddPlayerSpeed(this->ID, s->x, s->y, s->z);
}

void VCMPCSharpPlugin::CPlayer::Teleport(Vector ^ pos, float angle)
{
	api->RemovePlayerFromVehicle(this->ID);
	this->Position = pos; //We use this instead of using the direct API call, because it's easier.
	api->SetPlayerHeading(this->ID, angle);
}

void VCMPCSharpPlugin::CPlayer::SetTransparency(uint8_t alpha, int fadetime)
{
	api->SetPlayerAlpha(this->ID, alpha, fadetime);
}

void VCMPCSharpPlugin::CPlayer::GiveWeapon(int weapon, int ammo)
{
	api->GivePlayerWeapon(this->ID, weapon, ammo);
}

void VCMPCSharpPlugin::CPlayer::RemoveWeapon(int weapon)
{
	api->RemovePlayerWeapon(this->ID, weapon);
}

void VCMPCSharpPlugin::CPlayer::Disarm()
{
	api->RemoveAllWeapons(this->ID);
}

void VCMPCSharpPlugin::CPlayer::SetCameraPosition(Vector ^ pos, Vector ^ look_at)
{
	api->SetCameraPosition(this->ID, pos->x, pos->y, pos->z, look_at->x, look_at->y, look_at->z);
}

void VCMPCSharpPlugin::CPlayer::RestoreCamera()
{
	api->RestoreCamera(this->ID);
}

void VCMPCSharpPlugin::CPlayer::PlayAnim(int anim_group, int anim_id)
{
	api->SetPlayerAnimation(this->ID, anim_group, anim_id);
}

void VCMPCSharpPlugin::CPlayer::Redirect(String ^ IP, int port, String ^ Password)
{
	char * cIP = new char[IP->Length+1];
	char * cPassword = new char[Password->Length + 1];
	char * name = new char[this->Name->Length + 1];
	cIP = CLIStringToCharA(IP);
	cPassword = CLIStringToCharA(Password);
	name = CLIStringToCharA(this->Name);
	api->RedirectPlayerToServer(this->ID, cIP, port, name, cPassword, nullptr);
	delete cIP;
	delete cPassword;
	delete name;
}

void VCMPCSharpPlugin::CPlayer::PlaySound(int soundid)
{
	if (this->Connected)
	{
		api->PlaySound(this->World, soundid, this->Position->x, this->Position->y, this->Position->z);
	}
}

VCMPCSharpPlugin::CPlayer::operator bool()
{
	return api->IsPlayerConnected(this->ID);
}

VCMPCSharpPlugin::CPlayer::operator int()
{
	return this->ID;
}
