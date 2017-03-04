#ifndef HELP_HPP
#define HELP_HPP

#include <iostream>


/**
 * 
 * OS NAME
 * 
 */
#ifndef OS_NAME

#ifdef __linux__
#define OS_NAME     "GNU/Linux"
#elif __WIN32
#define OS_NAME     "Windows"
#elif __APPLE__
#define OS_NAME     "Mac OS"
#else
#define OS_NAME     "Unknown"
#endif

#endif


/**
 * 
 * OS ARCHITECTURE
 * 
 */
#ifndef OS_ARCHITECTURE

#ifdef __i386__
#define OS_ARCHITECTURE     "x86"
#elif __amd64__
#define OS_ARCHITECTURE     "x86_64"
#elif __arm__
#define OS_ARCHITECTURE     "arm"
#elif __aarch64__
#define OS_ARCHITECTURE     "arm64"
#else
#define OS_ARCHITECTURE     "Unknown"
#endif

#endif


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
