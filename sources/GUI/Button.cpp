#include <Button.hpp>

Button::Button(Vector _pos, Vector _size, std::string _text, Color _borderColor, Color _pressedColor, Color _idleColor, Color _textColor){
	pos = _pos;
	size = _size;

	text = _text;

	borderColor = _borderColor;
	pressedColor = _pressedColor;
	idleColor = _idleColor;
	textColor = _textColor;

	state = false;

	function = NULL;
}

Button::~Button(){

}

void Button::addFunctionCall(void (*_function)(bool state)){
	function = _function;
}

bool Button::pressed(){
	return state;
}

bool Button::update(Vector mouse, bool mouseState){
	if (!mouseState){
		state = false;
		return true;
	}
	else if (mouse.x > pos.x && mouse.y > pos.y && mouse.x < pos.x + size.x && mouse.y < pos.y + size.y){
		state = mouseState;
		if (function != NULL) function(state);
		return true;
	}
	return false;
}

void Button::draw(Window &window){
	if (state) window.rect(pos, pos + size, pressedColor, borderColor);
	else window.rect(pos, pos + size, idleColor, borderColor);
	window.text(pos + Vector(5, size.y / 2 - 3), text, textColor);
}
