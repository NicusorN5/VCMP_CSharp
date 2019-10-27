#include "stdafx.h"
#include "Server.h"

void VCMPCSharpPlugin::Server::Shutdown()
{
	api->ShutdownServer();
}

void VCMPCSharpPlugin::Server::ToggleKillCommand(bool toggle)
{
	api->SetKillCommandDelay(toggle * 255);
}

void VCMPCSharpPlugin::Server::CreateExplosion(int world, int type, VCMPCSharpPlugin::Vector ^ pos, VCMPCSharpPlugin::CPlayer ^ guilt_player, bool onground)
{
	int id;
	if (guilt_player) id = guilt_player->ID;
	else id = -1;
	api->CreateExplosion(world, type, pos->x, pos->y, pos->z, id, onground);
}

void VCMPCSharpPlugin::Server::PlaySound(int world, int sound, VCMPCSharpPlugin::Vector ^ pos)
{
	api->PlaySound(world, sound, pos->x, pos->y, pos->z);
}

void VCMPCSharpPlugin::Server::ShowMapObject(int model, VCMPCSharpPlugin::Vector ^ pos)
{
	api->ShowMapObject(model, pos->x, pos->y, pos->z);
}

void VCMPCSharpPlugin::Server::HideMapObject(int model, VCMPCSharpPlugin::Vector ^ pos)
{
	api->HideMapObject(model, pos->x, pos->y, pos->z);
}

void VCMPCSharpPlugin::Server::ShowAllMapObjects()
{
	api->ShowAllMapObjects();
}