#pragma once

#include "Token.hpp"
#include <fstream>
#include <sstream>

//C++ namespaces are sometimes a nuisance
using ifstream = std::ifstream;
using sstream = std::stringstream;


class Tokenizer {
private:

    //File contents
    string m_file_str;

    //----Array properties----
    //Array itself
    Token** m_array = nullptr;
    //Array's length
    size_t m_array_size = 0;

    //--Iterator properties---
    //Current character
    char m_current = ' ';
    //Current Index
    size_t m_current_index = 0;
    //Buffer to search and append tokens.
    string m_buffer;

public:

    //Initialises a tokenizer object
    Tokenizer();

    //Appends a Token pointer
    void append_token(Token*);

    //Iterates through the m_array and deletes members one by one
    //Cleans m_buffer and m_file_str variables
    //Sets the m_current_index and m_array_size variables to 0
    //Deletes m_array
    void clean();

    //Iterates through the token m_array and prints the tokens within said m_array.
    void print_tokens();

    //Returns the next character from a string. If the next index is a null terminator, it returns the same character.
    char peek();

    //Increases the index by one and sets the m_current variable to the corresponding character in the m_file_str string.
    void consume();

    //Decreases the index by one and sets the m_current variable to the corresponding character in the m_file_str string.
    void step_back();

    //Destructor. Calls the clear function and notifies the user that the tokenizer has been destructed.
    ~Tokenizer();

    //Iterates through the m_file_str character by character and buffers said characters.
    //Compares the buffer to the tokens that are listed in the Token.hpp file and finds tokens.
    //When it encounters any tokens, it appends them to the token array, m_array.
    void tokenize();

    //Reads the provided file and initialises the m_file_str variable using the file contents.
    void read_file(const char* filename);

    //Removes a Token pointer from the token m_array
    [[maybe_unused]] void pop(); //Might pop the m_array one by one as I iterate through it, IDK I haven't done this before.

    //Sets the m_file_str variable using the value that was passed through the function.
    [[maybe_unused]] void set_fileStr(string&);

    //Returns the m_file_str variable.
    [[maybe_unused]] string get_fileStr();
};
