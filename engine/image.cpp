#include "image.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

void setupImage(std::ifstream &file, std:string &input, Image &image) {
    std::getline(file, image.name);
    std::getline(file, image.path);
    std::getline(file, input);
    image.w = atoi(input.c_str());
    std::getline(file, input);
    image.h = atoi(input.c_str());
}