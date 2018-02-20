#include "scene.h"
#include <SDL.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "program.h"
#include "sprite.h"

void setupScene(Program &program) {
    program.scene = new Scene;
    program.scene.sceneName = program.sceneName[atoi(program.sceneImagePath.c_str())];
    program.readFile.open(program.scenePath[atoi(program.sceneImagePath.c_str())].c_str());
    std::getline(program.readFile, program.scene.functionName);
    std::getline(program.readFile, program.input);
    program.scene.sceneAttributes.w = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    program.scene.sceneAttributes.h = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    program.scene.sceneImageNum = atoi(program.input.c_str());
    program.scene.image = new int[program.scene.sceneImageNum];
    program.scene.spriteNum = 0;
    for(int a = 0; a < program.scene.sceneImageNum; ++a) {
        std::getline(program.readFile, program.input);
        program.scene.image[a] = atoi(program.input.c_str());
        program.scene.spriteNum += atoi(program.input.c_str());
    }
    setupSprite(program);
    std:getline(program.readFile, program.input);
    program.scene.collisionNum = atoi(program.input.c_str());
    program.scene.collisionAttributes = new SDL_Rect[program.scene.collisionNum];
    for(int a = 0; a < program.scene.collisionNum; ++a) {
        std::getline(program.readFile, program.input);
        program.scene.collisionAttributes[a].w = atoi(program.input.c_str());
        std::getline(program.readFile, program.input);
        program.scene.collisionAttributes[a].h = atoi(program.input.c_str());
        std::getline(program.readFile, program.input);
        program.scene.collisionAttributes[a].x = atoi(program.input.c_str());
        std::getline(program.readFile, program.input);
        program.scene.collisionAttributes[a].y = atoi(program.input.c_str());
    }
    std::getline(program.readFile, program.input);
    program.scene.spawnGroupNum = atoi(program.input.c_str());
    program.scene.spawnGroupSize = new int[program.scene.spawnGroupNum];
    for(int a = 0; a < program.scene.spawnGroupNum; ++a) {
        std::getline(program.readFile, program.input);
        program.scene.spawnGroupSize[a] = atoi(program.input.c_str());
    }
    program.scene.spawnArea = new SDL_Rect*[program.scene.spawnGroupNum];
    for(int a = 0; a < program.scene.spawnGroupNum; ++a) {
        program.scene.SpawnArea[a] = new SDL_Rect[program.scene.spawnGroupSize[a]];
    }
    for(int a = 0; a < program.scene.spawnGroupNum; ++a) {
        for(int b = 0; b < program.scene.spawnGroupSize[a]; ++b) {
            std::getline(program.readFile, program.input);
            program.scene.spawnArea[a][b].w = atoi(program.input.c_str());
            std::getline(program.readFile, program.input);
            program.scene.spawnArea[a][b].h = atoi(program.input.c_str());
            std::getline(program.readFile, program.input);
            program.scene.spawnArea[a][b].x = atoi(program.input.c_str());
            std::getline(program.readFile, program.input);
            program.scene.spawnArea[a][b].y = atoi(program.input.c_str());
        }
    }
    program.readFile.close();
    program.readFile.clear();
    //will require a lot more once characters and stuff added
    //split this up into separate files
}

//work on save next
