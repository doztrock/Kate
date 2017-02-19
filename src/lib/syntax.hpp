#ifndef SYNTAX_HPP
#define SYNTAX_HPP

#include <cstring>

using namespace std;

/** WhiteSpace */
static const string WHITESPACE = " ";


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


#endif /* SYNTAX_HPP */
