#ifndef STRING_HPP
#define STRING_HPP

#include <string>

#include "Object.hpp"

using namespace std;

class String : public Object {
public:

    /* Constructor */
    String();

    /* Value */
    void setValue(string value);
    string getValue(void);

    /* Operator */
    String &operator=(string value);

private:
    string value;
};

#endif /* STRING_HPP */

