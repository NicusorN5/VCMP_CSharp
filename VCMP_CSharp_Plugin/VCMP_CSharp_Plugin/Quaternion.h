#pragma once
#include "Vector.h"
namespace VCMPCSharpPlugin
{
	ref class Quaternion
	{
	public:
		Quaternion() : x(0), y(0), z(0), w(z) {};
		Quaternion(float X) : x(x), y(x), z(x), w(x) {};
		Quaternion(float X,float Y,float Z,float W) : x(x), y(x), z(Y), w(Z) {};
		float x, y, z, w;
		static property Quaternion^ Identity
		{
			Quaternion^ get()
			{
				return gcnew Quaternion(0, 0, 0, 1);
			}
		}
		static Quaternion^ FromEulerAngles(Vector^ euler_angles)
		{
			float yaw = euler_angles->z, pitch = euler_angles->y, roll = euler_angles->x;
			//thanks wikipedia
			double cy = cos(yaw * 0.5);
			double sy = sin(yaw * 0.5);
			double cp = cos(pitch * 0.5);
			double sp = sin(pitch * 0.5);
			double cr = cos(roll * 0.5);
			double sr = sin(roll * 0.5);

			Quaternion^ q= gcnew Quaternion();
			q->w = cr * cp * cy + sr * sp * sy;
			q->x = sr * cp * cy - cr * sp * sy;
			q->y = cr * sp * cy + sr * cp * sy;
			q->z = cr * cp * sy - sr * sp * cy;
			return q;
		}
	};
}
