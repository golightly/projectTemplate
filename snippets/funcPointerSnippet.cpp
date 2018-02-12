#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>

typedef void (*FunctionPointer) ();

struct FuncPointer {
	std::string id;
	FunctionPointer pointer;
};

void testFunction() {
	std::cout << "function runs" << std::endl;
}

void testFunction2() {
	std::cout << "this one too" << std::endl;
}

void runFunction(const char* name, FuncPointer* funcPointer, int &sceneNum) {
	for (int a = 0; a < sceneNum; ++a) {
		if (funcPointer[a].id == name) {
			funcPointer[a].pointer();
			a = sceneNum;
		}
	}
}

int main(int argc, char* args[]) {
	int sceneNum = 2;
	FuncPointer* funcPointer = new FuncPointer[sceneNum];
	funcPointer[0].id = "testFunction";
	funcPointer[0].pointer = &testFunction;
	funcPointer[1].id = "testFunction2";
	funcPointer[1].pointer = &testFunction2;
	runFunction("testFunction", funcPointer, sceneNum);
	runFunction("testFunction2", funcPointer, sceneNum);
	delete[] funcPointer;
	char input;
	std::cin >> input;
	return 0;
}