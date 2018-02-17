#include "sdkProcessCommand.h"
#include <string>
#include "program.h"

void sdkProcessCommand(Program &program) {
    if(program.commandType == "add-image")
        addImage(program);
    else if(program.commandType == "rm-image")
        removeImage(program);
    else if(program.commandType == "add-scene")
        addScene(program();
    else if(program.commandType == "rm-scene")
        removeScene(program);
    else if(program.commandType == "open")
        openScene(program);
}