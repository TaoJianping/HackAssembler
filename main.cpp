#include <iostream>
#include "Assembler.h"
#include "UnitTest.h"

int main() {
    auto assembler = new Assembler();
    std::string path =  "Add.asm";
    assembler->translate(path);
    return 0;
}
