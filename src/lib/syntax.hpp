#ifndef SYNTAX_HPP
#define SYNTAX_HPP

#include <string>

using namespace std;


/**
 * 
 * WHITESPACE
 * 
 */
static const string WHITESPACE = " ";


/**
 * 
 * ONE-LINE COMMENT CHARACTER
 * 
 */
static const string COMMENT_CHARACTER = "#";


/**
 * 
 * ASSIGNMENT OPERATOR
 * 
 */
static const char ASSIGNMENT_OPERATOR = ':';


/**
 * 
 * INVALID CHARACTERS
 * 
 */
static const string INVALID_CHARACTERS_VARIABLE_NAME = string("!$%&/()=?¿¡0123456789-{}[]|<>");


/**
 * 
 * CONSTANT KEYWORD
 * 
 */
static const int KEYWORD_CONSTANT_LENGTH = 3;

static const string KEYWORD_CONSTANT[KEYWORD_CONSTANT_LENGTH] = {
    "const" + WHITESPACE, "constant" + WHITESPACE, "constante" + WHITESPACE
};


/**
 * 
 * VARIABLE KEYWORD
 * 
 */
static const int KEYWORD_VARIABLE_LENGTH = 2;

static const string KEYWORD_VARIABLE[KEYWORD_VARIABLE_LENGTH] = {
    "var" + WHITESPACE, "variable" + WHITESPACE
};


#endif /* SYNTAX_HPP */
