#include <iostream>
#include <ctime>

#include <2D.hpp>

using namespace std;

int main(int argc, char **argv){

	Window window(WINDOWED, Vector(500, 500), "test");

	bool quit = false;

	while (!quit){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_KEYDOWN) quit = true;
			else if (event.type == SDL_MOUSEMOTION) window.updateMouse(&event.motion);
		}

		window.background(Black);

		window.draw();
	}

	return 0;
}
