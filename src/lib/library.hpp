#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>

using namespace std;

static const string TRIM_WHITESPACES = " \f\n\r\t\v";

string trim(string str, const string trimChars = TRIM_WHITESPACES);
string rtrim(string str, const string trimChars = TRIM_WHITESPACES);
string ltrim(string str, const string trimChars = TRIM_WHITESPACES);

#endif /* LIBRARY_HPP */
