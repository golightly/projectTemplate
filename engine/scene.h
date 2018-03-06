#pragma once

#include <string>
#include <SDL.h>
#include "program.h"
#include "sprite.h"
#include "sceneImage.h"
#include "text.h"

//will require a lot more
struct Scene {
    std::string sceneName, functionName; //functionName matches the id used by the pointer for the function intended for this scene
    SDL_Rect sceneAttributes; //attributes of the scene itself
    int sceneImageNum; //number of images/texture required for the scene
    int sceneFontNum; //number of fonts required for the scene
    int sceneTextNum; //number of text objects (1 per line of text) required for the scene
    SceneImage* sceneImage; //contains number of sprites per texture and the index of that image
    int spriteNum;
    Sprite* sprite; //all sprites in the scene
    int collisionNum; //number of collision boxes in the scene
    SDL_Rect* collisionAttributes; //all collision boxes for the scene
    int spawnGroupNum; //see below
    int* spawnGroupSize; //spawn groups can have different sizes, respresents size of second dimension in spawnArea
    SDL_Rect** spawnArea; //spawn areas.  first dimension is spawn groups, then second dimension is specific attributes to spawn at
    //to be added, characters, and other stuff I'm sure
    Text* text; //all lines of text in the scene
};

void setupScene(Program &program);

void closeScene(Program &program);
