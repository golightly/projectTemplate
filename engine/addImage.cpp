#include "addImage.h"
#include <iostream>
#include <string>
#include <cstdint>
#include "program.h"
#include "image.h"

void addImage(Program &program) {
    if(image != NULL) {
        Image* temp = new Image[program.imageNum];
        for(int a = 0; a < program.imageNum; ++a) {
            temp[a].name = program.image[a].name;
            temp[a].path = program.image[a].path;
            temp[a].w = program.image[a].w;
            temp[a].h = program.image[a].h;
        }
        delete [] program.image;
        ++program.imageNum;
        program.image = new Image[program.imageNum];
        for(int a = 0; a < (program.imageNum - 1); ++a) {
            program.image[a].name = temp[a].name;
            program.image[a].path = temp[a].path;
            program.image[a].w = temp[a].w;
            program.image[a].h = temp[a].h;
        }
    } //not done!
    else {
        ++program.imageNum;
        program.image = new Image[imageNum];
    }
    std::cout << "image name: ";
    std::getline(std::cin, program.input);
    program.image[(program.imageNum - 1)].name = program.input;
    program.image[(program.imageNum - 1)].path = program.sceneImagePath;
    program.readFile.open(program.sceneImagePath.c_str(), std::ios::in | std::ios::binary | std::ios::beg);
    program.readFile.read(program.image[(program.imageNum - 1)].w, sizeof(uint16_t));
    program.readFile.read(program.image[(program.imageNum - 1)].h, sizeof(uint16_t));
    program.readFile.close();
    program.readFile.clear();
}