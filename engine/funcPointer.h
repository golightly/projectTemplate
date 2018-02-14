#pragma once

#include <string>

typedef void (*FunctionPointer) ();

struct FuncPointer {
    std::string id;
    FunctionPointer pointer;
};