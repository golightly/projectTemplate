#pragma once

#include <string>
#include "image.h"

struct Font {
  Image* character;
};

void setupFont(Font &font, std::string* path, int pathNum);
