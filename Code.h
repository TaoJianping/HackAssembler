//
// Created by taojianping on 2019/12/4.
//

#ifndef HACKASSEMBLER_CODE_H
#define HACKASSEMBLER_CODE_H


#include <string>

class Code {
public:
    std::string Dest(const std::string& mnemonic);
    std::string Comp(const std::string& mnemonic);
    std::string Jump(const std::string& mnemonic);
};


#endif //HACKASSEMBLER_CODE_H
