#pragma once
#include"Common.h"
#include "VCMP_CSharp_Plugin.h"
#include "Color.h"
#include "Vector.h"

using namespace System;
namespace VCMPCSharpPlugin
{
	public ref class CPlayer
	{
		CPlayer() {};
	public:
		CPlayer(int ID);
		property String^ Name 
		{
			void set(String^ value) 
			{
				api->SetPlayerName(this->ID, CLIStringToCharA(value));
			}
			String^ get()
			{
				char *N = new char[25];
				api->GetPlayerName(this->ID, N, 25);
				String^ r = CharATOCLIString(N);
				delete N;
				return r;
			}
		}
		property int ID {int get() { return this->ID; }}
		property int Action 
		{
			int get()
			{
				return api->GetPlayerAction(this->ID);
			}
		}
		property bool Admin 
		{
			bool get() 
			{
				return api->IsPlayerAdmin(this->ID); 
			}
			void set(bool value)
			{
				api->SetPlayerAdmin(this->ID, value);
			}
		}
		property String^ IP
		{
			String^ get()
			{
				char * IP = new char[20];
				api->GetPlayerIP(this->ID, IP, 20);
				String^ r = CharATOCLIString(IP);
				delete IP;
				return r;
			}
		}
		property String^ UID
		{
			String^ get()
			{
				char * UID = new char[50];
				api->GetPlayerUID(this->ID, UID, 50);
				String^ result = CharATOCLIString(UID);
				delete UID;
				return result;
			}
		}
		property String^ UID2
		{
			String^ get()
			{
				char * UID2 = new char[50];
				api->GetPlayerUID2(this->ID, UID2, 50);
				String^ r = CharATOCLIString(UID2);
				delete UID2;
				return r;
			}
		}
		void Kick();
		void Ban();
		static CPlayer^ FindPlayer(int ID);
		static CPlayer^ FindPlayer(String^ Name);
		property bool Connected
		{
			bool get()
			{
				return api->IsPlayerConnected(this->ID);
			}
		}
		bool PlayerStreamedToPlayer(CPlayer^ p);
		property int UniqueID
		{
			int get()
			{
				return api->GetPlayerKey(this->ID);
			}
		}
		/* We're using int this time, since I get errors I cant fic reeeee
		property PlayerState State
		{
			PlayerState get()
			{
				PlayerState r = (PlayerState)api->GetPlayerState(this->ID);
				return r;
			}
		}
		*/
		property int State
		{
			int get()
			{
				return api->GetPlayerState(this->ID);
			}
		}
		property bool Fronzen
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionControllable);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionControllable, value);
			}
		}
		property bool CanDriveBy
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDriveBy);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDriveBy, value);
			}
		}
		property bool WhiteScanlines
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWhiteScanlines);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWhiteScanlines, value);
			}
		}
		property bool GreenScanlines
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionGreenScanlines);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionGreenScanlines, value);
			}
		}
		property bool Widescreen
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWidescreen);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWidescreen, value);
			}
		}
		property bool MarkersShown
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionShowMarkers);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionShowMarkers, value);
			}
		}
		property bool CanAttack
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionCanAttack);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionCanAttack, value);
			}
		}
		property bool HasMarker
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionHasMarker);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionHasMarker, value);
			}
		}
		property bool ChatTags
		{
			bool get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionChatTagsEnabled);
			}
			void set(bool value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionChatTagsEnabled, value);
			}
		}
		property uint8_t DrunkLevel
		{
			uint8_t get()
			{
				return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDrunkEffects);
			}
			void set(uint8_t value)
			{
				api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDrunkEffects, value);
			}
		}
		property int World
		{
			int get()
			{
				return api->GetPlayerWorld(this->ID);
			}
			void set(int v)
			{
				api->SetPlayerWorld(this->ID, v);
			}
		}
		property int SecondaryWorld
		{
			int get()
			{
				return api->GetPlayerSecondaryWorld(this->ID);
			}
			void set(int value)
			{
				api->SetPlayerSecondaryWorld(this->ID, value);
			}
		}
		property int UniqueWorld
		{
			int get()
			{
				return api->GetPlayerUniqueWorld(this->ID);
			}
		}
		bool WorldCompatible(int world);
		property int Class
		{
			int get()
			{
				return api->GetPlayerClass(this->ID);
			}
		}
		property int Team
		{
			int get()
			{
				return api->GetPlayerTeam(this->ID);
			}
			void set(int value)
			{
				api->SetPlayerTeam(this->ID, value);
			}
		}
		property int Skin
		{
			int get()
			{
				return api->GetPlayerSkin(this->ID);
			}
			void set(int v)
			{
				api->SetPlayerSkin(this->ID, v);
			}

		}
		property Color^ Colour
		{
			Color^ get()
			{
				return Color::FromUInt(api->GetPlayerColour(this->ID));
			}
			void set(Color^ color)
			{
				api->SetPlayerColour(this->ID, color->ToUint());
			}
		}
		property bool Spawned
		{
			bool get()
			{
				return api->IsPlayerSpawned(this->ID);
			}
		}
		void ForceSpawn();
		void ForceSelect();
		property bool Typing
		{
			bool get()
			{
				return api->IsPlayerTyping(this->ID);
			}
		}
		property int Money
		{
			int get()
			{
				return api->GetPlayerMoney(this->ID);
			}
			void set(int v)
			{
				api->SetPlayerMoney(this->ID, v);
			}
		}
		property int Score
		{
			int get()
			{
				return api->GetPlayerScore(this->ID);
			}
			void set(int newscore)
			{
				api->SetPlayerScore(this->ID, newscore);
			}
		}
		property uint8_t WantedLevel
		{
			uint8_t get()
			{
				return api->GetPlayerWantedLevel(this->ID);
			}
			void set(uint8_t v)
			{
				api->SetPlayerWantedLevel(this->ID, v);
			}
		}
		property int Ping
		{
			int get()
			{
				return api->GetPlayerPing(this->ID);
			}
		}
		property double FPS
		{
			double get()
			{
				return api->GetPlayerFPS(this->ID);
			}
		}
		property uint8_t Health
		{
			uint8_t get()
			{
				return api->GetPlayerHealth(this->ID);
			}
			void set(uint8_t h)
			{
				api->SetPlayerHealth(this->ID, h);
			}
		}
		property uint8_t Armour
		{
			uint8_t get()
			{
				return api->GetPlayerArmour(this->ID);
			}
			void set(uint8_t a)
			{
				api->SetPlayerArmour(this->ID, a);
			}
		}
		property int Immunity
		{
			int get()
			{
				return api->GetPlayerImmunityFlags(this->ID);
			}
			void set(int flags)
			{
				api->SetPlayerImmunityFlags(this->ID,flags);
			}
		}
		property Vector^ Position
		{
			Vector^ get()
			{
				float *x, *y, *z;
				api->GetPlayerPosition(this->ID, x, y, z);
				Vector^ v = gcnew Vector(*x, *y,*z);
				return v;
			}
			void set(Vector^ pos)
			{
				api->SetPlayerPosition(this->ID, pos->x, pos->y, pos->z);
			}
		}
		operator bool();
		operator int();
	};
	public enum class PlayerState : int
	{
		None = 0,
		Normal = 1,
		Aim = 2,
		Driver = 3,
		Passenger = 4,
		EnterDriver = 5,
		EnterPassenger = 6,
		Exit = 7,
		Unspawned = 8,
	} ;
}
