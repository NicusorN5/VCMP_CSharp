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

extern "C" DLL_EXPORT unsigned int VcmpPluginInit(PluginFuncs* pluginFuncs, PluginCallbacks* pluginCalls, PluginInfo* pluginInfo)
{
	api = pluginFuncs;
	calls = pluginCalls;
	pluginInfo->apiMajorVersion = PLUGIN_API_MAJOR;
	pluginInfo->apiMinorVersion = PLUGIN_API_MINOR;
	strcpy_s(pluginInfo->name, PluginName);
	PrintModuleColor();
	printf(" Loading C# plugin by Athanatos \r\n");
	ScriptCompiler ^compiler = gcnew ScriptCompiler();
	if (compiler->HasScripts == false)
	{
		PrintErrorColor();
		printf("No script(s) provided.");
		return 0;
	}
	//calls->OnServerInitialise = ScriptCompiler::CallserverInitialise;
	/*
	calls->OnServerShutdown = compiler->CallServerShutdown;
	calls->OnServerFrame = compiler->CallServerFrame;

	calls->OnIncomingConnection = compiler->CallIncomingConnection;
	calls->OnClientScriptData = compiler->CallClientScriptData;
	calls->OnPlayerConnect = compiler->CallPlayerConnection;
	calls->OnPlayerDisconnect = compiler->CallPlayerDisconnect;

	calls->OnPlayerRequestClass = compiler->CallPlayerRequestClass;
	calls->OnPlayerRequestSpawn = compiler->CallPlayerRequestSpawn;

	calls->OnPlayerSpawn = compiler->CallPlayerSpawn;
	calls->OnPlayerDeath = compiler->CallPlayerDeath;

	calls->OnPlayerUpdate = compiler->CallPlayerUpdate;
	calls->OnPlayerRequestEnterVehicle = compiler->CallPlayerRequestEnterVehicle;
	calls->OnPlayerEnterVehicle = compiler->CallPlayerEnterVehicle;
	calls->OnPlayerExitVehicle = compiler->CallPlayerExitVehicle;
	calls->OnPlayerNameChange = compiler->CallPlayerNameChange;
	calls->OnPlayerStateChange = compiler->CallPlayerStateChange;
	calls->OnPlayerActionChange = compiler->CallPlayerActionChange;
	calls->OnPlayerOnFireChange = compiler->CallPlayerOnFireChange;
	calls->OnPlayerCrouchChange = compiler->CallPlayerCrouchChange;
	calls->OnPlayerGameKeysChange = compiler->CallPlayerGameKeysChange;
	calls->OnPlayerBeginTyping = compiler->CallPlayerBeginTyping;
	calls->OnPlayerEndTyping = compiler->CallPlayerEndTyping;
	calls->OnPlayerAwayChange = compiler->CallPlayerAwayChange;
	calls->OnPlayerMessage = compiler->CallPlayerMessage;
	calls->OnPlayerCommand = compiler->CallPlayerCommand;
	calls->OnPlayerPrivateMessage = compiler->CallPlayerPrivateMessage;
	calls->OnPlayerKeyBindDown = compiler->CallPlayerKeyBindDown;
	calls->OnPlayerKeyBindUp = compiler->CallPlayerKeyBindUp;
	calls->OnPlayerSpectate = compiler->CallPlayerSpectate;
	calls->OnPlayerCrashReport = compiler->CallPlayerCrashReport;
	calls->OnVehicleUpdate = compiler->CallVehicleUpdate;
	calls->OnVehicleExplode = compiler->CallVehicleExplode;
	calls->OnVehicleRespawn = compiler->CallVehicleRespawn;
	calls->OnObjectShot = compiler->CallObjectShot;
	calls->OnObjectTouched = compiler->CallObjectTouched;
	calls->OnPickupPickAttempt = compiler->CallPickupPickAttempt;
	calls->OnPickupPicked = compiler->CallPickupPicked;
	calls->OnPickupRespawn = compiler->CallPickupRespawn;
	calls->OnCheckpointEntered = compiler->CallCheckpointEntered;
	calls->OnCheckpointExited = compiler->CallCheckpointExited;
	calls->OnServerPerformanceReport = compiler->CallServerPerformanceReport;
	calls->OnPlayerModuleList = compiler->CallPlayerModuleList;
	*/
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
