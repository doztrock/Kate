#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <cstring>

#include "syntax.hpp"
#include "trim.hpp"

using namespace std;

void parse(ifstream& stream);

bool checkVariable(string line, int lineCounter);
string getVariableName(string line);
string getVariableValue(string line);


#endif /* PARSE_HPP */

