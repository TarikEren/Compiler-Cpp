#pragma once

#include <iostream>
#include <string>

//C++ namespaces are sometimes a nuisance
using string = std::string;

enum token_types{
    //Just in case
    UNDEFINED = -1,

    //Literals
    //TODO: Implement Here
    TOKEN_LIT,              //Generic literal
    TOKEN_INT_L,            //Integer literal
    TOKEN_STR_L,            //String literal
    TOKEN_CHAR_L,           //Character literal
    TOKEN_FLO_L,            //Float literal
    TOKEN_BOOL_L,           //Bool literal

    //Keywords
    TOKEN_VAR,              // var
    TOKEN_INT,              // int
    TOKEN_CHAR,             // char
    TOKEN_FLO,              // float
    TOKEN_BOOL,             // bool
    TOKEN_VOID,             // void
    TOKEN_RET,              // return
    TOKEN_IF,               // if
    TOKEN_ELIF,             // elif
    TOKEN_ELSE,             // else
    TOKEN_DO,               // do
    TOKEN_WHI,              // while
    TOKEN_FUN,              // function or fun
    TOKEN_SWI,              // switch
    TOKEN_CAS,              // case
    TOKEN_CONS,             // const
    TOKEN_CONT,             // continue

    //Operators
    TOKEN_EQ,               // =
    TOKEN_GD,               // >
    TOKEN_LD,               // <
    TOKEN_PLU,              // +
    TOKEN_MIN,              // -
    TOKEN_SLA,              // /
    TOKEN_MOD,              // %
    TOKEN_STAR,             // *
    TOKEN_AMP,              // &
    TOKEN_COL,              // :
    TOKEN_COM,              // ,
    TOKEN_QUOT,             // "
    TOKEN_SQUO,             // '
    TOKEN_PIPE,             // |
    TOKEN_BANG,             // !
    TOKEN_NOT,              // !=   "NOT"
    TOKEN_IS,               // ==   "IS"
    TOKEN_GEQ,              // >=
    TOKEN_LEQ,              // <=
    TOKEN_AND,              // &&   "AND"
    TOKEN_OR,               // ||   "OR"
    TOKEN_NOR,              // !|   "NOR"
    TOKEN_NAND,             // !&   "NAND"
    TOKEN_INC,              // ++
    TOKEN_DEC,              // --

    //Miscellaneous
    TOKEN_COMMENT,          // //
    TOKEN_COMM_START,    // /*
    TOKEN_COMM_END,      // */
    TOKEN_LBRA,             // {
    TOKEN_RBRA,             // }
    TOKEN_LPAR,             // (
    TOKEN_RPAR,             // )
    TOKEN_SEMI,             // ;
    TOKEN_EOF               // End of file
};


class Token {
private:
    //Token string
    string m_token_str;
    //Token type
    int m_token_type;
public:
    //Constructor. Initialises a token object using the string and integer provided by the user.
    Token(string, int);
    //Destructor. Cleans m_token_str string and sets m_token_type to zero.
    ~Token();

    //A gigantic switch-case block to check the token type and return corresponding token string.
    //There has to be another way.
    [[nodiscard]] inline string tokenType_to_string() const {
        switch (this->m_token_type) {
            case UNDEFINED:
                return "UNDEFINED";
            case TOKEN_LIT:
                return "TOKEN_LIT";
            case TOKEN_INT:
                return "TOKEN_INT";
            case TOKEN_INT_L:
                return "TOKEN_INT_L";
            case TOKEN_STR_L:
                return "TOKEN_STR_L";
            case TOKEN_CHAR_L:
                return "TOKEN_CHAR_L";
            case TOKEN_FLO_L:
                return "TOKEN_FLO_L";
            case TOKEN_BOOL_L:
                return "TOKEN_BOOL_L";
            case TOKEN_VAR:
                return "TOKEN_VAR";
            case TOKEN_CHAR:
                return "TOKEN_CHAR";
            case TOKEN_FLO:
                return "TOKEN_FLO";
            case TOKEN_BOOL:
                return "TOKEN_BOOL";
            case TOKEN_VOID:
                return "TOKEN_VOID";
            case TOKEN_RET:
                return "TOKEN_RET";
            case TOKEN_IF:
                return "TOKEN_IF";
            case TOKEN_ELIF:
                return "TOKEN_ELIF";
            case TOKEN_ELSE:
                return "TOKEN_ELSE";
            case TOKEN_DO:
                return "TOKEN_DO";
            case TOKEN_WHI:
                return "TOKEN_WHI";
            case TOKEN_FUN:
                return "TOKEN_FUN";
            case TOKEN_SWI:
                return "TOKEN_SWI";
            case TOKEN_CAS:
                return "TOKEN_CAS";
            case TOKEN_CONS:
                return "TOKEN_CONS";
            case TOKEN_CONT:
                return "TOKEN_CONT";
            case TOKEN_EQ:
                return "TOKEN_EQ";
            case TOKEN_GD:
                return "TOKEN_GD";
            case TOKEN_LD:
                return "TOKEN_LD";
            case TOKEN_GEQ:
                return "TOKEN_GEQ";
            case TOKEN_LEQ:
                return "TOKEN_LEQ";
            case TOKEN_PLU:
                return "TOKEN_PLU";
            case TOKEN_MIN:
                return "TOKEN_MIN";
            case TOKEN_SLA:
                return "TOKEN_SLA";
            case TOKEN_MOD:
                return "TOKEN_MOD";
            case TOKEN_AND:
                return "TOKEN_AND";
            case TOKEN_OR:
                return "TOKEN_OR";
            case TOKEN_COMMENT:
                return "TOKEN_COMMENT";
            case TOKEN_COMM_START:
                return "TOKEN_COMM_START";
            case TOKEN_COMM_END:
                return "TOKEN_COMM_END";
                //Might remove a couple of these next ones.
            case TOKEN_NOR:
                return "TOKEN_NOR";
            case TOKEN_NAND:
                return "TOKEN_NAND";
            case TOKEN_IS:
                return "TOKEN_IS";
            case TOKEN_LBRA:
                return "TOKEN_LBRA";
            case TOKEN_RBRA:
                return "TOKEN_RBRA";
            case TOKEN_LPAR:
                return "TOKEN_LPAR";
            case TOKEN_RPAR:
                return "TOKEN_RPAR";
            case TOKEN_SEMI:
                return "TOKEN_SEMI";
            case TOKEN_STAR:
                return "TOKEN_STAR";
            case TOKEN_AMP:
                return "TOKEN_AMP";
            case TOKEN_COL:
                return "TOKEN_COL";
            case TOKEN_QUOT: //WTF is this name lol
                return "TOKEN_QUOT";
            case TOKEN_SQUO: //Need to work on naming these
                return "TOKEN_SQUO";
            case TOKEN_EOF:
                return "TOKEN_EOF";
            default:
                return "UNDEFINED";
        }
    }


    //Functions after this line might be removed.
    //Token copy constructor
    [[maybe_unused]] Token(const Token&);

    //Returns m_token_str.
    [[nodiscard]] string get_TokenStr() const;

    //Returns m_token_type.
    [[maybe_unused]] [[nodiscard]] int get_tokenType() const;

    //Sets the m_token_str variable.
    [[maybe_unused]] void set_tokenStr(const string&);

    //Sets the m_token_type variable.
    [[maybe_unused]] void set_tokenType(int);

    //Clears the m_token_str variable.
    [[maybe_unused]] void clear_tokenStr();

    //Sets the m_token_type variable to zero.
    [[maybe_unused]] void clear_tokenType();
};
