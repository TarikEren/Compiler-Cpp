#include "../include/Token.hpp"

string Token::get_TokenStr() const {
    return this->m_token_str;
}

[[maybe_unused]] int Token::get_tokenType() const {
    return this->m_token_type;
}

[[maybe_unused]] void Token::set_tokenStr(const string &str) {
    this->m_token_str = str;
}

[[maybe_unused]] void Token::set_tokenType(int type) {
    this->m_token_type = type;
}

[[maybe_unused]] void Token::clear_tokenStr() {
    this->m_token_str.clear();
}

[[maybe_unused]] void Token::clear_tokenType() {
    this->m_token_type = -1;
}

Token::Token(string token_str, int token_type) {
    this->m_token_str = std::move(token_str);
    this->m_token_type = token_type;
    string token_type_str = tokenType_to_string();
}

[[maybe_unused]] Token::Token(const Token &token_obj) {
    this->m_token_type = token_obj.m_token_type;
    this->m_token_str = token_obj.m_token_str;
}

Token::~Token() {
    this->m_token_str.clear();
    this->m_token_type = 0;
}
