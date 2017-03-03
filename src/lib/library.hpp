#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>

using namespace std;


/**
 * 
 * TRIM FUNCTIONS
 * 
 */
string trim(string str, const string trimChars = " \f\n\r\t\v");
string rtrim(string str, const string trimChars);
string ltrim(string str, const string trimChars);


#endif /* LIBRARY_HPP */
