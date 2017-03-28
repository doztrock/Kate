#include "String.hpp"

/**
 * 
 */
String::String() {
    this->setName("String");
}

/**
 * 
 * @param value
 */
void String::setValue(string value) {
    this->value = value;
}

/**
 * 
 * @return 
 */
string String::getValue() {
    return this->value;
}

String &String::operator=(string value) {

    this->value = value;

    return *this;
}