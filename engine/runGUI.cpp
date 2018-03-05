#include "runGUI.h"
#include <string>
#include "editor.h"
#include "scene.h"
#include "overhead.h"
#include "texture.h"
#include "image.h"
#include "access.h"

void runGUI(std::string windowName, Editor &editor, Scene &scene, Image* image) {
  accessData();
  setupOverhead(editor.GUIOverhead, editor.windowWidth, editor.windowHeight, windowName, editor);
  editor.texture.texture = NULL;
  editor.editorTexture = NULL;
  if(scene.sceneImageNum > 0) {
    int* w = new int[scene.sceneImageNum];
    int* h = new int[scene.sceneImageNum];
    std::string* path = new std::string[scene.sceneImageNum];
    for(int a = 0; a < scene.sceneImageNum; ++a) {
      w[a] = (int)image[scene.image[a]].w;
      h[a] = (int)image[scene.image[a]].h;
      path[a] = image[scene.image[a]].path;
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
  setupTexture(editor.GUIOverhead, editor.editorTexture, path); //this is index 0
  path = "spawnBox.png";
  setupTexture(editor.GUIOverhead, editor.editorTexture, path); //this is index 1
  accessComplete();
  //continue here
  //setup sprites in relation to scene in sprite setup
}
