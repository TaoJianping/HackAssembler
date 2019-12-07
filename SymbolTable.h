//
// Created by taojianping on 2019/12/4.
//

#ifndef HACKASSEMBLER_SYMBOLTABLE_H
#define HACKASSEMBLER_SYMBOLTABLE_H


#include <map>
#include <vector>


class SymbolTable {
private:
    int64_t BaseAddress = 16;
    std::map<std::string, int64_t> _container;
    std::vector<std::string>* _labels;
public:
    SymbolTable();
    void AddEntry(const std::string& symbol, int64_t address);
    bool contains(const std::string& symbol);
    int GetAddress(const std::string& symbol);
    void AddVariable(const std::string& symbol);
    void AddLabel(const std::string& symbol, int64_t address);
    bool ContainLabel(const std::string& symbol);
};


#endif //HACKASSEMBLER_SYMBOLTABLE_H
