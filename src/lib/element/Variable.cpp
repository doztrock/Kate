#include "Variable.hpp"

void Variable::setData(string name, string value) {
    this->name = name;
    this->value = value;
}

void Variable::setName(string name) {
    this->name = name;
}

void Variable::setValue(string value) {
    this->value = value;
}

string Variable::getName(void) {
    return this->name;
}

string Variable::getValue(void) {
    return this->value;
}
