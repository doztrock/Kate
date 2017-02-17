#include <iostream>
#include <cstdlib>
#include <fstream>

#include "lib/parse.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    /* File we'll run */
    char *file = NULL;
    ifstream stream;

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    file = argv[1];

    stream.open(file, std::ios::in);

    if (stream.is_open()) {

        cout << "File loaded successfully\n";
        cout << "File contents below:\n\n";
        
        parse(stream);
        
        stream.close();
    } else {
        cout << "File NOT loaded successfully\n";
    }

    return EXIT_SUCCESS;
}
