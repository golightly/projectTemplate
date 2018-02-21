#pragma once

#include <SDL.h>

struct Overhead {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int imgFlags;
};

void setupOverhead(Overhead &overhead, int w, int h);

void closeOverhead(Overhead &overhead);
