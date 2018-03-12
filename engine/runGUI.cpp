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
  setupOverhead(editor.GUIOverhead, editor.windowWidth, editor.windowHeight, windowName);
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
<<<<<<< HEAD
=======
//make separate function for the editorSprite setup which is used from openScene

//to do next: check if i missed anything in this, openScene and editorSpriteSetup.  then work on the mouse window which
//add editorFont and text for both of the graphical windows
//work on splitting this up and revising it also
//text for the scene will need to be access protected.  fonts too
//also work on mutexes because at the moment one can be locked twice at the same time, which is an error
>>>>>>> 8358202b63d210e06fabf51cafe8dd69951caad0
