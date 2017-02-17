#include <iostream>
#include <cstdlib>
#include <fstream>

// Windows
#ifdef _WIN32

#elif __linux__

#endif

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

        stream.close();
    } else {
        cout << "File NOT loaded successfully\n";
    }

    return EXIT_SUCCESS;
}
