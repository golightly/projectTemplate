#include "newContinueSDK.h"
#include <string>
#include <iostream>
#include "program.h"

void newContinueSDK(Program &program) {
    std::cout << "Trashviolent SDK\n";
    std::cout << "new project: n projectFolder/myProject.project\ncontinue: c projectFolder/myProject.project" << std::endl;
    std::cout << "$"; 
    std::getline(std::cin, program.input);
    for(int a = 2; a < program.input.size; ++a) {
        program.programPath += program.input[a];
    }
    setupProgram(program);
}