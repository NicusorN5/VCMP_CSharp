#pragma once
#include "Common.h"
#include "Vector.h"

namespace VCMPCSharpPlugin
{
	public ref class CPickup
	{
		int _id;
	public:
		CPickup(int id);
		CPickup(int model, int world, int quantity, Vector^ pos, uint8_t alpha, bool autom);
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
				return api->CheckEntityExists(vcmpEntityPool::vcmpEntityPoolPickup, this->_id);
			}
		}
		void Delete();
		property int World
		{
			int get()
			{
				if (this->Valid) return api->GetPickupWorld(this->_id);
				else return -1;
			}
			void set(int w)
			{
				if (this->Valid) api->SetPickupWorld(this->_id,w);
			}
		}
		property uint8_t Alpha
		{
			uint8_t get()
			{
				if (this->Valid) return api->GetPickupAlpha(this->_id);
				else return 0;
			}
			void set(uint8_t a)
			{
				if (this->Valid) api->SetPickupAlpha(this->_id, a);
			}
		}
		property bool Automatic
		{
			bool get()
			{
				if (this->Valid) return api->IsPickupAutomatic(this->_id);
				else return false;
			}
			void set(bool a)
			{
				if (this->Valid) api->SetPickupIsAutomatic(this->_id, a);
			}
		}
		property int AutoTimer
		{
			int get()
			{
				if (this->Valid) return api->GetPickupAutoTimer(this->_id);
				else return 0;
			}
			void set(int t)
			{
				if (this->Valid) api->SetPickupAutoTimer(this->_id, t);
			}
		}
		void Refresh();
		property Vector^ Position
		{
			Vector^ get()
			{
				if (this->Valid)
				{
					float* x = nullptr, * y = nullptr, * z = nullptr;
					api->GetPickupPosition(this->_id, x, y, z);
					return gcnew Vector(*x, *y, *z);
				}
				else return Vector::Zero;
			}
			void set(Vector^ p)
			{
				if (this->Valid) api->SetPickupPosition(this->_id, p->x, p->y, p->z);
			}
		}
		property int Model
		{
			int get()
			{
				if (this->Valid) return api->GetPickupModel(this->_id);
				else return 0;
			}
		}
		property int Quantity
		{
			int get()
			{
				if (this->Valid) return api->GetPickupQuantity(this->_id);
				else return 0;
			}
		}
	};
}

