#pragma once
#include "VCMP_CSharp_Plugin.h"
#include "Common.h"
#include "WorldBounds.h"
#include "WastedSettings.h"
#include "Vector.h"
#include "CPlayer.h"
#include "VCMP_Events.h"

using namespace System;
namespace VCMPCSharpPlugin
{
	ref class Server
	{
	private:
		Server() {}
	public:
		property String^ Name
		{
			String^ get()
			{
				char * servern = new char[50];
				api->GetServerName(servern, 50);
				String^ r = CharATOCLIString(servern);
				delete servern;
				return r;
			}
			void set(String^ name)
			{
				api->SetServerName(CLIStringToCharA(name));
			}
		}
		property int MaxPlayers
		{
			int get()
			{
				return api->GetMaxPlayers();
			}
			void set(int maxp)
			{
				api->SetMaxPlayers(maxp);
			}
		}
		property String^ Password
		{
			String^ get()
			{
				char *pass = new char[50];
				api->GetServerPassword(pass, 50);
				String^ r = CharATOCLIString(pass);
				delete pass;
				return r;
			}
			void set(String^ pass)
			{
				api->SetServerPassword(CLIStringToCharA(pass));
			}
		}
		property String^ Gamemode
		{
			String^ get()
			{
				char *gamemode = new char[50];
				api->GetGameModeText(gamemode, 50);
				String^ r = CharATOCLIString(gamemode);
				delete gamemode;
				return r;
			}
			void set(String^ g)
			{
				api->SetGameModeText(CLIStringToCharA(g));
			}
		}
		void Shutdown();
		property bool SyncFrameLimiter
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionSyncFrameLimiter);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionSyncFrameLimiter, toggle);
			}
		}
		property bool FrameLimiter
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionFrameLimiter);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionFrameLimiter, toggle);
			}
		}
		property bool TaxiBoostJump
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionTaxiBoostJump);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionTaxiBoostJump, toggle);
			}
		}
		property bool DriveOnWater
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionDriveOnWater);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionDriveOnWater, toggle);
			}
		}
		property bool FastSwitch
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionFastSwitch);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionFastSwitch, toggle);
			}
		}
		property bool FriendlyFire
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionFriendlyFire);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionFriendlyFire, toggle);
			}
		}
		property bool DisableDriveBy
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionDisableDriveBy);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionDisableDriveBy, toggle);
			}
		}
		property bool PerfectHandling
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionPerfectHandling);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionPerfectHandling, toggle);
			}
		}
		property bool FlyingCars
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionFlyingCars);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionFlyingCars, toggle);
			}
		}
		property bool JumpSwitch
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionJumpSwitch);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionJumpSwitch, toggle);
			}
		}
		property bool PlayerMarkers
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionShowMarkers);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionShowMarkers, toggle);
			}
		}
		property bool TeamOnlyMarkers
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionOnlyShowTeamMarkers);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionOnlyShowTeamMarkers, toggle);
			}
		}
		property bool StuntBike
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionStuntBike);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionStuntBike, toggle);
			}
		}
		property bool ShootInAir
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionShootInAir);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionShootInAir, toggle);
			}
		}
		property bool NameTags
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionShowNameTags);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionShowNameTags, toggle);
			}
		}
		property bool DefaultJoinMessages
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionJoinMessages);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionJoinMessages, toggle);
			}
		}
		property bool DefaultDeathMessages
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionDeathMessages);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionDeathMessages, toggle);
			}
		}
		property bool ChatTags
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionChatTagsEnabled);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionChatTagsEnabled, toggle);
			}
		}
		property bool Classes
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionUseClasses);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionUseClasses, toggle);
			}
		}
		property bool Wallglitch
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionWallGlitch);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionWallGlitch, toggle);
			}
		}
		property bool DisableBackFaceCulling
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionDisableBackfaceCulling);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionDisableBackfaceCulling, toggle);
			}
		}
		property bool DisableHelicopterBladeDamage
		{
			bool get()
			{
				return api->GetServerOption(vcmpServerOption::vcmpServerOptionDisableHeliBladeDamage);
			}
			void set(bool toggle)
			{
				api->SetServerOption(vcmpServerOption::vcmpServerOptionDisableHeliBladeDamage, toggle);
			}
		}
		property WorldBounds^ Bounds
		{
			WorldBounds^ get()
			{
				float *a=nullptr, *b=nullptr, *c=nullptr, *d=nullptr;
				api->GetWorldBounds(a, b, c, d);
				return gcnew WorldBounds(*a, *b, *c, *d);
			}
			void set(WorldBounds^ bounds)
			{
				api->SetWorldBounds(bounds->MaxX, bounds->MinX, bounds->MaxY, bounds->MinY);
			}
		}
		property WastedSettings^ SettingsWasted
		{
			WastedSettings^ get()
			{
				uint32_t *a=nullptr, *b=nullptr, *e=nullptr, *f=nullptr, *col=nullptr;
				float *c=nullptr, *d=nullptr;
				api->GetWastedSettings(a, b, c, d, col, e, f);
				return gcnew WastedSettings(*a, *b, *c, *d, Color::FromUInt(*col), *e, *f);
			}
			void set(WastedSettings^ w)
			{
				api->SetWastedSettings(w->DeathTime, w->FadeTime, w->FadeInSpeed, w->FadeOutSpeed, w->FadeColor->ToUint(), w->CorpseFadeDelay, w->CorpseFadeTime);
			}
		}
		property int TimeRate
		{
			int get()
			{
				return api->GetTimeRate();
			}
			void set(int time)
			{
				api->SetTimeRate(time);
			}
		}
		property int Hour
		{
			int get()
			{
				return api->GetHour();
			}
			void set(int h)
			{
				api->SetHour(h);
			}
		}
		property int Minute
		{
			int get()
			{
				return api->GetMinute();
			}
			void set(int m)
			{
				api->SetMinute(m);
			}
		}
		property int Weather
		{
			int get()
			{
				return api->GetWeather();
			}
			void set(int w)
			{
				api->SetWeather(w);
			}
		}
		property float Gravity
		{
			float get()
			{
				return api->GetGravity();
			}
			void set(float g)
			{
				api->SetGravity(g);
			}
		}
		property float GameSpeed
		{
			float get()
			{
				return api->GetGameSpeed();
			}
			void set(float speed)
			{
				api->SetGameSpeed(speed);
			}
		}
		property float WaterLevel
		{
			float get()
			{
				return api->GetWaterLevel();
			}
			//watter bottles plez, im thirsty
			void set(float water)
			{
				api->SetWaterLevel(water);
			}
		}
		property float MaxFlightAltitude
		{
			float get()
			{
				return api->GetMaximumFlightAltitude();
			}
			void set(float altitute)
			{
				api->SetMaximumFlightAltitude(altitute);
			}
		}
		property uint8_t KillDelay
		{
			uint8_t get()
			{
				return api->GetKillCommandDelay();
			}
			void set(uint8_t delay)
			{
				api->SetKillCommandDelay(delay);
			}
		}
		void ToggleKillCommand(bool toggle);
		property float ForceVehiclesRespawnHeight
		{
			float get()
			{
				return api->GetVehiclesForcedRespawnHeight();
			}
			void set(float max_h)
			{
				api->SetVehiclesForcedRespawnHeight(max_h);
			}
		}
		void CreateExplosion(int world, int type, Vector^ pos, CPlayer ^guilt_player, bool onground);
		void PlaySound(int world, int sound, Vector^ pos);
		void ShowMapObject(int model, Vector^ pos);
		void HideMapObject(int model, Vector^ pos);
		void ShowAllMapObjects();
		event OnServerInitialise^ OnServerStart;
		event OnServerShutdown^ OnServerStop;
		event OnServerFrame^ OnServerFrame;
		
		event  OnIncomingConnection^ OnPlayerConnecting;
		event OnClientScriptData^ OnClientScriptData;

		event OnPlayerConnect^ OnPlayerJoin;
		event OnPlayerDisconnect^ OnPlayerQuit;

		event  OnPlayerRequestClass^ OnPlayerRequestClass;
		event  OnPlayerRequestSpawn^ OnPlayerRequestSpawn;
		event OnPlayerSpawn^ OnPlayerSpawn;
		event OnPlayerDeath^ OnPlayerDeath;
		event OnPlayerUpdate^ OnPlayerUpdate;

		event  OnPlayerRequestEnterVehicle^ OnPlayerEnterRequestEnterVehicle;
		event OnPlayerEnterVehicle^ OnPlayerEnterVehicle;
		event OnPlayerExitVehicle^ OnPlayerExitVehicle;

		event OnPlayerNameChange^ OnPlayerNameChange;
		event OnPlayerStateChange^ OnPlayerStateChange;
		event OnPlayerActionChange^ OnPlayerActionChange;
		event OnPlayerOnFireChange^ OnPlayerOnFireChange;
		event OnPlayerCrouchChange^ OnPlayerCrouchChange;
		event OnPlayerGameKeysChange^ OnPlayerKeysChange;
		event OnPlayerBeginTyping^ OnPlayerBeginTyping;
		event OnPlayerEndTyping^ OnPlayerEndTyping;
		event OnPlayerAwayChange^ OnPlayerAwayChange;

		event  OnPlayerMessage^ OnPlayerChat;
		event  OnPlayerCommand^ OnPlayerCommand;
		event  OnPlayerPrivateMessage^ OnPlayerPM;

		event OnPlayerKeyBindDown^ OnPlayerKeyDown;
		event OnPlayerKeyBindUp^ OnPlayerKeyUp;
		event OnPlayerSpectate^ OnPlayerSpectate;
		event OnPlayerCrashReport^ OnPlayerCrash;

		event OnVehicleUpdate^ OnVehicleUpdate;
		event OnVehicleExplode^ OnVehicleExplode;
		event OnVehicleRespawn^ OnVehicleRespawn;

		event OnObjectShot^ OnObjectShot;
		event OnObjectTouched^ OnObjectBump;
		event  OnPickupPickAttempt^ OnPickupPickAttempt;
		event OnPickupPicked^ OnPickupCollected;
		event OnPickupRespawn^ OnPickupRespawn;

		event OnCheckpointEntered^ OnCheckpointEnter;
		event OnCheckpointExited^ OnCheckpointExit;

		//event OnEntityPoolChange(vcmpEntityPool entityType, int32_t entityId, uint8_t isDeleted);
		event OnServerPerformanceReport^ OnPerformanceReport;

		// TODO: MOVE LATER
		event OnPlayerModuleList^ OnPlayerModuleList;
};

}