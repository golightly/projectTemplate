#include <string>
#include <SDL.h>
#include "text.h"
#include "font.h"


void setupText(Text &text, Font &font, std::string name, int fontIndex, std::string line) {
  text.name = name;
  text.fontIndex = fontIndex;
  text.characterIndex = new char[line.size()];
  text.characterAttributes = new SDL_Rect[line.size()];
  text.lineAttributes.w = 0;
  text.lineAttributes.h = 0;
  for(int a = 0; a < line.size(); ++a) {
    characterIndex[a] = line[a] - 32;
    text.characterAttributes[a].w = font.charset[fontIndex].character[text.characterIndex[a]].width;
    text.characterAttributes[a].h = font.charset[fontIndex].character[text.characterIndex[a]].height;
    text.lineAttributes.w += text.characterAttributes[a].w;
    text.lineAttributes.h += text.characterAttributes[a].h;
  }
  //work on integrating this with scene setup and scene closing and make sure to do all this for the editor too
}

void closeText(Text* text, int sceneTextNum) {
  for(int a = 0; a < sceneTextNum; ++a) {
    delete [] text[a].characterIndex;
    delete [] text[a].characterAttributes;
  }
  if(sceneTextNum > 0)
    delete [] text;
}
