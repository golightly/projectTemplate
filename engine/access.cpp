#include "access.h"
#include <mutex>
#include <string>
#include "editor.h"
#include "sprite.h"
#include "render.h"
#include "scene.h"

//the only things that need protection right now are sprites, add more of these functions as required
void accessData(Editor &editor, Scene &scene. std::string &protectedType, std::string &actionType, int &index) {
  if(protectedType == "sprite") {
    editor.spriteLock.lock();
    if(actionType == "render") {
      render(editor.GUIOverhead, editor.texture[scene.sprite[a].textureIndex], scene.sprite[index]);
    }
    editor.spriteLock.unlock();
  }
}
