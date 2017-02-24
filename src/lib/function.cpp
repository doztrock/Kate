#include "function.hpp"

/** Execute the functions */
bool execute(ExecutionType executionType, string function, string line, int lineCounter) {

    bool result = false;

    switch (executionType) {

        case EMBEDDED_DEFINED_FUNCTION:
            result = executeEmbeddedDefinedFunction(function, line, lineCounter);
            break;

        case USER_DEFINED_FUNCTION:
            break;

        default:
            break;
    }

    return result;
}

bool executeEmbeddedDefinedFunction(string function, string line, int lineCounter) {

    // print
    if (function.compare(EMBEDDED_FUNCTION[0]) == 0) {
        print(EMBEDDED_FUNCTION[0], line);
        return true;
    }

    // println
    if (function.compare(EMBEDDED_FUNCTION[1]) == 0) {
        println(EMBEDDED_FUNCTION[1], line);
        return true;
    }

    return false;
}

bool print(string function, string line) {

    cout << trim(line.substr(function.size()), "\" ");

    return false;
}

bool println(string function, string line) {

    cout << trim(line.substr(function.size()), "\" ") << endl;

    return false;
}