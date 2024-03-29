#include "./include/Token.hpp"
#include "./include/Tokenizer.hpp"
#include "./include/Generator.hpp"

// This lexer will be a launching point for me to create a new programming language. For fun.

/*
 * The LANG_NAME Language
 *
 * I haven't really thought about the name, so it will be LANG_NAME for a while.
 * It will be a strongly typed language. (None of that stupid dynamically typed stuff.)
 * Main entry point will be a main function that returns an integer. Just like C.
 *
 * ----- Might Add (I'm not really sure about these as they seem daunting.) -----
 * Pointers
 * Bitwise Operations
 * Garbage Collection
 * Throw - Catch
 * Classes (OOP in general)
 * Type Defining
 * Bitwise Operations
 *
 * The syntax will be as follows:
 *
 * ----- Comments -----
 * Same as C.
 *
 *
 * ----- Types -----
 * Might add more types
 * Integer:     int
 * Character:   char
 * Float:       float
 * Bool:        bool
 * Void:        void
 * String:      string (Might not add this and implement it as char arrays or something.)
 *
 * ----- Variable Declaration -----
 * var "variable name" : "type" = "value";
 * "Variable 'variable name' with type 'type' has value 'value'
 * Variables cannot be void. It would be stupid.
 *
 * or you can declare const variables like:
 * const var "variable name" : "type" = "value";
 * "Constant variable 'variable name' with type 'type' has value 'value'
 *
 * ----- Arrays -----
 * Array "array name" : type["size"];
 * "Array "array name" with type "type" and size of "size";
 *
 * ----- Function Declaration -----
 * fun "function name" (arguments) : "type" {
 *    "Code"
 *    return 'value';
 * }
 *
 * "Function 'function name' takes 'arguments' and returns 'value' with return type of 'type'
 * It will support recursion (Scary I know.)
 *
 * So the main file will be like this:
 * fun main (arguments) : int {
 *    "Code"
 *    return 0;
 * }
 *
 * Important Note: Every program should have a main function as the main entry point.
 * Language shall follow C standards when it comes to return values.
 * (i.e. a function that successfully executed its code should return 0)
 *
 * ----- Comparisons -----
 * This part requires some more thought because I haven't really made up my mind about it.
 * Equals:                      == or "is"
 * Greater than:                >
 * Greater than or equal to:    >=
 * Less than:                   <
 * Less than or equal to:       <=
 * And:                         && or "and"
 * Or:                          || or "or"
 *
 * These are just ideas; I might not even add them
 * Xor:                         !| or "xor"
 * Nand:                        !& or "nand"
 *
 * ----- Operations -----
 * Addition:        +
 * Subtraction:     -
 * Multiplication:  *
 * Division:        /
 * Modulo:          %
 *
 *
 * ----- If - Elif - Else -----
 *  if (statement) {
 *      "Code"
 *  }
 *  elif (statement) {
 *      "Code"
 *  }
 *  else {
 *      "Code"
 *  }
 *  Pretty straightforward. Rather than using "else if" just like C family languages, I opted for elif.
 *  Because it's shorter and I'm lazy.
 *
 *
 * ----- Loops -----
 * While:
 *  while (statement) {
 *      "Code"
 *  }
 *
 * Do-While:
 *  do (statement) {
 *      "Code"
 *  } while (statement);
 *
 * For:
 *  for (statement) {
 *      "Code"
 * }
 * Again, pretty straightforward. Heavily influenced by C.
 * Keywords "break" and "continue" also exist.
 *
 * ----- Switch-Case -----
 * Switch ("statement") {
 *      case "value":
 *          "Code"
 *          break;
 *      default:
 *          "Code"
 *          break;
 * }
 * There's no way you can guess where I'm inspired from.
 *
 * ----- Structs -----
 * struct "name" {
 *      //Example variables
 *      var foo : int;
 *      var bar : char;
 *      Array arr : int[];
 * };
 *
 * struct "name" "variable name";
 * "A struct object of "name" struct named "variable name"
 *
 * struct "name" struct_obj;
 * struct_obj.foo = 10;
 * struct_obj.bar = 'a';
 *
 * Basically the same as C structs.
 *
 * There's probably some stuff I'm forgetting right now but it's 03:08AM right now, so I'm tired.
 *
 * */

//DONE: Vector causes multiple destructor call problems. Take a look into it. If the problem still persists, use some other way of storing the tokens.
//Rather than learning how to use vectors effectively, I made my own dynamic array.

//DONE: Change the tokenize function so that it works on my imaginary language.
//DONE: Remove unused functions (Later on)

//TODO: Implement support for different types of literals.

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        perror("Please provide a file\n");
        exit(EXIT_FAILURE);
    }
    Tokenizer lexer_obj = Tokenizer();
    lexer_obj.read_file(argv[1]);
    lexer_obj.tokenize();
    lexer_obj.print_tokens();
    generate_asm();
    generate_exit();

    return EXIT_SUCCESS;
}