#pragma once

#include <fstream>
#include <string>
#include "scene.h"
#include "image.h"

struct Program {
    std::ifstream readFile;
    std::ofstream writeFile;
    std::string input, programPath, programName, programType, commandType, sceneImagePath;
    std::string* scenePath; //stores ALL scene paths
    std::string* sceneName; //stores ALL scene names
    int* sceneWidth;
    int* sceneHeight;
    int sceneNum, imageNum;
    Scene* scene;
    Image* image;
    char* memblock;
};

void setupProgram(Program &program);
