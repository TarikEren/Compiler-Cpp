cmake_minimum_required(VERSION 3.22)
project(Lexer_Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lexer_Cpp main.cpp
        src/Token.cpp
        include/Token.hpp
        src/Lexer.cpp
        include/Lexer.hpp
        include/Macros.hpp
)
