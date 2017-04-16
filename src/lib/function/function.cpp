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

Object(*callFunction(string name))(ParameterList *) {

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
Object print(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
    class Void result;

    if (ARGV->getList().size() == argc) {
        cout << ARGV->getList().at(0);
    }

    return result;
}

/**
 * 
 * @param ARGV
 */
Object println(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
    class Void result;

    if (ARGV->getList().size() == argc) {
        cout << ARGV->getList().at(0) << endl;
    }

    return result;
}

/**
 * 
 * @param ARGV
 */
Object exit(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
    class Void result;

    if (ARGV->getList().size() == argc) {
        exit(EXIT_SUCCESS);
    }

    return result;
}

/**
 * 
 * @param ARGV
 */
Object add(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
    class Integer result;

    if (ARGV->getList().size() == argc) {
        exit(EXIT_SUCCESS);
    }

    return result;
}

/**
 * 
 * @param ARGV
 */
Object sub(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
    class Integer result;

    if (ARGV->getList().size() == argc) {
        exit(EXIT_SUCCESS);
    }

    return result;
}

/**
 * Debug function with unlimited arguments
 * @param ARGV
 */
Object sumatory(ParameterList *ARGV) {

    unsigned int argc = getArgcByName(__FUNCTION__);
    class Void result;

    if (argc == UNLIMITED_ARGUMENTS) {

        class Integer sumatory;

        sumatory = 0;

        for (unsigned int i = 0; i < ARGV->getList().size(); i++) {
            sumatory = Integer::parse(ARGV->getList().at(i)) + sumatory.getValue();
        }

        cout << "Sumatory:" << sumatory.getValue() << endl;

    }

    return result;
}