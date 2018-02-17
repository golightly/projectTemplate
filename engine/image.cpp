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
    program.readFile.open(image.path, std::ios | std::ios::binary | std::ios::beg);
    program.readFile.read(image.w, sizeof(uint16_t));
    program.readFile.read(image.h, sizeof(uint16_t));
    program.readFile.close();
    program.readFile.clear();
}