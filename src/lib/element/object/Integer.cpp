#include "Integer.hpp"

/**
 * 
 * @param value
 */
void Integer::setValue(string value) {
    this->value = value;
}

/**
 * 
 * @return 
 */
string Integer::getValue() {
    return this->value;
}

Integer* Integer::operator=(string value) {

    
    this->value = value;

    return this;
}
