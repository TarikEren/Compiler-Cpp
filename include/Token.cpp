#include "Token.hpp"

string Token::get_TokenStr() const {
    return this->token_str;
}

[[maybe_unused]] int Token::get_tokenType() const {
    return this->token_type;
}

[[maybe_unused]] void Token::set_tokenStr(const string &str) {
    this->token_str = str;
}

[[maybe_unused]] void Token::set_tokenType(int type) {
    this->token_type = type;
}

[[maybe_unused]] void Token::clear_tokenStr() {
    this->token_str.clear();
}

[[maybe_unused]] void Token::clear_tokenType() {
    this->token_type = -1;
}

Token::Token(string token_str, int token_type) {
    this->token_str = std::move(token_str);
    this->token_type = token_type;
    string token_type_str = tokenType_to_string();
}

[[maybe_unused]] Token::Token(const Token &token_obj) {
    this->token_type = token_obj.token_type;
    this->token_str = token_obj.token_str;
}

Token::Token() {
    std::cout << "Initialised token\n";
}

Token::~Token() {
    this->token_str.clear();
    this->token_type = 0;
}

