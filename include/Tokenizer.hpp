#include "../include/Tokenizer.hpp"

Tokenizer::Tokenizer()  {
    std::cout << "Tokenizer initialised\n";
    this->m_array = (Token**)malloc(sizeof(Token) * this->m_array_size);
}

void Tokenizer::append_token(Token *new_token)  {
    this->m_array_size++;
    this->m_array = (Token**)realloc(this->m_array, sizeof(Token*) * this->m_array_size);
    this->m_array[this->m_array_size - 1] = new_token;
}

[[maybe_unused]] void Tokenizer::pop() {
    this->m_array_size--;
    this->m_array = (Token**)realloc(this->m_array, sizeof(Token) * this->m_array_size);
}

void Tokenizer::print_tokens()  {
    std::cout << "------Tokens Start-------\n";
    std::cout << "Name\t\t\tIndex\n";
    string token_str;
    for (int i = 0; i < this->m_array_size; i++) {
        token_str = this->m_array[i]->get_TokenStr();
        
        //I couldn't align token_eof, so I came up with this monstrosity.
        if (token_str == "TOKEN_EOF")
            std::cout << token_str << "\t\t" << i << std::endl;
        else
            std::cout << token_str << "\t" << i << std::endl;
    }
    std::cout << "--------Tokens End--------\n";
}

[[maybe_unused]] void Tokenizer::set_fileStr(string &fileStr)  {
    this->m_file_str = fileStr;
}

[[maybe_unused]] string Tokenizer::get_fileStr()  {
    return this->m_file_str;
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
    std::cout << "Tokenizer has been destructured\n";
}

void Tokenizer::tokenize()  {
    this->m_current = this->m_file_str[this->m_current_index];
    char next;

    while (m_current != '\0' && this->m_current_index != this->m_file_str.length()) {
        if (m_current == '(') {
            auto new_token = new Token("TOKEN_LPAR", TOKEN_LPAR);
            append_token(new_token);
        }
        else if (m_current == ')') {
            auto new_token =  new Token("TOKEN_RPAR", TOKEN_RPAR);
            append_token(new_token);
        }
        else if (m_current == '{') {
            auto new_token = new Token("TOKEN_LBRA", TOKEN_LBRA);
            append_token(new_token);
        }
        else if (m_current == '}') {
            auto new_token = new Token("TOKEN_RBRA", TOKEN_RBRA);
            append_token(new_token);
        }
        else if (m_current == ';') {
            auto new_token = new Token("TOKEN_SEMI", TOKEN_SEMI);
            append_token(new_token);
        }
        else if (m_current == '=') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_IS", TOKEN_IS);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_EQ", TOKEN_EQ);
                append_token(new_token);
            }
        }
        else if (m_current == '>') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_GEQ", TOKEN_GEQ);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_GD", TOKEN_GD);
                append_token(new_token);
            }
        }
        else if (m_current == '<') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_LEQ", TOKEN_LEQ);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_LD", TOKEN_LD);
                append_token(new_token);
            }
        }
        else if (m_current == '+') {
            next = peek();
            if (next == '+') {
                auto new_token = new Token("TOKEN_INC", TOKEN_INC);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_PLU", TOKEN_PLU);
                append_token(new_token);
            }
        }
        else if (m_current == '-') {
            next = peek();
            if (next == '-') {
                auto new_token = new Token("TOKEN_DEC", TOKEN_DEC);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_MIN", TOKEN_MIN);
                append_token(new_token);
            }
        }
        else if (m_current == '/') {
            next = peek();
            if (next == '/') {
                auto new_token = new Token("TOKEN_COMMENT", TOKEN_COMMENT);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else if (next == '*') {
                auto new_token = new Token("TOKEN_COMM_ST", TOKEN_COMM_ST);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_SLA", TOKEN_SLA);
                append_token(new_token);
            }
        }
        else if (m_current == '%') {
            auto new_token = new Token("TOKEN_MOD", TOKEN_MOD);
            append_token(new_token);
        }
        else if (m_current == '*') {
            next = peek();
            if (next == '/') {
                auto new_token = new Token("TOKEN_COMM_END", TOKEN_COMM_END);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_STAR", TOKEN_STAR);
                append_token(new_token);
            }
        }
        else if (m_current == '&') {
            next = peek();
            if (next == '&') {
                auto new_token = new Token("TOKEN_AND", TOKEN_AND);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_AMP", TOKEN_AMP);
                append_token(new_token);
            }
        }
        else if (m_current == ':') {
            auto new_token = new Token("TOKEN_COL", TOKEN_COL);
            append_token(new_token);
        }
        else if (m_current == '"') {
            auto new_token = new Token("TOKEN_QUOT", TOKEN_QUOT);
            append_token(new_token);
        }
        else if (m_current == '!') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_NOT", TOKEN_NOT);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else if (next == '|') {
                auto new_token = new Token("TOKEN_NOR", TOKEN_NOR);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else if (next == '&') {
                auto new_token = new Token("TOKEN_NAND", TOKEN_NAND);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_BANG", TOKEN_BANG);
                append_token(new_token);
            }
        }
        else if (m_current == 39) {
            auto new_token = new Token("TOKEN_SQUO", TOKEN_SQUO);
            append_token(new_token);
        }
        else if (m_current == ',') {
            auto new_token = new Token("TOKEN_COM", TOKEN_COM);
            append_token(new_token);
        }
        else if (m_current == '|') {
            next = peek();
            if (next == '|') {
                auto new_token = new Token("TOKEN_OR", TOKEN_OR);
                append_token(new_token);
                this->m_current_index++;
                m_current = this->m_file_str[this->m_current_index];
            }
            else {
                auto new_token = new Token("TOKEN_PIPE", TOKEN_PIPE);
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
                auto new_token = new Token("TOKEN_INT", TOKEN_INT);
                append_token(new_token);
            }
            else if (this->m_buffer == "return") {
                auto new_token = new Token("TOKEN_RET", TOKEN_RET);
                append_token(new_token);
            }
            else if (this->m_buffer == "var") {
                auto new_token = new Token("TOKEN_VAR", TOKEN_VAR);
                append_token(new_token);
            }
            else if (this->m_buffer == "char") {
                auto new_token = new Token("TOKEN_CHAR", TOKEN_CHAR);
                append_token(new_token);
            }
            else if (this->m_buffer == "float") {
                auto new_token = new Token("TOKEN_FLO", TOKEN_FLO);
                append_token(new_token);
            }
            else if (this->m_buffer == "bool") {
                auto new_token = new Token("TOKEN_BOOL", TOKEN_BOOL);
                append_token(new_token);
            }
            else if (this->m_buffer == "void") {
                auto new_token = new Token("TOKEN_VOID", TOKEN_VOID);
                append_token(new_token);
            }
            else if (this->m_buffer == "if") {
                auto new_token = new Token("TOKEN_IF", TOKEN_IF);
                append_token(new_token);
            }
            else if (this->m_buffer == "elif") {
                auto new_token = new Token("TOKEN_ELIF", TOKEN_ELIF);
                append_token(new_token);
            }
            else if (this->m_buffer == "else") {
                auto new_token = new Token("TOKEN_ELSE", TOKEN_ELSE);
                append_token(new_token);
            }
            else if (this->m_buffer == "do") {
                auto new_token = new Token("TOKEN_DO", TOKEN_DO);
                append_token(new_token);
            }
            else if (this->m_buffer == "while") {
                auto new_token = new Token("TOKEN_WHI", TOKEN_WHI);
                append_token(new_token);
            }
            else if (this->m_buffer == "fun") {
                auto new_token = new Token("TOKEN_FUN", TOKEN_FUN);
                append_token(new_token);
            }
            else if (this->m_buffer == "switch") {
                auto new_token = new Token("TOKEN_SWI", TOKEN_SWI);
                append_token(new_token);
            }
            else if (this->m_buffer == "case") {
                auto new_token = new Token("TOKEN_CAS", TOKEN_CAS);
                append_token(new_token);
            }
            else if (this->m_buffer == "const") {
                auto new_token = new Token("TOKEN_CONS", TOKEN_CONS);
                append_token(new_token);
            }
            else if (this->m_buffer == "continue") {
                auto new_token = new Token("TOKEN_CONT", TOKEN_CONT);
                append_token(new_token);
            }

            //Change
            else {
                auto new_token = new Token("TOKEN_LIT", TOKEN_LIT);
                append_token(new_token);
            }
            step_back();
            this->m_buffer.clear();
        }

        consume();
    }
    auto new_token = new Token("TOKEN_EOF", TOKEN_EOF);
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
