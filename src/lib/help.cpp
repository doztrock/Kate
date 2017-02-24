#include "help.hpp"

void showHelp(SoftwareInformation software) {

    cout << software.NAME << " " << software.VERSION << endl;
    cout << "Created by" << " " << software.AUTHOR << endl;
    cout << endl;

    cout << "Usage:" << " " << software.EXECUTABLE << " " << "[options]" << endl;

}