#pragma once

	class Vector3 {

	private:
		//Variables
		float x, y, z;

	public:
		//Constructors of the class
		explicit Vector3(float x, float y, float z);					//3D-Vector
		explicit Vector3(float xyz);									//Vector with three equal coordinates
		explicit Vector3();												//makes a nullvector

		~Vector3();														//Destructor of the class

		//Setter
		void setCoordinates(float x, float y, float z);					//sets new Coordinates for the Vector
		
		//Getter	
		float getLenght() const;										//outputs the lenght of the Vector

		float getXCoordinate() const;									//outputs X-Coordinate
		float getYCoordinate() const;									//outputs Y-Coordinate
		float getZCoordinate() const;									//outputs Z-Coordinate
		
		float getAngle(Vector3 vector3) const;							//outputs the angle in which the two Vectors intersect [Degrees]
		float getAngleWithXAxis() const;								//outputs the angle in which the Vector intersects the X-Axis [Degrees]
		float getAngleWithYAxis() const;								//outputs the angle in which the Vector intersects the Y-Axis [Degrees]
		float getAngleWithZAxis() const;								//outputs the angle in which the Vector intersects the Z-Axis [Degrees]
												 
		bool isNullvector() const;										//return true if this Vecor is equal to the nullvector
		bool isEqual(Vector3 vector3) const;		//returns true if the Vectors are lineary dependent

		//Arithmetic operations
		Vector3 operator+(Vector3& vector3);							//Adding two Vectors

		Vector3 operator-(Vector3& vector3);							//Substracting two Vectors

		Vector3 operator*(Vector3& vector3);							//Multiplication
		Vector3 operator*(float scalar);

		//Methods
		void printOnConsole() const;									//prints the Vector on the console

	};

	