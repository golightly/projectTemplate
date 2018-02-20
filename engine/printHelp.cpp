#include "printHelp.h"
#include <iostream>

void printHelp() {
    std::cout << "list-scene: lists scene names" << std::endl;
    std::cout << "list-image: lists image names and paths" << std::endl;
    std::cout << "add-image-<path>: adds image from the specified path" << std::endl;
    std::cout << "rm-image-<index number>: removes the image at this index of\n\tthe array and adjusts the array and image number" << std::endl;
    std::cout << "rm-scene-<index number>: likewise, for a scene" << std::endl;
    std::cout << "add-scene-<path>: asks for scene basic stuff and creates" << std::endl;
    std::cout << "exit: exits the program" << std::endl;
    std::cout << "save: saves project (scenes are saved in scene editor)" << std::endl;
    std::cout << "open-<scene index number>: opens scene in sdl window for editing" << std::endl;
}
