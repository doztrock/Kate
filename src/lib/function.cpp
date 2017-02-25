#include "function.hpp"

string interpolate(string line) {

    int beginCount = count(line.begin(), line.end(), INTERPOLATION_OPERATOR_BEGIN);
    int endCount = count(line.begin(), line.end(), INTERPOLATION_OPERATOR_END);
    int total = 0;

    if (beginCount == endCount) {

        total = (int) ((beginCount + endCount) / 2);

        for (unsigned int i = 0; i < total; i++) {

            cout << line.find_first_of(INTERPOLATION_OPERATOR_BEGIN);


        }


    } else {
        cout << "Error, con variables en cadena";
    }

}

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

    cout << trim(interpolate(line).substr(function.size()), "\" ");

    return false;
}

bool println(string function, string line) {

    cout << trim(interpolate(line).substr(function.size()), "\" ") << endl;

    return false;
}