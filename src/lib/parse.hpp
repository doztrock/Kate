#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "syntax.hpp"
#include "memory.hpp"
#include "library.hpp"
#include "function/function.hpp"
#include "element/Datatype.hpp"

#include "language/language.hpp"

using namespace std;


/**
 * 
 * PARSE FUNCTIONS
 * 
 */
void parse(ifstream& stream);


/**
 * 
 * COMMENT FUNCTIONS
 * 
 */
bool checkComment(string line);


/**
 * 
 * CONSTANT FUNCTIONS
 * 
 */
bool checkConstant(string line, int lineCounter);
bool constantExists(string name);
bool checkConstantAlone(string line);
string getConstantName(string line);
string getConstantValue(string line);


/**
 * 
 * VARIABLE FUNCTIONS
 * 
 */
bool checkVariable(string line, int lineCounter);
bool checkVariableAssignment(string line, int lineCounter);
bool checkVariableAlone(string line);
string getVariableName(string line);
string getVariableValue(string line);
bool variableExists(string name);
void copyValueFromVariable(string origin, string destiny);
void copyValueFromConstant(string origin, string destiny);


/**
 * 
 * ELEMENT COMMON FUNCTIONS
 * 
 */
bool checkElementName(string name);
Datatype getDatatype(string value);


/**
 * 
 * DEBUG FUNCTIONS
 * 
 */
void debugConstants(void);
void debugVariables(void);


#endif /* PARSE_HPP */
