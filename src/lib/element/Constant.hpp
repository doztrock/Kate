#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <iostream>
#include <string>

using namespace std;

class Constant {
public:
    void setData(string name, string value);
    string getName(void);
    string getValue(void);
private:
    string name;
    string value;
};

#endif /* CONSTANT_HPP */
