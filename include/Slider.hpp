#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <Vector.hpp>
#include <Color.hpp>
#include <Window.hpp>

class Slider{

private:

	Vector pos;
	Vector size;

	double min;
	double max;

	double value;

	Color color;

public:

	Slider(Vector pos, Vector size, double min, double max, double value, Color color);

	double getValue();

	bool update(Vector mouse);
	void draw(Window &window);
};

#endif
