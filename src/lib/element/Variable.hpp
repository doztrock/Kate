#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <cstring>

using namespace std;

class Variable {
public:
    void setData(string name);
    void setData(string name, string value);
    void setName(string name);
    void setValue(string value);
    string getName(void);
    string getValue(void);
private:
    string name;
    string value;
};

#endif /* VARIABLE_HPP */

