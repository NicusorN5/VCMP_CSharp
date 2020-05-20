#pragma once

#include <stdio.h>
#include "Common.h"
#include "CPlayer.h"
#include "CVehicle.h"
#include "CCheckPoint.h"
#include "ServerInstance.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Collections::Generic;
using namespace System::CodeDom::Compiler;
using namespace System::CodeDom;

#pragma managed
namespace VCMPCSharpPlugin {
	public ref class ScriptCompiler abstract sealed //static class
	{
	public:
		static List<String^> ^Files;
		static List<String^> ^Assemblies;
		static String ^ClassName;
		static void Load();
		static void Initialize();
		static bool CompileAll();
		static bool HasScripts;

		static uint8_t CallserverInitialise();
		static void CallServerShutdown();
		static void CallServerFrame(float elapsedtime);

		static uint8_t CallIncomingConnection(char* playerName, size_t nameBufferSize, const char* userPassword, const char* ipAddress);
		static void CallClientScriptData(int32_t playerId, const uint8_t* data, size_t size);
		static void CallPlayerConnection(int32_t playerId);
		static void CallPlayerDisconnect(int32_t playerId, vcmpDisconnectReason reason);
		static uint8_t CallPlayerRequestClass(int32_t playerId, int32_t offset);
		static uint8_t CallPlayerRequestSpawn(int32_t playerId);
		static void CallPlayerSpawn(int32_t playerId);
		static void CallPlayerDeath(int32_t playerId, int32_t killerId, int32_t reason, vcmpBodyPart bodyPart);
		static void CallPlayerUpdate(int32_t playerId, vcmpPlayerUpdate updateType);
		static uint8_t CallPlayerRequestEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex);
		static void CallPlayerEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex);
		static void CallPlayerExitVehicle(int32_t playerId, int32_t vehicleId);
		static void CallPlayerNameChange(int32_t playerId, const char* oldName, const char* newName);
		static void CallPlayerStateChange(int32_t playerId, vcmpPlayerState oldState, vcmpPlayerState newState);
		static void CallPlayerActionChange(int32_t playerId, int32_t oldAction, int32_t newAction);
		static void CallPlayerOnFireChange(int32_t playerId, uint8_t isOnFire);
		static void CallPlayerCrouchChange(int32_t playerId, uint8_t isCrouching);
		static void CallPlayerGameKeysChange(int32_t playerId, uint32_t oldKeys, uint32_t newKeys);
		static void CallPlayerBeginTyping(int32_t playerId);
		static void CallPlayerEndTyping(int32_t playerId);
		static void CallPlayerAwayChange(int32_t playerId, uint8_t isAway);
		static uint8_t CallPlayerMessage(int32_t playerId, const char* message);
		static uint8_t CallPlayerCommand(int32_t playerId, const char* message);
		static uint8_t CallPlayerPrivateMessage(int32_t playerId, int32_t targetPlayerId, const char* message);
		static void CallPlayerKeyBindDown(int32_t playerId, int32_t bindId);
		static void CallPlayerKeyBindUp(int32_t playerId, int32_t bindId);
		static void CallPlayerSpectate(int32_t playerId, int32_t targetPlayerId);
		static void CallPlayerCrashReport(int32_t playerId, const char* report);
		static void CallVehicleUpdate(int32_t vehicleId, vcmpVehicleUpdate updateType);
		static void CallVehicleExplode(int32_t vehicleId);
		static void CallVehicleRespawn(int32_t vehicleId);
		static void CallObjectShot(int32_t objectId, int32_t playerId, int32_t weaponId);
		static void CallObjectTouched(int32_t objectId, int32_t playerId);
		static uint8_t CallPickupPickAttempt(int32_t pickupId, int32_t playerId);
		static void CallPickupPicked(int32_t pickupId, int32_t playerId);
		static void CallPickupRespawn(int32_t pickupId);
		static void CallCheckpointEntered(int32_t checkPointId, int32_t playerId);
		static void CallCheckpointExited(int32_t checkPointId, int32_t playerId);
		static void CallServerPerformanceReport(size_t entryCount, const char** descriptions, uint64_t* times);
		static void CallPlayerModuleList(int32_t playerId, const char* list);
	private:
		static CodeDomProvider ^compiler;
		static CompilerParameters ^params;
		static CompilerResults ^results;
		static Assembly ^compiledCode;
		static Type^ servertype;
		static Object^ serverinstance;
		static MethodInfo^ _serverInitialise,
			^ _ServerShutdown,
			^ _ServerFrame,
			^ _IncomingConnection,
			^ _ClientScriptData,
			^ _PlayerConnection,
			^ _PlayerDisconnect,
			^ _PlayerRequestClass,
			^ _PlayerRequestSpawn,
			^ _PlayerSpawn,
			^ _PlayerDeath,
			^ _PlayerUpdate,
			^ _PlayerRequestEnterVehicle,
			^ _PlayerEnterVehicle,
			^ _PlayerExitVehicle,
			^ _PlayerNameChange,
			^ _PlayerStateChange,
			^ _PlayerActionChange,
			^ _PlayerOnFireChange,
			^ _PlayerGameKeysChange,
			^ _PlayerCrouchChange,
			^ _PlayerBeginTyping,
			^ _PlayerEndTyping,
			^ _PlayerAwayChange,
			^ _PlayerMessage,
			^ _PlayerCommand,
			^ _PlayerPrivateMessage,
			^ _PlayerKeyBindDown,
			^ _PlayerKeyBindUp,
			^ _PlayerSpectate,
			^ _PlayerCrashReport,
			^ _VehicleUpdate,
			^ _VehicleExplode,
			^ _VehicleRespawn,
			^ _ObjectShot,
			^ _ObjectTouched,
			^ _PickupPickAttempt,
			^ _PickupPicked,
			^ _PickupRespawn,
			^ _CheckpointEntered,
			^ _CheckpointExited,
			^ _ServerPerformanceReport,
			^ _PlayerModuleList;
	};
}