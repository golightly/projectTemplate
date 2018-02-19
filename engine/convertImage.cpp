#include "convertImage.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include "image.h"
#include "program.h"

void convertImage(Image &image) {
	std::string getInput;
	std::string arg = "python writeFile.py ";
	arg += image.path;
	LPCTSTR argument = arg.c_str();
	ShellExecute(NULL, "open", "cmd.exe", argument, NULL, SW_SHOWNORMAL);
	while (getInput != "done") {
		std::cout << "input 'done' when finished: ";
		std::cin >> getInput;
	}
	image.path[image.path.size() - 3] = 'a';
	image.path[image.path.size() - 2] = 'r';
	image.path[image.path.size() - 1] = 't';
}