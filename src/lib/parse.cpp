#include "parse.hpp"

void parse(ifstream& stream) {

    string line;

    /** Counters */
    int lineCounter = 1;

    if (stream.is_open()) {

        while (getline(stream, line)) {

            line = trim(line);

            // Check if there's a variable
            if (checkVariable(line, lineCounter) == true) {
            }

            // Check if there's an assignment
            if (checkVariableAssignment(line, lineCounter) == true) {
            }

            // Check if there's a constant
            if (checkConstant(line, lineCounter) == true) {
            }

            // Check if there's an assignment with operation
            if (checkVariableAssignmentWithOperation(line, lineCounter) == true) {
            }

            lineCounter++;
        }

    }

    return;
}

/**
 * Check if the line contents a variable and if its syntax is valid.
 */
bool checkVariable(string line, int lineCounter) {

    string variableName;
    string variableValue;

    for (int index = 0; index < KEYWORD_VARIABLE_LENGTH; index++) {

        if (line.substr(0, KEYWORD_VARIABLE[index].size()).compare(KEYWORD_VARIABLE[index]) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 0:

                    variableName = getVariableName(line);

                    if (!variableName.empty()) {

                        VARIABLE_CONTAINER[VARIABLE_CONTAINER_INDEX].setData(variableName);
                        VARIABLE_CONTAINER_INDEX++;

                        return true;
                    }

                    break;

                case 1:

                    variableName = getVariableName(line);
                    variableValue = getVariableValue(line);

                    if (!(variableName.empty() && variableValue.empty())) {

                        VARIABLE_CONTAINER[VARIABLE_CONTAINER_INDEX].setData(variableName, variableValue);
                        VARIABLE_CONTAINER_INDEX++;

                        return true;
                    }

                    break;

                default:
                    cout << ERROR_VARIABLE_INITIALIZATION(lineCounter) << endl;
                    break;

            }

        }

    }

    return false;
}

bool checkVariableAssignment(string line, int lineCounter) {

    string variable;
    string value;

    // We check if there's a variable assignment
    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        variable = VARIABLE_CONTAINER[i].getName();

        if (line.substr(0, variable.size()).compare(variable) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:

                    value = getVariableValue(line);

                    if (!value.empty()) {
                        VARIABLE_CONTAINER[i].setData(variable, value);
                        return true;
                    } else {
                        cout << ERROR_VARIABLE_ASSIGNMENT_EMPTY_VALUE(lineCounter) << endl;
                    }

                    break;

                default:
                    cout << ERROR_VARIABLE_ASSIGNMENT(lineCounter) << endl;
                    break;

            }

        }

    }

    // We check if there's a constant assignment -> Error
    for (unsigned int i = 0; i < CONSTANT_CONTAINER_INDEX; i++) {

        variable = CONSTANT_CONTAINER[i].getName();

        if (line.substr(0, variable.size()).compare(variable) == 0) {
            cout << ERROR_CONSTANT_ASSIGNMENT(lineCounter) << endl;
        }

    }

    return false;
}

string getVariableName(string line) {

    size_t start = line.find_first_of(WHITESPACE);
    size_t length = line.find_first_of(ASSIGNMENT_OPERATOR) - start;

    return trim(line.substr(start, length));
}

string getVariableValue(string line) {
    return trim(line.substr(line.find_first_of(ASSIGNMENT_OPERATOR) + 1));
}

/**
 * Check if the line contents a constant and if its syntax is valid.
 */
bool checkConstant(string line, int lineCounter) {

    string constantName;
    string constantValue;

    for (int index = 0; index < KEYWORD_CONSTANT_LENGTH; index++) {

        if (line.substr(0, KEYWORD_CONSTANT[index].size()).compare(KEYWORD_CONSTANT[index]) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:

                    constantName = getConstantName(line);
                    constantValue = getConstantValue(line);

                    if (!(constantName.empty() && constantValue.empty())) {

                        CONSTANT_CONTAINER[CONSTANT_CONTAINER_INDEX].setData(constantName, constantValue);
                        CONSTANT_CONTAINER_INDEX++;

                        return true;
                    }

                    break;

                default:
                    cout << ERROR_CONSTANT_INITIALIZATION(lineCounter) << endl;
                    break;

            }

        }

    }

    return false;
}

string getConstantName(string line) {

    size_t start = line.find_first_of(WHITESPACE);
    size_t length = line.find_first_of(ASSIGNMENT_OPERATOR) - start;

    return trim(line.substr(start, length));
}

string getConstantValue(string line) {
    return trim(line.substr(line.find_first_of(ASSIGNMENT_OPERATOR) + 1));
}
//TODO: Incluir parse en declaration

bool checkVariableAssignmentWithOperation(string line, int lineCounter) {

    string variable;

    // We check if there's a valid variable assignment, but in this case we will
    // assign the result from one arithmetic operation
    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        variable = VARIABLE_CONTAINER[i].getName();

        if (line.substr(0, line.find_first_of(ASSIGNMENT_OPERATOR)).compare(variable) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:
                    parseOperation(line);
                    break;

                default:
                    cout << ERROR_VARIABLE_ASSIGNMENT(lineCounter) << endl;
                    break;

            }

        }

    }

    return false;
}

/** 
 * Parse and Execute an arithmetic operation and return its result as a string
 */
string parseOperation(string line) {

    string operation = trim(line.substr(line.find_first_of(ASSIGNMENT_OPERATOR) + 1));
    char operator;
    
    for (unsigned int i = 0; i < ORDER_OF_OPERATIONS; i++) {
        
        
        
    }


    cout << operation << endl;

    return "";
}