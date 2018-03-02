#include "sceneSetupCollision.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <SDL.h>
#include "program.h"
#include "scene.h"

void sceneSetupCollision(Program &program) {
  std:getline(program.readFile, program.input);
  program.scene.collisionNum = atoi(program.input.c_str());
  if(program.scene.collisionNum > 0)
    program.scene.collisionAttributes = new SDL_Rect[program.scene.collisionNum];
  for(int a = 0; a < program.scene.collisionNum; ++a) {
    std::getline(program.readFile, program.input);
    program.scene.collisionAttributes[a].w = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    program.scene.collisionAttributes[a].h = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    program.scene.collisionAttributes[a].x = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    program.scene.collisionAttributes[a].y = atoi(program.input.c_str());
  }
}
