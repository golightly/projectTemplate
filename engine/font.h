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

//move font to scene!

//Font font;

//something like this

/*std::getline(program.readFile, program.input);
        program.fontNum = atoi(program.input.c_str());
        program.fontPath = new std::string[program.fontNum];
        program.fontName = new std::string[program.fontNum];
        for(int a = 0; a < program.fontNum; ++a) {
            std::getline(program.readFile, program.fontPath[a]);
            std::getline(program.readFile, program.fontName[a]);
        }/*
