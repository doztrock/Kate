/**
 * English!
 */

#ifndef EN_HPP
#define EN_HPP

#include <string>
#include <sstream>


#define INT_STRING(x) dynamic_cast<std::ostringstream &> ((std::ostringstream() << x )).str()


/**
 * 
 * FILE ERRORS
 * 
 */
std::string FILE_NOT_LOADED_SUCCESSFULLY(void);


/**
 * 
 * CONSTANT ERRORS
 * 
 */
std::string ERROR_CONSTANT_INITIALIZATION(int line);
std::string ERROR_CONSTANT_ASSIGNMENT(int line);
std::string ERROR_EXPECTED_CONSTANT_NAME(int line);
std::string ERROR_UNUSED_CONSTANT(int line);
std::string ERROR_REDECLARED_CONSTANT(int line);
std::string ERROR_INVALID_CONSTANT_NAME(int line);


/**
 * 
 * VARIABLE ERRORS
 * 
 */
std::string ERROR_VARIABLE_INITIALIZATION(int line);
std::string ERROR_VARIABLE_ASSIGNMENT(int line);
std::string ERROR_VARIABLE_ASSIGNMENT_EMPTY_VALUE(int line);
std::string ERROR_EXPECTED_VARIABLE_NAME(int line);
std::string ERROR_UNUSED_VARIABLE(int line);
std::string ERROR_REDECLARED_VARIABLE(int line);
std::string ERROR_INVALID_VARIABLE_NAME(int line);


#endif /* EN_HPP */
