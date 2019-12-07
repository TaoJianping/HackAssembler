//
// Created by taojianping on 2019/12/5.
//

#include <iostream>
#include "Assembler.h"
#include "Parser.h"
#include "Utils.h"
#include "Code.h"
#include "SymbolTable.h"

void Assembler::translate(const std::string &path) {
    auto parser = new Parser(path);
    auto code = new Code();
    auto symbolTable = new SymbolTable();
    InitWriteFile("OutPut.hack");
    int64_t row = 0;
    while (parser->hasMoreCommands()) {
        parser->advance();
        if (!parser->IsInvalidCommand()) {
            if (parser->commandType() == CommandType::L_COMMAND) {
                auto label = parser->symbol();
                if (!symbolTable->contains(label)) {
                    symbolTable->AddLabel(label, row);
                }
            } else {
//                if (parser->commandType() == CommandType::A_COMMAND) {
//                    if (parser->isVariable()) {
//                        symbolTable->AddVariable(parser->symbol());
//                    }
//                }
                row += 1;
            }
        }
    }
    parser->reset();
    while (parser->hasMoreCommands()) {
        parser->advance();
        if (!parser->IsInvalidCommand() && !(parser->commandType() == CommandType::L_COMMAND)) {
            std::string instruction;
            if (parser->commandType() == CommandType::A_COMMAND) {
                auto address = parser->symbol();
                if (Utils::IsNumber(address)) {
                    auto value = std::stoi(address);
                    auto bit = Utils::ConvertToBitFormat(value);
                    instruction = "0" + bit;
                } else {
                    auto isLabel = symbolTable->ContainLabel(address);
                    if (isLabel) {
                        auto value = symbolTable->GetAddress(address);
                        auto bit = Utils::ConvertToBitFormat(value);
                        instruction = "0" + bit;
                    } else {
                        if (!symbolTable->contains(address)) {
                            symbolTable->AddVariable(address);
                        }
                        auto value = symbolTable->GetAddress(address);
                        auto bit = Utils::ConvertToBitFormat(value);
                        instruction = "0" + bit;
                    }
                }
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
            } else if (parser->commandType() == CommandType::L_COMMAND) {

            }
            WriteData(instruction);
            row += 1;
        }
    }
    CloseFile();
}

void Assembler::WriteData(const std::string &data) {
    _outPutFile << data << std::endl;
}

void Assembler::InitWriteFile(const std::string &path) {
    _outPutFile.open(path);
}

void Assembler::CloseFile() {
    _outPutFile.close();
}
