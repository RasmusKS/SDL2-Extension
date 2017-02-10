#include <Color.hpp>

Color::Color(){
	r = 0;
	g = 0;
	b = 0;
	a = 0;
}

Color::Color(uint8_t gray){
	r = gray;
	g = gray;
	b = gray;
	a = 255;
}

Color::Color(uint8_t gray, uint8_t alpha){
	r = gray;
	g = gray;
	b = gray;
	a = alpha;
}

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b){
	r = _r;
	g = _g;
	b = _b;
	a = 255;
}

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a){
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

Color::Color(const Color &c){
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
}

Color::Color(Color *c){
	r = c->r;
	g = c->g;
	b = c->b;
	a = c->a;
}

uint32_t Color::getRGBA(){
	return r << 0 | g << 8 | b << 16 | a << 24;
}

Color Color::operator+(Color c){
	return Color(
		constrain(this->r + c.r),
		constrain(this->g + c.g),
		constrain(this->b + c.b)
	);
}
Color Color::operator+=(Color c){
	this->r = constrain(this->r + c.r);
	this->g = constrain(this->g + c.g);
	this->b = constrain(this->b + c.b);
	return *this;
}
Color Color::operator-(Color c){
	return Color(
		constrain(this->r - c.r),
		constrain(this->g - c.g),
		constrain(this->b - c.b)
	);
}
Color Color::operator-=(Color c){
	this->r = constrain(this->r - c.r);
	this->g = constrain(this->g - c.g);
	this->b = constrain(this->b - c.b);
	return *this;
}

Color Color::operator*(double scale){
	return Color(
		constrain(this->r * scale),
		constrain(this->g * scale),
		constrain(this->b * scale)
	);
}
Color Color::operator*=(double scale){
	this->r = constrain(this->r * scale);
	this->g = constrain(this->g * scale);
	this->b = constrain(this->b * scale);
}
Color Color::operator/(double scale){
	return Color(
		constrain(this->r / scale),
		constrain(this->g / scale),
		constrain(this->b / scale)
	);
}
Color Color::operator/=(double scale){
	this->r = constrain(this->r / scale);
	this->g = constrain(this->g / scale);
	this->b = constrain(this->b / scale);
}

uint8_t Color::constrain(int x){
	if (x < 0) return 0;
	if (x > 255) return 255;
	return x;
}
