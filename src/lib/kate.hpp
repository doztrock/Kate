#ifndef KATE_HPP
#define KATE_HPP

#include <string>
#include <getopt.h>

/** Short Options String*/
const char *SHORT_OPTIONS = (const char *) std::string("h").c_str();

/** Long Options Structure */
static struct option LONG_OPTIONS[] = {
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
};

#endif /* KATE_HPP */

