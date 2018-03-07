#include "program.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "scene.h"
#include "image.h"
#include "font.h"

void setupProgram(Program &program) {
    if(program.input[0] == 'n') {
        std::cout << "\nNew Project Setup" << std::endl;
        std::cout << "Program Name: "; 
        std::getline(std::cin, program.programName);
        std::cout << "Program Type(sdlopengl | directx12): ";
        std::getline(std::cin, program.programType);
    }
    else {
        //continue project
        program.readFile.open(program.programPath.c_str());
        std::getline(program.readFile, program.programName);
        std::getline(program.readFile, program.programType);
        std::getline(program.readFile, program.input);
        program.sceneNum = atoi(program.input.c_str());
        program.scenePath = new std::string[program.sceneNum];
        program.sceneName = new std::string[program.sceneNum];
        std::getline(program.readFile, program.input);
        program.imageNum = atoi(program.input.c_str());
        program.image = new Image[program.imageNum];
        for(int a = 0; a < program.imageNum; ++a) {
            setupImage(program, program.image[a]);
        }
        for(int a = 0; a < program.sceneNum; ++a) {
            std::getline(program.readFile, program.sceneName[a]);
        }
        for(int a = 0; a < program.sceneNum; ++a) {
            std::getline(program.readFile, program.scenePath[a]);
        }
        std::getline(program.readFile, program.input);
        program.fontNum = atoi(program.input.c_str());
        program.fontPath = new std::string[program.fontNum];
        program.fontName = new std::string[program.fontNum];
        for(int a = 0; a < program.fontNum; ++a) {
            std::getline(program.readFile, program.fontPath[a]);
            std::getline(program.readFile, program.fontName[a]);
        }
        program.readFile.close();
        program.readFile.clear();
    }
}
