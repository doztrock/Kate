#ifndef BOOLEAN_HPP
#define BOOLEAN_HPP

#include "Object.hpp"

using namespace std;

class Boolean : public Object {
public:

    /* Constructor */
    Boolean();

    /* Value */
    void setValue(bool value);
    bool getValue(void);

    /* Operator */
    Boolean &operator=(bool value);

private:
    bool value;
};

#endif /* BOOLEAN_HPP */

