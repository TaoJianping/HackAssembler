//
// Created by taojianping on 2019/12/4.
//

#include "Parser.h"
#include "Utils.h"
#include <fstream>

bool has_suffix(const std::string &str, const std::string &suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

Parser::Parser(const std::string &path) {
    _fileStream.open(path.c_str(), std::ios::in);
}

void Parser::advance() {
    std::string tmp;
    std::getline(_fileStream, tmp);
    tmp = remove_ws(tmp);
    _currentCommand = removeComment(tmp);
}

bool Parser::hasMoreCommands() {
    return !_fileStream.eof();
}

CommandType Parser::commandType() {
    if (has_suffix(_currentCommand, ")")) {
        return CommandType::L_COMMAND;
    } else if (_currentCommand.compare(0, 1, "@") == 0) {
        return CommandType::A_COMMAND;
    } else {
        return CommandType::C_COMMAND;
    }
}

std::string Parser::symbol() {
    if (commandType() == CommandType::A_COMMAND) {
        return _currentCommand.substr(1);
    } else if (commandType() == CommandType::L_COMMAND) {
        return _currentCommand.substr(1, _currentCommand.size() - 2);
    } else {
        throw std::runtime_error("Parser::symbol() function not detect right CommandType");
    }
}

std::string Parser::dest() {
    if (commandType() == CommandType::C_COMMAND) {
        int len = 0;
        for (char &c : _currentCommand) {
            if (c == '=') {
                break;
            }
            len += 1;
        }
        if (len == _currentCommand.size()) {
            return "null";
        }
        return _currentCommand.substr(0, len);
    }
    throw std::runtime_error("Parser::dest() invalid command");
}

std::string Parser::comp() {
    if (commandType() == CommandType::C_COMMAND) {
        if (_currentCommand.find(';') != std::string::npos) {
            int len = 0;
            for (char &c : _currentCommand) {
                if (c == ';') {
                    break;
                }
                len += 1;
            }
            if (len == _currentCommand.size()) {
                return "null";
            }
            return _currentCommand.substr(0, len);
        } else {
            int pos = 0;
            for (char &c : _currentCommand) {
                if (c == '=') {
                    break;
                }
                pos += 1;
            }
            if (pos == _currentCommand.size()) {
                return "null";
            }
            return _currentCommand.substr(pos+1, _currentCommand.size());
        }
    }
    throw std::runtime_error("Parser::comp() invalid command");
}

std::string Parser::jump() {
    if (commandType() == CommandType::C_COMMAND) {
        int pos = 1;
        for (char &c : _currentCommand) {
            if (c == ';') {
                break;
            }
            pos += 1;
        }
        if (pos == _currentCommand.size()) {
            return "null";
        }
        return _currentCommand.substr(pos, _currentCommand.size());
    }
    throw std::runtime_error("Parser::jump() invalid command");
}

std::string Parser::exportCurrentCommand() {
    return _currentCommand;
}

std::string Parser::remove_ws( const std::string& str )
{
    std::string str_no_ws ;
    for( char c : str ) if( !std::isspace(c) ) str_no_ws += c ;
    return str_no_ws ;
}

bool Parser::IsInvalidCommand() {
    return _currentCommand == "\n" || IsComment(_currentCommand) || _currentCommand.empty();
}

bool Parser::IsComment(std::string str) {
    if (str.size() >= 2) {
        if (str[0] == '/' && str[1] == '/') {
            return true;
        }
    }
    return false;
}

void Parser::reset() {
    _fileStream.clear();                 // clear fail and eof bits
    _fileStream.seekg(0, std::ios::beg); // back to the start!
}

bool Parser::ContainDest() {
    return Utils::StringContains(_currentCommand, "=");
}

std::string Parser::ConcatenateCInstruction(const std::string& dest, const std::string& comp, const std::string& jump) {
    return "111" + comp + dest + jump;
}

std::string Parser::removeComment(const std::string& str) {
    int pos = str.find("//");
    if (pos!=std::string::npos) {
        return str.substr(0, pos);
    } else {
        return str;
    }
}

bool Parser::isVariable() {
    auto variable = symbol();
    return isupper(variable[0]) == 0 && !(Utils::StringContains(variable, ".")) && !(Utils::IsNumber(variable));
};

bool Parser::isLabel() {
    auto variable = symbol();
    return isupper(variable[0]) != 0 || Utils::StringContains(variable, ".");
};

