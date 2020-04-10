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
		Vector^ operator /= (Vector v);
		Vector^ operator /= (float scalar);
		Vector^ operator *= (Vector v);
		Vector^ operator *= (float scalar);
		property float Length
		{
			float get()
			{
				return sqrt(pow(x, 2) + pow(y, 2) + pow(x, 2));
			}
		}
		float x, y, z;
	};

}