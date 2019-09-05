#pragma once
#include "VCMP_CSharp_Plugin.h"
#include "Common.h"
#include "WorldBounds.h"
#include "WastedSettings.h"
#include "Vector.h"
#include "CPlayer.h"

using namespace System;
namespace VCMPCSharpPlugin
{
	ref class Server
	{
	private:
		Server() {}
	public:
		static property String^ Name
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
		static property int MaxPlayers
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
		static property String^ Password
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
		static property String^ Gamemode
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
		static void Shutdown();
		static property bool SyncFrameLimiter
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
		static property bool FrameLimiter
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
		static property bool TaxiBoostJump
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
		static property bool DriveOnWater
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
		static property bool FastSwitch
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
		static property bool FriendlyFire
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
		static property bool DisableDriveBy
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
		static property bool PerfectHandling
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
		static property bool FlyingCars
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
		static property bool JumpSwitch
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
		static property bool PlayerMarkers
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
		static property bool TeamOnlyMarkers
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
		static property bool StuntBike
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
		static property bool ShootInAir
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
		static property bool NameTags
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
		static property bool DefaultJoinMessages
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
		static property bool DefaultDeathMessages
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
		static property bool ChatTags
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
		static property bool Classes
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
		static property bool Wallglitch
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
		static property bool DisableBackFaceCulling
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
		static property bool DisableHelicopterBladeDamage
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
		static property WorldBounds^ Bounds
		{
			WorldBounds^ get()
			{
				float *a, *b, *c, *d;
				api->GetWorldBounds(a, b, c, d);
				return gcnew WorldBounds(*a, *b, *c, *d);
			}
			void set(WorldBounds^ bounds)
			{
				api->SetWorldBounds(bounds->MaxX, bounds->MinX, bounds->MaxY, bounds->MinY);
			}
		}
		static property WastedSettings^ SettingsWasted
		{
			WastedSettings^ get()
			{
				uint32_t *a, *b, *e, *f, *col;
				float *c, *d;
				api->GetWastedSettings(a, b, c, d, col, e, f);
				return gcnew WastedSettings(*a, *b, *c, *d, Color::FromUInt(*col), *e, *f);
			}
			void set(WastedSettings^ w)
			{
				api->SetWastedSettings(w->DeathTime, w->FadeTime, w->FadeInSpeed, w->FadeOutSpeed, w->FadeColor->ToUint(), w->CorpseFadeDelay, w->CorpseFadeTime);
			}
		}
		static property int TimeRate
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
		static property int Hour
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
		static property int Minute
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
		static property int Weather
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
		static property float Gravity
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
		static property float GameSpeed
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
		static property float WaterLevel
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
		static property float MaxFlightAltitude
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
		static property uint8_t KillDelay
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
		static void ToggleKillCommand(bool toggle);
		static property float ForceVehiclesRespawnHeight
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
		static void CreateExplosion(int world, int type, Vector^ pos, CPlayer ^guilt_player, bool onground);
		static void PlaySound(int world, int sound, Vector^ pos);
		static void ShowMapObject(int model, Vector^ pos);
		static void HideMapObject(int model, Vector^ pos);
		static void ShowAllMapObjects();
	};

}