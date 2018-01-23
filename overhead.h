#pragma once

#include <SDL.h>

struct Overhead {
	SDL_Window * window;
	SDL_GLContext context;
};

void setupOverhead(Overhead &overhead);