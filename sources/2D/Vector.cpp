#include <Vector.hpp>
#include <cmath>
#include <string>
#include <ostream>
#include <algorithm>
#include <iostream>

/////////////////
// Constructor //
/////////////////
Vector::Vector(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
Vector::Vector(const Vector *vect){
	this->x = vect->x;
	this->y = vect->y;
	this->z = vect->z;
}
Vector::Vector(const Vector &vect){
	this->x = vect.x;
	this->y = vect.y;
	this->z = vect.z;
}
Vector::Vector(const double x, const double y, const double z){
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector::Vector(const double x, const double y){
	this->x = x;
	this->y = y;
	this->z = 0;
}
Vector::Vector(const double x){
	this->x = x;
	this->y = 0;
	this->z = 0;
}

////////////////
// Destructor //
////////////////
Vector::~Vector(){

}

////////////////
// Set values //
////////////////
void Vector::setValues(const Vector *vect){
	this->x = vect->x;
	this->y = vect->y;
	this->z = vect->z;
}
void Vector::setValues(const Vector &vect){
	this->x = vect.x;
	this->y = vect.y;
	this->z = vect.z;
}
void Vector::setValues(const Vector vect){
	this->x = vect.x;
	this->y = vect.y;
	this->z = vect.z;
}
void Vector::setValues(const double x, const double y, const double z){
	this->x = x;
	this->y = y;
	this->z = z;
}
void Vector::setValues(const double x, const double y){
	this->x = x;
	this->y = y;
	this->z = 0;
}
void Vector::setValues(const double x){
	this->x = x;
	this->y = 0;
	this->z = 0;
}

///////////////
// Constrain //
///////////////
void Vector::constrain(const Vector *from, const Vector *to){
	if (this->x < from->x) this->x = from->x;
	else if (this->x > to->x) this->x = to->x;
	if (this->y < from->y) this->y = from->y;
	else if (this->y > to->y) this->y = to->y;
}
void Vector::constrain(const Vector &from, const Vector &to){
	if (this->x < from.x) this->x = from.x;
	else if (this->x > to.x) this->x = to.x;
	if (this->y < from.y) this->y = from.y;
	else if (this->y > to.y) this->y = to.y;
}
void Vector::constrain(const Vector from, const Vector to){
	if (this->x < from.x) this->x = from.x;
	else if (this->x > to.x) this->x = to.x;
	if (this->y < from.y) this->y = from.y;
	else if (this->y > to.y) this->y = to.y;
}
void Vector::constrain(const double from, const double to){
	if (getLength() < from) scaleTo(from);
	else if (getLength() > to) scaleTo(to);
}

///////////
// Scale //
///////////
void Vector::scaleTo(const double l){
	if (this->getLength() == 0) return;
	*this *= l / this->getLength();
}
void Vector::scaleToX(const double x){
	if (this->x == 0) return;
	*this *= x / this->x;
}
void Vector::scaleToY(const double y){
	if (this->y == 0) return;
	*this *= y / this->y;
}
void Vector::scaleToZ(const double z){
	if (this->z == 0) return;
	*this *= z / this->z;
}

////////////////
// Get length //
////////////////
double Vector::getLength(){
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}
double Vector::getLengthXY(){
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}
double Vector::getLengthXZ(){
	return sqrt(pow(this->x, 2) + pow(this->z, 2));
}
double Vector::getLengthYZ(){
	return sqrt(pow(this->y, 2) + pow(this->z, 2));
}

////////////
// Rotate //
////////////
void Vector::rotate(double rad){
	*this = Vector(
		sin(-rad) * this->y + cos(-rad) * this->x,
		cos(-rad) * this->y - sin(-rad) * this->x,
		this->z
	);
}

void Vector::rotateX(double rad){
	*this = Vector(
		this->x,
		sin(-rad) * this->z + cos(-rad) * this->y,
		cos(-rad) * this->z - sin(-rad) * this->y
	);
}

void Vector::rotateY(double rad){
	*this = Vector(
		cos(-rad) * this->x - sin(-rad) * this->z,
		this->y,
		sin(-rad) * this->x + cos(-rad) * this->z
	);
}

void Vector::rotateZ(double rad){
	*this = Vector(
		sin(-rad) * this->y + cos(-rad) * this->x,
		cos(-rad) * this->y - sin(-rad) * this->x,
		this->z
	);
}

////////////////////////////
// Rotate around a Vector //
////////////////////////////



///////////////////////////
// Rotate around a point //
///////////////////////////



///////////////////////////////
// Get angle between Vectors //
///////////////////////////////
double Vector::getAngle(Vector *vect){
	return acos(
		this->getScalar(vect) / (this->getLength() * vect->getLength())
	);
}
double Vector::getAngle(Vector &vect){
	return acos(
		this->getScalar(vect) / (this->getLength() * vect.getLength())
	);
}
double Vector::getAngleX(Vector *vect){
	Vector tempThis(0, this->y, this->z);
	Vector tempVect(0, vect->y, vect->z);
	return acos(
		tempThis.getScalar(tempVect) / (tempThis.getLength() * tempVect.getLength())
	);
}
double Vector::getAngleX(Vector &vect){
	Vector tempThis(0, this->y, this->z);
	Vector tempVect(0, vect.y, vect.z);
	return acos(
		tempThis.getScalar(tempVect) / (tempThis.getLength() * tempVect.getLength())
	);
}
double Vector::getAngleY(Vector *vect){
	Vector tempThis(this->x, 0, this->z);
	Vector tempVect(vect->x, 0, vect->z);
	return acos(
		tempThis.getScalar(tempVect) / (tempThis.getLength() * tempVect.getLength())
	);
}
double Vector::getAngleY(Vector &vect){
	Vector tempThis(this->x, 0, this->z);
	Vector tempVect(vect.x, 0, vect.z);
	return acos(
		tempThis.getScalar(tempVect) / (tempThis.getLength() * tempVect.getLength())
	);
}
double Vector::getAngleZ(Vector *vect){
	Vector tempThis(this->x, this->y, 0);
	Vector tempVect(vect->x, vect->y, 0);
	return acos(
		tempThis.getScalar(tempVect) / (tempThis.getLength() * tempVect.getLength())
	);
}
double Vector::getAngleZ(Vector &vect){
	Vector tempThis(this->x, this->y, 0);
	Vector tempVect(vect.x, vect.y, 0);
	return acos(
		tempThis.getScalar(tempVect) / (tempThis.getLength() * tempVect.getLength())
	);
}

///////////////
// Get angle //
///////////////
double Vector::getAngle(){
	if (this->y > 0){
		if (this->x > 0) return atan(this->y / this->x);
		else if (this->x < 0) return M_PI / 2 - atan(this->x / this->y);
		else return M_PI / 2;
	}
	else if (this->y < 0){
		if (this->x > 0) return M_PI / 2 * 3 - atan(this->x / this->y);
		else if (this->x < 0) return M_PI + atan(this->y / this->x);
		else return M_PI / 2 * 3;
	}
	else{
		if (this->x > 0) return 0;
		else if (this->x < 0) return M_PI;
		else return 0;
	}
}
double Vector::getAngleX(){
	if (this->z > 0){
		if (this->y > 0) return atan(this->z / this->y);
		else if (this->y < 0) return M_PI / 2 - atan(this->y / this->z);
		else return M_PI / 2;
	}
	else if (this->z < 0){
		if (this->y > 0) return M_PI / 2 * 3 - atan(this->y / this->z);
		else if (this->y < 0) return M_PI + atan(this->z / this->y);
		else return M_PI / 2 * 3;
	}
	else{
		if (this->y > 0) return 0;
		else if (this->y < 0) return M_PI;
		else return 0;
	}
}
double Vector::getAngleY(){
	if (this->x > 0){
		if (this->z > 0) return atan(this->x / this->z);
		else if (this->z < 0) return M_PI / 2 - atan(this->z / this->x);
		else return M_PI / 2;
	}
	else if (this->x < 0){
		if (this->z > 0) return M_PI / 2 * 3 - atan(this->z / this->x);
		else if (this->z < 0) return M_PI + atan(this->x / this->z);
		else return M_PI / 2 * 3;
	}
	else{
		if (this->z > 0) return 0;
		else if (this->z < 0) return M_PI;
		else return 0;
	}
}
double Vector::getAngleZ(){
	if (this->y > 0){
		if (this->x > 0) return atan(this->y / this->x);
		else if (this->x < 0) return M_PI / 2 - atan(this->x / this->y);
		else return M_PI / 2;
	}
	else if (this->y < 0){
		if (this->x > 0) return M_PI / 2 * 3 - atan(this->x / this->y);
		else if (this->x < 0) return M_PI + atan(this->y / this->x);
		else return M_PI / 2;
	}
	else{
		if (this->x > 0) return 0;
		else if (this->x < 0) return M_PI;
		else return 0;
	}
}

////////////////////////
// Get scalar product //
////////////////////////
double Vector::getScalar(Vector *vect){
	return this->x * vect->x + this->y * vect->y + this->z * vect->z;
}
double Vector::getScalar(Vector &vect){
	return this->x * vect.x + this->y * vect.y + this->z * vect.z;
}

///////////////////////
// Get cross product //
///////////////////////
Vector Vector::getCross(Vector *vect){
	return Vector(
		this->y * vect->z - this->z * vect->y,
		this->z * vect->x - this->x * vect->z,
		this->x * vect->y - this->y * vect->x
	);
}
Vector Vector::getCross(Vector &vect){
	return Vector(
		this->y * vect.z - this->z * vect.y,
		this->z * vect.x - this->x * vect.z,
		this->x * vect.y - this->y * vect.x
	);
}

//////////////
// Operator //
//////////////
Vector Vector::operator+(Vector vect){
	return Vector(this->x + vect.x, this->y + vect.y, this->z + vect.z);
}
Vector Vector::operator+=(Vector vect){
	this->x += vect.x;
	this->y += vect.y;
	this->z += vect.z;
	return *this;
}
Vector Vector::operator-(Vector vect){
	return Vector(this->x - vect.x, this->y - vect.y, this->z - vect.z);
}
Vector Vector::operator-=(Vector vect){
	this->x -= vect.x;
	this->y -= vect.y;
	this->z -= vect.z;
	return *this;
}
Vector Vector::operator*(double scale){
	return Vector(this->x * scale, this->y * scale, this->z * scale);
}
Vector Vector::operator*=(double scale){
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
	return *this;
}
Vector Vector::operator/(double scale){
	return Vector(this->x / scale, this->y / scale, this->z / scale);
}
Vector Vector::operator/=(double scale){
	this->x /= scale;
	this->y /= scale;
	this->z /= scale;
	return *this;
}
double Vector::operator*(Vector &vect){
	return this->x * vect.x + this->y * vect.y + this->z * vect.z;
}
bool Vector::operator==(Vector vect){
	return (this->x == vect.x && this->y == vect.y && this->z == vect.z);
}
bool Vector::operator==(double length){
	return getLength() == length;
}
bool Vector::operator!=(Vector vect){
	return !(this->x == vect.x && this->y == vect.y && this->z == vect.z);
}
bool Vector::operator!=(double length){
	return getLength() != length;
}
Vector Vector::operator=(std::string vect){
	vect.erase (std::remove(vect.begin(), vect.end(), '('), vect.end());
	vect.erase (std::remove(vect.begin(), vect.end(), ')'), vect.end());
	int index = vect.find(' ');
	if (index == -1) return Vector(0, 0);
	*this = Vector(std::stod(vect.substr(0, index), NULL), std::stod(vect.substr(index + 1), NULL));
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector vect){
	os << vect.x << ", " << vect.y << ", " << vect.z;
	return os;
}

Vector pow(Vector vect, double power){
	vect.scaleTo(pow(vect.getLength(), power));
	return vect;
}
