#pragma once

#include <SDL.h>
#include <string>
#include "sprite.h"

struct Text {
  std::string name;
  int fontIndex;
  int* characterIndex; //the index of each character in the line of text, can range from space (0) to tilde (94)
  SDL_Rect lineAttributes;
  SDL_Rect* characterAttributes;
};

void setupText(Text &text, std::string name, int fontIndex, std::string line);
