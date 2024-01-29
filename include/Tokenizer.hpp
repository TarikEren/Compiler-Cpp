#pragma once

#include "Token.hpp"
#include <fstream>
#include <sstream>

using ifstream = std::ifstream;
using sstream = std::stringstream;


class Tokenizer {
private:
    //File properties
    string file_str;

    //Array properties
    Token** array = nullptr;
    size_t array_size = 0;

    //Iterator properties
    char current = ' ';
    size_t current_index = 0;
    string buffer;

public:
    Tokenizer();
    void append_token(Token*);
    [[maybe_unused]] void pop(); //Might pop the array one by one as I iterate through it, IDK I haven't done this before.
    void print_tokens();
    [[maybe_unused]] void set_fileStr(string&);

    [[maybe_unused]] string get_fileStr();
    void clean();
    //Implement
    char peek();
    void consume();
    void step_back();
    ~Tokenizer();
    void tokenize();
    void read_file(const char* filename);

};
