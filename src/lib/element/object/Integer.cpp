#include "Integer.hpp"

/**
 * 
 * @param value
 */
void Integer::setValue(int value) {
    this->value = value;
}

/**
 * 
 * @return 
 */
int Integer::getValue() {
    return this->value;
}

Integer &Integer::operator=(int value) {
    
    this->value = value;

    return *this;
}
