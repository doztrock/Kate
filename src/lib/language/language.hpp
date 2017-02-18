/**
 * 
 * This header define the language we'll use to show errors and messages
 * 
 */

#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#ifdef LANGUAGE

#if LANGUAGE == EN      // English
#include "en.hpp"
#elif LANGUAGE == ES    // Spanish
#include "es.hpp"
#endif

#else
#include "en.hpp"
#endif

#endif /* LANGUAGE_HPP */
