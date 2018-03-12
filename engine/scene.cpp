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
#include "sceneSetupFont.h"
#include "sceneSetupText.h"
#include "sceneImage.h"
#include "font.h"

void setupScene(Program &program) {
    program.scene = new Scene;
    sceneNamePathAttributes(program);
    sceneImageNumSprite(program);
    sceneSetupCollision(program);
    sceneSetupSpawns(program);
    sceneSetupFont(program);
    sceneSetupText(program);
    program.readFile.close();
    program.readFile.clear();
    //will require a lot more once characters and stuff added
}

void closeScene(Scene &scene) {
    delete [] scene.sceneImage;
    delete [] scene.sprite;
    delete [] scene.collisionAttributes;
    for(int a = 0; a < scene.spawnGroupNum; ++a) {
        delete [] scene.spawnArea[a];
    }
    delete [] scene.spawnArea;
    delete [] scene.spawnGroupSize;
    closeFont(scene.font);
    closeText(scene.text, scene.sceneTextNum);
    delete scene;
    scene = NULL;
}

//work on openScene/main function next
