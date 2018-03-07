#include "font.h"
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <fstream>
#include <cstdint>
#include "image.h"
#include "charset.h"
#include "character.h"

void setupFont(Font &font,int fontNum, std::string* path, std::string* fontName, int* charNum, int* charSize, SDL_Color* colour) {
  font.fontNum = fontNum;
  font.fontName = new std::string[font.fontNum];
  font.charset = new Charset[font.fontNum];
  for(int a = 0; a < font.fontNum; ++a) {
    font.fontName[a] = fontName[a];
    font.charset[a].charNum = charNum[a];
    font.charset[a].charSize = charSize[a];
    font.charset[a].character = new Character[font.charset[a].charNum];
    TTF_Font* newFont;
    newFont = TTF_OpenFont(path[a].c_str(), font.charset[a].charSize);
    for(int b = 0; b < font.charset[a].charNum; ++b) { //sdl_ttf is already initialised, in overhead setup
      SDL_Surface* surface;
      char letter[1];
      letter[0] = b + 32;
      surface = TTF_RenderText_Blended(newFont, letter, colour[a]);
      font.charset[a].character[b].width = surface->w;
      font.charset[a].character[b].height = surface->h;
      font.charset[a].character[b].pixels = new float[(surface->w * surface->h) * 4];
      int count = 0;
      Uint8 red, green, blue, alpha;
      SDL_LockSurface(surface);
      Uint8* p = (Uint8*)surface->pixels;
      for(int y = 0; y < surface->h; ++y) {
        for(int x = 0; x < surface->w; ++x) {
          Uint32 pixel = p[(y * surface->w) + x];
          SDL_GetRGBA(pixel, surface->format, &red, &green, &blue, &alpha);
          font.charset[a].character[b].pixels[count] = ((float)red / 255.0f);
          ++count;
          font.charset[a].character[b].pixels[count] = ((float)green / 255.0f);
          ++count;
          font.charset[a].character[b].pixels[count] = ((float)blue / 255.0f);
          ++count;
          font.charset[a].character[b].pixels[count] = ((float)alpha / 255.0f);
          ++count;
        }
      }
      SDL_UnlockSurface(surface);
      SDL_FreeSurface(surface);
      TTF_CloseFont(newFont);
    }
  }
}

//closes all fonts
void closeFont(Font &font) {
  delete [] font.fontName;
  for(int a = 0; a < font.fontNum; ++a) {
    for(int b = 0; b < font.charset[a].charNum; ++b) {
      delete [] font.charset[a].character[b].pixels;
    }
    delete [] font.charset[a].character;
  }
  delete [] font.charset;
}
