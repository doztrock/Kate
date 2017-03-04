#include "help.hpp"

/**
 * 
 * SOFTWARE HELP & INFORMACION FUNCTION
 * 
 */

/**
 * Display the software information and help
 * @param SoftwareInformation   software
 */
void showHelp(SoftwareInformation software) {

    // Usage
    cout << "Usage:" << " " << software.EXECUTABLE << " " << "[FILE]" << endl;
    cout << endl;

    // Software
    cout << software.NAME << " " << software.VERSION << endl;
    cout << "Created by" << " " << software.AUTHOR << endl;
    cout << endl;

    // Build
    cout << "Build on" << " "
            << OS_NAME << " "
            << OS_ARCHITECTURE << " "
            << "At" << " "
            << __DATE__;

}