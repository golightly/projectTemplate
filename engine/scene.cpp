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

void setupScene(Program &program) {
    program.scene = new Scene;
    sceneNmePathAttributes(program);
    sceneImageNumSprite(program);
    sceneSetupCollision(program);
    sceneSetupSpawns(program);
    program.readFile.close();
    program.readFile.clear();
    //will require a lot more once characters and stuff added
}

void closeScene(Scene &scene) {
    if(scene.sceneImageNum > 1)
        delete [] scene.sceneImage;
    else if(scene.sceneImageNum == 1)
        delete scene.sceneImage;
    if(scene.spriteNum > 1)
        delete [] scene.sprite;
    else if(scene.spriteNum == 1)
        delete scene.sprite;
    if(scene.collisionNum > 1)
        delete [] scene.collisionAttributes;
    else if(scene.collisionNum == 1)
        delete scene.collisionAttributes;
    for(int a = 0; a < scene.spawnGroupNum; ++a) {
        if(scene.spawnGroupSize[a] > 1)
            delete [] scene.spawnArea[a];
        else if(scene.spawnGroupSize[a] == 1)
            delete scene.spawnArea[a];
    }
    if(scene.spawnGroupNum > 1)
        delete [] scene.spawnArea;
    else if(scene.spawnGroupNum == 1)
        delete scene.spawnArea;
    if(scene.spawnGroupSize > 1)
        delete [] scene.spawnGroupSize;
    else if(scene.spawnGroupSize == 1)
        delete scene.spawnGroupSize;
    delete scene;
    scene = NULL;
}

//work on openScene/main function next
