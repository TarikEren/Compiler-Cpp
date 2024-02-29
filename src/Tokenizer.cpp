#include "../include/Tokenizer.hpp"

Tokenizer::Tokenizer()  {
    this->m_array = (Token**)malloc(sizeof(Token) * this->m_array_size);
}

void Tokenizer::append_token(Token *new_token)  {
    this->m_array_size++;
    this->m_array = (Token**)realloc(this->m_array, sizeof(Token*) * this->m_array_size);
    this->m_array[this->m_array_size - 1] = new_token;
}

void Tokenizer::print_tokens()  {
    std::cout << "------Tokens Start-------\n";
    string token_str;
    for (size_t i = 0; i < this->m_array_size; i++) {
        std::cout << this->m_array[i]->tokenType_to_string() << std::endl;
    }
    std::cout << "--------Tokens End--------\n";
}

void Tokenizer::clean()  {
    for (int i = 0; i < this->m_array_size; i++) {
        delete m_array[i];
    }
    this->m_current = 0;
    this->m_current_index = 0;
    this->m_array_size = 0;
    this->m_file_str.clear();
    this->m_buffer.clear();
    free(this->m_array);
}

Tokenizer::~Tokenizer()  {
    clean();
}

void Tokenizer::tokenize()  {
    this->m_current = this->m_file_str[this->m_current_index];
    char next;

    while (m_current != '\0' && this->m_current_index != this->m_file_str.length()) {
        if (m_current == '(') {
            auto new_token = new Token(std::nullopt, TOKEN_LPAR);
            append_token(new_token);
        }
        else if (m_current == ')') {
            auto new_token =  new Token(std::nullopt, TOKEN_RPAR);
            append_token(new_token);
        }
        else if (m_current == '{') {
            auto new_token = new Token(std::nullopt, TOKEN_LBRA);
            append_token(new_token);
        }
        else if (m_current == '}') {
            auto new_token = new Token(std::nullopt, TOKEN_RBRA);
            append_token(new_token);
        }
        else if (m_current == ';') {
            auto new_token = new Token(std::nullopt, TOKEN_SEMI);
            append_token(new_token);
        }
        else if (m_current == '=') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token(std::nullopt, TOKEN_IS);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_EQ);
                append_token(new_token);
            }
        }
        else if (m_current == '>') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token(std::nullopt, TOKEN_GEQ);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_GD);
                append_token(new_token);
            }
        }
        else if (m_current == '<') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token(std::nullopt, TOKEN_LEQ);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_LD);
                append_token(new_token);
            }
        }
        else if (m_current == '+') {
            next = peek();
            if (next == '+') {
                auto new_token = new Token(std::nullopt, TOKEN_INC);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_PLU);
                append_token(new_token);
            }
        }
        else if (m_current == '-') {
            next = peek();
            if (next == '-') {
                auto new_token = new Token(std::nullopt, TOKEN_DEC);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_MIN);
                append_token(new_token);
            }
        }
        else if (m_current == '/') {
            next = peek();
            if (next == '/') {
                auto new_token = new Token(std::nullopt, TOKEN_COMMENT);
                append_token(new_token);
                while (m_current != '\n') {
                    consume();
                }
            }
            else if (next == '*') {
                auto new_token = new Token(std::nullopt, TOKEN_COMM_ST);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_SLA);
                append_token(new_token);
            }
        }
        else if (m_current == '%') {
            auto new_token = new Token(std::nullopt, TOKEN_MOD);
            append_token(new_token);
        }
        else if (m_current == '*') {
            next = peek();
            if (next == '/') {
                auto new_token = new Token(std::nullopt, TOKEN_COMM_END);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_STAR);
                append_token(new_token);
            }
        }
        else if (m_current == '&') {
            next = peek();
            if (next == '&') {
                auto new_token = new Token(std::nullopt, TOKEN_AND);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_AMP);
                append_token(new_token);
            }
        }
        else if (m_current == ':') {
            auto new_token = new Token(std::nullopt, TOKEN_COL);
            append_token(new_token);
        }
        else if (m_current == '"') {
            auto new_token = new Token(std::nullopt, TOKEN_QUOT);
            append_token(new_token);
        }
        else if (m_current == '!') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token(std::nullopt, TOKEN_NOT);
                append_token(new_token);
                consume();
            }
            else if (next == '|') {
                auto new_token = new Token("TOKEN_NOR", TOKEN_NOR);
                append_token(new_token);
                consume();
            }
            else if (next == '&') {
                auto new_token = new Token("TOKEN_NAND", TOKEN_NAND);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token("TOKEN_BANG", TOKEN_BANG);
                append_token(new_token);
            }
        }
        else if (m_current == '\'') {
            auto new_token = new Token(std::nullopt, TOKEN_SQUO);
            append_token(new_token);
        }
        else if (m_current == ',') {
            auto new_token = new Token(std::nullopt, TOKEN_COM);
            append_token(new_token);
        }
        else if (m_current == '|') {
            next = peek();
            if (next == '|') {
                auto new_token = new Token(std::nullopt, TOKEN_OR);
                append_token(new_token);
                consume();
            }
            else {
                auto new_token = new Token(std::nullopt, TOKEN_PIPE);
                append_token(new_token);
            }
        }
        else if (isalnum(m_current)) {
            while (isalpha(m_current)) {
                this->m_buffer.push_back(m_current);
                consume();
            }

            while (isdigit(m_current)) {
                this->m_buffer.push_back(m_current);
                consume();
            }
            if (this->m_buffer == "int") {
                auto new_token = new Token(std::nullopt, TOKEN_INT);
                append_token(new_token);
            }
            else if (this->m_buffer == "return") {
                auto new_token = new Token(std::nullopt, TOKEN_RET);
                append_token(new_token);
            }
            else if (this->m_buffer == "var") {
                auto new_token = new Token(std::nullopt, TOKEN_VAR);
                append_token(new_token);
            }
            else if (this->m_buffer == "char") {
                auto new_token = new Token(std::nullopt, TOKEN_CHAR);
                append_token(new_token);
            }
            else if (this->m_buffer == "float") {
                auto new_token = new Token(std::nullopt, TOKEN_FLO);
                append_token(new_token);
            }
            else if (this->m_buffer == "bool") {
                auto new_token = new Token(std::nullopt, TOKEN_BOOL);
                append_token(new_token);
            }
            else if (this->m_buffer == "void") {
                auto new_token = new Token(std::nullopt, TOKEN_VOID);
                append_token(new_token);
            }
            else if (this->m_buffer == "if") {
                auto new_token = new Token(std::nullopt, TOKEN_IF);
                append_token(new_token);
            }
            else if (this->m_buffer == "elif") {
                auto new_token = new Token(std::nullopt, TOKEN_ELIF);
                append_token(new_token);
            }
            else if (this->m_buffer == "else") {
                auto new_token = new Token(std::nullopt, TOKEN_ELSE);
                append_token(new_token);
            }
            else if (this->m_buffer == "do") {
                auto new_token = new Token(std::nullopt, TOKEN_DO);
                append_token(new_token);
            }
            else if (this->m_buffer == "while") {
                auto new_token = new Token(std::nullopt, TOKEN_WHI);
                append_token(new_token);
            }
            else if (this->m_buffer == "fun") {
                auto new_token = new Token(std::nullopt, TOKEN_FUN);
                append_token(new_token);
            }
            else if (this->m_buffer == "switch") {
                auto new_token = new Token(std::nullopt, TOKEN_SWI);
                append_token(new_token);
            }
            else if (this->m_buffer == "case") {
                auto new_token = new Token(std::nullopt, TOKEN_CAS);
                append_token(new_token);
            }
            else if (this->m_buffer == "const") {
                auto new_token = new Token(std::nullopt, TOKEN_CONS);
                append_token(new_token);
            }
            else if (this->m_buffer == "continue") {
                auto new_token = new Token(std::nullopt, TOKEN_CONT);
                append_token(new_token);
            }

                //Change
            else {
                auto new_token = new Token(m_buffer, TOKEN_LIT);
                append_token(new_token);
            }
            step_back();
            this->m_buffer.clear();
        }

        consume();
    }
    auto new_token = new Token(std::nullopt, TOKEN_EOF);
    append_token(new_token);
}

char Tokenizer::peek() {
    if (this->m_current_index < this->m_file_str.size()) {
        return this->m_file_str[this->m_current_index + 1];
    }
    else return this->m_file_str[this->m_current_index];
}

void Tokenizer::consume() {
    this->m_current_index++;
    this->m_current = this->m_file_str[this->m_current_index];
}

void Tokenizer::step_back() {
    this->m_current_index--;
    this->m_current = this->m_file_str[this->m_current_index];
}

void Tokenizer::read_file(const char *filename)  {
    ifstream file;
    file.open(filename, std::ios::in);
    string contents;
    sstream str_stream;

    str_stream << file.rdbuf();

    contents = str_stream.str();
    this->m_file_str = contents;
    file.close();
}