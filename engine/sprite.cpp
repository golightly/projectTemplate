#include <SDL.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "sprite.h"
#include "program.h"

//sets up one sprite
void setupSprite(Sprite &sprite, int w, int h, int x, int y, int textureIndex, std::string spriteName) {
    sprite.spriteName = spriteName;
    sprite.textureIndex = textureIndex;
    sprite.attributes.w = w; sprite.attributes.h = h; 
    sprite.attributes.x = x; sprite.attributes.y = y;
}

//sets up ALL of sprites for startup
void setupSprite(Program &program) {
    program.scene.sprite = new Sprite[program.scene.spriteNum];
    for(int a = 0; a < program.scene.spriteNum; ++a) {
        std::getline(program.readFile, program.scene.sprite[a].spriteName);
        std::getline(program.readFile, program.index);
        program.scene.sprite[a].textureIndex = atoi(program.input.c_str());
        std::getline(program.readFile, program.index);
        program.scene.sprite[a].attributes.w = atoi(program.input.c_str());
        std::getline(program.readFile, program.index);
        program.scene.sprite[a].attributes.h = atoi(program.input.c_str());
        std::getline(program.readFile, program.index);
        program.scene.sprite[a].attributes.x = atoi(program.input.c_str());
        std::getline(program.readFile, program.index);
        program.scene.sprite[a].attributes.y = atoi(program.input.c_str());
    }
}
