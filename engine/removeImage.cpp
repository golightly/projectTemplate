#include "removeImage.h"
#include <stdlib.h>
#include <fstream>
#include "program.h"
#include "image.h"

void removeImage(Program &program) {
    --program.imageNum;
    Image* temp = new Image[program.imageNum];
    int b = 0;
    for(int a = 0; a <= program.imageNum; ++a) {
        if(!a == atoi(program.sceneImagePath.c_str())) {
            temp[b].name = program.image[a].name;
            temp[b].path = program.image[a].path;
            temp[b].w = program.image[a].w;
            temp[b].h = program.image[a].h;
            ++b;
        }
    }
    delete program.image;
    program.image = new Image [program.imageNum];
    for(int a = 0; a < program.imageNum; ++a) {
        program.image[a].name = temp[a].name;
        program.image[a].path = temp[a].path;
        program.image[a].w = temp[a].w;
        program.image[a].h = temp[a].h;
    }
    //call the save function here, except tell it to omit that one image IMPORTANT
}

//this is not finished! have to remove it from the program file also.  give option to delete image