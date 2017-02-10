#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <SDL2/SDL.h>

#include "Vector.hpp"
#include "Color.hpp"

#define FULLSCREEN SDL_WINDOW_FULLSCREEN
#define WINDOWED_FULLSCREEN SDL_WINDOW_FULLSCREEN_DESKTOP
#define WINDOWED 0
#define ULTRA_HD 1
#define FULL_HD  2

class Window{

public:

	Vector *pos;
	Vector *size;

	Vector *translation;

	Color *fillColor;
	Color *strokeColor;

	Vector *mouse;
	Vector *pmouse;
	Vector *rmouse;

	unsigned int mode;

	int id;

private:

	SDL_Window *window;
	SDL_Renderer *renderer;

public:

	// Constructor
	Window(Vector pos, Vector size, const char *title);
	Window(Vector *pos, Vector *size, const char *title);
	Window(unsigned int mode, Vector size, const char *title);
	Window(unsigned int mode, Vector *size, const char *title);
	Window(unsigned int mode, const char *title);

	// Destructor
	~Window();

	void updateMouse(SDL_MouseMotionEvent *event);

	// Move window
	void move(Vector offset);
	void move(Vector *offset);

	// Set position of window
	void setPos(Vector pos);
	void setPos(Vector *pos);

	// Set size of window
	void setSize(Vector size);
	void setSize(Vector *size);

	// Set window mode
	void setMode(unsigned int mode);

	// Translate
	void translate(Vector trans);
	void translate(Vector *trans);

	// Clear window
	void clear();

	// Draw window
	void draw();

	// Set fill color
	void fill(Color color);
	void fill(Color *color);

	// Set stroke color
	void stroke(Color color);
	void stroke(Color *color);

	// Draw background
	void background(Color color);
	void background(Color *color);

	// Draw point
	void point(Vector pos);
	void point(Vector *pos);
	void point(Vector pos, Color color);
	void point(Vector *pos, Color *color);

	// Draw line
	void line(Vector pos1, Vector pos2);
	void line(Vector *pos1, Vector *pos2);
	void line(Vector pos1, Vector pos2, Color color);
	void line(Vector *pos1, Vector *pos2, Color *color);

	// Draw rect
	void rect(Vector pos, Vector size);
	void rect(Vector *pos, Vector *size);
	void rect(Vector pos, Vector size, Color color);
	void rect(Vector *pos, Vector *size, Color *color);
	void rect(Vector pos, Vector size, Color fillColor, Color strokeColor);
	void rect(Vector *pos, Vector *size, Color *fillColor, Color *strokeColor);

	// Draw circle
	void circle(Vector pos, double radius);
	void circle(Vector *pos, double radius);
	void circle(Vector pos, double radius, Color color);
	void circle(Vector *pos, double radius, Color *color);
	void circle(Vector pos, double radius, Color fillColor, Color strokeColor);
	void circle(Vector *pos, double radius, Color *fillColor, Color *strokeColor);

	// Draw text
	void text(Vector pos, std::string text);
	void text(Vector *pos, std::string text);
	void text(Vector pos, std::string text, Color color);
	void text(Vector *pos, std::string text, Color *color);
	void text(Vector pos, int number);
	void text(Vector *pos, int number);
	void text(Vector pos, int number, Color color);
	void text(Vector *pos, int number, Color *color);
	void text(Vector pos, double number);
	void text(Vector *pos, double number);
	void text(Vector pos, double number, Color color);
	void text(Vector *pos, double number, Color *color);
	void text(Vector pos, Vector vect);
	void text(Vector *pos, Vector *vect);
	void text(Vector pos, Vector vect, Color color);
	void text(Vector *pos, Vector *vect, Color *color);

	void vector(Vector pos, Vector dir);
	void vector(Vector *pos, Vector *dir);
	void vector(Vector pos, Vector dir, Color color);
	void vector(Vector *pos, Vector *dir, Color *color);
	void vector(Vector dir);
	void vector(Vector *dir);
	void vector(Vector dir, Color color);
	void vector(Vector *dir, Color *color);

private:

};

#endif
