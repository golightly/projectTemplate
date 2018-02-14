#include "texture.h"
#include <SDL.h>
#include <string>
#include "overhead.h"

void innerSetupTexture(Overhead &overhead, SDL_Texture* &texture, std::string path) {
    SDL_Surface* surface = IMG_Load(patch.c_str());
    if(texture != NULL) {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
    texture = SDL_CreateTextureFromSurface(overhead.renderer, surface);
    SDL_FreeSurface(surface);
}

void setupTexture(Overhead &overhead, Texture &texture, int* w, int* h, std::string* path, int &pathNum) {
    texture.texture = new SDL_Texture*[pathNum];
    texture.w = new int[pathNum]; texture.h = new int[pathNum];
    for(int a = 0; a < pathNum; ++a) {
        innerSetupTexture(overhead, texture.texture[a], path[a]);
        texture.w[a] = w[a]; texture.h[a] = h[a];
    }
}