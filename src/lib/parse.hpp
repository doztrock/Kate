#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "syntax.hpp"
#include "function.hpp"

#include "trim.hpp"

#include "language/language.hpp"

#include "element/Variable.hpp"
#include "element/Constant.hpp"
#include "element/UnterminatedCharacter.hpp"

using namespace std;

/** Container Max Size */
static const int CONTAINER_MAX_SIZE = 256;


/** Variable Container */
static Variable VARIABLE_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int VARIABLE_CONTAINER_INDEX = 0;


/** Constant Container */
static Constant CONSTANT_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int CONSTANT_CONTAINER_INDEX = 0;


/** Unterminated Characters */
static UnterminatedCharacter COUPLE_OF_CHARACTERS_CONTAINER[CONTAINER_MAX_SIZE];


/* Parser */
void parse(ifstream& stream);


/** Comment */
bool checkComment(string line, int lineCounter);


/* Variable */
bool checkVariable(string line, int lineCounter);
bool checkVariableAssignment(string line, int lineCounter);
bool checkVariableName(string name);
bool variableExists(string name);
void copyValue(string origin, string destiny, Variable container[CONTAINER_MAX_SIZE]);
string getVariableName(string line);
string getVariableValue(string line);


/* Constant */
bool checkConstant(string line, int lineCounter);
bool constantExists(string name);
string getConstantName(string line);
string getConstantValue(string line);


/* Operation */
bool checkVariableAssignmentWithOperation(string line, int lineCounter);
string parseOperation(string line);


/** Embedded Function */
bool checkEmbeddedFunction(string line, int lineCounter);


/** Unterminated Characters */
bool checkUnterminatedCharacters(string line, int lineCounter);


/** Debug */
void debugConstants(void);
void debugVariables(void);


#endif /* PARSE_HPP */
