#pragma once

#include <string>
#include <mutex>
#include <SDL.h>
#include "overhead.h"
#include "scene.h"
#include "texture.h"
#include "sprite.h"

//put all the sdl and scene editing stuff here
struct Editor {
  Overhead GUIOverhead, mouseOverhead;
  int windowWidth, windowHeight;
  std::string savePath;
  Texture* texture;
  Texture* mouseTexture; //mouse window uses different textures not intended for the scene
  Texture* editorTexture; //textures only used by the editor, ie. collision box representations
  int editorSpriteNum; //this should be setup with scene setup
  Sprite* editorSprite; //this too
  std::mutex spriteLock, sdl_lock;
  int cameraX, cameraY;
  //also have buttons and stuff for the editor only here
  //plan out how editing will actually work next
};
