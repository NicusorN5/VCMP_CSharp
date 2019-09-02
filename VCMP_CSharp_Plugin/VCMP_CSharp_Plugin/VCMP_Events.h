#pragma once
#include "CPlayer.h"
#include "CVehicle.h"
#include "CPickup.h"
#include "CCheckPoint.h"
#include "CObject.h"
using namespace System;

namespace VCMPCSharpPlugin
{
	public delegate void OnServerInitialise();
	public delegate void OnServerShutdown();
	public delegate void OnServerFrame(float elapsedTime);

	//uint8_t (*OnPluginCommand(uint32_t commandIdentifier, String ^message);

	public delegate int OnIncomingConnection(String^ playerName, int nameBufferSize, String^ userPassword, String^ ipAddress);
	public delegate void OnClientScriptData(CPlayer ^player, array<Byte^> ^data);

	public delegate void OnPlayerConnect(CPlayer ^player);

	public enum class DisconnectReason
	{
		vcmpDisconnectReasonTimeout = 0,
		vcmpDisconnectReasonQuit = 1,
		vcmpDisconnectReasonKick = 2,
		vcmpDisconnectReasonCrash = 3,
		vcmpDisconnectReasonAntiCheat = 4,
	};

	public delegate void OnPlayerDisconnect(CPlayer ^player, DisconnectReason ^reason);

	public delegate int OnPlayerRequestClass(CPlayer ^player, int offset);
	public delegate int OnPlayerRequestSpawn(CPlayer ^player);
	public delegate void OnPlayerSpawn(CPlayer ^player);
	public enum class BodyPart
	{
		vcmpBodyPartBody = 0,
		vcmpBodyPartTorso = 1,
		vcmpBodyPartLeftArm = 2,
		vcmpBodyPartRightArm = 3,
		vcmpBodyPartLeftLeg = 4,
		vcmpBodyPartRightLeg = 5,
		vcmpBodyPartHead = 6,
		vcmpBodyPartInVehicle = 7,
	};
	public delegate void OnPlayerDeath(CPlayer ^victim, CPlayer ^killer, int reason, BodyPart ^bodyPart);
	public delegate void OnPlayerUpdate(CPlayer ^player, PlayerState updateType);

	public delegate int OnPlayerRequestEnterVehicle(CPlayer ^player, CVehicle ^vehicle, int slotIndex);
	public delegate void OnPlayerEnterVehicle(CPlayer ^player, CVehicle ^vehicle, int slotIndex);
	public delegate void OnPlayerExitVehicle(CPlayer ^player, CVehicle ^vehicle);

	public delegate void OnPlayerNameChange(CPlayer ^player, String ^oldName, String ^newName);
	public delegate void OnPlayerStateChange(CPlayer ^player, PlayerState oldState, PlayerState newState);
	public delegate void OnPlayerActionChange(CPlayer ^player, int oldAction, int newAction);
	public delegate void OnPlayerOnFireChange(CPlayer ^player, Byte ^isOnFire);
	public delegate void OnPlayerCrouchChange(CPlayer ^player, Byte ^isCrouching);
	public delegate void OnPlayerGameKeysChange(CPlayer ^player, int oldKeys, int newKeys);
	public delegate void OnPlayerBeginTyping(CPlayer ^player);
	public delegate void OnPlayerEndTyping(CPlayer ^player);
	public delegate void OnPlayerAwayChange(CPlayer ^player, int isAway);

	public delegate int OnPlayerMessage(CPlayer ^player,String ^message);
	public delegate int OnPlayerCommand(CPlayer ^player, String^ message);
	public delegate int OnPlayerPrivateMessage(CPlayer ^player, int32_t targetPlayerId, String ^message);

	public delegate void OnPlayerKeyBindDown(CPlayer ^player, int32_t bindId);
	public delegate void OnPlayerKeyBindUp(CPlayer ^player, int32_t bindId);
	public delegate void OnPlayerSpectate(CPlayer ^player, int32_t targetPlayerId);
	public delegate void OnPlayerCrashReport(CPlayer ^player, String ^report);

	public delegate void OnVehicleUpdate(CVehicle ^vehicle, vcmpVehicleUpdate updateType);
	public delegate void OnVehicleExplode(CVehicle ^vehicle);
	public delegate void OnVehicleRespawn(CVehicle ^vehicle);

	public delegate void OnObjectShot(CObject ^object, CPlayer ^player, int32_t weaponId);
	public delegate void OnObjectTouched(CObject ^object, CPlayer ^player);

	public delegate int OnPickupPickAttempt(CPickup ^pickup, CPlayer ^player);
	public delegate void OnPickupPicked(CPickup ^pickup, CPlayer ^player);
	public delegate void OnPickupRespawn(CPickup ^pickup);

	public delegate void OnCheckpointEntered(CCheckPoint ^checkpoint, CPlayer ^player);
	public delegate void OnCheckpointExited(CCheckPoint ^checkpoint, CPlayer ^player);

	//public delegate void OnEntityPoolChange(vcmpEntityPool entityType, int32_t entityId, uint8_t isDeleted);
	public delegate void OnServerPerformanceReport(size_t entryCount, array<String^> ^descriptions, uint64_t* times);

	// TODO: MOVE LATER
	public delegate void OnPlayerModuleList(CPlayer ^player, String ^list);
}