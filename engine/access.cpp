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
    else if(actionType = "checkPosition") {
      actionType = "false";
      if((scene.sprite[index].attributes.x + scene.sprite[index].attributes.w) > editor.cameraX || scene.sprite[index].attributes.x < (editor.cameraX + editor.windowWidth)) {
        if((scene.sprite[index].attributes.y + scene.sprite[index].attributes.h) > editor.cameraY || scene.sprite[index].attributes.y < (editor.cameraY + editor.windowHeight))
          actionType = "true";
      }
    }
    editor.spriteLock.unlock();
  }
}
