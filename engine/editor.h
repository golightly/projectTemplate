#pragma once

#include <string>
#include <mutex>
#include "overhead.h"
#include "scene.h"

//put all the sdl and scene editing stuff here
struct Editor {
  Overhead GUIOverhead, mouseOverhead;
  int windowWidth, windowHeight;
  std::string savePath;
  SDL_Event event;
  bool quitEditor;
  Texture* texture;
  Texture* mouseTexture; //mouse window uses different textures not intended for the scene
  Texture* editorTexture; //textures only used by the editor, ie. collision box representations
  mutex mu;
  //also have buttons and stuff for the editor only here
  //plan out how editing will actually work next
};
