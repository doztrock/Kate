#include "es.hpp"

/**
 * 
 * FILE ERRORS
 * 
 */

std::string FILE_NOT_LOADED_SUCCESSFULLY(void) {
    return "File not loaded successfully";
}

/**
 * 
 * CONSTANT ERRORS
 * 
 */

std::string ERROR_CONSTANT_INITIALIZATION(int line) {
    return "Error with constant initialization at line " + INT_STRING(line);
}

std::string ERROR_CONSTANT_ASSIGNMENT(int line) {
    return "Error! You can't assing a value to a previosly-initialized constant at line " + INT_STRING(line);
}

std::string ERROR_EXPECTED_CONSTANT_NAME(int line) {
    return "Expected constant name at line " + INT_STRING(line);
}

std::string ERROR_UNUSED_CONSTANT(int line) {
    return "Unused constant at line " + INT_STRING(line);
}

std::string ERROR_REDECLARED_CONSTANT(int line) {
    return "You can't re-declare a previously declared constant in line " + INT_STRING(line);
}

std::string ERROR_INVALID_CONSTANT_NAME(int line) {
    return "Invalid constant name in line " + INT_STRING(line);
}

/**
 * 
 * VARIABLE ERRORS
 * 
 */

std::string ERROR_VARIABLE_INITIALIZATION(int line) {
    return "Error with variable initialization at line " + INT_STRING(line);
}

std::string ERROR_VARIABLE_ASSIGNMENT(int line) {
    return "Error with variable assignment at line " + INT_STRING(line);
}

std::string ERROR_VARIABLE_ASSIGNMENT_EMPTY_VALUE(int line) {
    return "Error with variable assignment, the value is empty at line " + INT_STRING(line);
}

std::string ERROR_EXPECTED_VARIABLE_NAME(int line) {
    return "Expected variable name at line " + INT_STRING(line);
}

std::string ERROR_UNUSED_VARIABLE(int line) {
    return "Unused variable at line " + INT_STRING(line);
}

std::string ERROR_REDECLARED_VARIABLE(int line) {
    return "You can't re-declare a previously declared variable in line " + INT_STRING(line);
}

std::string ERROR_INVALID_VARIABLE_NAME(int line) {
    return "Invalid variable name in line " + INT_STRING(line);
}
