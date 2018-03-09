#include "text.h"

void setupText(Text &text, Font &font, std::string name, int fontIndex, std::string line) {
  text.name = name;
  text.fontIndex = fontIndex;
  characterIndex = new char[line.size()];
  for(int a = 0; a < line.size(); ++a) {
    characterIndex[a] = line[a] - 32;
  }
  //work on integrating this with scene setup and scene closing and make sure to do all this for the editor too
}

void closeText(Text* text, int sceneTextNum) {
  for(int a = 0; a < sceneTextNum; ++a) {
    delete [] text[a].characterIndex;
    delete [] text[a].characterAttributes;
  }
  delete [] text;
}
