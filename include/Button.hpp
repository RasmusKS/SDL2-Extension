#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Vector.hpp>
#include <Color.hpp>
#include <Window.hpp>

class Button{

private:

	Vector pos;
	Vector size;

	std::string text;

	Color borderColor;
	Color pressedColor;
	Color idleColor;
	Color textColor;

	bool state;

	void (*function)(bool state);

public:

	Button(Vector pos, Vector size, std::string text, Color borderColor, Color checkedColor, Color idleColor, Color textColor);
	~Button();

	void addFunctionCall(void (*function)(bool state));

	bool pressed();

	bool update(Vector mouse, bool mouseState);
	void draw(Window &window);

};

#endif
