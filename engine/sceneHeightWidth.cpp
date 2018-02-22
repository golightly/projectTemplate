#include "sceneHeightWidth.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "scene.h"
#include "program.h"

void sceneHeightWidth(Program &program) {
  std::getline(program.readFile, program.input);
  program.scene.width = atoi(program.input.c_str());
  std::getline(program.readFile, program.input);
  program.scene.height = atoi(program.input.c_str());
}
