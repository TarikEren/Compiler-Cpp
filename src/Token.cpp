#include "../include/Token.hpp"

Token::Token(std::optional<string> value, TokenType token_type) {
    this->m_value = std::move(value);
    this->m_token_type = token_type;
}


Token::~Token() = default;