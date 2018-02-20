#include "sceneSetupSpawns.h"
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "scene.h"
#include "program.h"

void sceneSetupSpawns(Program &program) {
  std::getline(program.readFile, program.input);
  program.scene.spawnGroupNum = atoi(program.input.c_str());
  program.scene.spawnGroupSize = new int[program.scene.spawnGroupNum];
  for(int a = 0; a < program.scene.spawnGroupNum; ++a) {
    std::getline(program.readFile, program.input);
    program.scene.spawnGroupSize[a] = atoi(program.input.c_str());
  }
  program.scene.spawnArea = new SDL_Rect*[program.scene.spawnGroupNum];
  for(int a = 0; a < program.scene.spawnGroupNum; ++a) {
    program.scene.SpawnArea[a] = new SDL_Rect[program.scene.spawnGroupSize[a]];
  }
  for(int a = 0; a < program.scene.spawnGroupNum; ++a) {
    for(int b = 0; b < program.scene.spawnGroupSize[a]; ++b) {
      std::getline(program.readFile, program.input);
      program.scene.spawnArea[a][b].w = atoi(program.input.c_str());
      std::getline(program.readFile, program.input);
      program.scene.spawnArea[a][b].h = atoi(program.input.c_str());
      std::getline(program.readFile, program.input);
      program.scene.spawnArea[a][b].x = atoi(program.input.c_str());
      std::getline(program.readFile, program.input);
      program.scene.spawnArea[a][b].y = atoi(program.input.c_str());
    }
  }
}
