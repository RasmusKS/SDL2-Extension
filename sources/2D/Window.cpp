#include <Window.hpp>
#include <SDL2/SDL2_gfxPrimitives.h>

Window::Window(Vector *_pos, Vector *_size, const char *title){
	pos = new Vector(_pos->x, _pos->y);
	size = new Vector(_size->x, size->y);

	translation = new Vector(0, 0);

	mouse = new Vector(0, 0);
	pmouse = new Vector(0, 0);
	rmouse = new Vector(0, 0);

	fillColor = Black;
	strokeColor = White;

	window = SDL_CreateWindow(title, pos->x, pos->y, size->x, size->y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	id = SDL_GetWindowID(window);

	mode = WINDOWED;
}
Window::Window(Vector _pos, Vector _size, const char *title){
	pos = new Vector(_pos);
	size = new Vector(_size);

	translation = new Vector(0, 0);

	mouse = new Vector(0, 0);
	pmouse = new Vector(0, 0);
	rmouse = new Vector(0, 0);

	fillColor = Black;
	strokeColor = White;

	window = SDL_CreateWindow(title, pos->x, pos->y, size->x, size->y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	id = SDL_GetWindowID(window);

	mode = WINDOWED;
}
Window::Window(unsigned int _mode, Vector _size, const char *title){
	pos = new Vector(0, 0);
	size = new Vector(_size);

	translation = new Vector(0, 0);

	mouse = new Vector(0, 0);
	pmouse = new Vector(0, 0);
	rmouse = new Vector(0, 0);

	fillColor = Black;
	strokeColor = White;

	window = SDL_CreateWindow(title, pos->x, pos->y, size->x, size->y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	id = SDL_GetWindowID(window);

	mode = _mode;
	SDL_SetWindowFullscreen(window, mode);
}
Window::Window(unsigned int _mode, Vector *_size, const char *title){
	pos = new Vector(0, 0);
	size = new Vector(_size->x, _size->y);

	translation = new Vector(0, 0);

	mouse = new Vector(0, 0);
	pmouse = new Vector(0, 0);
	rmouse = new Vector(0, 0);

	fillColor = Black;
	strokeColor = White;

	window = SDL_CreateWindow(title, pos->x, pos->y, size->x, size->y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	id = SDL_GetWindowID(window);

	mode = _mode;
	SDL_SetWindowFullscreen(window, mode);
}
Window::Window(unsigned int _mode, const char *title){
	pos = new Vector(0, 0);
	if (mode == ULTRA_HD) size = new Vector(3840, 2160);
	else if (mode == FULL_HD) size = new Vector(1920, 1080);
	else size = new Vector(3840, 2160);

	translation = new Vector(0, 0);

	mouse = new Vector(0, 0);
	pmouse = new Vector(0, 0);
	rmouse = new Vector(0, 0);

	fillColor = Black;
	strokeColor = White;

	window = SDL_CreateWindow(title, pos->x, pos->y, size->x, size->y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	id = SDL_GetWindowID(window);

	mode = _mode;
	SDL_SetWindowFullscreen(window, mode);
}

Window::~Window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::updateMouse(SDL_MouseMotionEvent *event){
	*pmouse = *mouse;
	mouse->x = event->x;
	mouse->y = event->y;
	rmouse->x = event->xrel;
	rmouse->y = event->yrel;
}

void Window::move(Vector _offset){
	*pos += _offset;
	SDL_SetWindowPosition(window, pos->x, pos->y);
}

void Window::move(Vector *_offset){
	*pos += *_offset;
	SDL_SetWindowPosition(window, pos->x, pos->y);
}

void Window::setPos(Vector _pos){
	pos = new Vector(pos);
	SDL_SetWindowPosition(window, pos->x, pos->y);
}

void Window::setPos(Vector *_pos){
	*_pos = *_pos;
	SDL_SetWindowPosition(window, pos->x, pos->y);
}

void Window::setSize(Vector _size){
	*size = _size;
	SDL_SetWindowSize(window, size->x, size->y);
}

void Window::setSize(Vector *_size){
	*size = *_size;
	SDL_SetWindowSize(window, size->x, size->y);
}

void Window::setMode(unsigned int _mode){
	mode = _mode;
	SDL_SetWindowFullscreen(window, mode);
}

///////////////
// translate //
///////////////
void Window::translate(Vector trans){
	*translation += trans;
}
void Window::translate(Vector *trans){
	*translation += *trans;
}

///////////
// clear //
///////////
void Window::clear(){
	SDL_RenderClear(renderer);
}

//////////
// draw //
//////////
void Window::draw(){
	SDL_RenderPresent(renderer);
}

//////////
// fill //
//////////
void Window::fill(Color *_color){
	fillColor->r = _color->r;
	fillColor->g = _color->g;
	fillColor->b = _color->b;
	fillColor->a = _color->a;
}
void Window::fill(Color _color){
	delete fillColor;
	fillColor = new Color(_color);
}

////////////
// stroke //
////////////
void Window::stroke(Color _color){
	delete strokeColor;
	strokeColor = new Color(_color);
}
void Window::stroke(Color *_color){
	strokeColor->r = _color->r;
	strokeColor->g = _color->g;
	strokeColor->b = _color->b;
	strokeColor->a = _color->a;
}

////////////////
// background //
////////////////
void Window::background(Color color){
	rect(Vector(0, 0), size, color);
}
void Window::background(Color *color){
	rect(Vector(0, 0), size, color);
}

///////////
// pixel //
///////////
void Window::point(Vector pos){
	pixelColor(renderer, pos.x + translation->x, pos.y + translation->y, strokeColor->getRGBA());
}
void Window::point(Vector *pos){
	pixelColor(renderer, pos->x + translation->x, pos->y + translation->y, strokeColor->getRGBA());
}
void Window::point(Vector pos, Color color){
	pixelColor(renderer, pos.x + translation->x, pos.y + translation->y, color.getRGBA());
}
void Window::point(Vector *pos, Color *color){
	pixelColor(renderer, pos->x + translation->x, pos->y + translation->y, color->getRGBA());
}

//////////
// line //
//////////
void Window::line(Vector pos1, Vector pos2){
	lineColor(renderer, pos1.x + translation->x, pos1.y + translation->y, pos2.x + translation->x, pos2.y + translation->y, strokeColor->getRGBA());
}
void Window::line(Vector *pos1, Vector *pos2){
	lineColor(renderer, pos1->x + translation->x, pos1->y + translation->y, pos2->x + translation->x, pos2->y + translation->y, strokeColor->getRGBA());
}
void Window::line(Vector pos1, Vector pos2, Color color){
	lineColor(renderer, pos1.x + translation->x, pos1.y + translation->y, pos2.x + translation->x, pos2.y + translation->y, color.getRGBA());
}
void Window::line(Vector *pos1, Vector *pos2, Color *color){
	lineColor(renderer, pos1->x + translation->x, pos1->y + translation->y, pos2->x + translation->x, pos2->y + translation->y, color->getRGBA());
}

//////////
// rect //
//////////
void Window::rect(Vector pos, Vector size){
	if (pos.x > this->size->x && pos.x + size.x > this->size->x) return;
	if (pos.x < 0 && pos.x + size.x < 0) return;
	if (pos.y > this->size->y && pos.y + size.y > this->size->y) return;
	if (pos.y < 0 && pos.y + size.y < 0) return;
	boxColor(renderer, pos.x + translation->x, pos.y + translation->y, pos.x + translation->x + size.x, pos.y + translation->y + size.y, fillColor->getRGBA());
	rectangleColor(renderer, pos.x + translation->x, pos.y + translation->y, pos.x + translation->x + size.x, pos.y + translation->y + size.y, strokeColor->getRGBA());
}
void Window::rect(Vector *pos, Vector *size){
	if (pos->x > this->size->x && pos->x + size->x > this->size->x) return;
	if (pos->x < 0 && pos->x + size->x < 0) return;
	if (pos->y > this->size->y && pos->y + size->y > this->size->y) return;
	if (pos->y < 0 && pos->y + size->y < 0) return;
	boxColor(renderer, pos->x + translation->x, pos->y + translation->y, pos->x + translation->x + size->x, pos->y + translation->y + size->y, fillColor->getRGBA());
	rectangleColor(renderer, pos->x + translation->x, pos->y + translation->y, pos->x + translation->x + size->x, pos->y + translation->y + size->y, strokeColor->getRGBA());
}
void Window::rect(Vector pos, Vector size, Color color){
	if (pos.x > this->size->x && pos.x + size.x > this->size->x) return;
	if (pos.x < 0 && pos.x + size.x < 0) return;
	if (pos.y > this->size->y && pos.y + size.y > this->size->y) return;
	if (pos.y < 0 && pos.y + size.y < 0) return;
	boxColor(renderer, pos.x + translation->x, pos.y + translation->y, pos.x + translation->x + size.x, pos.y + translation->y + size.y, color.getRGBA());
}
void Window::rect(Vector *pos, Vector *size, Color *color){
	if (pos->x > this->size->x && pos->x + size->x > this->size->x) return;
	if (pos->x < 0 && pos->x + size->x < 0) return;
	if (pos->y > this->size->y && pos->y + size->y > this->size->y) return;
	if (pos->y < 0 && pos->y + size->y < 0) return;
	boxColor(renderer, pos->x + translation->x, pos->y + translation->y, pos->x + translation->x + size->x, pos->y + translation->y + size->y, color->getRGBA());
}
void Window::rect(Vector pos, Vector size, Color fillColor, Color strokeColor){
	if (pos.x > this->size->x && pos.x + size.x > this->size->x) return;
	if (pos.x < 0 && pos.x + size.x < 0) return;
	if (pos.y > this->size->y && pos.y + size.y > this->size->y) return;
	if (pos.y < 0 && pos.y + size.y < 0) return;
	boxColor(renderer, pos.x + translation->x, pos.y + translation->y, pos.x + size.x + translation->x, pos.y + translation->y + size.y, fillColor.getRGBA());
	rectangleColor(renderer, pos.x + translation->x, pos.y + translation->y, pos.x + translation->x + size.x, pos.y + translation->y + size.y, strokeColor.getRGBA());
}
void Window::rect(Vector *pos, Vector *size, Color *fillColor, Color *strokeColor){
	if (pos->x > this->size->x && pos->x + size->x > this->size->x) return;
	if (pos->x < 0 && pos->x + size->x < 0) return;
	if (pos->y > this->size->y && pos->y + size->y > this->size->y) return;
	if (pos->y < 0 && pos->y + size->y < 0) return;
	boxColor(renderer, pos->x + translation->x, pos->y + translation->y, pos->x + translation->x + size->x, pos->y + translation->y + size->y, fillColor->getRGBA());
	rectangleColor(renderer, pos->x + translation->x, pos->y + translation->y, pos->x + translation->x + size->x, pos->y + translation->y + size->y, strokeColor->getRGBA());
}

////////////
// circle //
////////////
void Window::circle(Vector pos, double radius){
	filledCircleColor(renderer, pos.x + translation->x, pos.y + translation->y, radius, fillColor->getRGBA());
	circleColor(renderer, pos.x + translation->x, pos.y + translation->y, radius, strokeColor->getRGBA());
}
void Window::circle(Vector *pos, double radius){
	filledCircleColor(renderer, pos->x + translation->x, pos->y + translation->y, radius, fillColor->getRGBA());
	circleColor(renderer, pos->x + translation->x, pos->y + translation->y, radius, strokeColor->getRGBA());
}
void Window::circle(Vector pos, double radius, Color color){
	filledCircleColor(renderer, pos.x + translation->x, pos.y + translation->y, radius, color.getRGBA());
}
void Window::circle(Vector *pos, double radius, Color *color){
	filledCircleColor(renderer, pos->x + translation->x, pos->y + translation->y, radius, color->getRGBA());
}
void Window::circle(Vector pos, double radius, Color fillColor, Color strokeColor){
	filledCircleColor(renderer, pos.x + translation->x, pos.y + translation->y, radius, fillColor.getRGBA());
	circleColor(renderer, pos.x + translation->x, pos.y + translation->y, radius, strokeColor.getRGBA());
}
void Window::circle(Vector *pos, double radius, Color *fillColor, Color *strokeColor){
	filledCircleColor(renderer, pos->x + translation->x, pos->y + translation->y, radius, fillColor->getRGBA());
	circleColor(renderer, pos->x + translation->x, pos->y + translation->y, radius, strokeColor->getRGBA());
}

//////////
// text //
//////////
void Window::text(Vector pos, std::string text){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, text.c_str(), strokeColor->getRGBA());
}
void Window::text(Vector *pos, std::string text){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, text.c_str(), strokeColor->getRGBA());
}
void Window::text(Vector pos, std::string text, Color color){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, text.c_str(), color.getRGBA());
}
void Window::text(Vector *pos, std::string text, Color *color){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, text.c_str(), color->getRGBA());
}

void Window::text(Vector pos, int number){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, std::to_string(number).c_str(), strokeColor->getRGBA());
}
void Window::text(Vector *pos, int number){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, std::to_string(number).c_str(), strokeColor->getRGBA());
}
void Window::text(Vector pos, int number, Color color){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, std::to_string(number).c_str(), color.getRGBA());
}
void Window::text(Vector *pos, int number, Color *color){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, std::to_string(number).c_str(), color->getRGBA());
}

void Window::text(Vector pos, double number){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, std::to_string(number).c_str(), strokeColor->getRGBA());
}
void Window::text(Vector *pos, double number){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, std::to_string(number).c_str(), strokeColor->getRGBA());
}
void Window::text(Vector pos, double number, Color color){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, std::to_string(number).c_str(), color.getRGBA());
}
void Window::text(Vector *pos, double number, Color *color){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, std::to_string(number).c_str(), color->getRGBA());
}

void Window::text(Vector pos, Vector vect){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, ("X: " + std::to_string(vect.x) + " Y: " + std::to_string(vect.y) + " Z: " + std::to_string(vect.z)).c_str(), strokeColor->getRGBA());
}
void Window::text(Vector *pos, Vector *vect){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, ("X: " + std::to_string(vect->x) + " Y: " + std::to_string(vect->y).c_str() + " Z: " + std::to_string(vect->z)).c_str(), strokeColor->getRGBA());
}
void Window::text(Vector pos, Vector vect, Color color){
	stringColor(renderer, pos.x + translation->x, pos.y + translation->y, ("X: " + std::to_string(vect.x) + " Y: " + std::to_string(vect.y).c_str() + " Z: " + std::to_string(vect.z)).c_str(), color.getRGBA());
}
void Window::text(Vector *pos, Vector *vect, Color *color){
	stringColor(renderer, pos->x + translation->x, pos->y + translation->y, ("X: " + std::to_string(vect->x) + " Y: " + std::to_string(vect->y).c_str() + " Z: " + std::to_string(vect->z)).c_str(), color->getRGBA());
}

void Window::vector(Vector pos, Vector dir){
	lineColor(renderer, pos.x + translation->x, pos.y + translation->y, pos.x + translation->x + dir.x, pos.y + translation->y + dir.y, strokeColor->getRGBA());
}
void Window::vector(Vector *pos, Vector *dir){
	lineColor(renderer, pos->x + translation->x, pos->y + translation->y, pos->x + translation->x + dir->x, pos->y + translation->y + dir->y, strokeColor->getRGBA());
}
void Window::vector(Vector pos, Vector dir, Color color){
	lineColor(renderer, pos.x + translation->x, pos.y + translation->y, pos.x + translation->x + dir.x, pos.y + translation->y + dir.y, color.getRGBA());
}
void Window::vector(Vector *pos, Vector *dir, Color *color){
	lineColor(renderer, pos->x + translation->x, pos->y + translation->y, pos->x + translation->x + dir->x, pos->y + translation->y + dir->y, color->getRGBA());
}
void Window::vector(Vector dir){
	lineColor(renderer, translation->x, translation->y, translation->x + dir.x, translation->y + dir.y, strokeColor->getRGBA());
}
void Window::vector(Vector *dir){
	lineColor(renderer, translation->x, translation->y, translation->x + dir->x, translation->y + dir->y, strokeColor->getRGBA());
}
void Window::vector(Vector dir, Color color){
	lineColor(renderer, translation->x, translation->y, translation->x + dir.x, translation->y + dir.y, color.getRGBA());
}
void Window::vector(Vector *dir, Color *color){
	lineColor(renderer, translation->x, translation->y, translation->x + dir->x, translation->y + dir->y, color->getRGBA());
}
