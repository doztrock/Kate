#include "library.hpp"

/**
 * 
 * TRIM FUNCTIONS
 * 
 */

/**
 * Strip whitespace (or other characters) from the beginning and end of a string
 * @param string    str
 * @param string    trimChar
 */
string trim(string str, const string trimChars) {
    return rtrim(ltrim(str, trimChars), trimChars);
}

/**
 * Strip whitespace (or other characters) from the end of a string
 * @param string    str
 * @param string    trimChar
 */
string rtrim(string str, const string trimChars) {
    str.erase(str.find_last_not_of(trimChars) + 1);
    return str;
}

/**
 * Strip whitespace (or other characters) from the beginning of a string
 * @param string    str
 * @param string    trimChar
 */
string ltrim(string str, const string trimChars) {
    str.erase(0, str.find_first_not_of(trimChars));
    return str;
}



/**
 * 
 * TEXT FUNCTIONS
 * 
 */

/**
 * EXPLODE
 * @param str
 * @param delim
 * @return 
 */
std::vector<std::string> explode(std::string str, char delim) {

    std::vector<std::string> result;
    std::stringstream stream(str);
    std::string buffer = "";

    while (std::getline(stream, buffer, delim)) {
        result.push_back(buffer);
    }

    return result;
}