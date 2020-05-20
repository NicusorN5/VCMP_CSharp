#include "stdafx.h"
#include "Vector.h"


VCMPCSharpPlugin::Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator+=(Vector v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return this;
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator-=(Vector v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return this;
}


VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator/=(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return this;
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator*=(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return this;
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::Normalize()
{
	this->x /= this->Length;
	this->y /= this->Length;
	this->z /= this->Length;
}

float VCMPCSharpPlugin::Vector::Distance(Vector^ a, Vector^ b)
{
	return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}

float VCMPCSharpPlugin::Vector::Distance(Vector^ d)
{
	return sqrt(pow(this->x - d->x, 2) + pow(this->y - d->y, 2) + pow(this->z - d->z, 2));
}
