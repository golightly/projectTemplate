#include "openScene.h"
#include <iostream>
#include <SDL.h>
#include <cstdlib>
#include <thread>
#include "program.h"
#include "scene.h"
#include "editor.h"
#include "runGUI.h"
#include "runMousePosWindow.h"
#include "runCmdLineEditor.h"

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
  std::string windowName = "Scene Editor: ";
  windowName += program.scene.sceneName;
  std::thread editorGUI(runGUI, windowName, editor, program.scene);
  std::thread mousePosWindow(runMousePosWindow, editor);
  runCmdLineEditor(editor, program.scene);
  editorGUI.join();
  mousePosWindow.join();
  SDL_Quit();
}
//don't forget to change the texture code because textures no longer delete
