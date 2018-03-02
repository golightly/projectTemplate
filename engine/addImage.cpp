#include "addImage.h"
#include <iostream>
#include <string>
#include <cstdint>
#include "program.h"
#include "image.h"
#include "convertImage.h"

void addImage(Program &program) {
    if(program.image != NULL) {
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
	    delete [] temp;
    }
    else {
        ++program.imageNum;
        program.image = new Image[program.imageNum];
    }
    std::cout << "image name: ";
    std::getline(std::cin, program.input);
    program.image[(program.imageNum - 1)].name = program.input;
    program.image[(program.imageNum - 1)].path = program.sceneImagePath;
    if(program.image[(program.imageNum - 1)].path[program.image[(program.imageNum - 1)].path.size() - 1] == 'g')
	convertImage(program.image[program.imageNum - 1]);
    program.readFile.open(program.sceneImagePath.c_str(), std::ios::in | std::ios::binary | std::ios::beg);
	program.memblock = new char[sizeof(uint16_t)];
	program.readFile.read(program.memblock, sizeof(uint16_t));
	program.image[(program.imageNum - 1)].w = (uint16_t)program.memblock;
	program.readFile.read(program.memblock, sizeof(uint16_t));
	program.image[(program.imageNum - 1)].h = (uint16_t)program.memblock;
	delete[] program.memblock;
    program.readFile.close();
    program.readFile.clear();
}
