#include "Constant.hpp"

void Constant::setData(string name, string value) {
    this->name = name;
    this->value = value;
}

void Constant::setDatatype(Datatype datatype) {
    this->datatype = datatype;
}

string Constant::getName(void) {
    return this->name;
}

string Constant::getValue(void) {
    return this->value;
}

Datatype Constant::getDatatype() {
    return this->datatype;
}
