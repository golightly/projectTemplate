#include "openScene.h"
#include <iostream>
#include <cstdlib>
#include "program.h"
#include "scene.h"
#include "editor.h"
#include "runEditor.h"

void openScene(Program &program) {
  //scene already loaded, so it doesn't need to know which scene is loaded, except for saving purposes
  //use editor to store all the sdl and editing scene related stuff
  //have editor also store the path to save to, for simplicity
  Editor editor;
  std::cout << "width of editor window: ";
  std::cin >> editor.windowWidth;
  std::cout << "height of editor window: ";
  std::cin >> editor.windowHeight;
  editor.savePath = program.scenePath[atoi(program.sceneImagePath.c_str())];
  setupEditor(editor, program.scene);
  runEditor(editor, program.scene);
}
