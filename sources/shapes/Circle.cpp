#include <Circle.hpp>

#include <math.h>

Circle::Circle(double _r){
	r = _r;
}

double Circle::getArea(){
	return M_PI * pow(r, 2);
}
