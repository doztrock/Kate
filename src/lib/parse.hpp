#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "syntax.hpp"
#include "memory.hpp"
#include "library.hpp"
#include "function.hpp"

#include "language/language.hpp"

using namespace std;


/* Parser */
void parse(ifstream& stream);


/** Comment */
bool checkComment(string line, int lineCounter);


/* Constant */
bool checkConstant(string line, int lineCounter);
bool constantExists(string name);
string getConstantName(string line);
string getConstantValue(string line);


/* Variable */
bool checkVariable(string line, int lineCounter);
bool checkVariableAssignment(string line, int lineCounter);
bool checkVariableName(string name);
string getVariableName(string line);
string getVariableValue(string line);
bool variableExists(string name);
void copyValue(string origin, string destiny, Variable container[CONTAINER_MAX_SIZE]);


/** Debug */
void debugConstants(void);
void debugVariables(void);


#endif /* PARSE_HPP */
