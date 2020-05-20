#pragma once
#include <cmath>

namespace VCMPCSharpPlugin {
	public ref class Vector
	{
	public:
		Vector();
		Vector(float X, float Y, float Z) : x(X), y(Y), z(Z) {};
		Vector(float X) : x(X), y(X), z(X) {};
		Vector^ operator += (Vector v);
		Vector^ operator -= (Vector v);
		Vector^ operator /= (float scalar);
		Vector^ operator *= (float scalar);
		property float Length
		{
			float get()
			{
				return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
			}
		}
		float x, y, z;
		static property Vector^ Zero
		{
			Vector^ get()
			{
				return gcnew Vector(0);
			}
		}
		static property Vector^ One
		{
			Vector^ get()
			{
				return gcnew Vector(1);
			}
		}
		static property Vector^ UnitX
		{
			Vector^ get()
			{
				return gcnew Vector(1,0,0);
			}
		}
		static property Vector^ UnitY
		{
			Vector^ get()
			{
				return gcnew Vector(0, 1, 0);
			}
		}
		static property Vector^ UnitZ
		{
			Vector^ get()
			{
				return gcnew Vector(0, 0, 1 );
			}
		}
		Vector^ Normalize();
		static float Distance(Vector^ a, Vector^ b);
		float Distance(Vector^ d);
		property float Angle
		{
			float get()
			{
				return atan2f(this->x, this->y);
			}
		}
	};

}