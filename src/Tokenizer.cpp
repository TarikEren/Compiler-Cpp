#include "../include/Tokenizer.hpp"

Tokenizer::Tokenizer()  {
    std::cout << "Tokenizer initialised\n";
    this->array = (Token**)malloc(sizeof(Token) * this->array_size);
}

void Tokenizer::append_token(Token *new_token)  {
    this->array_size++;
    this->array = (Token**)realloc(this->array, sizeof(Token*) * this->array_size);
    this->array[this->array_size - 1] = new_token;
}

[[maybe_unused]] void Tokenizer::pop() {
    this->array_size--;
    this->array = (Token**)realloc(this->array, sizeof(Token) * this->array_size);
}

void Tokenizer::print_tokens()  {
    std::cout << "------Tokens Start-------\n";
    std::cout << "Name\t\tType\tIndex\n";
    string token_str;
    int token_type;
    for (int i = 0; i < this->array_size; i++) {
        token_str = this->array[i]->get_TokenStr();
        token_type = this->array[i]->get_tokenType();
        std::cout << token_str << "\t" << token_type  << "\t" << i << std::endl;
    }
    std::cout << "--------Tokens End--------\n";
}

[[maybe_unused]] void Tokenizer::set_fileStr(string &fileStr)  {
    this->file_str = fileStr;
}

[[maybe_unused]] string Tokenizer::get_fileStr()  {
    return this->file_str;
}

void Tokenizer::clean()  {
    for (int i = 0; i < this->array_size; i++) {
        delete array[i];
    }
    this->current = 0;
    this->current_index = 0;
    this->array_size = 0;
    this->file_str.clear();
    this->buffer.clear();
    free(this->array);
}


Tokenizer::~Tokenizer()  {
    clean();
    std::cout << "Tokenizer has been destructured\n";
}

void Tokenizer::tokenize()  {
    this->current = this->file_str[this->current_index];
    char next;

    while (current != '\0' && this->current_index != this->file_str.length()) {
        if (current == '(') {
            auto new_token = new Token("TOKEN_LPAR", TOKEN_LPAR);
            append_token(new_token);
        }
        else if (current == ')') {
            auto new_token =  new Token("TOKEN_RPAR", TOKEN_RPAR);
            append_token(new_token);
        }
        else if (current == '{') {
            auto new_token = new Token("TOKEN_LBRA", TOKEN_LBRA);
            append_token(new_token);
        }
        else if (current == '}') {
            auto new_token = new Token("TOKEN_RBRA", TOKEN_RBRA);
            append_token(new_token);
        }
        else if (current == ';') {
            auto new_token = new Token("TOKEN_SEMI", TOKEN_SEMI);
            append_token(new_token);
        }
        else if (current == '=') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_IS", TOKEN_IS);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_EQ", TOKEN_EQ);
                append_token(new_token);
            }
        }
        else if (current == '>') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_GEQ", TOKEN_GEQ);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_GD", TOKEN_GD);
                append_token(new_token);
            }
        }
        else if (current == '<') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_LEQ", TOKEN_LEQ);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_LD", TOKEN_LD);
                append_token(new_token);
            }
        }
        else if (current == '+') {
            next = peek();
            if (next == '+') {
                auto new_token = new Token("TOKEN_INC", TOKEN_INC);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_PLU", TOKEN_PLU);
                append_token(new_token);
            }
        }
        else if (current == '-') {
            next = peek();
            if (next == '-') {
                auto new_token = new Token("TOKEN_DEC", TOKEN_DEC);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_MIN", TOKEN_MIN);
                append_token(new_token);
            }
        }
        else if (current == '/') {
            next = peek();
            if (next == '/') {
                auto new_token = new Token("TOKEN_COMMENT", TOKEN_COMMENT);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_SLA", TOKEN_SLA);
                append_token(new_token);
            }
        }
        else if (current == '%') {
            auto new_token = new Token("TOKEN_MOD", TOKEN_MOD);
            append_token(new_token);
        }
        else if (current == '*') {
            auto new_token = new Token("TOKEN_STAR", TOKEN_STAR);
            append_token(new_token);
        }
        else if (current == '&') {
            next = peek();
            if (next == '&') {
                auto new_token = new Token("TOKEN_AND", TOKEN_AND);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_AMP", TOKEN_AMP);
                append_token(new_token);
            }
        }
        else if (current == ':') {
            auto new_token = new Token("TOKEN_COL", TOKEN_COL);
            append_token(new_token);
        }
        else if (current == '"') {
            auto new_token = new Token("TOKEN_QUOT", TOKEN_QUOT);
            append_token(new_token);
        }
        else if (current == '!') {
            next = peek();
            if (next == '=') {
                auto new_token = new Token("TOKEN_NOT", TOKEN_NOT);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else if (next == '|') {
                auto new_token = new Token("TOKEN_NOR", TOKEN_NOR);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else if (next == '&') {
                auto new_token = new Token("TOKEN_NAND", TOKEN_NAND);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_BANG", TOKEN_BANG);
                append_token(new_token);
            }
        }
        else if (current == 39) {
            auto new_token = new Token("TOKEN_SQUO", TOKEN_SQUO);
            append_token(new_token);
        }
        else if (current == ',') {
            auto new_token = new Token("TOKEN_COM", TOKEN_COM);
            append_token(new_token);
        }
        else if (current == '|') {
            next = peek();
            if (next == '|') {
                auto new_token = new Token("TOKEN_OR", TOKEN_OR);
                append_token(new_token);
                this->current_index++;
                current = this->file_str[this->current_index];
            }
            else {
                auto new_token = new Token("TOKEN_PIPE", TOKEN_PIPE);
                append_token(new_token);
            }
        }
        else if (isalnum(current)) {
            while (isalpha(current)) {
                this->buffer.push_back(current);
                consume();
            }

            while (isdigit(current)) {
                this->buffer.push_back(current);
                consume();
            }
            if (this->buffer == "int") {
                auto new_token = new Token("TOKEN_INT", TOKEN_INT);
                append_token(new_token);
            }
            else if (this->buffer == "return") {
                auto new_token = new Token("TOKEN_RET", TOKEN_RET);
                append_token(new_token);
            }
            else if (this->buffer == "var") {
                auto new_token = new Token("TOKEN_VAR", TOKEN_VAR);
                append_token(new_token);
            }
            else if (this->buffer == "char") {
                auto new_token = new Token("TOKEN_CHAR", TOKEN_CHAR);
                append_token(new_token);
            }
            else if (this->buffer == "float") {
                auto new_token = new Token("TOKEN_FLO", TOKEN_FLO);
                append_token(new_token);
            }
            else if (this->buffer == "bool") {
                auto new_token = new Token("TOKEN_BOOL", TOKEN_BOOL);
                append_token(new_token);
            }
            else if (this->buffer == "void") {
                auto new_token = new Token("TOKEN_VOID", TOKEN_VOID);
                append_token(new_token);
            }
            else if (this->buffer == "if") {
                auto new_token = new Token("TOKEN_IF", TOKEN_IF);
                append_token(new_token);
            }
            else if (this->buffer == "elif") {
                auto new_token = new Token("TOKEN_ELIF", TOKEN_ELIF);
                append_token(new_token);
            }
            else if (this->buffer == "else") {
                auto new_token = new Token("TOKEN_ELSE", TOKEN_ELSE);
                append_token(new_token);
            }
            else if (this->buffer == "do") {
                auto new_token = new Token("TOKEN_DO", TOKEN_DO);
                append_token(new_token);
            }
            else if (this->buffer == "while") {
                auto new_token = new Token("TOKEN_WHI", TOKEN_WHI);
                append_token(new_token);
            }
            else if (this->buffer == "fun") {
                auto new_token = new Token("TOKEN_FUN", TOKEN_FUN);
                append_token(new_token);
            }
            else if (this->buffer == "switch") {
                auto new_token = new Token("TOKEN_SWI", TOKEN_SWI);
                append_token(new_token);
            }
            else if (this->buffer == "case") {
                auto new_token = new Token("TOKEN_CAS", TOKEN_CAS);
                append_token(new_token);
            }
            else if (this->buffer == "const") {
                auto new_token = new Token("TOKEN_CONS", TOKEN_CONS);
                append_token(new_token);
            }
            else if (this->buffer == "continue") {
                auto new_token = new Token("TOKEN_CONT", TOKEN_CONT);
                append_token(new_token);
            }

            //Change
            else {
                auto new_token = new Token("TOKEN_LIT", TOKEN_LIT);
                append_token(new_token);
            }
            step_back();
            this->buffer.clear();
        }

        consume();
    }
    auto new_token = new Token("TOKEN_EOF", TOKEN_EOF);
    append_token(new_token);
}

char Tokenizer::peek() {
    if (this->current_index < this->file_str.size()) {
        return this->file_str[this->current_index+1];
    }
    else return this->file_str[this->current_index];
}

void Tokenizer::consume() {
    this->current_index++;
    this->current = this->file_str[this->current_index];
}

void Tokenizer::step_back() {
    this->current_index--;
    this->current = this->file_str[this->current_index];
}

void Tokenizer::read_file(const char *filename)  {
    ifstream file;
    file.open(filename, std::ios::in);
    string contents;
    sstream str_stream;

    str_stream << file.rdbuf();

    contents = str_stream.str();
    this->file_str = contents;
    file.close();
}
