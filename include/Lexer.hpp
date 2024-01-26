#ifndef LEXER_CPP_LEXER_HPP
#define LEXER_CPP_LEXER_HPP

#include "Token.hpp"
#include <fstream>
#include <sstream>

using fstream = std::fstream;
using sstream = std::stringstream;


class Lexer {
private:
    string file_str;
    Token** array = nullptr;
    int size = 0;
public:
    Lexer();
    void append_token(Token*);
    [[maybe_unused]] void pop(); //Might pop the array one by one as I iterate through it, IDK I haven't done this before.
    void print_tokens();
    [[maybe_unused]] void set_fileStr(string&);
    string get_fileStr();
    void clean();
    //Implement
    char peek();
    void consume(); //I don't know how to add this.
    ~Lexer();
    void tokenize();
    bool read_file(const char*);

};

#endif //LEXER_CPP_LEXER_HPP


//TOKEN: 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