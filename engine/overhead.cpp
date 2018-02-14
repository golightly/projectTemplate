#include "overhead.h"
#include <SDL.h>
#include <SDL_image.h>
#include "texture.h"

void setupOverhead(Overhead &overhead, int w, int h) {
    SDL_Init(SDL_INIT_VIDEO);
    overhead.w = w; overhead.h = h;
    overhead.window = SDL_CreateWindow("Trashviolent SDK", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, overhead.w, overhead.h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    overhead.imgLoad = IMG_INIT_PNG; IMG_Init(overhead.imgLoad);
    overhead.renderer = SDL_CreateRenderer(overhead.window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(overhead.renderer, 0, 0, 0, 0);
}

void close(Overhead &overhead, Texture &texture) {
    for(int a = 0; a < texture.textureNum; ++a) {
        SDL_DestroyTexture(texture.texture[a]);
    }
    delete [] texture.texture;
    SDL_DestroyRenderer(overhead.renderer);
    SDL_DestroyWindow(overhead.window);
    IMG_Quit();
    SDL_Quit();
}