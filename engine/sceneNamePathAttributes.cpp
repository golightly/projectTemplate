#include "sceneNamePathAttributes.h"
#include <fstream>
#inclue <iostream>
#include <string>
#include <cstdlib>
#include "scene.h"
#include "program.h"

void sceneNamePathAttributes(Program &program) {
  program.scene.sceneName = program.sceneName[atoi(program.sceneImagePath.c_str())];
  program.readFile.open(program.scenePath[atoi(program.sceneImagePath.c_str())].c_str());
  std::getline(program.readFile, program.scene.functionName);
  std::getline(program.readFile, program.input);
  program.scene.sceneAttributes.w = atoi(program.input.c_str());
  std::getline(program.readFile, program.input);
  program.scene.sceneAttributes.h = atoi(program.input.c_str());
}
