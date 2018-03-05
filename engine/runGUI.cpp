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
#include "render.h"

void runGUI(std::string windowName, Editor &editor, Scene &scene, Image* image) {
  accessData();
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
  w = 50;
  h = 50;
  path = "collisionBox.png";
  setupTexture(editor.GUIOverhead, editor.editorTexture, w, h, path); //this is index 0
  path = "spawnBox.png";
  setupTexture(editor.GUIOverhead, editor.editorTexture, w, h, path); //this is index 1
  accessComplete();
  bool quit = false;
  SDL_Event event;
  while(!quit) {
    while(SDL_PollEvent(&event) != 0) {
      if(event.type == SDL_QUIT)
        quit = true;
    }
    SDL_RenderClear(editor.GUIOverhead.renderer);
    for(int a = 0; a < scene.spriteNum; ++a) {
      render(editor.GUIOverhead, editor.texture[scene.sprite[a].textureIndex] //continue
    }
    //define sprites for editorTextures! then render them too
    SDL_RenderPresent(editor.GUIOverhead.renderer);
  }
  //continue here
  //setup sprites in relation to scene in sprite setup - done
  //error in how data is accessed, this doesn't actually protect it at all! restructure
  //also, forgot to do camera stuff and movement of camera
}
