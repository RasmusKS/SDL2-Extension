#include <Slider.hpp>

Slider::Slider(Vector _pos, Vector _size, double _min, double _max, double _value, Color _color){
	pos = _pos;
	size = _size;
	min = _min;
	max = _max;
	value = _value;
	color = _color;
}

double Slider::getValue(){
	return value;
}

bool Slider::update(Vector mouse){
	if (mouse.x >= pos.x && mouse.y >= pos.y && mouse.x <= pos.x + size.x && mouse.y <= pos.y + size.y){
		value = min + (mouse.x - pos.x) / size.x * (max - min);
		return true;
	}
	return false;
}

void Slider::draw(Window &window){
	window.line(Vector(pos.x, pos.y + size.y / 2), Vector(pos.x + size.x, pos.y + size.y / 2), color);
	window.line(Vector(pos.x + size.x * value / (max - min), pos.y), Vector(pos.x + size.x * value / (max - min), pos.y + size.y), color);
}
