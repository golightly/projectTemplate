#include "image.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "program.h"

//sets up one image at a time
void setupImage(Program &program, Image &image) {
    std::getline(program.readFile, image.name);
    std::getline(program.readFile, image.path);
    std::ifstream readFile;
    readFile.open(image.path, std::ios::in | std::ios::binary | std::ios::beg);
    program.memblock = new char[sizeof(uint16_t)];
    readFile.read(program.memblock, sizeof(uint16_t));
    image.w = (uint16_t)program.memblock;
    readFile.read(program.memblock, sizeof(uint16_t));
    image.h = (uint16_t)program.memblock;
    delete [] program.memblock;
    readFile.close();
    readFile.clear();
}
