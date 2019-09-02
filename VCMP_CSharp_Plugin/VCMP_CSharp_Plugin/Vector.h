#pragma once
ref class Vector
{
public:
	Vector();
	Vector(float X,float Y,float Z) : x(X), y(Y), z(Z) {};
	Vector(float X) : x(X), y(X), z(X) {};
	Vector^ operator += (Vector v);
	Vector^ operator -= (Vector v);
	Vector^ operator /= (Vector v);
	Vector^ operator /= (float scalar);
	Vector^ operator *= (Vector v);
	Vector^ operator *= (float scalar);
	float x, y, z;
};

