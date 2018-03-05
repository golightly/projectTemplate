#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "overhead.h"

struct Texture {
    SDL_Texture** texture;
    int* w; int* h;
};

void innerSetupTexture(Overhead &overhead, SDL_Texture* &texture, std::string path);

<<<<<<< HEAD
void setupTexture(Overhead &overhead, Texture &texture, int* w, int* h, std::string* path, int pathNum);
=======
void setupTexture(Overhead &overhead, Texture &texture, int* w, int* h, std::string* path);
>>>>>>> origin/master

int setupTexture(Overhead &overhead, Texture &texture, int w, int h, std::string path);

void closeTexture(Texture &texture);

void closeTexture(Texture &texture, int index);
