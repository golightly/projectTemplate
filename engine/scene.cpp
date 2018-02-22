#include "scene.h"
#include <SDL.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "program.h"
#include "sprite.h"
#include "sceneImageNumSprite.h"
#include "sceneNamePathAttributes.h"
#include "sceneSetupCollision.h"
#include "sceneSetupSpawns.h"
#include "sceneHeightWidth.h"

void setupScene(Program &program) {
    program.scene = new Scene;
    sceneHeightWidth(program);
    sceneNmePathAttributes(program);
    sceneImageNumSprite(program);
    sceneSetupCollision(program);
    sceneSetupSpawns(program);
    program.readFile.close();
    program.readFile.clear();
    //will require a lot more once characters and stuff added
}

//work on openScene/main function next
