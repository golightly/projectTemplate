#include "texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "overhead.h"

void innerSetupTexture(Overhead &overhead, SDL_Texture* &texture, std::string path) {
    path[path.size() - 1] = 'g';
    path[path.size() - 2] = 'n';
    path[path.size() - 3] = 'g';
    SDL_Surface* surface = IMG_Load(path.c_str()); //leave this as is, don't care about the sdl way, opengl is different
    texture = SDL_CreateTextureFromSurface(overhead.renderer, surface);
    SDL_FreeSurface(surface);
}

//setup a group of textures at startup
void setupTexture(Overhead &overhead, Texture &texture, int* w, int* h, std::string* path, int pathNum) {
    texture.texture = new SDL_Texture*[999];
    for(int a = 0; a < 999; ++a) {
        texture.texture[a] = NULL;
    }
    texture.w = new int[999]; texture.h = new int[999];
    for(int a = 0; a < pathNum; ++a) {
        innerSetupTexture(overhead, texture.texture[a], path[a]);
        texture.w[a] = w[a]; texture.h[a] = h[a];
    }
}

//setup one texture, during runtime, returns index of texture so that sprites can be set to it
int setupTexture(Overhead &overhead, Texture &texture, int w, int h, std::string path) {
    //find the first empty texture pointer and set the texture up there
    if(texture.texture == NULL) { //if is new scene
        texture.texture = new SDL_Texture*[999];
        for(int a = 0; a < 999; ++a) {
            texture.texture[a] = NULL;
        }
        texture.w = new int[999]; texture.h = new int[999];
    }
    for(int a = 0; a < 999; ++a) {
        if(texture.texture[a] == NULL) {
            texture.w[a] = w;
            texture.h[a] = h;
            innerSetupTexture(overhead, texture.texture[a], path);
            return a;
        }
    }
}
//remove all textures, at close
void closeTexture(Texture &texture) {
    for(int a = 0; a < 999; ++a) {
        if(texture.texture[a] != NULL)
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
        texture.texture[index] = NULL;
    }
