#include "resetSDKData.h"
#include <string>
#include "program.h"
#include "scene.h"

void resetSDKData(Program &program) {
    if(program.scene != NULL) {
        closeScene(program.scene);
    }
    program.input.clear();
    program.commandType.clear();
    program.sceneImagePath.clear();
}
