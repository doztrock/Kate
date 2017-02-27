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


/** Invalid Characters */
static const string INVALID_CHARACTERS_VARIABLE_NAME = string("!$%&/()=?¿¡0123456789-{}[]|<>");


/** Constant Keyword*/
static const int KEYWORD_CONSTANT_LENGTH = 3;

static const string KEYWORD_CONSTANT[KEYWORD_CONSTANT_LENGTH] = {
    "const" + WHITESPACE, "constant" + WHITESPACE, "constante" + WHITESPACE
};


/** Variable Keyword */
static const int KEYWORD_VARIABLE_LENGTH = 2;

static const string KEYWORD_VARIABLE[KEYWORD_VARIABLE_LENGTH] = {
    "var" + WHITESPACE, "variable" + WHITESPACE
};


#endif /* SYNTAX_HPP */
