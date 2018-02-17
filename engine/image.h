#pragma once

#include <string>
#include <fstream>
#include <cstdint>
#include "program.h"

struct Image {
    std::string name, path;
    uint16_t w, h;
};

void setupImage(Program &program, Image &image);

//convert the inital image reader to also get the width and height from the image file
//using binary reading