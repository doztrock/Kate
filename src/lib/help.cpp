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

    cout << software.NAME << " " << software.VERSION << endl;
    cout << "Created by" << " " << software.AUTHOR << endl;
    cout << endl;

    cout << "Usage:" << " " << software.EXECUTABLE << " " << "[options]" << endl;

}