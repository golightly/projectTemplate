#include "texture.h"
#include <SDL.h>
#include <string>
#include "overhead.h"

void innerSetupTexture(Overhead &overhead, SDL_Texture* &texture, std::string path) {
    SDL_Surface* surface = IMG_Load(patch.c_str()); //this definitely needs changing, want to create texture from pixels
    texture = SDL_CreateTextureFromSurface(overhead.renderer, surface);
    SDL_FreeSurface(surface);
}

//setup a group of textures at startup
void setupTexture(Overhead &overhead, Texture &texture, int* w, int* h, std::string* path, int &pathNum) {
    texture.textureNum = pathNum;
    texture.texture = new SDL_Texture*[pathNum];
    texture.w = new int[pathNum]; texture.h = new int[pathNum];
    for(int a = 0; a < pathNum; ++a) {
        innerSetupTexture(overhead, texture.texture[a], path[a]);
        texture.w[a] = w[a]; texture.h[a] = h[a];
    }
}

//setup one texture, during runtime
void setupTexture(Overhead &overhead, Texture &texture, int w, int h, std::string path) {
    int* tempW = new int[texture.textureNum];
    int* tempH = new int[texture.textureNum];
    SDL_Texture** temp;
    temp = new SDL_Texture*[texture.textureNum];
    for(int a = 0; a < texture.textureNum; ++a) { //trying to get pointer to texture, test this one out...
        temp[a] = &texture.texture[a];
        delete texture.texture[a];
        tempW[a] = texture.w[a];
        tempH[a] = texture.h[a];
    }
    delete [] texture.texture;
    delete [] texture.w;
    delete [] texture.h;
    ++texture.textureNum;
    texture.w = new int[texture.textureNum];
    texture.h = new int[texture.textureNum];
    texture.texture = new SDL_Texture*[texture.textureNum];
    for(int a = 0; a < (texture.textureNum - 1); ++a) {
        texture.texture[a] = &temp[a];
        delete temp[a];
        texture.w[a] = tempW[a];
        texture.h[a] = tempH[a];
    }
    delete [] temp;
    delete [] tempW;
    delete [] tempH;
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
    
    void closeTexture(Texture &texture, int index) {
        SDL_DestroyTexture(texture.texture[index]);
        int* tempW = new int[texture.textureNum - 1];
        int* tempH = new int[texture.textureNum - 1];
        int b = 0;
        for(int a = 0; a < texture.textureNum; ++a) {
            if(a != index) {
                tempW[b] = texture.w[a];
                tempH[b] = texture.h[a];
                ++b;
            }
        }
        delete [] texture.w;
        delete [] texture.h;
        --textureNum;
        texture.w = new int[texture.textureW];
        texture.h = new int[texture.textureH];
        for(int a = 0; a < texture.textureNum; ++a) {
            texture.w[a] = tempW[a];
            texture.h[a] = tempH[a];
        }
    }
