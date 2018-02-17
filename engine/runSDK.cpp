#include "runSDK.h"
#include "program.h"
#include "scene.h"
#include "image.h"
#include "newContinueSDK.h"
#include "sdkGetInput.h"
#include "processSDKInput.h"
#include "resetSDKData.h"

void runSDK(Program &program) {
    program.sceneNum = 0;
    program.imageNum = 0;
    program.scene = NULL;
    program.image = NULL;
    program.scenePath = NULL;
    program.sceneName = NULL;
    newContinueSDK(program);
    bool quitSDK = false;
    while(!quitSDK) {
        resetSDKData(program);
        sdkGetInput(program);
        processSDKInput(program, quitSDK);
    }
}