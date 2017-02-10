#ifndef COLOR_HPP
#define COLOR_HPP

#define White		new Color(255, 255, 255, 255)
#define Gray		new Color(127, 127, 127, 255)
#define LightGray	new Color( 63,  63,  63, 255)
#define DarkGray	new Color(195, 195, 195, 255)
#define Black		new Color(  0,   0,   0, 255)
#define Red		new Color(255,   0,   0, 255)
#define DarkRed		new Color(127,   0,   0, 255)
#define Magenta		new Color(255,   0, 255, 255)
#define DarkMagenta	new Color(127,   0, 127, 255)
#define Blue		new Color(  0,   0, 255, 255)
#define DarkBlue	new Color(  0,   0, 127, 255)
#define Cyan		new Color(  0, 255, 255, 255)
#define DarkCyan	new Color(  0, 127, 127, 255)
#define Green		new Color(  0, 255,   0, 255)
#define DarkGreen	new Color(  0, 127,   0, 255)
#define Yellow		new Color(255, 255,   0, 255)
#define DarkYellow	new Color(127, 127,   0, 255)

#define Orange		new Color(255, 127,   0, 255)

#define Transparent	new Color(  0,   0,   0,   0)

#include <stdint.h>

class Color{

	public:

		Color();
		Color(uint8_t gray);
		Color(uint8_t gray, uint8_t alpha);
		Color(uint8_t red, uint8_t green, uint8_t blue);
		Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		Color(const Color &color);
		Color(Color *color);

		uint32_t getRGBA();

		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		// Operators
		Color operator+(Color c);
		Color operator+=(Color c);
		Color operator-(Color c);
		Color operator-=(Color c);

		Color operator/(double scale);
		Color operator/=(double scale);
		Color operator*(double scale);
		Color operator*=(double scale);

	private:

		uint8_t constrain(int x);
};

#endif
