#pragma once

#include <string>
#include <SDL.h>
#include "program.h"
#include "sprite.h"

//will require a lot more
struct Scene {
    std::string sceneName, functionName; //functionName matches the id used by the pointer for the function intended for this scene
    SDL_Rect sceneAttributes; //attributes of the scene itself
    int sceneImageNum; //number of images/texture required for the scene
    int* image; //images required for the scene, size is number of textures, holds the id of the image in the image array
    int spriteNum;
    Sprite* sprite; //all sprites in the scene
    int collisionNum; //number of collision boxes in the scene
    SDL_Rect* collisionAttributes; //all collision boxes for the scene
    int spawnGroupNum; //see below
    int* spawnGroupSize; //spawn groups can have different sizes, respresents size of second dimension in spawnArea
    SDL_Rect** spawnArea; //spawn areas.  first dimension is spawn groups, then second dimension is specific attributes to spawn at
    //to be added, characters, and other stuff I'm sure
};

void setupScene(Program &program);

void closeScene(Program &program);
