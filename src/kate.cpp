#include <iostream>
#include <cstdlib>
#include <fstream>

#include "lib/kate.hpp"
#include "lib/parse.hpp"
#include "lib/library.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    /** Information */
    SoftwareInformation software = {
        .NAME = SOFTWARE_NAME,
        .VERSION = SOFTWARE_VERSION,
        .AUTHOR = SOFTWARE_AUTHOR,
        .EXECUTABLE = argv[0]
    };

    /** Selected Option */
    int option;

    while ((option = getopt_long(argc, argv, SHORT_OPTIONS, LONG_OPTIONS, NULL)) != -1) {

        switch (option) {

            case 'h':
                showHelp(software);
                return EXIT_SUCCESS;
                break;

            default:
                break;

        }

    }


    /* File we'll run */
    char *file = NULL;
    ifstream stream;

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    file = argv[1];

    stream.open(file, std::ios::in);

    if (stream.is_open()) {

        parse(stream);

        stream.close();
    } else {
        cout << FILE_NOT_LOADED_SUCCESSFULLY() << endl;
    }

    return EXIT_SUCCESS;
}
