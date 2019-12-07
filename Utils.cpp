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

bool Utils::IsNumber(const std::string& str) {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
    // c++ 11
    // return !str.empty() && std::find_if(str.begin(),
    //                                   str.end(), [](char c) { return !std::isdigit(c); }) == str.end();
}

