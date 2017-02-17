#include "parse.hpp"

void parse(ifstream& stream) {

    string line;

    /** Counters */
    int variableCounter = 0;

    if (stream.is_open()) {

        while (getline(stream, line)) {

            line = trim(line);

            // Check if there's a variable
            if (checkVariable(line) == true) {
                variableCounter++;
            }

        }

    }

    cout << "We've found " << variableCounter << " variables" << endl;

    return;
}

/**
 * Check if the line contents a variable (declared and initialized) and if its syntax is valid.
 */
bool checkVariable(string line) {

    for (int index = 0; index < KEYWORD_VARIABLE_LENGTH; index++) {

        if (line.substr(0, KEYWORD_VARIABLE[index].size()).compare(KEYWORD_VARIABLE[index]) == 0) {
            return true;
        }

    }

    return false;
}
