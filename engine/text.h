#pragma once

#include <SDL.h>
#include <string>
#include "sprite.h"

struct Text {
  std::string name;
  int fontIndex;
  char* characterIndex; //the index (as a char) of each character in the line of text, can range from space (0) to tilde (94)
  SDL_Rect lineAttributes;
  SDL_Rect* characterAttributes;
};

void setupText(Text &text, Font &font, std::string name, int fontIndex, std::string line);
