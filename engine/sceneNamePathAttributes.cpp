#include "sceneNamePathAttributes.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "scene.h"
#include "program.h"

void sceneNamePathAttributes(Program &program) {
  program.scene.sceneName = program.sceneName[atoi(program.sceneImagePath.c_str())];
  program.readFile.open(program.scenePath[atoi(program.sceneImagePath.c_str())].c_str());
  std::getline(program.readFile, program.scene.functionName); //will be NULL FUNCTION PATH the first time
  std::getline(program.readFile, program.input);
  program.scene.sceneAttributes.w = atoi(program.input.c_str());
  std::getline(program.readFile, program.input);
  program.scene.sceneAttributes.h = atoi(program.input.c_str());
  program.scene.sceneAttributes.x = 0;
  program.scene.sceneAttributes.y = 0;
}
