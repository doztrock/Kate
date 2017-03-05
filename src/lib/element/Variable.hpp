#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <string>

#include "Datatype.hpp"

using namespace std;

class Variable {
public:
    void setData(string name, string value);
    void setName(string name);
    void setValue(string value);
    void setDatatype(Datatype datatype);

    string getName(void);
    string getValue(void);
    Datatype getDatatype(void);

private:
    string name;
    string value;
    Datatype datatype;
};

#endif /* VARIABLE_HPP */

