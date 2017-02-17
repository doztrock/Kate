#include "parse.hpp"

void parse(ifstream& stream) {

    string line;

    /** Counters */
    int lineCounter = 1;
    int variableCounter = 0;

    if (stream.is_open()) {

        while (getline(stream, line)) {

            line = trim(line);

            // Check if there's a variable
            if (checkVariable(line, lineCounter) == true) {
                variableCounter++;
            }

            lineCounter++;
        }

    }

    cout << "We've found " << variableCounter << " variables" << endl;

    return;
}

/**
 * Check if the line contents a variable (declared and initialized) and if its syntax is valid.
 */
bool checkVariable(string line, int lineCounter) {

    for (int index = 0; index < KEYWORD_VARIABLE_LENGTH; index++) {

        if (line.substr(0, KEYWORD_VARIABLE[index].size()).compare(KEYWORD_VARIABLE[index]) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 0:
                    cout << "Variable: " << getVariableName(line) << endl << endl;
                    return true;
                    break;

                case 1:
                    cout << "Variable: " << getVariableName(line) << endl;
                    cout << "Valor:    " << getVariableValue(line) << endl << endl;
                    return true;
                    break;

                default:
                    cout << "Error with variable initialization at line " << lineCounter << endl;
                    break;

            }

        }

    }

    return false;
}

string getVariableName(string line) {

    size_t start = line.find_first_of(" ");
    size_t length = line.find_first_of(ASSIGNMENT_OPERATOR) - start;

    return trim(line.substr(start, length));
}

string getVariableValue(string line) {
    return trim(line.substr(line.find_first_of(ASSIGNMENT_OPERATOR) + 1));
}
