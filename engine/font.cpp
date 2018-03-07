#include "font.h"
#include <string>
#include <fstream>
#include <cstdint>
#include "image.h"

void setupFont(Font &font,int fontNum, std::string* path, std::string* fontName, int* charNum, int* charSize) {
  font.fontNum = fontNum;
  font.fontName = new std::string[font.fontNum];
  for(int a = 0; a < font.fontNum; ++a) {
    font.fontName[a] = fontName[a];
  }
  char* memblock;
  std::ifstream readFile;
  for(int a = 0; a < 95; ++a) {
    font.character[a].path = path[a];
    font.character[a].name += (char)(a+32); //a font should be every ascii character from space (32) to tilde (126)
    readFile.open(font.character[a].path.c_str(), std::ios::in | std::ios::binary | std::ios::beg);
    memblock = new char[sizeof(uint16_t))];
    readFile.read(memblock, sizeof(uint16_t));
    font.character[a].w = (uint16_t)memblock;
  }
  delete [] memblock;
  readFile.close();
  readFile.clear();
}
