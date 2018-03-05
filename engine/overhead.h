#pragma once

#include <SDL.h>
#include "editor.h"

struct Overhead {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int imgFlags;
};

void setupOverhead(Overhead &overhead, int w, int h, Editor &editor);

void closeOverhead(Overhead &overhead);
