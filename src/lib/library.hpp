#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * 
 * TRIM FUNCTIONS
 * 
 */
string trim(string str, const string trimChars = " \f\n\r\t\v");
string rtrim(string str, const string trimChars);
string ltrim(string str, const string trimChars);



/**
 * 
 * TEXT FUNCTIONS
 * 
 */
std::vector<std::string> explode(std::string str, char delim = ' ');


#endif /* LIBRARY_HPP */
