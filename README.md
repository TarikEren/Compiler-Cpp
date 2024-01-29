# Lexer-Cpp
A lexer I made for practice purposes and as a launching point for a compiler I'm trying to make.

### Supported Tokens
//Just in case
    UNDEFINED = -1,

    //Literals
    //TODO: Implement Here
    TOKEN_LIT,      //Generic literal
    TOKEN_INT_L,    //Integer literal
    TOKEN_STR_L,    //String literal    Might not add this and implement it as a char array
    TOKEN_CHAR_L,   //Character literal
    TOKEN_FLO_L,    //Float literal
    TOKEN_BOOL_L,   //Bool literal

    //Keywords
    TOKEN_VAR,      // var
    TOKEN_INT,      // int
    TOKEN_CHAR,     // char
    TOKEN_FLO,      // float
    TOKEN_BOOL,     // bool
    TOKEN_VOID,     // void
    TOKEN_RET,      // return
    TOKEN_IF,       // if
    TOKEN_ELIF,     // elif
    TOKEN_ELSE,     // else
    TOKEN_DO,       // do
    TOKEN_WHI,      // while
    TOKEN_FUN,      // function or fun
    TOKEN_SWI,      // switch
    TOKEN_CAS,      // case
    TOKEN_CONS,     // const
    TOKEN_CONT,     // continue

    //Operators
    TOKEN_EQ,       // =
    TOKEN_GD,       // >
    TOKEN_LD,       // <
    TOKEN_PLU,      // +
    TOKEN_MIN,      // -
    TOKEN_SLA,      // /
    TOKEN_MOD,      // %
    TOKEN_STAR,     // *
    TOKEN_AMP,      // &
    TOKEN_COL,      // :
    TOKEN_COM,      // ,
    TOKEN_QUOT,     // "
    TOKEN_SQUO,     // '
    TOKEN_PIPE,     // |
    TOKEN_BANG,     // !
    TOKEN_NOT,      // !=   "NOT"
    TOKEN_IS,       // ==   "IS"
    TOKEN_GEQ,      // >=
    TOKEN_LEQ,      // <=
    TOKEN_AND,      // &&   "AND"
    TOKEN_OR,       // ||   "OR"
    TOKEN_NOR,      // !|   "NOR"
    TOKEN_NAND,     // !&   "NAND"
    TOKEN_INC,      // ++
    TOKEN_DEC,      // --

    //Miscellaneous
    TOKEN_COMMENT,  // Comment
    TOKEN_LBRA,     // {
    TOKEN_RBRA,     // }
    TOKEN_LPAR,     // (
    TOKEN_RPAR,     // )
    TOKEN_SEMI,     // ;
    TOKEN_EOF       // End of file
