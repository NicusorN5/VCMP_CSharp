#include "stdafx.h"
#include "Vector.h"


Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector^ Vector::operator+=(Vector v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return this;
}

Vector^ Vector::operator-=(Vector v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return this;
}

Vector^ Vector::operator/=(Vector v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return this;
}

Vector^ Vector::operator/=(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return this;
}

Vector^ Vector::operator*=(Vector v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return this;
}

Vector^ Vector::operator*=(float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return this;
}
