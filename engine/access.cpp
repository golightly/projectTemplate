#include "access.h"
#include <mutex>
#include <string>
#include "editor.h"
#include "sprite.h"
#include "render.h"
#include "scene.h"
 
//the only things that need protection right now are sprites, add more of these functions as required
void accessData(Editor &editor, Scene &scene, std::string &protectedType, std::string &actionType, int &index) {
 if(protectedType == "sprite") {
  editor.spriteLock.lock();
  if(actionType == "render")
   render(editor.GUIOverhead, editor.texture[scene.sprite[index].textureIndex], scene.sprite[index]);
  else if(actionType == "checkPosition") {
   actionType = "false";
   if((scene.sprite[index].attributes.x + scene.sprite[index].attributes.w) > editor.cameraX || scene.sprite[index].attributes.x < (editor.cameraX + editor.windowWidth)) {
    if((scene.sprite[index].attributes.y + scene.sprite[index].attributes.h) > editor.cameraY || scene.sprite[index].attributes.y < (editor.cameraY + editor.windowHeight))
     actionType = "true";
   }
  }
    editor.spriteLock.unlock();
 }
 else if(protectedType == "editorSprite") {
  editor.editorSpriteLock.lock();
  if(actionType == "render")
   render(editor.GUIOverhead, editor.editorTexture[editor.editorSprite[index].textureIndex, editor.editorSprite[index]);
  else if(actionType == "checkPosition") {
   actionType = false;
   if((editor.editorSprite[index].attributes.x + editor.editorSprite[index].attributes.w) > editor.cameraX || editor.editorSprite[index].attributes.x < (editor.cameraX + editor.windowWidth)) {
    if((editor.editorSprite[index].attributes.y + editor.editorSprite[index].attributes.h) > editor.cameraY || editor.editorSprite[index].attributes.y < (editor.cameraY + editor.windowHeight))
     actionType = "true";
    }
   }
   editor.editorSpriteLock.unlock();
  }
}
