#include "sdkProcessCommand.h"
#include <string>
#include "program.h"
#include "scene.h"

void sdkProcessCommand(Program &program) {
    if(program.commandType == "add-image")
        addImage(program);
    else if(program.commandType == "rm-image")
        removeImage(program);
    else if(program.commandType == "add-scene")
        addScene(program();
    else if(program.commandType == "rm-scene")
        removeScene(program);
    else if(program.commandType == "open") {
        setupScene(program);
        openScene(program);
        //no need for unload function, that's taken care of by resetSDKData
    }
}
