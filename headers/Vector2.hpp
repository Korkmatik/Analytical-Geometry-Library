 #pragma once
 
    class Vector2 {

        private:
            //Variables
            float x, y;

        public:
            //Constructors of the class
            explicit Vector2(float x, float y);     //2D-Vector
            explicit Vector2(float xy);             //2D-Vector with two equal Coordiantes
            explicit Vector2();                     //Creates the nullvector

            //Setter
            void setCoordinates(float x, float y);  //sets new Coordiantes
            void setX(float x);
            void setY(float y);

            //Getter
            float getLenght() const;                //outputs the length of the Vector

            float getXCoordinate() const;           //outputs X-Coordinate
            float getYCoordinate() const;           //outputs the Y-Coordinate

            float getAngle(Vector2 vector2) const;  //returns the angle in which the Vectors intersect [degree]
            float getAngleWithXAxis() const;        //returns the angle in which the Vector intersects the X-Axis [degree]
            float getAngleWithYAxis() const;        //returns the angle in which the Vector intersects the Y-Axis [degree]

            bool isNullvector() const;              //returns True if this Vector is equal to the nullvector
            bool isLinearlyDependent(Vector2 vector2) const;    //return True if the two Vectors are linearly dependent

            //Arithmetic operations
            Vector2 operator+(Vector2& vector2);    //Returns a new Vector which is created by adding two Vectors
            Vector2 operator-(Vector2& vector2);    //Returns a new Vector which is created by substracting two Vectors
            Vector2 operator*(Vector2& vector2);    //Returns a scalar which is created by multipliing two vectors
            Vector2 operator*(float scalar);        //Returns a new vector which is created by multipliing the current vector with the scalar

            //Methods
            void printOnConsole() const;            //prints the Coordinates of the current vector on the console
    };