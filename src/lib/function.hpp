#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <string>
#include <algorithm>

#include "syntax.hpp"
#include "memory.hpp"
#include "library.hpp"

using namespace std;

/**
 * 
 * FUNCTION STRUCTURE
 * 
 */
typedef struct __function_structure {
    const string NAME;
    unsigned int ARGC;
} Function;


/**
 * 
 * FUNCTION CONTAINER
 * 
 */
static const int FUNCTION_CONTAINER_LENGTH = 3;

static const Function FUNCTION_CONTAINER[FUNCTION_CONTAINER_LENGTH] = {

    /* Printing Functions */
    {.NAME = "print", .ARGC = 1},
    {.NAME = "println", .ARGC = 1},

    /* Exit Function */
    {.NAME = "exit", .ARGC = 0}

};


#endif /* FUNCTION_HPP */
