cmake_minimum_required(VERSION 3.22)
project(better_lexer_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(better_lexer_cpp main.cpp
        src/Tokenizer.cpp
        src/Token.cpp
        include/Token.hpp
        include/Tokenizer.hpp
        include/Macros.hpp)
