//
// Created by taojianping on 2019/12/5.
//

#include <iostream>
#include "Assembler.h"
#include "Parser.h"

void Assembler::translate(const std::string &path) {
    auto parser = new Parser(path);
    while (parser->hasMoreCommands()) {
        parser->advance();
        if (!parser->IsInvalidCommand()) {

        }
    }
}
