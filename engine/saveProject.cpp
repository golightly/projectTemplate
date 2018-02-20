#include "saveProject.h"
#include <string>
#include <fstream>
#include "program.h"
#include "image.h"

void saveProject(Program &program) {
  program.writeFile.open(program.programPath.c_str(), std::ios::beg);
  program.writeFile << program.programName << "\n";
  program.writeFile << program.programType << "\n";
  program.writeFile << program.sceneNum;
  program.writeFile << program.imageNum;
  for(int a = 0; a < program.imageNum; ++a) {
    program.writeFile << program.image[a].name;
    program.writeFile << program.image[a].path;
  }
  for(int a = 0; a < program.sceneNum; ++a) {
    program.writeFile << program.sceneName[a];
  }
  for(int a = 0; a < program.sceneNum; ++a) {
    program.writeFile << program.scenePath[a];
  }
  program.writeFile.close();
  program.writeFile.clear();
}
//split up setupScene next
