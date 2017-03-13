#include "function.hpp"

bool lookupFunction(string name, unsigned int &index) {

    for (unsigned int i = 0; i < (sizeof (FUNCTION_CONTAINER) / sizeof (FUNCTION_CONTAINER[0])); i++) {

        if (FUNCTION_CONTAINER[i].NAME.compare(name) == 0) {
            index = i;
            return true;
        }

    }

    index = FUNCTION_NOT_FOUND;
    return false;
}

void (*callFunction(string name))(ParameterList *) {

    int index = FUNCTION_NOT_FOUND;

    if (lookupFunction(name, index) == true) {
        return FUNCTION_CONTAINER[index].FUNCTION;
    }

    return NULL;
}

void print(ParameterList *ARGV) {
    return;
}

void println(ParameterList *ARGV) {
    return;
}

void exit(ParameterList *ARGV) {
    return;
}