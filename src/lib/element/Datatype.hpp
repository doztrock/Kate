#ifndef DATATYPE_HPP
#define DATATYPE_HPP

#include "object/String.hpp"
#include "object/Double.hpp"
#include "object/Integer.hpp"
#include "object/Character.hpp"
#include "object/Boolean.hpp"
#include "object/Void.hpp"

typedef enum __datatype {
    String, Double, Integer, Character, Boolean, Void, Unknown
} Datatype;

#endif /* DATATYPE_HPP */
