#ifndef HELP_HPP
#define HELP_HPP

#include <iostream>

using namespace std;

/** Software Information Structure */
typedef struct __softwareInformationStructure {
    const char *NAME;
    const char *VERSION;
    const char *AUTHOR;
    const char *EXECUTABLE;
} SoftwareInformation;


/** Help and Information */
void showHelp(SoftwareInformation software);


#endif /* HELP_HPP */
