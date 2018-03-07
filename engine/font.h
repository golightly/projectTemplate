#pragma once

#include <string>
#include "charset.h"

struct Font { //restructure font as a set of character sets, each with 95 characters, filled in when the scene is initialised
  Charset* charset;
};
//setup one at a time
void setupFont(Font &font, std::string &path);
