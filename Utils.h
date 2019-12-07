//
// Created by taojianping on 2019/12/6.
//

#ifndef HACKASSEMBLER_UTILS_H
#define HACKASSEMBLER_UTILS_H


#include <string>

class Utils {
public:
    static std::string ConvertToBitFormat(int value);
    static bool StringContains(const std::string& source, const std::string& c);
};


#endif //HACKASSEMBLER_UTILS_H
