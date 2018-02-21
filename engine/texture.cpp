#include "texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "overhead.h"

void innerSetupTexture(Overhead &overhead, SDL_Texture* &texture, std::string path) {
    SDL_Surface* surface = IMG_Load(path.c_str()); //leave this as is, don't care about the sdl way, opengl is different
    texture = SDL_CreateTextureFromSurface(overhead.renderer, surface);
    SDL_FreeSurface(surface);
}

//setup a group of textures at startup
void setupTexture(Overhead &overhead, Texture &texture, int* w, int* h, std::string* path, int &pathNum) {
    texture.textureNum = pathNum;
    texture.texture = new SDL_Texture*[999];
    texture.w = new int[999]; texture.h = new int[999];
    for(int a = 0; a < texture.textureNum; ++a) {
        innerSetupTexture(overhead, texture.texture[a], path[a]);
        texture.w[a] = w[a]; texture.h[a] = h[a];
    }
}

//setup one texture, during runtime
void setupTexture(Overhead &overhead, Texture &texture, int w, int h, std::string path) {
    ++texture.textureNum;
    //find the first empty texture pointer and set the texture up there
    texture.w[texture.textureNum - 1] = w;
    texture.h[texture.textureNum - 1] = h;
    innerSetupTexture(overhead, texture.texture[texture.textureNum - 1], path);
}
//remove all textures, at close
void closeTexture(Texture &texture) {
    for(int a = 0; a < texture.textureNum; ++a) {
        SDL_DestroyTexture(texture.texture[a]);
    }
    delete [] texture.texture;
    delete [] texture.w;
    delete [] texture.h;
}
    //remove one texture, sets pointer to NULL, cannot rearrange textures.  sets w and h for that index to 0
    void closeTexture(Texture &texture, int index) {
        SDL_DestroyTexture(texture.texture[index]);
        texture.w[index] = 0;
        texture.h[index] = 0;
        --textureNum;
        texture.texture[index] = NULL;
    }
