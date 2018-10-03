#pragma once
#define _USE_MATH_DEFINES

class Vector3 {

private:
	//Variables
	float x, y, z;

public:
	//Constructors of the class
	explicit Vector3(float x, float y, float z);  //3D-Vector
	explicit Vector3(float xyz);				  //Vector with three equal coordinates
	explicit Vector3();							  //makes a nullvector

												  //Setter										 
	void setCoordinates(float x, float y, float z);	 //sets new Coordinates for the Vector
	void setX(float x);
	void setY(float y);
	void setZ(float z);

	//Getter										 
	float getLenght() const;      //outputs the length of the Vector

	float getXCoordinate() const; //outputs X-Coordinate
	float getYCoordinate() const; //outputs Y-Coordinate
	float getZCoordinate() const; //outputs Z-Coordinate

	float getAngle(Vector3 vector3) const;	//outputs the angle in which the two Vectors intersect [Degrees]
	float getAngleWithXAxis() const;		//outputs the angle in which the Vector intersects the X-Axis [Degrees]
	float getAngleWithYAxis() const;		//outputs the angle in which the Vector intersects the Y-Axis [Degrees]
	float getAngleWithZAxis() const;		//outputs the angle in which the Vector intersects the Z-Axis [Degrees]

	bool isNullvector() const;			 //return true if this Vecor is equal to the nullvector
	bool isLinearlyDependent(Vector3 vector3) const; //returns true if the Vectors are lineary dependent

													 //Arithmetic operations
	Vector3 operator+(Vector3& vector3);  //returns a new vector which is created by adding two vectors											  
	Vector3 operator-(Vector3& vector3);  //returns a new vector which is created by substracting two vectors											  
	Vector3 operator*(Vector3& vector3);  //returns a scalar which is created by multipliing the two vectors
	Vector3 operator*(float scalar);	  //returns a new vector which is created by multipliing the current vector with a scalar

										  //Methods
	void printOnConsole() const;   //prints the Vector on the console

};


