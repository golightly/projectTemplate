#include "sdkGetCommandPath.h"
#include "program.h"

void sdkGetCommandPath(Program &program) {
    for(int a = 0; a < program.input.size(); ++a) {
        program.commandType += program.input[a];
        if(program.commandType == "add-image" || program.commandType == "rm-image" || program.commandType == "add-scene" || program.commandType == "rm-scene" || program.commandType == "open") {
            for(int b = a + 2; b < program.input.size(); ++b) {
                program.sceneImagePath += input[b];
            }
            a = b;
        }
    }
}