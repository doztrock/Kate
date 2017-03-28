#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <string>

#include "Object.hpp"

using namespace std;

class Integer : public Object {
public:

    /* Value */
    void setValue(int value);
    int getValue(void);

    /* Operator */
    Integer &operator=(int value);

private:
    int value;
};

#endif /* INTEGER_HPP */

