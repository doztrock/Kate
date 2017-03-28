#include "Boolean.hpp"

/**
 * 
 */
Boolean::Boolean() {
    this->setName("Boolean");
}

/**
 * 
 * @param value
 */
void Boolean::setValue(bool value) {
    this->value = value;
}

/**
 * 
 * @return 
 */
char Boolean::getValue() {
    return this->value;
}

Boolean &Boolean::operator=(bool value) {

    this->value = value;

    return *this;
}