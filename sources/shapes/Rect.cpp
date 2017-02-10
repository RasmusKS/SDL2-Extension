#include <Rect.hpp>

Rect::Rect(double _x, double _y){
	x = _x;
	y = _y;
}

double Rect::getArea(){
	return x * y;
}
