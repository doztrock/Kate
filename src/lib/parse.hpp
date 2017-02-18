#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "syntax.hpp"
#include "trim.hpp"

#include "language/language.hpp"

#include "element/Variable.hpp"
#include "element/Constant.hpp"

using namespace std;

/** Container Max Size */
static const int CONTAINER_MAX_SIZE = 256;

/** Variable Container */
static Variable VARIABLE_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int VARIABLE_CONTAINER_INDEX = 0;

/** Constant Container */
static Constant CONSTANT_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int CONSTANT_CONTAINER_INDEX = 0;

/* Parser */
void parse(ifstream& stream);

/* Variable */
bool checkVariable(string line, int lineCounter);
bool checkVariableAssignment(string line, int lineCounter);
string getVariableName(string line);
string getVariableValue(string line);

/* Constant */
bool checkConstant(string line, int lineCounter);
string getConstantName(string line);
string getConstantValue(string line);

#endif /* PARSE_HPP */
