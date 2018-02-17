#include "processSDKInput.h"
#include <string>
#include "program.h"
#include "printHelp.h"
#include "exitSDK.h"
#include "listSceneImage.h"
#include "sdkGetCommandPath.h"
#include "sdkProcessCommand.h"

void processSDKInput(Program &program, bool &quitSDK) {
    if(program.input == "help")
        printHelp();
    else if(program.input == "exit")
        exitSDK(program, quitSDK);
    else if(program.input == "save") {
        //take care of this later
    }
    else if(program.input == "list-scene" || program.input == "list-image")
        listSceneImage(program);
    else {
        sdkGetCommandPath(program);
        sdkProcessCommand(program);
    }
}