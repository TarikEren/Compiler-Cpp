# Compiler-Cpp
A compiler I'm making for practice purposes.

### Supported Tokens

    UNDEFINED = -1,

    //Literals
    TOKEN_LIT,      //Generic literal
    
    //The following literals are not yet implemented
    TOKEN_INT_L,    //Integer literal
    TOKEN_STR_L,    //String literal
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
    TOKEN_GEQ,      // >=
    TOKEN_LEQ,      // <=
    TOKEN_INC,      // ++
    TOKEN_DEC,      // --
    
    //Might add support for the words listed below as well
    TOKEN_NOT,      // !=   "NOT"
    TOKEN_IS,       // ==   "IS"
    TOKEN_AND,      // &&   "AND"
    TOKEN_OR,       // ||   "OR"
    TOKEN_NOR,      // !|   "NOR"
    TOKEN_NAND,     // !&   "NAND"

    //Miscellaneous
    TOKEN_COMMENT,  // Comment
    //Block comments are not yet implemented.
    
    TOKEN_LBRA,     // {
    TOKEN_RBRA,     // }
    TOKEN_LPAR,     // (
    TOKEN_RPAR,     // )
    TOKEN_SEMI,     // ;
    TOKEN_EOF       // End of file

### Planned Syntax

## Assignment: A C ripoff for the most part.
        var 'name' : int = 'value';

## Loops:
# For
        for (; ;) {
            //Code
        }
# While
        while (condition) {
            //Code
        }

## Conditional Statements:
        if (condition) {
            //Code
        }
        elif (condition) {
            //Code
        }
        else {
            //Code
        }
        
