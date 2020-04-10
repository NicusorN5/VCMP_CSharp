#pragma once
#include"Common.h"
#include "Color.h"
#include "Vector.h"
#include "VCMPEnums.h"

//Before you compiain, i know this class is supposed to be filled with null-checks of the player instance. Ok bye.
using namespace System;
namespace VCMPCSharpPlugin
{
	public ref class CPlayer
	{
		int _id;
		CPlayer();
	public:
		CPlayer(int id);
		property String^ Name 
		{
			void set(String^ value) 
			{
				if(this->Connected) api->SetPlayerName(this->ID, CLIStringToCharA(value));
			}
			String^ get()
			{
				if (this->Connected)
				{
					char* N = new char[25];
					api->GetPlayerName(this->ID, N, 25);
					String^ r = CharATOCLIString(N);
					delete N;
					return r;
				}
				else return String::Empty;
			}
		}
		property int ID {
			int get() 
			{
				return _id;
			}

			private: void set(int v)
			{
				this->Connected = api->IsPlayerConnected(v);
				if (this->Connected) _id = v;
			}
		}
		property bool Admin 
		{
			bool get() 
			{
				if (this->Connected) return api->IsPlayerAdmin(this->ID);
				else return false;
			}
			void set(bool value)
			{
				if(this->Connected) api->SetPlayerAdmin(this->ID, value);
			}
		}
		property String^ IP
		{
			String^ get()
			{
				if (this->Connected)
				{
					char* IP = new char[20];
					api->GetPlayerIP(this->ID, IP, 20);
					String^ r = CharATOCLIString(IP);
					delete IP;
					return r;
				}
				else return "0.0.0.0";
			}
		}
		property String^ UID
		{
			String^ get()
			{
				if (this->Connected)
				{
					char* UID = new char[50];
					api->GetPlayerUID(this->ID, UID, 50);
					String^ result = CharATOCLIString(UID);
					delete UID;
					return result;
				}
				else return String::Empty;
			}
		}
		property String^ UID2
		{
			String^ get()
			{
				if (this->Connected)
				{
					char* UID2 = new char[50];
					api->GetPlayerUID2(this->ID, UID2, 50);
					String^ r = CharATOCLIString(UID2);
					delete UID2;
					return r;
				}
				else return String::Empty;
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
			private: void set(bool value) {}
		}
		bool PlayerStreamedToPlayer(CPlayer^ p);
		property int UniqueID
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerKey(this->ID);
				else return 0;
			}
		}
		property PlayerState State
		{
			PlayerState get()
			{
				if(this->Connected) return (PlayerState)api->GetPlayerState(this->ID);
				else return PlayerState::Unspawned;
			}
		}
		property bool Frozen
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionControllable);
				else return false;
			}
			void set(bool value)
			{
				if(this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionControllable, value);
			}
		}
		property bool CanDriveBy
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDriveBy);
				else return false;
			}
			void set(bool value)
			{
				if (this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDriveBy, value);
			}
		}
		property bool WhiteScanlines
		{
			bool get()
			{
				if(this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWhiteScanlines);
				return false;
			}
			void set(bool value)
			{
				if(this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWhiteScanlines, value);
			}
		}
		property bool GreenScanlines
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionGreenScanlines);
				else return false;
			}
			void set(bool value)
			{
				if(this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionGreenScanlines, value);
			}
		}
		property bool Widescreen
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWidescreen);
				else return false;
			}
			void set(bool value)
			{
				if (this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionWidescreen, value);
			}
		}
		property bool MarkersShown
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionShowMarkers);
				else return false;
			}
			void set(bool value)
			{
				if(this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionShowMarkers, value);
			}
		}
		property bool CanAttack
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionCanAttack);
				else return false;
			}
			void set(bool value)
			{
				if(this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionCanAttack, value);
			}
		}
		property bool HasMarker
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionHasMarker);
				else return false;
			}
			void set(bool value)
			{
				if (this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionHasMarker, value);
			}
		}
		property bool ChatTags
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionChatTagsEnabled);
				else return false;
			}
			void set(bool value)
			{
				if(this->Connected)api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionChatTagsEnabled, value);
			}
		}
		property uint8_t DrunkLevel
		{
			uint8_t get()
			{
				if (this->Connected) return api->GetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDrunkEffects);
				else return 0;
			}
			void set(uint8_t value)
			{
				if(this->Connected) api->SetPlayerOption(this->ID, vcmpPlayerOption::vcmpPlayerOptionDrunkEffects, value);
			}
		}
		property int World
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerWorld(this->ID);
				else return 0;
			}
			void set(int v)
			{
				if(this->Connected) api->SetPlayerWorld(this->ID, v);
			}
		}
		property int SecondaryWorld
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerSecondaryWorld(this->ID);
				else return 0;
			}
			void set(int value)
			{
				if(this->Connected) api->SetPlayerSecondaryWorld(this->ID, value);
			}
		}
		property int UniqueWorld
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerUniqueWorld(this->ID);
				else return 0;
			}
		}
		bool WorldCompatible(int world);
		property int Class
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerClass(this->ID);
				else return 0;
			}
		}
		property int Team
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerTeam(this->ID);
				else return 0;
			}
			void set(int value)
			{
				if(this->Connected) api->SetPlayerTeam(this->ID, value);
			}
		}
		property int Skin
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerSkin(this->ID);
				else return 0;
			}
			void set(int v)
			{
				if(this->Connected) api->SetPlayerSkin(this->ID, v);
			}

		}
		property Color^ Colour
		{
			Color^ get()
			{
				if (this->Connected) return Color::FromUInt(api->GetPlayerColour(this->ID));
				else return gcnew Color(0, 0, 0);
			}
			void set(Color^ color)
			{
				if(this->Connected) api->SetPlayerColour(this->ID, color->ToUint());
			}
		}
		property bool Spawned
		{
			bool get()
			{
				if (this->Connected) return api->IsPlayerSpawned(this->ID);
				else return false;
			}
		}
		void ForceSpawn();
		void ForceSelect();
		property bool Typing
		{
			bool get()
			{
				if (this->Connected) return api->IsPlayerTyping(this->ID);
				else return false;
			}
		}
		property int Money
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerMoney(this->ID);
				else return 0;
			}
			void set(int v)
			{
				if(this->Connected) api->SetPlayerMoney(this->ID, v);
			}
		}
		property int Score
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerScore(this->ID);
				else return 0;
			}
			void set(int newscore)
			{
				if(this->Connected) api->SetPlayerScore(this->ID, newscore);
			}
		}
		property uint8_t WantedLevel
		{
			uint8_t get()
			{
				if (this->Connected) return api->GetPlayerWantedLevel(this->ID);
				else return 0;
			}
			void set(uint8_t v)
			{
				if(this->Connected) api->SetPlayerWantedLevel(this->ID, v);
			}
		}
		property int Ping
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerPing(this->ID);
				else return 0x7fffffff;
			}
		}
		property double FPS
		{
			double get()
			{
				if (this->Connected) return api->GetPlayerFPS(this->ID);
				else return 0;
			}
		}
		property float Health
		{
			float get()
			{
				if (this->Connected) return api->GetPlayerHealth(this->ID);
				else return 0;
			}
			void set(float h)
			{
				if(this->Connected) api->SetPlayerHealth(this->ID, h);
			}
		}
		property float Armour
		{
			float get()
			{
				if (this->Connected) return api->GetPlayerArmour(this->ID);
				else return 0;
			}
			void set(float a)
			{
				if(this->Connected) api->SetPlayerArmour(this->ID, a);
			}
		}
		property int Immunity
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerImmunityFlags(this->ID);
				else return 0;
			}
			void set(int flags)
			{
				if(this->Connected) api->SetPlayerImmunityFlags(this->ID,flags);
			}
		}
		property Vector^ Position
		{
			Vector^ get()
			{
				if (this->Connected)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetPlayerPosition(this->ID, x, y, z);
					Vector^ v = gcnew Vector(*x, *y, *z);
					return v;
				}
				else return gcnew Vector(0);
			}
			void set(Vector^ pos)
			{
				if(this->Connected) api->SetPlayerPosition(this->ID, pos->x, pos->y, pos->z);
			}
		}
		property Vector^ Speed
		{
			Vector^ get()
			{
				if (this->Connected)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetPlayerSpeed(this->ID, x, y, z);
					Vector^ v = gcnew Vector(*x, *y, *z); //I dont think we need to delete this because we use C# garbage collector.
					return v;
				}
				else return gcnew Vector(0);
			}
			void set(Vector^ pos)
			{
				if(this->Connected) api->SetPlayerSpeed(this->ID, pos->x, pos->y, pos->z);
			}
		}
		void AddSpeed(Vector ^s);
		property float Angle
		{
			float get()
			{
				if (this->Connected) return api->GetPlayerHeading(this->ID);
				else return 0;
			}
			void set(float v)
			{
				if(this->Connected) api->SetPlayerHeading(this->ID, v);
			}
		}
		void Teleport(Vector^ pos, float angle);
		void SetTransparency(uint8_t alpha, int fadetime);
		property uint8_t Alpha
		{
			uint8_t get()
			{
				if (this->Connected) return api->GetPlayerAlpha(this->ID);
				return 255;
			}
		}
		property Vector^ AimDirection
		{
			Vector^ get()
			{
				if (this->Connected)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetPlayerAimDirection(this->ID, x, y, z);
					Vector^ a = gcnew Vector(*x, *y, *z);
					return a;
				}
				else return gcnew Vector(0);
			}
		}
		property Vector^ AimPosition
		{
			Vector^ get()
			{
				if (this->Connected)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetPlayerAimPosition(this->ID, x, y, z);
					Vector^ aimp = gcnew Vector(*x, *y, *z);
					return aimp;
				}
				else return gcnew Vector(0);
			}
		}
		property bool OnFire
		{
			bool get()
			{
				if (this->Connected) return api->IsPlayerOnFire(this->ID);
				else return false;
			}
		}
		property bool Crouching
		{
			bool get()
			{
				if (this->Connected) return api->IsPlayerCrouching(this->ID);
				else return false;
			}
		}
		property int Action
		{
			int get()
			{
				if(this->Connected) return api->GetPlayerAction(this->ID);
				return false;
			}
		}
		/*What is this??*/
		property int GameKeys
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerGameKeys(this->ID);
				else return 0;
			}
		}
		property int VehicleID
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerVehicleId(this->ID);
				else return -1;
			}
			void set(int v)
			{
				if(this->Connected)api->PutPlayerInVehicle(this->ID,v, 0, 1, 1);
			}
		}
		property int Weapon
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerWeapon(this->ID);
				else return 0;
			}
			void set(int w)
			{
				if(this->Connected) api->SetPlayerWeapon(this->ID, w, 1);
			}
		}
		property int Ammo
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerWeaponAmmo(this->ID);
				else return 0;
			}
		}
		property int WeaponSlot
		{
			int get()
			{
				if (this->Connected) return api->GetPlayerWeaponSlot(this->ID);
				else return 0;
			}
			void set(int slot)
			{
				if(this->Connected) api->SetPlayerWeaponSlot(this->ID, slot);
			}
		}
		void GiveWeapon(int weapon, int ammo);
		void RemoveWeapon(int weapon);
		void Disarm();
		
		void SetCameraPosition(Vector^ pos, Vector^ look_at);
		void RestoreCamera();
		property bool IsCameraLocked
		{
			bool get()
			{
				if (this->Connected) return api->IsCameraLocked(this->ID);
				else return 0;
			}
		}

		void PlayAnim(int anim_group, int anim_id);
		property bool StandingOnVehicle
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerStandingOnVehicle(this->ID);
				else return 0;
			}
		}
		property bool StandingOnObject
		{
			bool get()
			{
				if (this->Connected) return api->GetPlayerStandingOnObject(this->ID);
				else return false;
			}
		}
		property bool AFK
		{
			bool get()
			{
				if (this->Connected) return api->IsPlayerAway(this->ID);
				else return false;
			}
		}
		property CPlayer^ SpectateTarget
		{
			CPlayer ^ get()
			{
				int id = api->GetPlayerSpectateTarget(this->ID);
				if (id >= 0)
				{
					CPlayer^ ret = gcnew CPlayer(id);
					if (ret->Connected == true)
					{
						return ret;
					}
				}
				return nullptr;
			}
			void set(CPlayer^ plr)
			{
				if (plr->Connected == false)
				{
					plr = nullptr;
					api->SetPlayerSpectateTarget(this->ID, this->ID);
					return;
				}
				api->SetPlayerSpectateTarget(this->ID, plr->ID);
			}
		}
		void Redirect(String^ IP, int port, String^ Password);
		void PlaySound(int soundid);

		operator bool();
		operator int();
	};
}
