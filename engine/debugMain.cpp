//next phase: setup(either start a new project or continue one, done on command line)
//organize this mess in visual studio
//FIX 2D ARRAYS, should be pointers in the first dimension

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "funcPointer.h"
#include "overhead.h"
#include "texture.h"
#include "sprite.h"
#include "image.h"
#include "scene.h"
#include "render.h"

int main(int argc, char* args[]) {
    std::ifstream file;
    std::string input, path, programName, programType;
    std::string* scenePath;
    int sceneNum = 0;
    int imageNum = 0;
    Scene* scene = NULL;
    Image* image = NULL;
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
        std::getline(file, input);
        sceneNum = atoi(input.c_str());
        std::getline(file, input);
        imageNum = atoi(inut.c_str());
        scene = new Scene[sceneNum];
        image = new Image[imageNum];
        for(int a = 0; a < imageNum; ++a) {
            setupImage(file, image[a], input);
        }
        for(int a = 0; a < sceneNum; ++a) { //for every scene saved so far
            setupScene(file, scene[a], input, image);
        }
        file.close();
        file.clear();
    }
    bool quitSDK = false;
    while(!quitSDK) {
        std::cout << programName << std::endl;
        std::cout << "scene#" << sceneNum << " image#" << imageNum << std::endl;
        std::cout << "type help for command list" << std::endl;
        std::cout << "$";
        std::cin << input;
        if(input == "help") {
            std::cout << "list-scene: lists scene names and paths" << std::endl;
            std:;cout << "list-image: lists image paths" << std::endl;
            std::cout << "add-image-<path>: adds image from the specified path" << std::endl;
            std::cout << "rm-image-<index number>: removes the image at this index of\n\tthe array and adjusts the array and image number" << std::endl;
            std::cout << "rm-scene-<index number>: likewise, for a scene" << std::endl;
            std::cout << "add-scene-<path>: asks for scene basic stuff and creates" << std::endl;
            std::cout << "exit: exits the program" << std::endl;
            std::cout << "save: saves everything" << std::endl;
            std::cout << "open-<scene index number>: opens scene in sdl window for editing" << std::endl;
            std::cout << "open-<scene name>: does the same thing" << std::endl;
            std::cout << "open-<scene path>: see above" << std::endl;
        }
        else if(input == "exit") {
            for(int a = 0; a < sceneNum; ++a) {
                for(int b = 0; b < scene[a].spawnGroupNum; ++b) {
                    delete [] scene[a].spawnArea[b];
                }
                delete [] scene[a].spawnArea;
                delete [] scene[a].collisionAttributes;
                for(int b = 0; b < scene[a].sceneImageNum; ++b) {
                    delete [] scene[a].spriteAttributes[b];
                }
                delete [] scene[a].spriteAttributes;
                delete [] scene[a].spritePerTexture;
                delete [] scene[a].image;
            }
            if(scene != NULL)
                delete [] scene;
            if(image != NULL)
                delete [] image;
            quitSDK = true;
        }
        //add more here IMPORTANT
        //the main function will end shortly after this, the sdl part is a separate function obviously
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
