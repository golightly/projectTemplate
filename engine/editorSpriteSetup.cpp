#include "editorSpriteSetup.h"
#include <sstream>
#include <string>
#include <SDL.h>
#include "editor.h"
#include "sprite.h"
#include "scene.h"

void editorSpriteSetup(Editor &editor, Scene &scene) {
  editor.editorSpriteNum = 0;
  std::ostringstream sstream;
  editor.editorSpriteNum += scene.collisionNum;
  if(editor.editorSpriteNum > 0)
    Sprite* editorTemp = new Sprite[editor.editorSpriteNum];
  for(int a = 0; a < editor.editorSpriteNum; ++a) {
    editorTemp[a].spriteName = "collisionBox";
    sstream << a;
    editorTemp[a].spriteName += sstream.str();
    sstream.str(std::string());
    sstream.clear();
    editorTemp[a].textureIndex = 0;
    editorTemp[a].attributes.w = scene.collisionAttributes[a].w;
    editorTemp[a].attributes.h = scene.collisionAttributes[a].h;
    editorTemp[a].attributes.x = scene.collisionAttributes[a].x;
    editorTemp[a].attributes.y = scene.collisionAttributes[a].y;
  }
  for(int a = 0; a < scene.spawnGroupNum; ++a) {
    editor.editorSpriteNum += scene.spawnGroupSize[a];
  }
  if(editor.editorSpriteNum > 0) {
    editor.editorSprite = new Sprite[editor.editorSpriteNum];
    if(scene.sceneCollisionNum > 0) {
      for(int a = 0; a < scene.collisionNum; ++a) {
        editor.editorSprite[a].spriteName = editorTemp[a].spriteName;
        editor.editorSprite[a].textureIndex = editorTemp[a].textureIndex;
        editor.editorSprite[a].attributes.w = editorTemp[a].attributes.w;
        editor.editorSprite[a].attributes.h = editorTemp[a].attributes.h;
        editor.editorSprite[a].attributes.x = editorTemp[a].attributes.x;
        editor.editorSprite[a].attributes.y = editorTemp[a].attributes.y;
      }
      delete [] editorTemp;
    }
    int c = scene.collisionNum;
    for(int a = 0; a < scene.spawnGroupNum; ++a) {
      for(int b = 0; b < scene.spawnGroupSize[a]; ++b) {
        editor.editorSprite[c].spriteName = "spawnBox";
        sstream << (c - scene.collisionNum);
        editor.editorSprite[c].spriteName += sstream.str();
        sstream.str(std::string());
        sstream.clear();
        editor.editorSprite[c].textureIndex = 1;
        editor.editorSprite[c].w = scene.spawnArea[a][b].w;
        editor.editorSprite[c].h = scene.spawnArea[a][b].h;
        editor.editorSprite[c].x = scene.spawnArea[a][b].x;
        editor.editorSprite[c].y = scene.spawnArea[a][b].y;
        ++c;
      }
    }
  }
}
