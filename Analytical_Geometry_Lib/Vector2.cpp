#include "stdafx.h"
#include "Vector2.hpp"
#include <cmath>
#include <iostream>


/*----------------------------------------------------------CONSTRUCTOR---------------------------------------------------------------------*/

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(float xy) : x(xy), y(xy) {}

Vector2::Vector2() : x(0), y(0) {}

/*----------------------------------------------------------SETTER--------------------------------------------------------------------------*/

void Vector2::setCoordinates(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::setX(float x)
{
	this->x = x;
}

void Vector2::setY(float y)
{
	this->y = y;
}

/*----------------------------------------------------------GETTER--------------------------------------------------------------------------*/

float Vector2::getLenght() const
{
	return sqrt(x * x + y * y);
}

float Vector2::getXCoordinate() const
{
	return x;
}

float Vector2::getYCoordinate() const
{
	return y;
}

float Vector2::getAngle(Vector2 vector2) const
{
	float numerator = abs(x * vector2.getXCoordinate() + y * vector2.getYCoordinate());
	float denominator = this->getLenght() * vector2.getLenght();

	return (180 * acos(numerator / denominator)) / M_PI;
}

float Vector2::getAngleWithXAxis() const
{
	float numerator = abs(x);
	float denominator = this->getLenght();

	return (180 * acos(numerator / denominator)) / M_PI;
}

float Vector2::getAngleWithYAxis() const
{
	float numerator = abs(y);
	float denominator = this->getLenght();

	return (180 * acos(numerator / denominator)) / M_PI;
}

/*----------------------------------------------------------ARITHMETIC OPERATIONS-----------------------------------------------------------*/

bool Vector2::isNullvector() const
{
	bool isNullvector = false;

	if (this->x == 0 && this->y == 0) isNullvector = true;

	return isNullvector;
}

bool Vector2::isLinearlyDependent(Vector2 vector2) const
{
	bool isLD = false;

	if (x == vector2.getXCoordinate() && y == vector2.getYCoordinate()) isLD = true;
	else
	{
		double k1 = x / vector2.getXCoordinate();
		double k2 = y / vector2.getYCoordinate();

		if (k1 == k2) isLD = true;
	}

	return isLD;
}

Vector2 Vector2::operator+(Vector2& vector2)
{
	return Vector2(x + vector2.getXCoordinate(), y + vector2.getYCoordinate());
}

Vector2 Vector2::operator-(Vector2& vector2)
{
	return Vector2(x - vector2.getXCoordinate(), y - vector2.getYCoordinate());
}

Vector2 Vector2::operator*(Vector2& vector2)
{
	float k = x * vector2.getYCoordinate() - y * vector2.getXCoordinate();

	return Vector2(k, k);
}

Vector2 Vector2::operator*(float scalar)
{
	return Vector2(x * scalar, y * scalar);
}

/*----------------------------------------------------------METHODS-----------------------------------------------------------*/

void Vector2::printOnConsole() const
{
	std::cout << "Coordinates: " << x << y << std::endl;
}