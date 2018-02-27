#include "sceneImageNumSprite.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "scene.h"
#include "program.h"
#include "sprite.h"

void sceneImageNumSprite(Program &program) {
  std::getline(program.readFile, program.input);
  program.scene.sceneImageNum = atoi(program.input.c_str());
  program.scene.image = new int[program.scene.sceneImageNum];
  program.scene.spriteNum = 0;
  for(int a = 0; a < program.scene.sceneImageNum; ++a) {
    std::getline(program.readFile, program.input);
    program.scene.image[a] = atoi(program.input.c_str());
    program.scene.spriteNum += atoi(program.input.c_str()); //this needs correcting! probably.  how to know how many
  }//sprites per image? image holds the index of the image required!  rework it all.
  setupSprite(program); //wait, what image index.  there is no such thing... rewrite the stuff for the image variable
}// to actually be the number of sprites per texture
