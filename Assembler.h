//
// Created by taojianping on 2019/12/5.
//

#ifndef HACKASSEMBLER_ASSEMBLER_H
#define HACKASSEMBLER_ASSEMBLER_H


#include <string>
#include <fstream>

class Assembler {
    std::ofstream _outPutFile;
public:
    void translate(const std::string& path);
    void WriteData(const std::string& data);
    void InitWriteFile(const std::string& path);
    void CloseFile();

};


#endif //HACKASSEMBLER_ASSEMBLER_H
