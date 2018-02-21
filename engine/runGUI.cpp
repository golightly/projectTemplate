#include "runGUI.h"
#include <string>
#include "editor.h"
#include "scene.h"
#include "overhead.h"
#include "texture.h"
#include "image.h"

void runGUI(std::string windowName, Editor &editor, Scene &scene, Image* image) {
  setupOverhead(editor.GUIOverhead, editor.windowWidth, editor.windowHeight, windowName);
  editor.texture.texture = NULL;
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
  //continue here
}
