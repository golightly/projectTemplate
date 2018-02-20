#pragma once

#include <SDL.h>

struct Overhead {
    SDL_Window* window;
    SDL_Renderer* renderer;
};

void setupOverhead(Overhead &overhead, int w, int h);

void closeOverhead(Overhead &overhead);
