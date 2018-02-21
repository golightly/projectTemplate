#include "runGUI.h"
#include <string>
#include "editor.h"
#include "scene.h"
#include "overhead.h"

void runGUI(std::string windowName, Editor &editor, Scene &scene) {
  setupOverhead(editor.GUIOverhead, editor.windowWidth, editor.windowHeight, windowName);
  //deal with texture inner setup and the texture setup in openscene.cpp
  //continue here
}
