#include "Integer.hpp"

/**
 * 
 */
Integer::Integer() {
    this->setName("Integer");
}

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

/**
 * 
 * @param value
 * @return 
 */
int Integer::parse(string value) {
    return atoi(value.c_str());
}

