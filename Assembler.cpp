//
// Created by taojianping on 2019/12/5.
//

#include <iostream>
#include "Assembler.h"
#include "Parser.h"
#include "Utils.h"
#include "Code.h"

void Assembler::translate(const std::string &path) {
    auto parser = new Parser(path);
    auto code = new Code();
    InitWriteFile("OutPut.hack");
    while (parser->hasMoreCommands()) {
        parser->advance();
        if (!parser->IsInvalidCommand()) {
            std::string instruction;
            if (parser->commandType() == CommandType::A_COMMAND) {
                auto address = parser->symbol();
                auto value = std::stoi(address);
                auto bit = Utils::ConvertToBitFormat(value);
                instruction = "0" + bit;
            } else if (parser->commandType() == CommandType::C_COMMAND) {
                std::string dest;
                std::string comp;
                std::string jump;
                if (parser->ContainDest()) {
                    dest = code->Dest(parser->dest());
                    comp = code->Comp(parser->comp());
                    jump = "000";
                } else {
                    dest = "000";
                    comp = code->Comp(parser->comp());
                    jump = code->Jump(parser->jump());
                }
                instruction = parser->ConcatenateCInstruction(dest, comp, jump);
            }
            WriteData(instruction);
        }
    }
    CloseFile();
}

void Assembler::WriteData(const std::string& data) {
    _outPutFile << data << std::endl;
}

void Assembler::InitWriteFile(const std::string& path) {
    _outPutFile.open(path);
}

void Assembler::CloseFile() {
    _outPutFile.close();
}
