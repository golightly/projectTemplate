#include "overhead.h"
#include <SDL.h>
#include <cstdint>
#include <string>
#include "texture.h"

void setupOverhead(Overhead &overhead, int w, int h, std::string windowName) {
    if(SDL_WasInit(SDL_INIT_VIDEO) == 0)
        SDL_Init(SDL_INIT_VIDEO);
    overhead.window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    overhead.renderer = SDL_CreateRenderer(overhead.window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(overhead.renderer, 0, 0, 0, 0);
}

void closeOverhead(Overhead &overhead) {
    SDL_DestroyRenderer(overhead.renderer);
    SDL_DestroyWindow(overhead.window);
    SDL_Quit();
}
