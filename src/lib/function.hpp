#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#include "syntax.hpp"
#include "trim.hpp"

using namespace std;

/** Replace - Interpolate */
string interpolate(string line);

/** Embedded Functions */
static const int EMBEDDED_FUNCTION_LENGTH = 2;

static const string EMBEDDED_FUNCTION[EMBEDDED_FUNCTION_LENGTH] = {

    /** Printing Function */
    "print" + WHITESPACE,
    "println" + WHITESPACE

};


/* Prototypes */
bool execute(ExecutionType executionType, string function, string line, int lineCounter);
bool executeEmbeddedDefinedFunction(string function, string line, int lineCounter);


/** Embedded Defined Functions Prototypes */
bool print(string function, string line);
bool println(string function, string line);


#endif /* FUNCTION_HPP */

