cmake_minimum_required(VERSION 3.15)
project(HackAssembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(HackAssembler main.cpp Parser.cpp Parser.h Code.cpp Code.h SymbolTable.cpp SymbolTable.h Defines.h Assembler.cpp Assembler.h Utils.cpp Utils.h UnitTest.cpp UnitTest.h)
