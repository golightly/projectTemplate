#include "saveProject.h"
#include <string>
#include <fstream>
#include "program.h"
#include "image.h"

void saveProject(Program &program) {
  program.writeFile.open(program.programPath.c_str(), std::ios::beg);
  program.writeFile << program.programName << "\n";
  program.writeFile << program.programType << "\n";
  program.writeFile << program.sceneNum << "\n";
  program.writeFile << program.imageNum << "\n";
  for(int a = 0; a < program.imageNum; ++a) {
    program.writeFile << program.image[a].name << "\n";
    program.writeFile << program.image[a].path << "\n";
  }
  for(int a = 0; a < program.sceneNum; ++a) {
    program.writeFile << program.sceneName[a] << "\n";
  }
  for(int a = 0; a < program.sceneNum; ++a) {
    program.writeFile << program.scenePath[a] << "\n";
  }
  program.writeFile << program.fontNum << "\n";
  for(int a = 0; a < program.fontNum; ++a) {
    for(int b = 0; b < 95; ++b) {
      program.writeFile << program.font[a].character[b].path << "\n";
    }
  }
  program.writeFile.close();
  program.writeFile.clear();
}
//split up setupScene next
