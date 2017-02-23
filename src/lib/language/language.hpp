/**
 *
 * This header define the language we'll use to show errors and messages
 *
 */

#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#ifdef LANGUAGE

#ifdef en       // English
#include "en.hpp"
#elif es        // Spanish
#include "es.hpp"
#endif
#endif

#ifndef LANGUAGE
#include "en.hpp"
#endif

#endif /* LANGUAGE_HPP */
