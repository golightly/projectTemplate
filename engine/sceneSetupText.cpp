#include "sceneSetupText.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "program.h"
#include "scene.h"
#include "font.h"
#include "text.h"

void sceneSetupText(Program &program) {
  std::getline(program.readFile, program.input);
  program.scene.sceneTextNum = atoi(program.input.c_str());
  program.scene.text = new Text[program.scene.sceneTextNum];
  for(int a = 0; a < program.scene.sceneTextNum; ++a) {
    int fontIndex;
    std::string name, line;
    std::getline(program.readFile, program.input);
    fontIndex = atoi(program.input.c_str());
    std::getline(program.readFile, name);
    std::getline(program.readFile, line);
    setupText(program.scene.text[a], program.scene.font, name, fontIndex, line);
  }
}
