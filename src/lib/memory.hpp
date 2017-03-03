#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "element/Constant.hpp"
#include "element/Variable.hpp"

/**
 * 
 * CONTAINER MAX SIZE
 * 
 */
static const int CONTAINER_MAX_SIZE = 256;


/**
 * 
 * CONSTANT CONTAINER
 * 
 */
static Constant CONSTANT_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int CONSTANT_CONTAINER_INDEX = 0;


/**
 * 
 * VARIABLE CONTAINER
 * 
 */
static Variable VARIABLE_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int VARIABLE_CONTAINER_INDEX = 0;


#endif /* MEMORY_HPP */
