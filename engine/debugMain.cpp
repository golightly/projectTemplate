//next phase: setup(either start a new project or continue one, done on command line)

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

struct Overhead {
    SDL_Window* window;
    int imgLoad, w, h;
    SDL_Renderer* renderer;
};

struct Texture {
    SDL_Texture** texture;
    int textureNum;
    int* w; int* h;
};

struct Sprite {
    int textureIndex;
    SDL_Rect attributes;
};

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
    SDL_DestroyRenderer(overhead.renderer);
    SDL_DestroyWindow(overhead.window);
    IMG_Quit();
    SDL_Quit();
}

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
    texture.texture = new SDL_Texture[pathNum];
    texture.w = new int[pathNum]; texture.h = new int[pathNum];
    for(int a = 0; a < pathNum; ++a) {
        innerSetupTexture(overhead, texture.texture[a], path[a]);
        texture.w[a] = w[a]; texture.h[a] = h[a];
    }
}

void setupSprite(Sprite &sprite, int w, int h, int x, int y, int textureIndex) {
    sprite.textureIndex = textureIndex;
    sprite.attributes.w = w; sprite.attributes.h = h; 
    sprite.attributes.x = x; sprite.attributes.y = y;
}

//renders one sprite per function call
void render(Overhead &overhead, Texture &texture, Sprite &sprite) {
    SDL_Rect renderQuad = { sprite.attributes.x, sprite.attributes.y, sprite.attributes.w, sprite.attributes.h };
    SDL_RenderCopy(overhead.renderer, texture.texture[sprite.textureIndex], &overhead.attributes, &renderQuad);
}

int main(int argc, char* args[]) {
    std::ifstream file;
    std::string input, path, programName, programType;
    std::string* scenePath; 
    SDL_Rect* sceneAttributes;
    std::cout << "Trashviolent SDK\n";
    std::cout << "new project: n projectFolder/myProject.project\ncontinue: c projectFolder/myProject.project" << std::endl;
    std::cout << "$"; std::getline(std::cin, input);
    for(int a = 2; a < input.size; ++a) {
        path += input[a];
    }
    if(input[0] == 'n') {
        //new project setup
        std::cout << "\nNew Project Setup" << std::endl;
        std::cout << "Program Name: "; std::getline(std::cin, programName);
        std::cout << "Program Type(sdlopengl | directx12): ";
        std::getline(std::cin, programType);
    }
    else {
        //continue project
        file.open(path.c_str());
        std::getline(file, programName);
        std::getline(file, programType);
        file.close();
        file.clear();
    }
    
    
    //divider between real code ^ and test sdl code below
    Overhead overhead; setupOverhead(overhead, 800, 600);
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
    close(overhead, texture);
    return 0;
}
