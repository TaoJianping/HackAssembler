//
// Created by taojianping on 2019/12/4.
//

#ifndef HACKASSEMBLER_PARSER_H
#define HACKASSEMBLER_PARSER_H


#include <string>
#include <fstream>
#include "Defines.h"

class Parser {
private:
    std::string _currentCommand;
    std::ifstream _fileStream;
public:
    explicit Parser(const std::string& path);
    bool hasMoreCommands();
    void advance();
    CommandType commandType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();
    std::string exportCurrentCommand();
    bool IsInvalidCommand();
    static bool IsComment(std::string);
    static std::string remove_ws(const std::string& str);
    void reset();
    bool ContainDest();
    std::string ConcatenateCInstruction(const std::string& dest, const std::string& comp, const std::string& jump);
};


#endif //HACKASSEMBLER_PARSER_H
