//
// Created by taojianping on 2019/12/4.
//

#ifndef HACKASSEMBLER_SYMBOLTABLE_H
#define HACKASSEMBLER_SYMBOLTABLE_H


#include <map>


class SymbolTable {
private:
    std::map<std::string, int> _container;
public:
    SymbolTable();
    void AddEntry(std::string symbol, int address);
    bool contains(std::string symbol);
    int GetAddress(std::string symbol);
};


#endif //HACKASSEMBLER_SYMBOLTABLE_H
