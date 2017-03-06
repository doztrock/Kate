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
    Datatype constantDatatype;

    for (int index = 0; index < KEYWORD_CONSTANT_LENGTH; index++) {

        if (trim(line).compare(trim(KEYWORD_CONSTANT[index])) == 0) {
            cout << ERROR_EXPECTED_CONSTANT_NAME(lineCounter) << endl;
            break;
        }

        if (checkConstantAlone(line) == true) {
            cout << ERROR_UNUSED_CONSTANT(lineCounter) << endl;
            break;
        }

        if (line.substr(0, KEYWORD_CONSTANT[index].size()).compare(KEYWORD_CONSTANT[index]) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:

                    constantName = trim(getConstantName(line));
                    constantValue = trim(getConstantValue(line));
                    constantDatatype = getDatatype(constantValue);

                    if (constantDatatype == Unknown) {
                        cout << "Unknown datatype at line " << lineCounter << endl;
                    }

                    if (variableExists(constantName)) {
                        cout << "There's an already-declared variable with this name at " << lineCounter << endl;
                        return false;
                    }

                    if (constantExists(constantName)) {
                        cout << ERROR_REDECLARED_CONSTANT(lineCounter) << endl;
                        return false;
                    }

                    if (!(constantName.empty() || constantValue.empty())) {

                        if (checkElementName(constantName) == true) {

                            CONSTANT_CONTAINER[CONSTANT_CONTAINER_INDEX].setData(constantName, constantValue);
                            CONSTANT_CONTAINER[CONSTANT_CONTAINER_INDEX].setDatatype(constantDatatype);
                            CONSTANT_CONTAINER_INDEX++;

                            return true;

                        } else {
                            cout << ERROR_INVALID_CONSTANT_NAME(lineCounter) << endl;
                        }

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
    Datatype variableDatatype;

    for (int index = 0; index < KEYWORD_VARIABLE_LENGTH; index++) {

        if (trim(line).compare(trim(KEYWORD_VARIABLE[index])) == 0) {
            cout << ERROR_EXPECTED_VARIABLE_NAME(lineCounter) << endl;
            break;
        }

        if (checkVariableAlone(line) == true) {
            cout << ERROR_UNUSED_VARIABLE(lineCounter) << endl;
            break;
        }

        if (line.substr(0, KEYWORD_VARIABLE[index].size()).compare(KEYWORD_VARIABLE[index]) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 0:

                    variableName = trim(getVariableName(line));

                    if (checkElementName(variableName) == true) {

                        VARIABLE_CONTAINER[VARIABLE_CONTAINER_INDEX].setName(variableName);
                        VARIABLE_CONTAINER_INDEX++;

                        return true;

                    } else {
                        cout << ERROR_INVALID_VARIABLE_NAME(lineCounter) << endl;
                    }

                    break;

                case 1:

                    variableName = trim(getVariableName(line));
                    variableValue = trim(getVariableValue(line));
                    variableDatatype = getDatatype(variableValue);

                    if (constantExists(variableName)) {
                        cout << "There's an already-declared constant with this name at " << lineCounter << endl;
                        return false;
                    }

                    if (variableExists(variableName)) {
                        cout << ERROR_REDECLARED_VARIABLE(lineCounter) << endl;
                        return false;
                    }

                    if (!(variableName.empty() || variableValue.empty())) {

                        if (checkElementName(variableName) == true) {

                            VARIABLE_CONTAINER[VARIABLE_CONTAINER_INDEX].setData(variableName, variableValue);
                            VARIABLE_CONTAINER[VARIABLE_CONTAINER_INDEX].setDatatype(variableDatatype);
                            VARIABLE_CONTAINER_INDEX++;


                            if (variableExists(variableValue)) {
                                // If there's an assignment (Variable-Variable)
                                copyValueFromVariable(variableValue, variableName);
                            } else if (constantExists(variableValue)) {
                                // If there's an assignment (Constant-Variable)
                                copyValueFromConstant(variableValue, variableName);
                            } else {

                                if (variableDatatype == Unknown) {
                                    cout << "Unknown datatype at line " << lineCounter << endl;
                                }

                            }

                            return true;

                        } else {
                            cout << ERROR_INVALID_VARIABLE_NAME(lineCounter) << endl;
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
    Datatype variableDatatype;

    // We check if there's a variable assignment -> OK
    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        variable = VARIABLE_CONTAINER[i].getName();

        if (line.substr(0, variable.size()).compare(variable) == 0) {

            switch (count(line.begin(), line.end(), ASSIGNMENT_OPERATOR)) {

                case 1:

                    value = getVariableValue(line);
                    variableDatatype = getDatatype(value);

                    if (variableExists(value)) {
                        // If there's an assignment (Variable-Variable)
                        copyValueFromVariable(value, variable);
                        return true;
                    } else if (constantExists(value)) {
                        // If there's an assignment (Constant-Variable)
                        copyValueFromConstant(value, variable);
                        return true;
                    } else {

                        if (variableDatatype == Unknown) {
                            cout << "Unknown datatype at line " << lineCounter << endl;
                        }

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
 */
void copyValueFromVariable(string origin, string destiny) {

    /* Origin Variable */
    string originVariableName;
    string originVariableValue;

    /* Destiny Variable */
    string destinyVariableName;

    for (unsigned int i = 0; i < VARIABLE_CONTAINER_INDEX; i++) {

        originVariableName = VARIABLE_CONTAINER[i].getName();

        if (origin.compare(originVariableName) == 0) {
            originVariableValue = VARIABLE_CONTAINER[i].getValue();
            break;
        }

    }

    for (unsigned int j = 0; j < VARIABLE_CONTAINER_INDEX; j++) {

        destinyVariableName = VARIABLE_CONTAINER[j].getName();

        if (destiny.compare(destinyVariableName) == 0) {
            VARIABLE_CONTAINER[j].setValue(originVariableValue);
            VARIABLE_CONTAINER[j].setDatatype(getDatatype(originVariableValue));
            break;
        }

    }

    return;
}

/**
 * Copy the value between a constant and a variable, based in their names
 * @param string    origin
 * @param string    destiny
 */
void copyValueFromConstant(string origin, string destiny) {

    /* Origin Constant */
    string originConstantName;
    string originConstantValue;

    /* Destiny Variable */
    string destinyVariableName;

    for (unsigned int i = 0; i < CONSTANT_CONTAINER_INDEX; i++) {

        originConstantName = CONSTANT_CONTAINER[i].getName();

        if (origin.compare(originConstantName) == 0) {
            originConstantValue = CONSTANT_CONTAINER[i].getValue();
            break;
        }

    }

    for (unsigned int j = 0; j < VARIABLE_CONTAINER_INDEX; j++) {

        destinyVariableName = VARIABLE_CONTAINER[j].getName();

        if (destiny.compare(destinyVariableName) == 0) {
            VARIABLE_CONTAINER[j].setValue(originConstantValue);
            VARIABLE_CONTAINER[j].setDatatype(getDatatype(originConstantValue));
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
 * ELEMENT COMMON FUNCTIONS
 * 
 */

/**
 * Check if the element has a valid name
 * @param string    name
 */
bool checkElementName(string name) {

    char first = name.at(0);
    char character;

    for (unsigned int i = 0; i < INVALID_CHARACTERS_ELEMENT_NAME.size(); i++) {

        character = INVALID_CHARACTERS_ELEMENT_NAME.at(i);

        if (first == character) {
            return false;
        }

    }

    return true;
}

Datatype getDatatype(string value) {

    value = trim(value);

    // String
    if (value.at(0) == '"' && value.at(value.size() - 1) == '"') {
        return String;
    }

    // Double
    if (value.find_first_not_of("0123456789.") == string::npos) {

        if (count(value.begin(), value.end(), '.') == 1) {
            return Double;
        }

    }

    // Integer
    if (value.find_first_not_of("0123456789") == string::npos) {
        return Integer;
    }

    // Character
    if (value.size() == 3 && value.at(0) == '\'' && value.at(value.size() - 1) == '\'') {
        return Character;
    }

    return Unknown;
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
    Datatype datatype;

    cout << "List of constants:" << endl << endl;

    for (unsigned int index = 0; index < CONSTANT_CONTAINER_INDEX; index++) {

        constant = CONSTANT_CONTAINER[index].getName();
        value = CONSTANT_CONTAINER[index].getValue();
        datatype = CONSTANT_CONTAINER[index].getDatatype();

        cout << "Constant: " << constant;
        cout << " || ";
        cout << "Value: " << value;
        cout << " || ";

        switch (datatype) {

            case String:
                cout << "Type: " << "String";
                break;

            case Double:
                cout << "Type: " << "Double";
                break;

            case Integer:
                cout << "Type: " << "Integer";
                break;

            case Character:
                cout << "Type: " << "Character";
                break;

            case Unknown:
                cout << "Type: " << "Unknown";
                break;

        }

        cout << endl;
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
    Datatype datatype;

    cout << "List of variables:" << endl << endl;

    for (unsigned int index = 0; index < VARIABLE_CONTAINER_INDEX; index++) {

        variable = VARIABLE_CONTAINER[index].getName();
        value = VARIABLE_CONTAINER[index].getValue();
        datatype = VARIABLE_CONTAINER[index].getDatatype();

        cout << "Variable: " << variable;
        cout << " || ";
        cout << "Value: " << value;
        cout << " || ";

        switch (datatype) {

            case String:
                cout << "Type: " << "String";
                break;

            case Double:
                cout << "Type: " << "Double";
                break;

            case Integer:
                cout << "Type: " << "Integer";
                break;

            case Character:
                cout << "Type: " << "Character";
                break;

            case Unknown:
                cout << "Type: " << "Unknown";
                break;

        }

        cout << endl;
    }

    cout << endl << endl;

    return;
}
