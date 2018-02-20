//next phase: setup(either start a new project or continue one, done on command line)
//organize this mess in visual studio
//FIX 2D ARRAYS, should be pointers in the first dimension
//add rotation for sprites
//clean this up more
//put all those loose variables at the start into a Program struct and do a huge rewrite
//make stuff so scenes are all in one file at the end of the process, but not during SDK process, like imgs
//clean up main includes

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "funcPointer.h"
#include "overhead.h"
#include "texture.h"
#include "sprite.h"
#include "image.h"
#include "scene.h"
#include "render.h"
#include "program.h"
#include "runSDK.h"

int main(int argc, char* args[]) {
    Program* program = new Program;
    runSDK(program);
    
    
    //divider between real code ^ and test sdl code below
    Overhead overhead; 
    setupOverhead(overhead, 800, 600);
    int spriteNum = 8; //these will both be heavily overhauled too
    int* spriteTextureIndex = new int[spriteNum];
    file.open(path);
    for(int a = 0; a < 2; ++a) { //as many times as needed to get to the right line in the .project file really
        file.ignore(1000, '\n');
    }
    std::getline(file, input);
    int textureNum = atoi(input.c_str());
    std::string* texturePath = new std::string[textureNum];
    int* textureW = new int[textureNum]; int* textureH = new int[textureNum];
    for(int a = 0; a < textureNum; ++a) {
        std::getline(file, texturePath[a]);
    }
    Texture texture; setupTexture(overhead, texture, textureW, textureH,  texturePath, textureNum);
    //IMPORTANT actually, edit to have it load only the textures needed per scene, store images only as names and paths in the main .project file
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
            case SDL_WINDOWEVENT:
                switch(event.window.event) {
                case SDL_WINDOWEVENT_CLOSE:
                    quit = true;
                    event.type = SDL_QUIT;
                    std::cout << "window close triggered" << std::endl;
                    break;
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    overhead.w = event.window.data1;
                    overhead.h = event.window.data2;
                    std::cout << "width: " << overhead.w << std::endl;
                    std::cout << "height: " << overhead.h << std::endl;
                    break;
                }
            break;
            }
        }
        SDL_RenderClear(overhead.renderer);
        render(overhead, texture);
        SDL_RenderPresent(overhead.renderer);
        }
    closeTexture(texture);
    closeOverhead(overhead);
    return 0;
}
