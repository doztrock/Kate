#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

#include "ParameterList.hpp"
#include "../syntax.hpp"
#include "../memory.hpp"
#include "../library.hpp"
#include "../element/Datatype.hpp"

#define FUNCTION_NOT_FOUND  (CONTAINER_MAX_SIZE - 1)
#define ARGC_NOT_FOUND      (CONTAINER_MAX_SIZE - 1)

#define UNLIMITED_ARGUMENTS INT_MAX

using namespace std;

/**
 * 
 * FUNCTION STRUCTURE
 * 
 */
typedef struct __function_structure {
    const string NAME;
    unsigned int ARGC;
    Object(*FUNCTION)(ParameterList *ARGV);
} Function;


/**
 * 
 * PROTOTYPES
 * 
 */

/* Basic Management */
Object print(ParameterList *ARGV);
Object println(ParameterList *ARGV);
Object exit(ParameterList *ARGV);

/* Basic Math */
Object add(ParameterList *ARGV);
Object sub(ParameterList *ARGV);
Object sumatory(ParameterList *ARGV);


/**
 * 
 * FUNCTION CONTAINER
 * 
 */
static const Function FUNCTION_CONTAINER[CONTAINER_MAX_SIZE] = {

    /* Printing Functions */
    {
        .NAME = "print",
        .ARGC = 1,
        .FUNCTION = print
    },
    {
        .NAME = "println",
        .ARGC = 1,
        .FUNCTION = println
    },

    /* Exit Function */
    {
        .NAME = "exit",
        .ARGC = 0,
        .FUNCTION = exit
    },

    /* Basic Math */
    {
        .NAME = "add",
        .ARGC = 2,
        .FUNCTION = add
    },
    {
        .NAME = "sub",
        .ARGC = 2,
        .FUNCTION = sub
    },
    {
        .NAME = "sumatory",
        .ARGC = UNLIMITED_ARGUMENTS,
        .FUNCTION = sumatory
    }
};


/**
 * 
 * FUNCTION MANAGER METHODS
 * 
 */
unsigned int getArgcByName(string name);
bool lookupFunction(string name, unsigned int &index);
Object(*callFunction(string name))(ParameterList *);


#endif /* FUNCTION_HPP */
