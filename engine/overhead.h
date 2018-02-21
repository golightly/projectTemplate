#pragma once

#include <SDL.h>

struct Overhead {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int imgFlags;
    bool isMouseWindow;
};

void setupOverhead(Overhead &overhead, int w, int h, Editor &editor, bool isMouseWindow);

void closeOverhead(Overhead &overhead, bool isMouseWindow);
