//
// Created by taojianping on 2019/12/4.
//

#include <iostream>
#include "Code.h"
#include "Defines.h"

std::string Code::Comp(const std::string& mnemonic) {
    if (CompTable.count(mnemonic) > 0) {
        return CompTable.at(mnemonic);
    }
    std::cout << "This mnemonic not find => " << mnemonic << std::endl;
    throw std::runtime_error("Not Find Instruction in Code::Comp");
}

std::string Code::Dest(const std::string& mnemonic) {
    if (DestTable.count(mnemonic) > 0) {
        return DestTable.at(mnemonic);
    }
    std::cout << "This mnemonic not find => " << mnemonic << std::endl;
    throw std::runtime_error("Not Find Instruction in Code::Dest");
}

std::string Code::Jump(const std::string& mnemonic) {
    if (JumpTable.count(mnemonic) > 0) {
        return JumpTable.at(mnemonic);
    }
    std::cout << "This mnemonic not find => " << mnemonic << std::endl;
    throw std::runtime_error("Not Find Instruction in Code::JumpTable");
}
