#include "sceneImageNum.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "scene.h"
#include "program.h"
#include "sprite.h"

void sceneImageNum(Program &program) {
  std::getline(program.readFile, program.input);
  program.scene.sceneImageNum = atoi(program.input.c_str());
  program.scene.image = new int[program.scene.sceneImageNum];
  program.scene.spriteNum = 0;
  for(int a = 0; a < program.scene.sceneImageNum; ++a) {
    std::getline(program.readFile, program.input);
    program.scene.image[a] = atoi(program.input.c_str());
    program.scene.spriteNum += atoi(program.input.c_str());
  }
  setupSprite(program);
}
