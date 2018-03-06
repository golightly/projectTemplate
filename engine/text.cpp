#include "text.h"

void setupText(Text &text, std::string name, int fontIndex, std::string line) {
  text.name = name;
  text.fontIndex = fontIndex;
  characterIndex = new int[line.size()];
  for(int a = 0; a < line.size(); ++a) {
    characterIndex[a] = (int)(line[a] - 32);
  }
  //decide on a base size for all characters, they are not necessarily all the same size, gonna need to do that
  //at home or otherwise with an art program
}
