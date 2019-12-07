//
// Created by taojianping on 2019/12/6.
//

#include <bitset>
#include <iostream>
#include "Utils.h"


std::string Utils::ConvertToBitFormat(int value) {
    std::string binary = std::bitset<15>(value).to_string(); //to binary
//    unsigned long decimal = std::bitset<8>(binary).to_ulong();
//    std::cout<<decimal<<"\n";
    return binary;
}

bool Utils::StringContains(const std::string& source, const std::string& c) {
    return source.find(c) != std::string::npos;
}

