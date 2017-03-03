#ifndef HELP_HPP
#define HELP_HPP

#include <iostream>

using namespace std;

/**
 * 
 * SOFTWARE INFORMATION
 * 
 */
typedef struct __software_information_structure {
    const char *NAME;
    const char *VERSION;
    const char *AUTHOR;
    const char *EXECUTABLE;
} SoftwareInformation;


/**
 * 
 * SOFTWARE HELP & INFORMACION FUNCTION
 * 
 */
void showHelp(SoftwareInformation software);


#endif /* HELP_HPP */
