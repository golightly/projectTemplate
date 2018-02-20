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
    //continue here
}

//work on save next
