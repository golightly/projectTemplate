#pragma once

#include <string>
#include <fstream>

struct Image {
    std::string name, path;
    int w, h;
};

void setupImage(std::ifstream &file, std::string &input, Image &image);