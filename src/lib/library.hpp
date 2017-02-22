#ifndef LIBRARY_HPP
#define LIBRARY_HPP

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


#endif /* LIBRARY_HPP */
