#include "listSceneImage.h"
#include <string>
#include <fstream>
#include <Windows.h>
#include "program.h"
#include "scene.h"
#include "image.h"

void listSceneImage(Program &program) {
    if(program.input == "list-scene") {
        if(program.sceneNum < 20) {
            for(int a = 0; a < program.sceneNum; ++a) {
                std::cout << a << ": " << program.sceneName[a] << std::endl;
            }
        }
        else if(program.sceneNum >= 20) {
            program.writeFile.open("list.txt");
            for(int a = 0; a < program.sceneNum; ++a) {
                program.writeFile << a << ": " << program.sceneName[a] << "\n";
            }
            program.writeFile.close();
            program.writeFile.clear();
            ShellExecute(NULL, "open", "list.exe", NULL, NULL, SW_SHOWNORMAL); //this might need testing
        }
    }
    else if(program.input == "list-image") {
        if(program.imageNum < 20) {
            for(int a = 0; a < program.imageNum; ++a) {
                std::cout << a << ": " << program.image[a].name << std::endl;
                std::cout << "\t" << program.image[a].path << std::endl;
            }
        }
        else if(program.imageNum >= 20) {
            program.writeFile.open("list.txt");
            for(int a = 0; a < program.imageNum; ++a) {
                program.writeFile << a << ": " << program.image[a].name << "\n";
                program.writeFile << "\t" << program.image[a].path << "\n";
            }
            program.writeFile.close();
            program.writeFile.clear();
            ShellExecute(NULL, "open", "list.exe", NULL, NULL, SW_SHOWNORMAL); //this might need testing
        }
    }
}