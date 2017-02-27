#ifndef SYNTAX_HPP
#define SYNTAX_HPP

#include <string>

using namespace std;

/** WhiteSpace */
static const string WHITESPACE = " ";


/** One-Line Commentary */
static const string COMMENT_CHARACTER = "#";


/** Assignment Operator */
static const char ASSIGNMENT_OPERATOR = ':';


/** Addition Operator */
static const char ADDITION_OPERATOR = '+';


/** Subtraction Operator */
static const char SUBTRACTION_OPERATOR = '-';


/** Multiplication Operator */
static const char MULTIPLICATION_OPERATOR = '*';


/** Divistion Operator */
static const char DIVISION_OPERATOR = '/';


/** Order Of Operations */
static const char ORDER_OF_OPERATIONS[4] = {
    DIVISION_OPERATOR,
    MULTIPLICATION_OPERATOR,
    ADDITION_OPERATOR,
    SUBTRACTION_OPERATOR
};


/** Variable Keyword */
static const int KEYWORD_VARIABLE_LENGTH = 2;

static const string KEYWORD_VARIABLE[KEYWORD_VARIABLE_LENGTH] = {
    "var" + WHITESPACE, "variable" + WHITESPACE
};


/** Constant Keyword*/
static const int KEYWORD_CONSTANT_LENGTH = 3;

static const string KEYWORD_CONSTANT[KEYWORD_CONSTANT_LENGTH] = {
    "const" + WHITESPACE, "constant" + WHITESPACE, "constante" + WHITESPACE
};


/** Interpolation Operator */
static const char INTERPOLATION_OPERATOR_BEGIN = '{';
static const char INTERPOLATION_OPERATOR_END = '}';

/** Execution Types */
typedef enum __execution_type {
    EMBEDDED_DEFINED_FUNCTION, USER_DEFINED_FUNCTION
} ExecutionType;

/** Unterminated Characters */
typedef struct __unterminated_character {
    char begin;
    char end;
} UnterminatedCharacter;

static UnterminatedCharacter UNTERMINATED_CHARACTER_CONTAINER[5] = {
    {.begin = '(', .end = ')'},
    {.begin = '[', .end = ']'},
    {.begin = '{', .end = '}'},
    {.begin = '\"', .end = '\"'},
    {.begin = '\'', .end = '\''}
};

#endif /* SYNTAX_HPP */
