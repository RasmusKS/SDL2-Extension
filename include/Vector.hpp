#ifndef Vector_HPP
#define Vector_HPP

#define redToDeg(x) (x * 180 / M_PI)
#define degToRad(x) (x * M_PI / 180)

#include <string>

#define X_AXIS	new Vector(1, 0, 0)
#define Y_AXIS	new Vector(0, 1, 0)
#define Z_AXIS	new Vector(0, 0, 1)

class Vector{

public:

	double x;
	double y;
	double z;

private:



public:

	// Constructor
	Vector();
	Vector(const Vector *vect);
	Vector(const Vector &vect);
	Vector(const double x, const double y, const double z);
	Vector(const double x, const double y);
	Vector(const double x);

	// Destructor
	~Vector();

	// Set values
	void setValues(const Vector *vect);
	void setValues(const Vector &vect);
	void setValues(const Vector vect);
	void setValues(const double x, const double y, const double z);
	void setValues(const double x, const double y);
	void setValues(const double x);

	// Constrain
	void constrain(const Vector *from, const Vector *to);
	void constrain(const Vector &from, const Vector &to);
	void constrain(const Vector from, const Vector to);
	void constrain(const double from, const double to);

	// Scale
	void scaleTo(const double l);
	void scaleToX(const double x);
	void scaleToY(const double y);
	void scaleToZ(const double z);

	// Get length
	double getLength();
	double getLengthXY();
	double getLengthXZ();
	double getLengthYZ();

	// Rotate
	void rotate(double rad);
	void rotateX(double rad);
	void rotateY(double rad);
	void rotateZ(double rad);

	// Rotate around a Vector
	//void rotateAroundVector(double rad, Vector *Vector);
	//void rotateAroundVector(double rad, Vector &Vector);
	//void rotateAroundVector(double rad, Vector Vector);
	//void rotateAroundVector(double rad, double x, doube y, double z);

	// Rotate around point
	//void rotateAroundPoint(double rad, Vector *point);
	//void rotateAroundPoint(double rad, Vector *point);
	//void rotateAroundPoint(double rad, Vector *point);
	//void rotateAroundPoint(double rad, double x, doube y, double z);

	// Get angles between Vectors
	double getAngle(Vector *vect);
	double getAngle(Vector &vect);
	double getAngleX(Vector *vect);
	double getAngleX(Vector &vect);
	double getAngleY(Vector *vect);
	double getAngleY(Vector &vect);
	double getAngleZ(Vector *vect);
	double getAngleZ(Vector &vect);

	// Get angle
	double getAngle();
	double getAngleX();
	double getAngleY();
	double getAngleZ();

	// Get scalar product
	double getScalar(Vector *vect);
	double getScalar(Vector &vect);

	// Get cross product
	Vector getCross(Vector *vect);
	Vector getCross(Vector &vect);

	// Operators
	Vector operator+(Vector vect);
	Vector operator+=(Vector vect);

	Vector operator-(Vector vect);
	Vector operator-=(Vector vect);

	Vector operator*(double scale);
	Vector operator*=(double scale);

	Vector operator/(double scale);
	Vector operator/=(double scale);

	double operator*(Vector &vect);

	bool operator==(Vector vect);
	bool operator==(double length);
	bool operator!=(Vector vect);
	bool operator!=(double length);

	Vector operator=(std::string vect);


private:

};

std::ostream& operator<<(std::ostream& os, const Vector vect);
Vector pow(Vector vect, double power);

#endif
