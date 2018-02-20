#include "processSDKInput.h"
#include <string>
#include "program.h"
#include "printHelp.h"
#include "exitSDK.h"
#include "listSceneImage.h"
#include "sdkGetCommandPath.h"
#include "sdkProcessCommand.h"
#include "saveProject.h"

void processSDKInput(Program &program, bool &quitSDK) {
    if(program.input == "help")
        printHelp();
    else if(program.input == "exit")
        exitSDK(program, quitSDK);
    else if(program.input == "save") {
        saveProject(program);
    }
    else if(program.input == "list-scene" || program.input == "list-image")
        listSceneImage(program);
    else {
        sdkGetCommandPath(program);
        sdkProcessCommand(program);
    }
}
