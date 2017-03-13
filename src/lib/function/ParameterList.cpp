#include "ParameterList.hpp"

void ParameterList::appendParameter(string parameter) {
    this->list.insert(this->list.end(), parameter);
}

vector<string> ParameterList::getList(void) {
    return this->list;
}