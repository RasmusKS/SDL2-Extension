#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include <Vector.hpp>
#include <Color.hpp>
#include <Window.hpp>

class Checkbox{

private:

	Vector pos;
	Vector size;

	std::string text;

	Color borderColor;
	Color checkedColor;
	Color idleColor;
	Color textColor;

	bool state;

	void (*function)(bool state);

public:

	Checkbox(Vector pos, Vector size, std::string text, Color borderColor, Color checkedColor, Color idleColor, Color textColor);
	~Checkbox();

	void addFunctionCall(void (*function)(bool state));

	bool checked();

	void check();
	void uncheck();

	bool update(Vector mouse);
	void draw(Window &window);

};

#endif
