#include "openScene.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <thread>
#include <functional>
#include <sstream>
#include "program.h"
#include "scene.h"
#include "image.h"
#include "editor.h"
#include "runGUI.h"
#include "runMousePosWindow.h"
#include "runCmdLineEditor.h"
#include "texture.h"

void openScene(Program &program) {
  //scene already loaded, so it doesn't need to know which scene is loaded, except for saving purposes
  //use editor to store all the sdl and editing scene related stuff
  //have editor also store the path to save to, for simplicity
  Editor editor;
  editor.editorSpriteNum = 0;
  std::ostringstream sstream;
  editor.editorSpriteNum += scene.collisionNum;
  if(editor.editorSpriteNum > 0)
    Sprite* editorTemp = new Sprite[editor.editorSpriteNum];
  for(int a = 0; a < editor.editorSpriteNum; ++a) {
    editor.editorTemp[a].spriteName = "collisionBox";
    sstream << a;
    editor.editorTemp[a].spriteName += sstream.str();
    sstream.str(std::string());
    sstream.clear();
    editor.editorTemp[a].textureIndex = 0;
    editor.editorTemp[a].attributes.w = scene.collisionAttributes[a].w;
    editor.editorTemp[a].attributes.h = scene.collisionAttributes[a].h;
    editor.editorTemp[a].attributes.x = scene.collisionAttributes[a].x;
    editor.editorTemp[a].attributes.y = scene.collisionAttributes[a].y;
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
  std::cout << "width of editor window: ";
  std::cin >> editor.windowWidth;
  std::cout << "height of editor window: ";
  std::cin >> editor.windowHeight;
  editor.savePath = program.scenePath[atoi(program.sceneImagePath.c_str())];
  std::string windowName = "Scene Editor: ";
  windowName += program.scene.sceneName;
  std::thread editorGUI(runGUI, windowName, std::ref(editor), std::ref(program.scene), std::ref(program.image));
  std::thread mousePosWindow(runMousePosWindow, std::ref(editor));
  runCmdLineEditor(editor, std::ref(program.scene), std::ref(program.image));
  editorGUI.join();
  mousePosWindow.join();
  closeTexture(editor.texture);
  closeTexture(editor.mouseTexture);
  closeTexture(editor.editorTexture);
  closeScene(program.scene);
  IMG_Quit();
  SDL_Quit();
}
//textures are created at an open slot in a 999 size array
//the files are going to stay 8 bit because that makes them smaller
//mouse window works differently, uses its own textures
//textures are loaded from png files for the editor because sdl is so different from the opengl implementation that it doesn't matter
//work on runGUI
//add bundleProject function to the first part of the sdk: bundle images and scenes separately, and compress images
//put the project file in with the rest of the project as it's needed
//when scene is deleted, it shouold also delete sprites and other custom stuff
//check program close to see if it closes everything properly
