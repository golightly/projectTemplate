#include "removeScene.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "program.h"
#include "scene.h"

void removeScene(Program &program) {
  std::cout << "delete scene from hard drive(y/n): ";
  std::cin >> program.input;
  if(program.input == "y")
    remove(program.scenePath[atoi(program.sceneImagePath.c_str())].c_str());
  std::string* temp = new std::string[program.sceneNum - 1];
  std::string* temp2 = new std::string[program.sceneNum - 1];
  int b = 0;
  for(int a = 0; a < program.sceneNum; ++a) {
    if(a != atoi(program.sceneImagePath.c_str())) {
      temp[b] = program.scenePath[a];
      temp2[b] = program.sceneName[a];
      ++b;
    }
  }
  delete [] program.scenePath;
  delete [] program.sceneName;
  --program.sceneNum;
  for(int a = 0; a < program.sceneNum; ++a) {
    program.scenePath[a] = temp[a];
    program.sceneName = temp2[a];
  }
  delete [] temp;
  delete [] temp2;
}

//work on setupScene update next
