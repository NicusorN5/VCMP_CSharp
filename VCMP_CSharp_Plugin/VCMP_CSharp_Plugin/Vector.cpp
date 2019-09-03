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

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator/=(Vector v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return this;
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator/=(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return this;
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator*=(Vector v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return this;
}

VCMPCSharpPlugin::Vector^ VCMPCSharpPlugin::Vector::operator*=(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return this;
}
