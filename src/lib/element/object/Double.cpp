#include "Double.hpp"

/**
 * 
 */
Double::Double() {
    this->setName("Double");
}

/**
 * 
 * @param value
 */
void Double::setValue(double value) {
    this->value = value;
}

/**
 * 
 * @return 
 */
double Double::getValue() {
    return this->value;
}

Double &Double::operator=(double value) {

    this->value = value;

    return *this;
}