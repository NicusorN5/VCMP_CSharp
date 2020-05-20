#include "stdafx.h"
#include "Common.h"
#include <Windows.h>
#include <stdio.h>
#include <cstring>
#include "VCMP_CSharp_Plugin.h"

PluginFuncs *api;

PluginCallbacks *calls;

char * PluginName = "C# for VC:MP";

using namespace VCMPCSharpPlugin;

uint8_t OnServerInitialise()
{
	return ScriptCompiler::CallserverInitialise();
}
void OnServerShutdown()
{
	ScriptCompiler::CallServerShutdown();
}
void OnServerFrame(float elapsedTime)
{
	ScriptCompiler::CallServerFrame(elapsedTime);
}

uint8_t OnIncomingConnection(char* playerName, size_t nameBufferSize, const char* userPassword, const char* ipAddress)
{
	return ScriptCompiler::CallIncomingConnection(playerName, nameBufferSize, userPassword, ipAddress);
}
void OnClientScriptData(int32_t playerId, const uint8_t* data, size_t size)
{
	ScriptCompiler::CallClientScriptData(playerId, data, size);
}

void OnPlayerConnect(int32_t playerId)
{
	ScriptCompiler::CallPlayerConnection(playerId);
}
void OnPlayerDisconnect(int32_t playerId, vcmpDisconnectReason reason)
{
	ScriptCompiler::CallPlayerDisconnect(playerId, reason);
}

uint8_t OnPlayerRequestClass(int32_t playerId, int32_t offset)
{
	return ScriptCompiler::CallPlayerRequestClass(playerId, offset);
}
uint8_t OnPlayerRequestSpawn(int32_t playerId)
{
	return ScriptCompiler::CallPlayerRequestSpawn(playerId);
}
void OnPlayerSpawn(int32_t playerId)
{
	ScriptCompiler::CallPlayerSpawn(playerId);
}
void OnPlayerDeath(int32_t playerId, int32_t killerId, int32_t reason, vcmpBodyPart bodyPart)
{
	ScriptCompiler::CallPlayerDeath(playerId, killerId, reason, bodyPart);
}
void OnPlayerUpdate(int32_t playerId, vcmpPlayerUpdate updateType)
{
	ScriptCompiler::CallPlayerUpdate(playerId, updateType);
}

uint8_t OnPlayerRequestEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex)
{
	return ScriptCompiler::CallPlayerRequestEnterVehicle(playerId, vehicleId, slotIndex);
}
void OnPlayerEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex)
{
	ScriptCompiler::CallPlayerEnterVehicle(playerId, vehicleId, slotIndex);
}
void OnPlayerExitVehicle(int32_t playerId, int32_t vehicleId)
{
	ScriptCompiler::CallPlayerExitVehicle(playerId, vehicleId);
}

void OnPlayerNameChange(int32_t playerId, const char* oldName, const char* newName)
{
	ScriptCompiler::CallPlayerNameChange(playerId, oldName, newName);
}
void OnPlayerStateChange(int32_t playerId, vcmpPlayerState oldState, vcmpPlayerState newState)
{
	ScriptCompiler::CallPlayerStateChange(playerId, oldState, newState);
}
void OnPlayerActionChange(int32_t playerId, int32_t oldAction, int32_t newAction)
{
	ScriptCompiler::CallPlayerActionChange(playerId, oldAction, newAction);
}
void OnPlayerOnFireChange(int32_t playerId, uint8_t isOnFire)
{
	ScriptCompiler::CallPlayerOnFireChange(playerId, isOnFire);
}
void OnPlayerCrouchChange(int32_t playerId, uint8_t isCrouching)
{
	ScriptCompiler::CallPlayerCrouchChange(playerId, isCrouching);
}
void OnPlayerGameKeysChange(int32_t playerId, uint32_t oldKeys, uint32_t newKeys)
{
	ScriptCompiler::CallPlayerGameKeysChange(playerId, oldKeys, newKeys);
}
void OnPlayerBeginTyping(int32_t playerId)
{
	ScriptCompiler::CallPlayerBeginTyping(playerId);
}
void OnPlayerEndTyping(int32_t playerId)
{
	ScriptCompiler::CallPlayerEndTyping(playerId);
}
void OnPlayerAwayChange(int32_t playerId, uint8_t isAway)
{
	ScriptCompiler::CallPlayerAwayChange(playerId, isAway);
}

uint8_t OnPlayerMessage(int32_t playerId, const char* message)
{
	return (uint8_t)ScriptCompiler::CallPlayerMessage(playerId, message);
}
uint8_t OnPlayerCommand(int32_t playerId, const char* message)
{
	return (uint8_t)ScriptCompiler::CallPlayerCommand(playerId, message);
}
uint8_t OnPlayerPrivateMessage(int32_t playerId, int32_t targetPlayerId, const char* message)
{
	return ScriptCompiler::CallPlayerPrivateMessage(playerId, targetPlayerId, message);
}

void OnPlayerKeyBindDown(int32_t playerId, int32_t bindId)
{
	ScriptCompiler::CallPlayerKeyBindDown(playerId, bindId);
}
void OnPlayerKeyBindUp(int32_t playerId, int32_t bindId)
{
	ScriptCompiler::CallPlayerKeyBindUp(playerId, bindId);
}
void OnPlayerSpectate(int32_t playerId, int32_t targetPlayerId)
{
	ScriptCompiler::CallPlayerSpectate(playerId, targetPlayerId);
}
void OnPlayerCrashReport(int32_t playerId, const char* report)
{
	ScriptCompiler::CallPlayerCrashReport(playerId, report);
}

void OnVehicleUpdate(int32_t vehicleId, vcmpVehicleUpdate updateType)
{
	ScriptCompiler::CallVehicleUpdate(vehicleId, updateType);
}
void OnVehicleExplode(int32_t vehicleId)
{
	ScriptCompiler::CallVehicleExplode(vehicleId);
}
void OnVehicleRespawn(int32_t vehicleId)
{
	ScriptCompiler::CallVehicleRespawn(vehicleId);
}

void OnObjectShot(int32_t objectId, int32_t playerId, int32_t weaponId)
{
	ScriptCompiler::CallObjectShot(objectId, playerId, weaponId);
}
void OnObjectTouched(int32_t objectId, int32_t playerId)
{
	ScriptCompiler::CallObjectTouched(objectId, playerId);
}

uint8_t OnPickupPickAttempt(int32_t pickupId, int32_t playerId)
{
	return ScriptCompiler::CallPickupPickAttempt(pickupId, playerId);
}
void OnPickupPicked(int32_t pickupId, int32_t playerId)
{
	ScriptCompiler::CallPickupPicked(pickupId, playerId);
}
void OnPickupRespawn(int32_t pickupId)
{
	ScriptCompiler::CallPickupRespawn(pickupId);
}

void OnCheckpointEntered(int32_t checkPointId, int32_t playerId)
{
	ScriptCompiler::CallCheckpointEntered(checkPointId, playerId);
}
void OnCheckpointExited(int32_t checkPointId, int32_t playerId)
{
	ScriptCompiler::CallCheckpointEntered(checkPointId, playerId);
}
void OnServerPerformanceReport(size_t entryCount, const char** descriptions, uint64_t* times)
{
	ScriptCompiler::CallServerPerformanceReport(entryCount, descriptions, times);
}

// TODO: MOVE LATER
void OnPlayerModuleList(int32_t playerId, const char* list)
{
	ScriptCompiler::CallPlayerModuleList(playerId, list);
}

extern "C" DLL_EXPORT unsigned int VcmpPluginInit(PluginFuncs* pluginFuncs, PluginCallbacks* pluginCalls, PluginInfo* pluginInfo)
{
	api = pluginFuncs;
	calls = pluginCalls;
	pluginInfo->apiMajorVersion = PLUGIN_API_MAJOR;
	pluginInfo->apiMinorVersion = PLUGIN_API_MINOR;
	strcpy_s(pluginInfo->name, PluginName);
	PrintModuleColor();
	printf(" Loading C# plugin by Athanatos \r\n");
	ScriptCompiler::Load();
	ScriptCompiler::Initialize();
	if (ScriptCompiler::HasScripts == false)
	{
		PrintErrorColor();
		printf("No script(s) provided.");
		return 0;
	}
	calls->OnServerInitialise = OnServerInitialise;
	
	calls->OnServerShutdown = OnServerShutdown;
	calls->OnServerFrame = OnServerFrame;

	calls->OnIncomingConnection = OnIncomingConnection;
	calls->OnClientScriptData = OnClientScriptData;
	calls->OnPlayerConnect = OnPlayerConnect;
	calls->OnPlayerDisconnect = OnPlayerDisconnect;

	calls->OnPlayerRequestClass = OnPlayerRequestClass;
	calls->OnPlayerRequestSpawn = OnPlayerRequestSpawn;

	calls->OnPlayerSpawn = OnPlayerSpawn;
	calls->OnPlayerDeath = OnPlayerDeath;

	calls->OnPlayerUpdate = OnPlayerUpdate;
	calls->OnPlayerRequestEnterVehicle = OnPlayerRequestEnterVehicle;
	calls->OnPlayerEnterVehicle = OnPlayerEnterVehicle;
	calls->OnPlayerExitVehicle = OnPlayerExitVehicle;
	calls->OnPlayerNameChange = OnPlayerNameChange;
	calls->OnPlayerStateChange = OnPlayerStateChange;
	calls->OnPlayerActionChange = OnPlayerActionChange;
	calls->OnPlayerOnFireChange = OnPlayerOnFireChange;
	calls->OnPlayerCrouchChange = OnPlayerCrouchChange;
	calls->OnPlayerGameKeysChange = OnPlayerGameKeysChange;
	calls->OnPlayerBeginTyping = OnPlayerBeginTyping;
	calls->OnPlayerEndTyping = OnPlayerEndTyping;
	calls->OnPlayerAwayChange = OnPlayerAwayChange;
	calls->OnPlayerMessage = OnPlayerMessage;
	calls->OnPlayerCommand = OnPlayerCommand;
	calls->OnPlayerPrivateMessage = OnPlayerPrivateMessage;
	calls->OnPlayerKeyBindDown = OnPlayerKeyBindDown;
	calls->OnPlayerKeyBindUp = OnPlayerKeyBindUp;
	calls->OnPlayerSpectate = OnPlayerSpectate;
	calls->OnPlayerCrashReport = OnPlayerCrashReport;
	calls->OnVehicleUpdate = OnVehicleUpdate;
	calls->OnVehicleExplode = OnVehicleExplode;
	calls->OnVehicleRespawn = OnVehicleRespawn;
	calls->OnObjectShot = OnObjectShot;
	calls->OnObjectTouched = OnObjectTouched;
	calls->OnPickupPickAttempt = OnPickupPickAttempt;
	calls->OnPickupPicked = OnPickupPicked;
	calls->OnPickupRespawn = OnPickupRespawn;
	calls->OnCheckpointEntered = OnCheckpointEntered;
	calls->OnCheckpointExited = OnCheckpointExited;
	calls->OnServerPerformanceReport = OnServerPerformanceReport;
	calls->OnPlayerModuleList = OnPlayerModuleList;
	
	PrintModuleColor();
	printf("[C#]Initialization complete!");
	return 1;
}

#pragma unmanaged
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
