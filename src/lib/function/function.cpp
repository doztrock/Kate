#include "function.hpp"

unsigned int getArgcByName(string name) {

    unsigned int index = FUNCTION_NOT_FOUND;

    if (lookupFunction(name, index) == true) {
        return FUNCTION_CONTAINER[index].ARGC;
    }

    return ARGC_NOT_FOUND;
}

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

    unsigned int index = FUNCTION_NOT_FOUND;

    if (lookupFunction(name, index) == true) {
        return FUNCTION_CONTAINER[index].FUNCTION;
    }

    return NULL;
}



/**
 * 
 * FUNCTIONS SUPPORTED BY KATE
 * 
 */

/**
 * 
 * @param ARGV
 */
void print(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
        
    if (ARGV->getList().size() == argc) {
        cout << ARGV->getList().at(0);
    }

    return;
}

/**
 * 
 * @param ARGV
 */
void println(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
        
    if (ARGV->getList().size() == argc) {
        cout << ARGV->getList().at(0) << endl;
    }

    return;
}

/**
 * 
 * @param ARGV
 */
void exit(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
        
    if (ARGV->getList().size() == argc) {
        exit(EXIT_SUCCESS);
    }

    return;
}

/**
 * 
 * @param ARGV
 */
void add(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
        
    if (ARGV->getList().size() == argc) {
        exit(EXIT_SUCCESS);
    }

    return;
}

/**
 * 
 * @param ARGV
 */
void sub(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
        
    if (ARGV->getList().size() == argc) {
        exit(EXIT_SUCCESS);
    }

    return;
}