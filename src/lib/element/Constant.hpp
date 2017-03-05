#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <iostream>
#include <string>

#include "Datatype.hpp"

using namespace std;

class Constant {
public:
    void setData(string name, string value);
    void setDatatype(Datatype datatype);

    string getName(void);
    string getValue(void);
    Datatype getDatatype(void);

private:
    string name;
    string value;
    Datatype datatype;
};

#endif /* CONSTANT_HPP */
