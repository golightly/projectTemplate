#include "exitSDK.h"
#include "program.h"
#include "scene.h"
#include "image.h"

void exitSDK(Program &program, bool &quitSDK) {
    if(program.image != NULL)
        delete [] program.image;
    if(program.scenePath != NULL)
        delete program.scenePath;
    if(program.sceneName != NULL)
        delete program.sceneName;
    quitSDK = true;
}