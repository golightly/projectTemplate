#include "sceneSetupFont.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <SDL.h>
#include "program.h"
#include "scene.h"
#include "font.h"

void sceneSetupFont(Program &program) {
  int fontNum;
  std::string* fontName;
  std::string* path;
  int* charNum;
  int* charSize;
  SDL_Color* colour;
  std::getline(program.readFile, program.input);
  fontNum = atoi(program.input.c_str());
  fontName = new std::string[fontNum];
  path = new std::string[fontNum];
  charNum = new int[fontNum];
  charSize = new int[fontNum];
  colour = new SDL_Color[fontNum];
  for(int a = 0; a < fontNum; ++a) {
    std::getline(program.readFile, fontName);
    std::getline(program.readFile, path);
    std::getline(program.readFile, input);
    charNum[a] = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    charSize[a] = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    colour[a].r = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    colour[a].g = atoi(program.input.c_str());
    std::getline(program.readFile, program.input);
    colour[a].b = atoi(program.input.c_str());
  }
  setupFont(program.scene.font, fontNum, path, fontName, charNum, charSize, colour);
  delete [] fontName;
  delete [] path;
  delete [] charNum;
  delete [] charSize;
  delete [] colour;
}
