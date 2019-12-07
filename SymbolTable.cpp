//
// Created by taojianping on 2019/12/4.
//

#include <iostream>
#include "SymbolTable.h"
#include <algorithm>

SymbolTable::SymbolTable() {
    _container["SP"] = 0;
    _container["LCL"] = 1;
    _container["ARG"] = 2;
    _container["THIS"] = 3;
    _container["THAT"] = 4;
    _container["R0"] = 0;
    _container["R1"] = 1;
    _container["R2"] = 2;
    _container["R3"] = 3;
    _container["R4"] = 4;
    _container["R5"] = 5;
    _container["R6"] = 6;
    _container["R7"] = 7;
    _container["R8"] = 8;
    _container["R9"] = 9;
    _container["R10"] = 10;
    _container["R11"] = 11;
    _container["R12"] = 12;
    _container["R13"] = 13;
    _container["R14"] = 14;
    _container["R15"] = 15;
    _container["SCREEN"] = 16384;
    _container["KBD"] = 24576;
    _labels = new std::vector<std::string>();
}

void SymbolTable::AddEntry(const std::string& symbol, int64_t address) {
    _container[symbol] = address;
}

bool SymbolTable::contains(const std::string& symbol) {
    return _container.count(symbol) > 0;
}

int SymbolTable::GetAddress(const std::string& symbol) {
    if (!contains(symbol)) {
        std::cout << "The symbol is => " << symbol << std::endl;
        throw std::runtime_error("SymbolTable::GetAddress function not detect right symbol");
    }
    return _container.at(symbol);
}

void SymbolTable::AddVariable(const std::string &symbol) {
    if (!contains(symbol)) {
        _container[symbol] = BaseAddress;
        BaseAddress += 1;
    }
}

void SymbolTable::AddLabel(const std::string &symbol, int64_t address) {
    _container[symbol] = address;
    _labels->push_back(symbol);
}

bool SymbolTable::ContainLabel(const std::string &symbol) {
    return std::find(_labels->begin(), _labels->end(), symbol) != _labels->end();
}
