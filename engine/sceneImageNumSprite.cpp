#include "sceneImageNumSprite.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "scene.h"
#include "program.h"
#include "sprite.h"
#include "sceneImage.h"

void sceneImageNumSprite(Program &program) {
  std::getline(program.readFile, program.input);
  program.scene.sceneImageNum = atoi(program.input.c_str());
  program.scene.sceneImage = new SceneImage[program.scene.sceneImageNum];
  program.scene.spriteNum = 0;
  for(int a = 0; a < program.scene.sceneImageNum; ++a) {
    std::getline(program.readFile, program.input);
    program.scene.sceneImage[a].imagePath = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    program.scene.sceneImage[a].numSprites = atoi(program.input.c_str());
    program.scene.spriteNum += program.scene.sceneImage[a].numSprites;
  }
  setupSprite(program);
}
