#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
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
bool variableExists(string name);
void copyValue(string origin, string destiny, Variable container[CONTAINER_MAX_SIZE]);
string getVariableName(string line);
string getVariableValue(string line);


/* Operation */
bool checkVariableAssignmentWithOperation(string line, int lineCounter);
string parseOperation(string line);


/** Embedded Function */
bool checkEmbeddedFunction(string line, int lineCounter);


/** Debug */
void debugConstants(void);
void debugVariables(void);


#endif /* PARSE_HPP */
