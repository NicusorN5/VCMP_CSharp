#pragma once
#include "VCMP.h"
#include "Common.h"
#include "CPlayer.h"
#include "Quaternion.h"

namespace VCMPCSharpPlugin
{
	ref class CPlayer;
	public ref class CVehicle
	{
		int _id;
		CVehicle();
	public:
		CVehicle(int id) : _id(id) {};
		CVehicle(int Model, int world, Vector pos, float rotation, int c1, int c2);
		property int ID
		{
			int get()
			{
				return _id;
			}
		}
		property bool Valid
		{
			bool get()
			{
				return api->CheckEntityExists(vcmpEntityPool::vcmpEntityPoolVehicle, this->ID);
			}
		}
		
		property CPlayer^ Driver
		{
			CPlayer^ get()
			{
				if (this->Valid) return gcnew CPlayer(api->GetVehicleOccupant(this->ID, 0));
				else return nullptr;
			}
			void set(CPlayer^ plr)
			{
				if (this->Valid)
				{
					api->PutPlayerInVehicle(plr->ID, this->ID, 0, 1, 1);
				}
			}
		}
		void Delete();
		property bool Locked
		{
			bool get()
			{
				if (this->Valid) return api->GetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionDoorsLocked);
				else return true;
			}
			void set(bool v)
			{
				if (this->Valid) api->SetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionDoorsLocked, v);
			}
		}
		property bool Alarm
		{
			bool get()
			{
				if (this->Valid) return api->GetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionAlarm);
				else return true;
			}
			void set(bool v)
			{
				if (this->Valid) api->SetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionAlarm, v);
			}
		}
		property bool Lights
		{
			bool get()
			{
				if (this->Valid) return api->GetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionLights);
				else return true;
			}
			void set(bool v)
			{
				if (this->Valid) api->SetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionLights, v);
			}
		}
		property bool RadioLocked
		{
			bool get()
			{
				if (this->Valid) return api->GetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionRadioLocked);
				else return true;
			}
			void set(bool v)
			{
				if (this->Valid) api->SetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionRadioLocked, v);
			}
		}
		property bool Ghost
		{
			bool get()
			{
				if (this->Valid) return api->GetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionGhost);
				else return true;
			}
			void set(bool v)
			{
				if (this->Valid) api->SetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionGhost, v);
			}
		}
		property bool Siren
		{
			bool get()
			{
				if (this->Valid) return api->GetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionSiren);
				else return true;
			}
			void set(bool v)
			{
				if (this->Valid) api->SetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionSiren, v);
			}
		}
		property bool SingleUse
		{
			bool get()
			{
				if (this->Valid) return api->GetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionSingleUse);
				else return true;
			}
			void set(bool v)
			{
				if (this->Valid) api->SetVehicleOption(this->ID, vcmpVehicleOption::vcmpVehicleOptionSingleUse, v);
			}
		}
		property int World
		{
			int get()
			{
				if (this->Valid) return api->GetVehicleWorld(this->ID);
				else return -1;
			}
			void set(int w)
			{
				if(this->Valid) api->SetVehicleWorld(this->ID, w);
			}
		}
		property int Model
		{
			int get()
			{
				if (this->Valid) return api->GetVehicleModel(this->ID);
			}
		}
		CPlayer^ GetOccupant(int slot);
		void Respawn();
		property int ImmunityFlags
		{
			int get()
			{
				if (this->Valid) return api->GetVehicleImmunityFlags(this->ID);
				else return 0;
			}
			void set(int im)
			{
				if (this->Valid) api->SetVehicleImmunityFlags(this->ID, im);
			}
		}
		void Explode();
		property bool Wrecked
		{
			bool get()
			{
				return api->IsVehicleWrecked(this->ID);
			}
		}
		property Vector^ Position
		{
			Vector^ get()
			{
				if (this->Valid)
				{
					float* x=nullptr, * y=nullptr, * z=nullptr;
					api->GetVehiclePosition(this->ID, x, y, z);
					return gcnew Vector(*x, *y, *z);
				}
				else return Vector::Zero;
			}
			void set(Vector^ pos)
			{
				if (this->Valid) api->SetVehiclePosition(this->ID, pos->x, pos->y, pos->z,false);
			}
		}
		property Quaternion^ Rotation
		{
			Quaternion^ get()
			{
				if (this->Valid)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr, * w = nullptr;
					api->GetVehicleRotation(this->ID, x, y, z, w);
					return gcnew Quaternion(*x, *y, *z, *w);
				}
				else return Quaternion::Identity;
			}
			void set(Quaternion^ q)
			{
				if (this->Valid) api->SetVehicleRotation(this->ID, q->x, q->y, q->z, q->w);
			}
		}
		property Vector^ EulerRotation
		{
			Vector^ get()
			{
				if (this->Valid)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetVehicleRotationEuler(this->ID, x, y, z);
					return gcnew Vector(*x, *y, *z);
				}
				else return Vector::Zero;
			}
			void set(Vector^ e) // not the e constant equal to ~2.7
			{
				if (this->Valid) api->SetVehicleRotationEuler(this->ID, e->x, e->y, e->z);
			}
		}
		Vector^ GetVehicleSpeed(bool relative);
		void SetVehicleSpeed(Vector^ speed,bool relative);
		void AddVehicleSpeed(Vector^ speed,bool relative);
		Vector^ GetVehicleTurnSpeed(bool relative);
		void SetVehicleTurnSpeed(Vector^ speed,bool relative);
		void AddVehicleTurnSpeed(Vector^ speed,bool relative);

		property Vector^ SpawnPosition
		{
			Vector^ get()
			{
				if (this->Valid)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetVehicleSpawnPosition(this->ID, x, y, z);
					return gcnew Vector(*x, *y, *z);
				}
				else return Vector::Zero;
			}
			void set(Vector^ pos)
			{
				if (this->Valid) api->SetVehicleSpawnPosition(this->ID, pos->x, pos->y, pos->z);
			}
		}
		property Quaternion^ SpawnRotation
		{
			Quaternion^ get()
			{
				if (this->Valid)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr, * w = nullptr;
					api->GetVehicleSpawnRotation(this->ID, x, y, z, w);
					return gcnew Quaternion(*x, *y, *z, *w);
				}
				else return Quaternion::Identity;
			}
			void set(Quaternion^ q)
			{
				if (this->Valid) api->SetVehicleSpawnRotation(this->ID, q->x, q->y, q->z, q->w);
			}
		}
		property Vector^ SpawnEulerRotation
		{
			Vector^ get()
			{
				if (this->Valid)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetVehicleSpawnRotationEuler(this->ID, x, y, z);
					return gcnew Vector(*x, *y, *z);
				}
				else return Vector::Zero;
			}
			void set(Vector^ e) // not the e constant equal to ~2.7
			{
				if (this->Valid) api->SetVehicleSpawnRotationEuler(this->ID, e->x, e->y, e->z);
			}
		}
		property int IdleRespawnTimer
		{
			int get()
			{
				if (this->Valid) return api->GetVehicleIdleRespawnTimer(this->ID);
				else return INT_MAX;
			}
			void set(int ms)
			{
				if (this->Valid) api->SetVehicleIdleRespawnTimer(this->ID, ms);
			}
		}
		property float Health
		{
			float get()
			{
				if (this->Valid) return api->GetVehicleHealth(this->ID);
				else return 0;
			}
			void set(float h)
			{
				if (this->Valid) api->SetVehicleHealth(this->ID, h);
			}
		}
		property int Color1
		{
			int get()
			{
				if (this->Valid)
				{
					int* c1, * c2;
					api->GetVehicleColour(this->ID, c1, c2);
					return *c1;
				}
				else return 0;
			}
			void set(int c1)
			{
				if (this->Valid) api->SetVehicleColour(this->ID, c1, this->Color2);
			}
		}
		property int Color2
		{
			int get()
			{
				if (this->Valid)
				{
					int* c1, * c2;
					api->GetVehicleColour(this->ID, c1, c2);
					return *c2;
				}
				else return 0;
			}
			void set(int c2)
			{
				if (this->Valid) api->SetVehicleColour(this->ID, this->Color1,c2);
			}
		}
		int GetPartStatus(int part);
		void SetPartStatus(int part, int state);
		int GetTyreStatus(int part);
		void SetTyreStatus(int part, int state);
		property int DamageData
		{
			int get()
			{
				if (this->Valid) return api->GetVehicleDamageData(this->ID);
			}
			void set(int d)
			{
				if (this->Valid) api->GetVehicleDamageData(this->ID);
			}
		}
		property int Radio
		{
			int get()
			{
				if (this->Valid) return api->GetVehicleRadio(this->ID);
			}
			void set(int r)
			{
				if (this->Valid) api->SetVehicleRadio(this->ID,r);
			}
		}
		property Vector^ TurretRotation
		{
			Vector^ get()
			{
				if (this->Valid)
				{
					float* x = nullptr, * y = nullptr;
					api->GetVehicleTurretRotation(this->ID, x, y);
					return gcnew Vector(*x, *y, 0);
				}
			}
		}
		static void ResetAllVehicleHandlings();

		static bool HandlingModelRuleExists(int model, int rule);
		static void SetModelHandlingRule(int model, int rule, double v);
		static double GetModelHandlingRule(int model, int rule);
		static void ResetModelHandlingRule(int model,int rule);
		static void ResetModelHandling(int model);

		bool HandlingRuleExists(int rule);
		void SetHandlingRule(int rule, double v);
		double GetHandlingRule(int rule, double v);
		void ResetHandlingRule(int rule);
		void ResetHandlingRules();

	};
}