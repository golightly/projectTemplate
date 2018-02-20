#pragma once

#include <SDL.h>
#include <string>
#include "program.h"

struct Sprite {
    std::string spriteName;
    int textureIndex;
    SDL_Rect attributes;
};

void setupSprite(Sprite &sprite, int w, int h, int x, int y, int textureIndex);

void setupSprite(Program &program);
