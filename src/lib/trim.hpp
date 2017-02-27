#ifndef TRIM_HPP
#define TRIM_HPP

#include <string>

using namespace std;

static const string WHITESPACES = " \f\n\r\t\v";

string trim(string str, const string trimChars = WHITESPACES);

string rtrim(string str, const string trimChars = WHITESPACES);
string ltrim(string str, const string trimChars = WHITESPACES);

#endif /* TRIM_HPP */

