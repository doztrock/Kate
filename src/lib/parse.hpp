#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "syntax.hpp"
#include "trim.hpp"

#include "element/Variable.hpp"

using namespace std;

/** Container Max Size */
static const int CONTAINER_MAX_SIZE = 256;

/** Variable Container */
static Variable VARIABLE_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int VARIABLE_CONTAINER_INDEX = 0;

void parse(ifstream& stream);

bool checkVariable(string line, int lineCounter);
string getVariableName(string line);
string getVariableValue(string line);


#endif /* PARSE_HPP */

