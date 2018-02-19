#include "image.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "program.h"

void setupImage(Program &program, Image &image) {
    std::getline(program.readFile, image.name);
    std::getline(program.readFile, image.path);
    program.readFile.close();
    program.readFile.clear();
    program.readFile.open(image.path, std::ios::in | std::ios::binary | std::ios::beg);
	program.memblock = new char[sizeof(uint16_t)];
    program.readFile.read(program.memblock, sizeof(uint16_t));
	image.w = (uint16_t)program.memblock;
    program.readFile.read(program.memblock, sizeof(uint16_t));
	image.h = (uint16_t)program.memblock;
    program.readFile.close();
    program.readFile.clear();
}