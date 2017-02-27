#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#include "syntax.hpp"
#include "memory.hpp"
#include "library.hpp"

using namespace std;

/** Interpolate */
string interpolate(string line);

/** Embedded Functions */
static const int EMBEDDED_FUNCTION_LENGTH = 2;

static const string EMBEDDED_FUNCTION[EMBEDDED_FUNCTION_LENGTH] = {

    /** Printing Function */
    "print" + WHITESPACE,
    "println" + WHITESPACE

};


#endif /* FUNCTION_HPP */
