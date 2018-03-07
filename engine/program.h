#pragma once

#include <fstream>
#include <string>
#include "scene.h"
#include "image.h"
#include "font.h"

struct Program {
    std::ifstream readFile;
    std::ofstream writeFile;
    std::string input, programPath, programName, programType, commandType, sceneImagePath;
    std::string* scenePath; //stores ALL scene paths
    std::string* sceneName; //stores ALL scene names
    std::string* fontPath;
    std::string* fontName;
    int sceneNum, imageNum, fontNum;
    Scene* scene;
    Image* image;
    char* memblock;
};

void setupProgram(Program &program);
