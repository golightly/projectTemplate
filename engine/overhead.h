#pragma once

#include <SDL.h>
#include <SDL_image.h>

struct Overhead {
    SDL_Window* window;
    int imgLoad, w, h;
    SDL_Renderer* renderer;
};

void setupOverhead(verhead &overhead, int w, int h);

void close(Overhead &overhead, Texture &texture);