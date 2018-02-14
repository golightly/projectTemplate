#pragma once

#include <SDL.h>

struct Sprite {
    int textureIndex;
    SDL_Rect attributes;
};

void setupSprite(Sprite &sprite, int w, int h, int x, int y, int textureIndex);