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
  std::getline(program.readFile, program.scene.functionName);
  program.scene.sceneAttributes.w = 
  program.scene.sceneAttributes.h = 
}
