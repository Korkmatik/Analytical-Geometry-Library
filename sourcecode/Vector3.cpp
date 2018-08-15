#include "stdafx.h"
#include "Vector3.hpp"
#include <cmath>
#include <iostream>

#define M_PI 3.14159265358979323846 /*PI*/

//----------------------------------------------------------CONSTRUCTOR---------------------------------------------------------------------

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(float xyz) : x(xyz), y(xyz), z(xyz) {}

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

//----------------------------------------------------------SETTER--------------------------------------------------------------------------

void Vector3::setCoordinates(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::setX(float x)
{
	this->x = x;
}

void Vector3::setY(float y)
{
	this->y = y;
}

void Vector3::setZ(float z)
{
	this->z = z;
}

//----------------------------------------------------------GETTER--------------------------------------------------------------------------

float Vector3::getLenght() const
{
	return sqrt(x * x + y * y + z * z);
}

float Vector3::getXCoordinate() const
{
	return x;
}

float Vector3::getYCoordinate() const
{
	return y;
}

float Vector3::getZCoordinate() const
{
	return z;
}

float Vector3::getAngle(Vector3 vector3) const
{
	float numerator = abs(x * vector3.getXCoordinate() + y * vector3.getYCoordinate() + z * vector3.getZCoordinate());
	float denominator = this->getLenght() * vector3.getLenght();

	return (180 * cos(numerator / denominator)) / M_PI;
}

float Vector3::getAngleWithXAxis() const
{
	float numerator = abs(x * 1);
	float denominator = this->getLenght();

	return (180 * cos(numerator / denominator)) / M_PI;
}

float Vector3::getAngleWithYAxis() const
{
	float numerator = abs(y * 1);
	float denominator = this->getLenght();

	return (180 * cos(numerator / denominator)) / M_PI;
}

float Vector3::getAngleWithZAxis() const
{
	float numerator = abs(z * 1);
	float denominator = this->getLenght();

	return (180 * cos(numerator / denominator)) / M_PI;
}

//----------------------------------------------------------ARITHMETIC OPERATIONS-----------------------------------------------------------

bool Vector3::isNullvector() const
{
	bool isNullvector = false;

	if (x == 0 && y == 0 && z == 0)
	{
		isNullvector = true;
	}

	return isNullvector;
}

bool Vector3::isLinearlyDependent(Vector3 vector3) const
{
	bool isEqual = false;

	if (x == vector3.getXCoordinate() && y == vector3.getYCoordinate() && z == vector3.getZCoordinate()) {
		isEqual = true;
	}
	else {
		float k1 = x / vector3.getXCoordinate();
		float k2 = y / vector3.getYCoordinate();
		float k3 = z / vector3.getZCoordinate();

		if (k1 == k2 && k2 == k3 && k1 == k3) {
			isEqual = true;
		}

	}

	return isEqual;
}

Vector3 Vector3::operator+(Vector3& vector3)
{
	float x1, x2, x3;
	x1 = x + vector3.getXCoordinate();
	x2 = y + vector3.getYCoordinate();
	x3 = z + vector3.getZCoordinate();

	return Vector3( x1, x2, x3);
}

Vector3 Vector3::operator-(Vector3 & vector3)
{
	float x1, x2, x3;
	x1 = x - vector3.getXCoordinate();
	x2 = y - vector3.getYCoordinate();
	x3 = z - vector3.getZCoordinate();

	return Vector3(x1, x2, x3);
}

Vector3 Vector3::operator*(Vector3 & vector3)
{
	float x1 = y * vector3.getZCoordinate() - z * vector3.getYCoordinate();
	float x2 = z * vector3.getXCoordinate() - x * vector3.getZCoordinate();
	float x3 = x * vector3.getYCoordinate() - y * vector3.getXCoordinate();

	float result[3] = { x1, x2, x3 };
	 
	return Vector3(result[0], result[1], result[2]);
}

Vector3 Vector3::operator*(float scalar)
{
	float result[3] = { x *scalar, y * scalar, z * scalar };

	return Vector3(result[0], result[1], result[2]);
}

//----------------------------------------------------------METHODS-----------------------------------------------------------

void Vector3::printOnConsole() const
{
	std::cout << "Coordinates: " << x << y << z << std::endl;
}
