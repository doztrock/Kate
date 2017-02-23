/**
 * English!
 */

#ifndef EN_HPP
#define EN_HPP

#include <string>
#include <sstream>

#define SSTR(x) dynamic_cast<std::ostringstream &> ((std::ostringstream() << x )).str()

std::string FILE_NOT_LOADED_SUCCESSFULLY(void);

std::string ERROR_VARIABLE_INITIALIZATION(int line);
std::string ERROR_VARIABLE_ASSIGNMENT(int line);
std::string ERROR_VARIABLE_ASSIGNMENT_EMPTY_VALUE(int line);

std::string ERROR_CONSTANT_INITIALIZATION(int line);
std::string ERROR_CONSTANT_ASSIGNMENT(int line);

#endif /* EN_HPP */
