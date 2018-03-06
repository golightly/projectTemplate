#pragma once

#include <string>
#include "image.h"

struct Font {
  Image* character;
};

void setupFont(std::string* path);
