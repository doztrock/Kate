#include "en.hpp"

std::string FILE_NOT_LOADED_SUCCESSFULLY(void) {
    return "File not loaded successfully";
}

std::string ERROR_VARIABLE_INITIALIZATION(int line) {
    return "Error with variable initialization at line " + INT_STRING(line);
}

std::string ERROR_VARIABLE_ASSIGNMENT(int line) {
    return "Error with variable assignment at line " + INT_STRING(line);
}

std::string ERROR_VARIABLE_ASSIGNMENT_EMPTY_VALUE(int line) {
    return "Error with variable assignment, the value is empty at line " + INT_STRING(line);
}

std::string ERROR_CONSTANT_INITIALIZATION(int line) {
    return "Error with constant initialization at line " + INT_STRING(line);
}

std::string ERROR_CONSTANT_ASSIGNMENT(int line) {
    return "Error! You can't assing a value to a previosly-initialized declared constant at line " + INT_STRING(line);
}
