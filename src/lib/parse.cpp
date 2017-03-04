#include "parse.hpp"

/**
 * 
 * PARSE FUNCTIONS
 * 
 */

/**
 * Parse the file
 * @param ifstream    stream
 */
void parse(ifstream& stream) {

    string line;

    /** Counters */
    int lineCounter = 1;

    if (stream.is_open()) {

        while (getline(stream, line)) {

            line = trim(line);

            // Check if there's a comment (So, we'll ignore the other verifications
            if (checkComment(line) == false) {

                // Check if there's a constant
                if (checkConstant(line, lineCounter) == true) {
                }

                // Check if there's a variable
                if (checkVariable(line, lineCounter) == true) {
                }

                // Check if there's an assignment
                if (checkVariableAssignment(line, lineCounter) == true) {
                }

            }

            lineCounter++;
        }

        // Debug Information
        debugConstants();
        debugVariables();

        stream.close();
    }

    return;
}



/**
 * 
 * COMMENT FUNCTIONS
 * 
 */

/**
 * Check if there's a comment in the line
 * @param string    line
 * @param int       lineCounter
 */
bool checkComment(string line) {

    if (line.find_first_of(COMMENT_CHARACTER) == 0) {
        return true;
    }

    return false;
}



/**
 * 
 * CONSTANT FUNCTIONS
 * 
 */

/**
 * Check if there's a constant in the line
 * @param string    line
 * @param int       lineCounter
 */
bool checkConstant(string line, int lineCounter) {

    string constantName;
    string constantValue;

    for (int index = 0; index < KEYWORD_CONSTANT_LENGTH; index++) {

        if (trim(line).compare(trim(KEYWORD_CONSTANT[index])) == 0) {
            cout << "Expected constant name at line " << lineCounter << endl;
            break;
        }

        if (checkConstantAlone(line) == true) {
            cout << "Unused constant at line " << lineCounter << endl;
            break;
        }

        if (line.substr(0, KEYWORD_CONSTANT[index].size()).compare(KEYWORD_CONSTANT[index]) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:

                    constantName = trim(getConstantName(line));
                    constantValue = trim(getConstantValue(line));

                    if (constantExists(constantName)) {
                        cout << "You can't re-declare a previously declared constant in line " << lineCounter << endl;
                        return false;
                    }

                    if (!(constantName.empty() || constantValue.empty())) {

                        CONSTANT_CONTAINER[CONSTANT_CONTAINER_INDEX].setData(constantName, constantValue);
                        CONSTANT_CONTAINER_INDEX++;

                        return true;

                    } else {
                        cout << ERROR_CONSTANT_INITIALIZATION(lineCounter) << endl;
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

/**
 * Check if a constant exists based in its name
 * @param string    name
 */
bool constantExists(string name) {

    string constant;

    for (unsigned int i = 0; i < CONSTANT_CONTAINER_INDEX; i++) {

        constant = CONSTANT_CONTAINER[i].getName();

        if (name.compare(constant) == 0) {
            return true;
        }

    }

    return false;
}

bool checkConstantAlone(string line) {

    string constant;

    for (unsigned int i = 0; i < CONSTANT_CONTAINER_INDEX; i++) {

        constant = CONSTANT_CONTAINER[i].getName();

        if (trim(line).compare(constant) == 0) {
            return true;
        }

    }

    return false;
}

/**
 * Get the constant name based in its line
 * @param string    line
 */
string getConstantName(string line) {

    size_t start = line.find_first_of(WHITESPACE);
    size_t length = line.find_first_of(ASSIGNMENT_OPERATOR) - start;

    return trim(line.substr(start, length));
}

/**
 * Get the constant value based in its name
 * @param string    line
 */
string getConstantValue(string line) {
    return trim(line.substr(line.find_first_of(ASSIGNMENT_OPERATOR) + 1));
}



/**
 * 
 * VARIABLE FUNCTIONS
 * 
 */

/**
 * Check if there's a variable in the line
 * @param string    line
 * @param int       lineCounter
 */
bool checkVariable(string line, int lineCounter) {

    string variableName;
    string variableValue;

    for (int index = 0; index < KEYWORD_VARIABLE_LENGTH; index++) {

        if (trim(line).compare(trim(KEYWORD_VARIABLE[index])) == 0) {
            cout << "Expected variable name at line " << lineCounter << endl;
            break;
        }

        if (checkVariableAlone(line) == true) {
            cout << "Unused variable at line " << lineCounter << endl;
            break;
        }

        if (line.substr(0, KEYWORD_VARIABLE[index].size()).compare(KEYWORD_VARIABLE[index]) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 0:

                    variableName = trim(getVariableName(line));

                    if (checkVariableName(variableName) == true) {

                        VARIABLE_CONTAINER[VARIABLE_CONTAINER_INDEX].setName(variableName);
                        VARIABLE_CONTAINER_INDEX++;

                        return true;

                    } else {
                        cout << "Invalid variable name at " << lineCounter << endl;
                    }

                    break;

                case 1:

                    variableName = trim(getVariableName(line));
                    variableValue = trim(getVariableValue(line));

                    if (variableExists(variableName)) {
                        cout << "You can't re-declare a previously declared variable in line " << lineCounter << endl;
                        return false;
                    }

                    if (!(variableName.empty() || variableValue.empty())) {

                        if (checkVariableName(variableName) == true) {

                            VARIABLE_CONTAINER[VARIABLE_CONTAINER_INDEX].setData(variableName, variableValue);
                            VARIABLE_CONTAINER_INDEX++;

                            if (variableExists(variableValue)) {
                                copyValue(variableValue, variableName, VARIABLE_CONTAINER);
                            }

                            return true;

                        } else {
                            cout << "Invalid variable name at " << lineCounter << endl;
                        }

                    } else {
                        cout << ERROR_VARIABLE_INITIALIZATION(lineCounter) << endl;
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

/**
 * Check if there's an assignment in the line
 * @param string    line
 * @param int       lineCounter
 */
bool checkVariableAssignment(string line, int lineCounter) {

    string variable;
    string constant;
    string value;

    // We check if there's a variable assignment -> OK
    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        variable = VARIABLE_CONTAINER[i].getName();

        if (line.substr(0, variable.size()).compare(variable) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:

                    value = getVariableValue(line);

                    if (variableExists(value)) {
                        copyValue(value, variable, VARIABLE_CONTAINER);
                        return true;
                    }

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

    // We check if there's a constant assignment -> ERROR
    for (unsigned int i = 0; i < CONSTANT_CONTAINER_INDEX; i++) {

        constant = CONSTANT_CONTAINER[i].getName();

        if (line.substr(0, constant.size()).compare(constant) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:
                    cout << ERROR_CONSTANT_ASSIGNMENT(lineCounter) << endl;
                    break;

                default:
                    break;

            }

        }

    }

    return false;
}

/**
 * Check if the variable has a valid name based in its name
 * @param string    name
 */
bool checkVariableName(string name) {

    char first = name.at(0);
    char character;

    for (unsigned int i = 0; i < INVALID_CHARACTERS_VARIABLE_NAME.size(); i++) {

        character = INVALID_CHARACTERS_VARIABLE_NAME.at(i);

        if (first == character) {
            return false;
        }

    }

    return true;
}

/**
 * Check if a variable exists based in its name
 * @param string    name
 */
bool variableExists(string name) {

    string variable;

    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        variable = VARIABLE_CONTAINER[i].getName();

        if (name.compare(variable) == 0) {
            return true;
        }

    }

    return false;
}

bool checkVariableAlone(string line) {

    string variable;

    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        variable = VARIABLE_CONTAINER[i].getName();

        if (trim(line).compare(variable) == 0) {
            return true;
        }

    }

    return false;
}

/**
 * Copy the value between two variables, based in their names
 * @param string    origin
 * @param string    destiny
 * @param Variable  container
 */
void copyValue(string origin, string destiny, Variable container[CONTAINER_MAX_SIZE]) {

    string variable;
    string value;

    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        variable = VARIABLE_CONTAINER[i].getName();

        if (origin.compare(variable) == 0) {
            value = container[i].getValue();
            break;
        }

    }

    for (unsigned int j = 0; j < VARIABLE_CONTAINER_INDEX; j++) {

        variable = VARIABLE_CONTAINER[j].getName();

        if (destiny.compare(variable) == 0) {
            container[j].setValue(value);
            break;
        }

    }

    return;
}

/**
 * Get the variable name based in its line
 * @param string    line
 */
string getVariableName(string line) {

    size_t start = line.find_first_of(WHITESPACE);
    size_t length = line.find_first_of(ASSIGNMENT_OPERATOR) - start;

    return trim(line.substr(start, length));
}

/**
 * Get the variable value based in its name
 * @param string    line
 */
string getVariableValue(string line) {
    return trim(line.substr(line.find_first_of(ASSIGNMENT_OPERATOR) + 1));
}

/**
 * 
 * DEBUG FUNCTIONS
 * 
 */

/**
 * Show a constant list
 * @param void
 */
void debugConstants(void) {

    string constant;
    string value;

    cout << "List of constants:" << endl << endl;

    for (unsigned int index = 0; index < CONSTANT_CONTAINER_INDEX; index++) {

        constant = CONSTANT_CONTAINER[index].getName();
        value = CONSTANT_CONTAINER[index].getValue();

        cout << "Constant: " << constant << " || " << "Value: " << value << endl;

    }

    cout << endl << endl;

    return;
}

/**
 * Show a variable list
 * @param void
 */
void debugVariables(void) {

    string variable;
    string value;

    cout << "List of variables:" << endl << endl;

    for (unsigned int index = 0; index < VARIABLE_CONTAINER_INDEX; index++) {

        variable = VARIABLE_CONTAINER[index].getName();
        value = VARIABLE_CONTAINER[index].getValue();

        cout << "Variable: " << variable << " || " << "Value: " << value << endl;

    }

    cout << endl << endl;

    return;
}
