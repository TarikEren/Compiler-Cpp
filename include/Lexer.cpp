#include "Lexer.hpp"
#include "Macros.hpp"

Lexer::Lexer()  {
    std::cout << "Lexer initialised\n";
    this->array = (Token**)malloc(sizeof(Token) * this->size);
}

void Lexer::append_token(Token *new_token)  {
    this->size++;
    this->array = (Token**)realloc(this->array, sizeof(Token*) * this->size);
    this->array[this->size-1] = new_token;
}

[[maybe_unused]] void Lexer::pop() {
    this->size--;
    this->array = (Token**) realloc(this->array, sizeof(Token) * this->size);
}

void Lexer::print_tokens()  {
    std::cout << "------Tokens Start-------\n";
    std::cout << "Name\t\tType\tIndex\n";
    string token_str;
    int token_type;
    for (int i = 0; i < this->size; i++) {
        token_str = array[i]->get_TokenStr();
        token_type = array[i]->get_tokenType();
        std::cout << token_str << "\t" << token_type  << "\t" << i << std::endl;
    }
    std::cout << "--------Tokens End--------\n";
}

[[maybe_unused]] void Lexer::set_fileStr(string &fileStr)  {
    this->file_str = fileStr;
}

string Lexer::get_fileStr()  {
    return this->file_str;
}

void Lexer::clean()  {
    for (int i = 0; i < this->size; i++) {
        delete array[i];
    }
    this->file_str.clear();
    free(this->array);
}


Lexer::~Lexer()  {
    clean();
    std::cout << "Lexer has been destructured\n";
}

void Lexer::tokenize()  {
    int index = 0;
    char current = this->file_str[index];
    string buffer;

    while (current != '\0') {
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
            auto new_token = new Token("TOKEN_EQ", TOKEN_EQ);
            append_token(new_token);
        }
        else if (current == '>') {
            auto new_token = new Token("TOKEN_GD", TOKEN_GD);
            append_token(new_token);
        }
        else if (current == '<') {
            auto new_token = new Token("TOKEN_LD", TOKEN_LD);
            append_token(new_token);
        }
        else if (current == '+') {
            auto new_token = new Token("TOKEN_PLU", TOKEN_PLU);
            append_token(new_token);
        }
        else if (current == '-') {
            auto new_token = new Token("TOKEN_MIN", TOKEN_MIN);
            append_token(new_token);
        }
        else if (current == '/') {
            auto new_token = new Token("TOKEN_SLA", TOKEN_SLA);
            append_token(new_token);
        }
        else if (current == '%') {
            auto new_token = new Token("TOKEN_PLU", TOKEN_PLU);
            append_token(new_token);
        }
        else if (current == '*') {
            auto new_token = new Token("TOKEN_STAR", TOKEN_STAR);
            append_token(new_token);
        }
        else if (current == '&') {
            auto new_token = new Token("TOKEN_AMP", TOKEN_AMP);
            append_token(new_token);
        }
        else if (current == ':') {
            auto new_token = new Token("TOKEN_COL", TOKEN_COL);
            append_token(new_token);
        }
        else if (current == '"') {
            auto new_token = new Token("TOKEN_QUOT", TOKEN_QUOT);
            append_token(new_token);
        }
        else if (current == 39) {
            auto new_token = new Token("TOKEN_SQUO", TOKEN_SQUO);
            append_token(new_token);
        }
        else if (isalnum(current)) {
            while (isalpha(current)) {
                buffer.push_back(current);
                index++;
                current = this->file_str[index];
            }

            while (isdigit(current)) {
                buffer.push_back(current);
                index++;
                current = this->file_str[index];
            }
            if (buffer == "int") {
                auto new_token = new Token("TOKEN_INT", TOKEN_INT);
                append_token(new_token);
            }
            else if (buffer == "return") {
                auto new_token = new Token("TOKEN_RET", TOKEN_RET);
                append_token(new_token);
            }
            else if (buffer == "var") {
                auto new_token = new Token("TOKEN_VAR", TOKEN_VAR);
                append_token(new_token);
            }
            else if (buffer == "char") {
                auto new_token = new Token("TOKEN_CHAR", TOKEN_CHAR);
                append_token(new_token);
            }
            else if (buffer == "float") {
                auto new_token = new Token("TOKEN_FLO", TOKEN_FLO);
                append_token(new_token);
            }
            else if (buffer == "bool") {
                auto new_token = new Token("TOKEN_BOOL", TOKEN_BOOL);
                append_token(new_token);
            }
            else if (buffer == "void") {
                auto new_token = new Token("TOKEN_VOID", TOKEN_VOID);
                append_token(new_token);
            }
            else if (buffer == "if") {
                auto new_token = new Token("TOKEN_IF", TOKEN_IF);
                append_token(new_token);
            }
            else if (buffer == "elif") {
                auto new_token = new Token("TOKEN_ELIF", TOKEN_ELIF);
                append_token(new_token);
            }
            else if (buffer == "else") {
                auto new_token = new Token("TOKEN_ELSE", TOKEN_ELSE);
                append_token(new_token);
            }
            else if (buffer == "do") {
                auto new_token = new Token("TOKEN_DO", TOKEN_DO);
                append_token(new_token);
            }
            else if (buffer == "while") {
                auto new_token = new Token("TOKEN_WHI", TOKEN_WHI);
                append_token(new_token);
            }
            else if (buffer == "fun") {
                auto new_token = new Token("TOKEN_FUN", TOKEN_FUN);
                append_token(new_token);
            }
            else if (buffer == "switch") {
                auto new_token = new Token("TOKEN_SWI", TOKEN_SWI);
                append_token(new_token);
            }
            else if (buffer == "case") {
                auto new_token = new Token("TOKEN_CAS", TOKEN_CAS);
                append_token(new_token);
            }
            else if (buffer == "const") {
                auto new_token = new Token("TOKEN_CONS", TOKEN_CONS);
                append_token(new_token);
            }
            else if (buffer == "continue") {
                auto new_token = new Token("TOKEN_CONT", TOKEN_CONT);
                append_token(new_token);
            }
            else {
                auto new_token = new Token("TOKEN_LIT", TOKEN_LIT);
                append_token(new_token);
            }
            index--;
            buffer.clear();
        }

        index++;
        current = this->file_str[index];
    }
    auto new_token = new Token("TOKEN_EOF", TOKEN_EOF);
    append_token(new_token);
}

char Lexer::peek() {

    return 0;
}

bool Lexer::read_file(const char *filename)  {
    fstream file;
    file.open(filename, std::ios::in);
    if (!file) {
        std::cout << "File " << filename << " cannot be accessed\n";
        return false;
    }
    string contents;
    sstream str_stream;

    str_stream << file.rdbuf();

    contents = str_stream.str();
    this->file_str = contents;
    file.close();
    return true;
}

