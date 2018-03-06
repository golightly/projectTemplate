#include "runGUI.h"
#include <string>
#include <SDL.h>
#include "editor.h"
#include "scene.h"
#include "overhead.h"
#include "texture.h"
#include "image.h"
#include "access.h"
#include "sceneImage.h"

//this is gonna need to be split up

void runGUI(std::string windowName, Editor &editor, Scene &scene, Image* image) {
  setupOverhead(editor.GUIOverhead, editor.windowWidth, editor.windowHeight, windowName, editor);
  editor.texture.texture = NULL;
  editor.editorTexture.texture = NULL;
  if(scene.sceneImageNum > 0) {
    std::string* path = new std::string[scene.sceneImageNum];
    int* w = new int[scene.sceneImageNum];
    int* h = new int[scene.sceneImageNum];
    for(int a = 0; a < scene.sceneImageNum; ++a) {
      w[a] = (int)image[scene.sceneImage[a].imageIndex].w;
      h[a] = (int)image[scene.sceneImage[a].imageIndex].h;
      path[a] = image[scene.sceneImage[a].imageIndex].path;
    }
    setupTexture(editor.GUIOverhead, editor.texture, w, h, path, scene.sceneImageNum);
  }
  delete [] w;
  delete [] h;
  delete [] path;
  w = new int;
  h = new int;
  path = new std::string;
  w = 500;
  h = 500;
  path = "collisionBox.png";
  setupTexture(editor.GUIOverhead, editor.editorTexture, w, h, path); //this is index 0
  path = "spawnBox.png";
  setupTexture(editor.GUIOverhead, editor.editorTexture, w, h, path); //this is index 1
  bool quit = false;
  SDL_Event event;
  std::string protectedType, actionType;
  while(!quit) {
    while(SDL_PollEvent(&event) != 0) {
      if(event.type == SDL_QUIT)
        quit = true;
      else if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
          case SDLK_UP:
            if(editor.cameraY > 0)
              --editor.cameraY;
            break;
          case SDLK_DOWN:
            if((editor.cameraY + editor.windowHeight) < scene.sceneAttributes.h)
              ++editor.cameraY;
            break;
          case SDLK_LEFT:
            if(editor.cameraX > 0)
              --editor.cameraX;
            break;
          case SDLK_RIGHT:
            if((editor.cameraX + editor.windowWidth) < scene.sceneAttributes.w)
              ++editor.cameraY;
            break;
        }
      }
    }
    SDL_RenderClear(editor.GUIOverhead.renderer);
    protectedType = "sprite";
    for(int a = 0; a < scene.spriteNum; ++a) {
      actionType = "checkPosition";
      accessData(editor, scene, protectedType, actionType, a);
      if(actionType == "true") {
        actionType = "render";
        accessData(editor, scene, protectedType, actionType, a);
      }
    }
    protectedType = "editorSprite";
    for(int a = 0; a < editor.editorSpriteNum; ++a) {
      actionType = "checkPosition";
      accessData(editor, scene, protectedType, actionType, a);
      if(actionType == "true") {
        actionType = "render";
        accessData(editor, scene, protectedType, actionType, a);
      }
    }
    //define sprites for editorTextures! then render them too
    SDL_RenderPresent(editor.GUIOverhead.renderer);
  }
  //continue here
  //setup sprites in relation to scene in sprite setup - done
}
//make separate function for the editorSprite setup which is used from openScene

//to do next: check if i missed anything in this, openScene and editorSpriteSetup.  then work on the mouse window which
//will require an editor font.  so work on fonts in general
