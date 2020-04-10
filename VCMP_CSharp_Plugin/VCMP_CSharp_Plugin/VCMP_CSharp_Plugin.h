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
	public ref class ScriptCompiler
	{
	public:
		static List<String^> ^Files;
		static List<String^> ^Assemblies;
		String ^ClassName;
		ScriptCompiler();
		void Initialize();
		bool CompileAll();
		bool HasScripts;

		uint8_t CallserverInitialise();
		void CallServerShutdown();
		void CallServerFrame(float elapsedtime);

		uint8_t CallIncomingConnection(char* playerName, size_t nameBufferSize, const char* userPassword, const char* ipAddress);
		void CallClientScriptData(int32_t playerId, const uint8_t* data, size_t size);
		void CallPlayerConnection(int32_t playerId);
		void CallPlayerDisconnect(int32_t playerId, vcmpDisconnectReason reason);
		void CallPlayerRequestClass(int32_t playerId, int32_t offset);
		void CallPlayerRequestSpawn(int32_t playerId);
		void CallPlayerSpawn(int32_t playerId);
		void CallPlayerDeath(int32_t playerId, int32_t killerId, int32_t reason, vcmpBodyPart bodyPart);
		void CallPlayerUpdate(int32_t playerId, vcmpPlayerUpdate updateType);
		void CallPlayerRequestEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex);
		void CallPlayerEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex);
		void CallPlayerExitVehicle(int32_t playerId, int32_t vehicleId);
		void CallPlayerNameChange(int32_t playerId, const char* oldName, const char* newName);
		void CallPlayerStateChange(int32_t playerId, vcmpPlayerState oldState, vcmpPlayerState newState);
		void CallPlayerActionChange(int32_t playerId, int32_t oldAction, int32_t newAction);
		void CallPlayerOnFireChange(int32_t playerId, uint8_t isOnFire);
		void CallPlayerCrouchChange(int32_t playerId, uint8_t isCrouching);
		void CallPlayerGameKeysChange(int32_t playerId, uint32_t oldKeys, uint32_t newKeys);
		void CallPlayerBeginTyping(int32_t playerId);
		void CallPlayerEndTyping(int32_t playerId);
		void CallPlayerAwayChange(int32_t playerId, uint8_t isAway);
		void CallPlayerMessage(int32_t playerId, const char* message);
		void CallPlayerCommand(int32_t playerId, const char* message);
		void CallPlayerPrivateMessage(int32_t playerId, int32_t targetPlayerId, const char* message);
		void CallPlayerKeyBindDown(int32_t playerId, int32_t bindId);
		void CallPlayerKeyBindUp(int32_t playerId, int32_t bindId);
		void CallPlayerSpectate(int32_t playerId, int32_t targetPlayerId);
		void CallPlayerCrashReport(int32_t playerId, const char* report);
		void CallVehicleUpdate(int32_t vehicleId, vcmpVehicleUpdate updateType);
		void CallVehicleExplode(int32_t vehicleId);
		void CallVehicleRespawn(int32_t vehicleId);
		void CallObjectShot(int32_t objectId, int32_t playerId, int32_t weaponId);
		void CallObjectTouched(int32_t objectId, int32_t playerId);
		void CallPickupPickAttempt(int32_t pickupId, int32_t playerId);
		void CallPickupPicked(int32_t pickupId, int32_t playerId);
		void CallPickupRespawn(int32_t pickupId);
		void CallCheckpointEntered(int32_t checkPointId, int32_t playerId);
		void CallCheckpointExited(int32_t checkPointId, int32_t playerId);
		void CallServerPerformanceReport(size_t entryCount, const char** descriptions, uint64_t* times);
		void CallPlayerModuleList(int32_t playerId, const char* list);
	private:
		CodeDomProvider ^compiler;
		CompilerParameters ^params;
		CompilerResults ^results;
		Assembly ^compiledCode;
		Type^ servertype;
		Object^ serverinstance;
		MethodInfo^ _serverInitialise,
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
