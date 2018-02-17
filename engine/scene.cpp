#include "scene.h"
#include <SDL.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "image.h"

void setupScene(std::ifsteam &file, Scene &scene, std::string &input, Image* image, std::string &scenePath) {
    std::getline(file, scene.sceneName);
    std::getline(file, scenePath);
    std::getline(file, scene.functionName);
    std::getline(file, input);
    scene.sceneAttributes.w = atoi(input.c_str());
    std::getline(file, input);
    scene.sceneAttributes.h = atoi(input.c_str());
    scene.sceneAttributes.x = 0; scene.sceneAttributes.y = 0;
    std::getline(file, input);
    scene.sceneImageNum = atoi(input.c_str());
    scene.image = new std::string[scene.sceneImageNum];
    for(int a = 0; a < scene.sceneImageNum; ++a) {
        std::getline(file, input);
        scene.image[a] = atoi(input.c_str());
    }
    scene.spritePerTexture = new int[scene.sceneImageNum];
    scene.spriteAttributes = new SDL_Rect*[scene.sceneImageNum];
    for(int a = 0; a < scene.sceneImageNum; ++a) {
        std::getline(file, input);
        scene.spritePerTexture[a] = atoi(input.c_str());
        scene.spriteAttributes[a] = new SDL_Rect[scene.spritePerTexture[a]];
    }
    for(int a = 0; a < scene.sceneImageNum; ++a) {
        for(int b = 0; b < scene.spritePerTexture[a]; ++a) {
            scene.spriteAttributes[a][b].w = image[a].w;
            scene.spriteAttributes[a][b].h = image[a].h;
            std::getline(file, input);
            scene.spriteAttributes[a][b].x = atoi(input.c_str());
            std::getline(file, input);
            scene.spriteAttributes[a][b].y = atoi(input.c_str());
        }
    }
    std::getline(file, input);
    scene.collisionNum = atoi(input.c_str());
    scene.collisionAttributes = new SDL_Rect[scene.collisionNum];
    for(int a = 0; a < scene.collisionNum: ++a) {
        std::getline(file, input);
        scene.collisionAttributes[a].w = atoi(input.c_str());
        std::getline(file, input);
        scene.collisionAttributes[a].h = atoi(input.c_str());
        std::getline(file, input);
        scene.collisionAttributes[a].x = atoi(input.c_str());
        std::getline(file, input);
        scene.collisionAttributes[a].y = atoi(input.c_str());
    }
    std::getline(file, input);
    scene.spawnGroupNum = atoi(input.c_str());
    std::getline(file, input);
    scene.spawnGroupSize = atoi(input.c_str());
    scene.spawnArea = new SDL_Rect*[scene.spawnGroupNum];
    for(int a = 0; a < scene.spawnGroupNum; ++a) {
        scene.spawnArea[a] = new SDL_Rect[scene.spawnGroupSize];
    }
}