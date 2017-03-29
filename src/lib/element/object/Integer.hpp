#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <string>

#include "Object.hpp"

using namespace std;

class Integer : public Object {
public:

    /* Value */
    void setValue(string value);
    string getValue(void);

    /* Operator */
    Integer* operator=(string value);

private:
    string value;
};

#endif /* INTEGER_HPP */

