/**
 *
 * This header define the language we'll use to show errors and messages
 *
 */

#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#ifdef LANGUAGE

#ifdef EN      // English
#include "EN.hpp"
#elif ES    // Spanish
#include "ES.hpp"
#endif
#endif

#ifndef LANGUAGE
#include "EN.hpp"
#endif

#endif /* LANGUAGE_HPP */
