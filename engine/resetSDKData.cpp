#include "resetSDKData.h"
#include <string>
#include "program.h"
#include "scene.h"

void resetSDKData(Program &program) {
    if(program.scene != NULL) {
        for(int a = 0; a < program.scene.spawnGroupNum; ++a) {
            delete [] program.scene.spawnArea[a];
        }
        delete [] program.scene.spawnArea;
        delete [] program.scene.spawnGroupSize;
        delete [] program.scene.collisionAttributes;
        delete [] sprite;
        delete [] program.scene.image;
        delete program.scene;
    }
    program.input.clear();
    program.commandType.clear();
    program.sceneImagePath.clear();
}
