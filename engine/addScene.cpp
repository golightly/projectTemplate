#include "addScene.h"
#include <string>
#include <iostream>
#include "program.h"
#include "scene.h"

void addScene(Program &program) {
    ++program.sceneNum;
    if(program.scenePath != NULL) {
        std::string* temp = new std::string[program.sceneNum - 1];
        std::string* temp2 = new std::string[program.sceneNum - 1];
        for(int a = 0; a < (program.sceneNum - 1); ++a) {
            temp[a] = program.scenePath[a];
            temp2[a] = program.sceneName[a];
        }
        delete [] program.scenePath;
        delete [] program.sceneName;
        program.scenePath = new std::string[program.sceneNum];
        program.sceneName = new std::string[program.sceneNum];
        for(int a = 0; a < (program.sceneNum - 1); ++a) {
            program.scenePath[a] = temp[a];
            program.sceneName[a] = temp2[a];
        }
        delete [] temp;
        delete [] temp2;
    }
    else {
        program.scenePath = new std::string[program.sceneNum];
        program.sceneName = new std::string[program.sceneNum];
    }
    std::cout << "Scene path: ";
    std::getline(std::cin, program.scenePath[program.sceneNum - 1]);
    std::cout << "Scene name: ";
    std::getline(std::cin, program.sceneName[program.sceneNum - 1]);
    std::cout << "Scene width: ";
    std::cin >> program.input;
    program.writeFile.open(program.scenePath[program.sceneNum - 1].c_str());
    program.writeFile << "NULL FUNCTION PATH"; //initialise function path
    program.writeFile << program.input << "\n";
    std::cout << "Scene Height: ";
    std::cin >> program.input;
    program.writeFile << program.input << "\n";
    program.writeFile.close();
    program.writeFile.clear();
}
