#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <string>
#include <algorithm>

#include "ParameterList.hpp"
#include "../syntax.hpp"
#include "../memory.hpp"
#include "../library.hpp"

#define FUNCTION_NOT_FOUND  (CONTAINER_MAX_SIZE - 1)
#define ARGC_NOT_FOUND      (CONTAINER_MAX_SIZE - 1)

using namespace std;

/**
 * 
 * FUNCTION STRUCTURE
 * 
 */
typedef struct __function_structure {
    const string NAME;
    unsigned int ARGC;
    void (*FUNCTION)(ParameterList *ARGV);
} Function;


/**
 * 
 * PROTOTYPES
 * 
 */
void print(ParameterList *ARGV);
void println(ParameterList *ARGV);
void exit(ParameterList *ARGV);

/* Basic Math */
void add(ParameterList *ARGV);
void sub(ParameterList *ARGV);


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
    }
};


/**
 * 
 * FUNCTION MANAGER METHODS
 * 
 */
unsigned int getArgcByName(string name);
bool lookupFunction(string name, unsigned int &index);
void (*callFunction(string name))(ParameterList *);


#endif /* FUNCTION_HPP */