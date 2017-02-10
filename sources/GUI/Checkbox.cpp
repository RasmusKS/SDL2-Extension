#include <Checkbox.hpp>

Checkbox::Checkbox(Vector _pos, Vector _size, std::string _text, Color _borderColor, Color _checkedColor, Color _idleColor, Color _textColor){
	pos = _pos;
	size = _size;
	text = _text;

	borderColor = _borderColor;
	checkedColor = _checkedColor;
	idleColor = _idleColor;
	textColor = _textColor;

	state = false;

	function = NULL;
}

Checkbox::~Checkbox(){

}

void Checkbox::addFunctionCall(void (*_function)(bool state)){
	function = _function;
}

bool Checkbox::checked(){
	return state;
}

void Checkbox::check(){
	state = true;
	if (function != NULL) function(state);
}

void Checkbox::uncheck(){
	state = false;
	if (function != NULL) function(state);
}

bool Checkbox::update(Vector mouse){
	if (mouse.x > pos.x && mouse.y > pos.y && mouse.x < pos.x + size.x && mouse.y < pos.y + size.y){
		state = !state;
		if (function != NULL) function(state);
		return true;
	}
	return false;
}

void Checkbox::draw(Window &window){
	if (state) window.rect(pos + Vector(size.x - size.y, 0), pos + size, checkedColor, borderColor);
	else window.rect(pos + Vector(size.x - size.y, 0), pos + size, idleColor, borderColor);
	window.text(pos + Vector(5, size.y / 2 - 3), text, textColor);
}
