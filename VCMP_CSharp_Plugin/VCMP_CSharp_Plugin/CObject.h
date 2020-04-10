#pragma once
#include "Vector.h"
#include "Common.h"
#include "VCMP.h"
namespace VCMPCSharpPlugin
{
	public ref class CObject
	{
		int _id;
	public:
		CObject(int id);
		CObject(int model, int world, Vector^ pos, int alpha);
		property int ID
		{
			int get()
			{
				return _id;
			}
			void set(int v)
			{
				_id = v;
			}
		}
		property bool Valid
		{
			bool get()
			{
				return api->CheckEntityExists(vcmpEntityPool::vcmpEntityPoolObject, this->ID);
			}
		}
	};
}

