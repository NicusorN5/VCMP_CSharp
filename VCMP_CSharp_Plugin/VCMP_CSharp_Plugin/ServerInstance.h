#pragma once

#include "CPlayer.h"
#include "CVehicle.h"
#include "CPickup.h"
#include "CCheckPoint.h"
#include "CObject.h"
#include "VCMPEnums.h"

using namespace System;

namespace VCMPCSharpPlugin
{
	ref class CPlayer;
	ref class CVehicle;
	public interface class ServerInstance
	{

	public:
		virtual bool OnServerInitialise() = 0;
		virtual void OnServerShutdown() = 0;
		virtual void OnServerFrame(float elapsedTime) = 0;

		virtual int OnIncomingConnection(String^ playerName, int nameBufferSize, String^ userPassword, String^ ipAddress) = 0;
		virtual void OnClientScriptData(CPlayer^ player, array<Byte^>^ data) = 0;

		virtual void OnPlayerConnect(CPlayer^ player) = 0;
		virtual void OnPlayerDisconnect(CPlayer^ player, DisconnectReason^ reason) = 0;

		virtual int OnPlayerRequestClass(CPlayer^ player, int offset) = 0;
		virtual int OnPlayerRequestSpawn(CPlayer^ player) = 0;
		virtual void OnPlayerSpawn(CPlayer^ player) = 0;

		virtual void OnPlayerDeath(CPlayer^ victim, CPlayer^ killer, int reason, BodyPart^ bodyPart) = 0;
		virtual void OnPlayerUpdate(CPlayer^ player, PlayerUpdate updateType) = 0;

		virtual int OnPlayerRequestEnterVehicle(CPlayer^ player, CVehicle^ vehicle, int slotIndex) = 0;
		virtual void OnPlayerEnterVehicle(CPlayer^ player, CVehicle^ vehicle, int slotIndex) = 0;
		virtual void OnPlayerExitVehicle(CPlayer^ player, CVehicle^ vehicle) = 0;

		virtual void OnPlayerNameChange(CPlayer^ player, String^ oldName, String^ newName) = 0;
		virtual void OnPlayerStateChange(CPlayer^ player, PlayerState oldState, PlayerState newState) = 0;
		virtual void OnPlayerActionChange(CPlayer^ player, int oldAction, int newAction) = 0;
		virtual void OnPlayerOnFireChange(CPlayer^ player, Byte^ isOnFire) = 0;
		virtual void OnPlayerCrouchChange(CPlayer^ player, Byte^ isCrouching) = 0;
		virtual void OnPlayerGameKeysChange(CPlayer^ player, int oldKeys, int newKeys) = 0;
		virtual void OnPlayerBeginTyping(CPlayer^ player) = 0;
		virtual void OnPlayerEndTyping(CPlayer^ player) = 0;
		virtual void OnPlayerAwayChange(CPlayer^ player, int isAway) = 0;

		virtual int OnPlayerMessage(CPlayer^ player, String^ message) = 0;
		virtual int OnPlayerCommand(CPlayer^ player, String^ message) = 0;
		virtual int OnPlayerPrivateMessage(CPlayer^ player, int32_t targetPlayerId, String^ message) = 0;

		virtual void OnPlayerKeyBindDown(CPlayer^ player, int32_t bindId) = 0;
		virtual void OnPlayerKeyBindUp(CPlayer^ player, int32_t bindId) = 0;
		virtual void OnPlayerSpectate(CPlayer^ player, int32_t targetPlayerId) = 0;
		virtual void OnPlayerCrashReport(CPlayer^ player, String^ report) = 0;

		virtual void OnVehicleUpdate(CVehicle^ vehicle, vcmpVehicleUpdate updateType) = 0;
		virtual void OnVehicleExplode(CVehicle^ vehicle) = 0;
		virtual void OnVehicleRespawn(CVehicle^ vehicle) = 0;

		virtual void OnObjectShot(CObject^ object, CPlayer^ player, int32_t weaponId) = 0;
		virtual void OnObjectTouched(CObject^ object, CPlayer^ player) = 0;

		virtual int OnPickupPickAttempt(CPickup^ pickup, CPlayer^ player) = 0;
		virtual void OnPickupPicked(CPickup^ pickup, CPlayer^ player) = 0;
		virtual void OnPickupRespawn(CPickup^ pickup) = 0;

		virtual void OnCheckpointEntered(CCheckPoint^ checkpoint, CPlayer^ player) = 0;
		virtual void OnCheckpointExited(CCheckPoint^ checkpoint, CPlayer^ player) = 0;

		//virtual void OnEntityPoolChange(vcmpEntityPool entityType, int32_t entityId, uint8_t isDeleted)= 0;
		virtual void OnServerPerformanceReport(size_t entryCount, array<String^>^ descriptions, uint64_t* times) = 0;

		// TODO: MOVE LATER
		virtual void OnPlayerModuleList(CPlayer^ player, String^ list) = 0;
	};
}