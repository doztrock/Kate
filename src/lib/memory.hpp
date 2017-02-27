#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "element/Constant.hpp"
#include "element/Variable.hpp"

/** Container Max Size */
static const int CONTAINER_MAX_SIZE = 256;


/** Constant Container */
static Constant CONSTANT_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int CONSTANT_CONTAINER_INDEX = 0;


/** Variable Container */
static Variable VARIABLE_CONTAINER[CONTAINER_MAX_SIZE];
static unsigned int VARIABLE_CONTAINER_INDEX = 0;


#endif /* MEMORY_HPP */
