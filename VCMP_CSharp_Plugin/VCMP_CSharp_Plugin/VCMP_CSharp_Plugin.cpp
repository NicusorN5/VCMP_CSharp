#include "stdafx.h"

#include "VCMP_CSharp_Plugin.h"

void VCMPCSharpPlugin::ScriptCompiler::Load()
{
	//Read configuration
	int files_counter = 0;
	array<String^> ^Scripts2Compile = File::ReadAllLines(L"server.cfg");
	Assemblies = gcnew List<String^>();
	HasScripts = false;
	//Get scripts to compile and assemblies to load
	for (int i = 0; i < Scripts2Compile->Length; i++)
	{
		array<String^> ^Data = Scripts2Compile[i]->Split(' ');
		if (Data[0] == L"cs_file")
		{
			String^ path = "";
			for (int j = 1; j < Data->Length; j++)
			{
				path += Data[j]+ ' ';
				HasScripts = true;
			}
			char* pathp = CLIStringToCharA(path);
			PrintInfoColor();
			printf("Loaded file: ");
			printf(pathp);
			printf("\r\n");
			delete pathp;
			Files->Add(path);
			files_counter += 1;
		}
		if (Data[0] == L"cs_asm")
		{
			String^ path = "";
			for (int j = 1; j < Data->Length; j++)
			{
				path += Data[j]+' ';
			}
			char* pathp = CLIStringToCharA(path);
			PrintInfoColor();
			printf("Loaded assembly: ");
			printf(pathp);
			printf("\r\n");
			delete pathp;
			Assemblies->Add(path);
			files_counter += 1;
		}
		if (Data[0] == "classname")
		{
			ClassName = Data[1];
		}
	}
	Assemblies->Add("mscorlib.dll");
	Assemblies->Add("System.dll");
	PrintInfoColor();
	printf("Loaded default assembly: mscorlib.dll \r\n");
	PrintInfoColor();
	printf("Loaded default assembly: System.dll \r\n");
	if (files_counter == 0) {
		PrintErrorColor();
		printf("No scripts were loaded... \r\n");
	}
	else printf("Files loaded: %i", files_counter);
}
void VCMPCSharpPlugin::ScriptCompiler::Initialize()
{
	servertype = compiledCode->GetType(ClassName);
	serverinstance = compiledCode->CreateInstance(ClassName, true);

	_serverInitialise = servertype->GetMethod("OnServerInitialise");
	_ServerShutdown = servertype->GetMethod("OnServerShutdown");
	_ServerFrame = servertype->GetMethod("OnServerFrame");

	_IncomingConnection = servertype->GetMethod("OnIncomingConnection");
	_ClientScriptData = servertype->GetMethod("OnClientScriptData");
	_PlayerConnection = servertype->GetMethod("OnPlayerConnect");
	_PlayerDisconnect = servertype->GetMethod("OnPlayerDisconnect");

	_PlayerRequestClass = servertype->GetMethod("OnPlayerRequestClass");
	_PlayerRequestSpawn = servertype->GetMethod("OnPlayerRequestSpawn");
	_PlayerSpawn = servertype->GetMethod("OnPlayerSpawn");
	_PlayerDeath = servertype->GetMethod("OnPlayerDeath");

	_PlayerUpdate = servertype->GetMethod("OnPlayerUpdate");
	_PlayerRequestEnterVehicle = servertype->GetMethod("OnPlayerRequestEnterVehicle");
	_PlayerEnterVehicle = servertype->GetMethod("OnPlayerEnterVehicle");
	_PlayerExitVehicle = servertype->GetMethod("OnPlayerExitVehicle");

	_PlayerNameChange = servertype->GetMethod("OnPlayerNameChange");
	_PlayerStateChange = servertype->GetMethod("OnPlayerStateChange");
	_PlayerActionChange = servertype->GetMethod("OnPlayerActionChange");
	_PlayerOnFireChange = servertype->GetMethod("OnPlayerOnFireChange");
	_PlayerCrouchChange = servertype->GetMethod("OnPlayerCrouchChange");
	_PlayerGameKeysChange = servertype->GetMethod("OnPlayerGameKeysChange");
	_PlayerBeginTyping = servertype->GetMethod("OnPlayerBeginTyping");
	_PlayerEndTyping = servertype->GetMethod("OnPlayerEndTyping");
	_PlayerAwayChange = servertype->GetMethod("OnPlayerAwayChange");

	_PlayerMessage = servertype->GetMethod("OnPlayerMessage");
	_PlayerCommand = servertype->GetMethod("OnPlayerCommand");
	_PlayerPrivateMessage = servertype->GetMethod("OnPlayerPrivateMessage");

	_PlayerKeyBindDown = servertype->GetMethod("OnPlayerKeyBindDown");
	_PlayerKeyBindUp = servertype->GetMethod("OnPlayerKeyBindUp");
	_PlayerSpectate = servertype->GetMethod("OnPlayerSpectate");
	_PlayerCrashReport = servertype->GetMethod("OnPlayerCrashReport");

	_VehicleUpdate = servertype->GetMethod("OnVehicleUpdate");
	_VehicleExplode = servertype->GetMethod("OnVehicleExplode");
	_VehicleRespawn = servertype->GetMethod("OnVehicleRespawn");

	_ObjectShot = servertype->GetMethod("OnObjectShot");
	_ObjectTouched = servertype->GetMethod("OnObjectTouched");

	_PickupPickAttempt = servertype->GetMethod("OnPickupPickAttempt");
	_PickupPicked = servertype->GetMethod("OnPickupPicked");
	_PickupRespawn = servertype->GetMethod("OnPickupRespawn");

	_CheckpointEntered = servertype->GetMethod("OnCheckpointEntered");
	_CheckpointExited = servertype->GetMethod("OnCheckpointExited");

	_ServerPerformanceReport = servertype->GetMethod("OnServerPerformanceReport");
	_PlayerModuleList = servertype->GetMethod("OnPlayerModuleList");
}
bool VCMPCSharpPlugin::ScriptCompiler::CompileAll()
{
	params = gcnew CompilerParameters(Assemblies->ToArray());
	params->GenerateInMemory = true;
	params->MainClass = ClassName;
	params->GenerateExecutable = false;
	compiler = CodeDomProvider::CreateProvider("CSharp");
	results = compiler->CompileAssemblyFromFile(params, Files->ToArray());
	if (results->Errors->HasErrors)
	{
		for (int i = 0; i < results->Errors->Count; i++)
		{
			PrintErrorColor();
			printf("Error %d.) %s Line %d Column %d \r\n", i, CLIStringToCharA(results->Errors[i]->ErrorText), results->Errors[i]->Line,results->Errors[i]->Column);
		}
		PrintInfoColor();
		printf("Since compilation failed, this plugin's execution will terminate...");
		delete compiler;
		return false;
	}
	else
	{
		PrintInfoColor();
		printf("Compilation succeded!");
		compiledCode = results->CompiledAssembly;
		delete compiler;
		return true;
	}
}
uint8_t VCMPCSharpPlugin::ScriptCompiler::CallserverInitialise()
{
	if (_serverInitialise != nullptr)
	{
		return (uint8_t)_serverInitialise->Invoke(serverinstance, nullptr);
	}
	return 1;
}
void VCMPCSharpPlugin::ScriptCompiler::CallServerShutdown()
{
	if (_ServerShutdown != nullptr)
	{
		_ServerShutdown->Invoke(serverinstance, nullptr);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallServerFrame(float elapsedtime)
{
	if (_ServerShutdown != nullptr)
	{
		array<Object^> ^args = gcnew array<Object^>(1);
		args[0] = elapsedtime;
		_ServerShutdown->Invoke(serverinstance,args);
	}
}

uint8_t VCMPCSharpPlugin::ScriptCompiler::CallIncomingConnection(char* playerName, size_t nameBufferSize, const char* userPassword, const char* ipAddress)
{
	if (_IncomingConnection != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = CharATOCLIString(playerName, nameBufferSize);
		args[1] = CharATOCLIString(userPassword);
		args[2] = CharATOCLIString(ipAddress);
		return (uint8_t)_IncomingConnection->Invoke(serverinstance, args);
	}
	else return 1;
}
array<uint8_t>^ CreateArrayFromBuffer(const uint8_t* data, size_t size)
{
	array<uint8_t>^ r = gcnew array<uint8_t>((int)size);
	for (unsigned i = 0; i < size; i++)
	{
		r[i] = data[i];
	}
	return r;
}
void VCMPCSharpPlugin::ScriptCompiler::CallClientScriptData(int32_t playerId, const uint8_t* data, size_t size)
{
	if (_ClientScriptData != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = CreateArrayFromBuffer(data,size);
		_ClientScriptData->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerConnection(int32_t playerId)
{
	if (_PlayerConnection != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CPlayer(playerId);
		_PlayerConnection->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerDisconnect(int32_t playerId, vcmpDisconnectReason reason)
{
	if (_PlayerDisconnect != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = (DisconnectReason)reason;
		_PlayerDisconnect->Invoke(serverinstance, args);
	}
}

uint8_t VCMPCSharpPlugin::ScriptCompiler::CallPlayerRequestClass(int32_t playerId, int32_t offset)
{
	if (_PlayerRequestClass != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = offset;
		return (uint8_t)_PlayerRequestClass->Invoke(serverinstance, args);
	}
	else return 1;
}
uint8_t VCMPCSharpPlugin::ScriptCompiler::CallPlayerRequestSpawn(int32_t playerId)
{
	if (_PlayerRequestSpawn != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CPlayer(playerId);
		return (uint8_t)_PlayerRequestSpawn->Invoke(serverinstance, args);
	}
	else return 1;
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerSpawn(int32_t playerId)
{
	if (_PlayerSpawn != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CPlayer(playerId);
		_PlayerSpawn->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerDeath(int32_t playerId, int32_t killerId, int32_t reason, vcmpBodyPart bodyPart)
{
	if (_PlayerDeath != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(4);
		args[0] = gcnew CPlayer(playerId);
		args[1] = gcnew CPlayer(killerId);
		args[2] = reason;
		args[3] = (BodyPart)bodyPart;
		_PlayerDeath->Invoke(serverinstance, args);
	}
}

void VCMPCSharpPlugin::ScriptCompiler::CallPlayerUpdate(int32_t playerId, vcmpPlayerUpdate updateType)
{
	if (_PlayerUpdate != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = (PlayerUpdate)updateType;
		_PlayerDeath->Invoke(serverinstance, args);
	}
}
uint8_t VCMPCSharpPlugin::ScriptCompiler::CallPlayerRequestEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex)
{
	if (_PlayerRequestEnterVehicle != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = gcnew CVehicle(vehicleId);
		return (uint8_t)_PlayerRequestEnterVehicle->Invoke(serverinstance, args);
	}
	else return 1;
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerEnterVehicle(int32_t playerId, int32_t vehicleId, int32_t slotIndex)
{
	if (_PlayerEnterVehicle != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = gcnew CPlayer(playerId);
		args[1] = gcnew CVehicle(vehicleId);
		args[2] = slotIndex;
		_PlayerEnterVehicle->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerExitVehicle(int32_t playerId, int32_t vehicleId)
{
	if (_PlayerEnterVehicle != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = gcnew CVehicle(vehicleId);
		_PlayerEnterVehicle->Invoke(serverinstance, args);
	}
}

void VCMPCSharpPlugin::ScriptCompiler::CallPlayerNameChange(int32_t playerId, const char* oldName, const char* newName)
{
	if (_PlayerNameChange != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = gcnew CPlayer(playerId);
		args[1] = CharATOCLIString(oldName);
		args[2] = CharATOCLIString(newName);
		_PlayerNameChange->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerStateChange(int32_t playerId, vcmpPlayerState oldState, vcmpPlayerState newState)
{
	if (_PlayerStateChange != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = gcnew CPlayer(playerId);
		args[1] = (PlayerState)oldState;
		args[2] = (PlayerState)newState;
		_PlayerStateChange->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerActionChange(int32_t playerId, int32_t oldAction, int32_t newAction)
{
	if (_PlayerActionChange != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = gcnew CPlayer(playerId);
		args[1] = oldAction;
		args[2] = newAction;
		_PlayerActionChange->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerOnFireChange(int32_t playerId, uint8_t isOnFire)
{
	if (_PlayerOnFireChange != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = isOnFire;
		_PlayerOnFireChange->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerCrouchChange(int32_t playerId, uint8_t isCrouching)
{
	if (_PlayerCrouchChange != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = isCrouching;
		_PlayerCrouchChange->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerGameKeysChange(int32_t playerId, uint32_t oldKeys, uint32_t newKeys)
{
	if (_PlayerGameKeysChange != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = gcnew CPlayer(playerId);
		args[1] = oldKeys;
		args[2] = newKeys;
		_PlayerGameKeysChange->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerBeginTyping(int32_t playerId)
{
	if (_PlayerBeginTyping != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CPlayer(playerId);
		_PlayerBeginTyping->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerEndTyping(int32_t playerId)
{
	if (_PlayerEndTyping != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CPlayer(playerId);
		_PlayerEndTyping->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerAwayChange(int32_t playerId, uint8_t isAway)
{
	if (_PlayerAwayChange != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = isAway;
		_PlayerAwayChange->Invoke(serverinstance, args);
	}
}

uint8_t VCMPCSharpPlugin::ScriptCompiler::CallPlayerMessage(int32_t playerId, const char* message)
{
	if (_PlayerMessage != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = CharATOCLIString(message);
		return (uint8_t)_PlayerMessage->Invoke(serverinstance, args);
	}
	return 1;
}
uint8_t VCMPCSharpPlugin::ScriptCompiler::CallPlayerCommand(int32_t playerId, const char* message)
{
	if (_PlayerCommand != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = CharATOCLIString(message);
		return (uint8_t)_PlayerCommand->Invoke(serverinstance, args);
	}
	return 1;
}
uint8_t VCMPCSharpPlugin::ScriptCompiler::CallPlayerPrivateMessage(int32_t playerId, int32_t targetPlayerId, const char* message)
{
	if (_PlayerPrivateMessage != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = gcnew CPlayer(playerId);
		args[1] = gcnew CPlayer(targetPlayerId);
		args[2] = CharATOCLIString(message);
		return (uint8_t)_PlayerPrivateMessage->Invoke(serverinstance, args);
	}
	else return 1;
}

void VCMPCSharpPlugin::ScriptCompiler::CallPlayerKeyBindDown(int32_t playerId, int32_t bindId)
{
	if (_PlayerKeyBindDown != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = bindId;
		_PlayerKeyBindDown->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerKeyBindUp(int32_t playerId, int32_t bindId)
{
	if (_PlayerKeyBindUp != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = bindId;
		_PlayerKeyBindUp->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerSpectate(int32_t playerId, int32_t targetPlayerId)
{
	if (_PlayerSpectate != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = gcnew CPlayer(targetPlayerId);
		_PlayerSpectate->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerCrashReport(int32_t playerId, const char* report)
{
	if (_PlayerCrashReport != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = CharATOCLIString(report);
		_PlayerCrashReport->Invoke(serverinstance, args);
	}
}

void VCMPCSharpPlugin::ScriptCompiler::CallVehicleUpdate(int32_t vehicleId, vcmpVehicleUpdate updateType)
{
	if (_VehicleUpdate != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CVehicle(vehicleId);
		args[1] = (VehicleUpdate)updateType;
		_VehicleUpdate->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallVehicleExplode(int32_t vehicleId)
{
	if (_VehicleExplode != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CVehicle(vehicleId);
		_VehicleExplode->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallVehicleRespawn(int32_t vehicleId)
{
	if (_VehicleRespawn != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CVehicle(vehicleId);
		_VehicleRespawn->Invoke(serverinstance, args);
	}
}

void VCMPCSharpPlugin::ScriptCompiler::CallObjectShot(int32_t objectId, int32_t playerId, int32_t weaponId)
{
	if (_ObjectShot != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = gcnew CObject(objectId);
		args[1] = gcnew CPlayer(playerId);
		args[2] = weaponId;
		_ObjectShot->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallObjectTouched(int32_t objectId, int32_t playerId)
{
	if (_ObjectTouched != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CObject(objectId);
		args[1] = gcnew CPlayer(playerId);
		_ObjectTouched->Invoke(serverinstance, args);
	}
}

uint8_t VCMPCSharpPlugin::ScriptCompiler::CallPickupPickAttempt(int32_t pickupId, int32_t playerId)
{
	if (_PickupPickAttempt != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPickup(pickupId);
		args[1] = gcnew CPlayer(playerId);
		return (uint8_t)_PickupPickAttempt->Invoke(serverinstance, args);
	}
	else return 1;
}
void VCMPCSharpPlugin::ScriptCompiler::CallPickupPicked(int32_t pickupId, int32_t playerId)
{
	if (_PickupPicked != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPickup(pickupId);
		args[1] = gcnew CPlayer(playerId);
		_PickupPicked->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPickupRespawn(int32_t pickupId)
{
	if (_PickupRespawn != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(1);
		args[0] = gcnew CPickup(pickupId);
		_PickupRespawn->Invoke(serverinstance, args);
	}
}

void VCMPCSharpPlugin::ScriptCompiler::CallCheckpointEntered(int32_t checkPointId, int32_t playerId)
{
	if (_CheckpointEntered != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CCheckPoint(checkPointId);
		args[1] = gcnew CPlayer(playerId);
		_CheckpointEntered->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallCheckpointExited(int32_t checkPointId, int32_t playerId)
{
	if (_CheckpointExited != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CCheckPoint(checkPointId);
		args[1] = gcnew CPlayer(playerId);
		_CheckpointExited->Invoke(serverinstance, args);
	}
}

void VCMPCSharpPlugin::ScriptCompiler::CallServerPerformanceReport(size_t entryCount, const char** descriptions, uint64_t* times)
{
	if (_ServerPerformanceReport != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(3);
		args[0] = entryCount;
		array<String^>^ desc = gcnew array<String^>((int)entryCount);
		array<uint64_t>^ t = gcnew array<uint64_t>((int)entryCount);
		for (unsigned i = 0; i < entryCount; i++)
		{
			desc[i] = CharATOCLIString(descriptions[i]);
			t[i] = times[i];
		}
		args[1] = desc;
		args[2] = t;
		_ServerPerformanceReport->Invoke(serverinstance, args);
	}
}
void VCMPCSharpPlugin::ScriptCompiler::CallPlayerModuleList(int32_t playerId, const char* list)
{
	if (_PlayerModuleList != nullptr)
	{
		array<Object^>^ args = gcnew array<Object^>(2);
		args[0] = gcnew CPlayer(playerId);
		args[1] = CharATOCLIString(list);
		_PlayerModuleList->Invoke(serverinstance, args);
	}
}
