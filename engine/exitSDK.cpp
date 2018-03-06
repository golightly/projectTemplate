#include "exitSDK.h"
#include "program.h"
#include "scene.h"
#include "image.h"
#include "font.h"

void exitSDK(Program &program, bool &quitSDK) {
    if(program.image != NULL)
        delete [] program.image;
    if(program.scenePath != NULL)
        delete [] program.scenePath;
    if(program.sceneName != NULL)
        delete [] program.sceneName;
    for(int a = 0; a < program.fontNum; ++a) {
        delete [] program.font[a].character;
    }
    delete [] program.font;
    program.font = NULL;
    program.image = NULL;
    program.scenePath = NULL;
    program.sceneName = NULL;
    quitSDK = true;
}
