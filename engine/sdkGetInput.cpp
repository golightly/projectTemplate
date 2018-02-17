#include "sdkGetInput.h"
#include <string>
#include <iostream>
#include "program.h"

void sdkGetInput(Program &program) {
    std::cout << program.programName << std::endl;
    std::cout << "scene#" << program.sceneNum << " image#" << program.imageNum << std::endl;
    std::cout << "type help for command list" << std::endl;
    std::cout << "$";
    std::cin << program.input;
}