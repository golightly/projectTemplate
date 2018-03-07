#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "charset.h"

struct Font { //restructure font as a set of character sets, each with 95 characters, filled in when the scene is initialised
  Charset* charset;
  std::string* fontName;
  int fontNum;
};
//setup all fonts at once
void setupFont(Font &font, int fontNum,  std::string* path, std::string fontName, int* charNum, int* charSize, SDL_Color* colour);

void closeFont();

//move font to scene!

