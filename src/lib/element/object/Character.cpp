#include "Character.hpp"

/**
 * 
 */
Character::Character() {
    this->setName("Character");
}

/**
 * 
 * @param value
 */
void Character::setValue(char value) {
    this->value = value;
}

/**
 * 
 * @return 
 */
char Character::getValue() {
    return this->value;
}

Character &Character::operator=(char value) {

    this->value = value;

    return *this;
}