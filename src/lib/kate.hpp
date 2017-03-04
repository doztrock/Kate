#ifndef KATE_HPP
#define KATE_HPP

#include <string>
#include <getopt.h>

/**
 * 
 * SOFTWARE NAME
 * 
 */
#define SOFTWARE_NAME "Kate"


/**
 * 
 * SOFTWARE VERSION
 * 
 */
#define SOFTWARE_VERSION "0.0.1"


/**
 * 
 * SOFTWARE AUTHOR
 * 
 */
#define SOFTWARE_AUTHOR "Ivan B."


/**
 * 
 * SOFTWARE SHORT OPTIONS SCHEMA
 * 
 */
const char *SHORT_OPTIONS = (const char *) std::string("h").c_str();

/**
 * 
 * SOFTWARE LONG OPTIONS STRUCTURE
 * 
 */
static struct option LONG_OPTIONS[] = {
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
};


#endif /* KATE_HPP */
