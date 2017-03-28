#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Object.hpp"

using namespace std;

class Character : public Object {
public:

    /* Constructor */
    Character();

    /* Value */
    void setValue(char value);
    char getValue(void);

    /* Operator */
    Character &operator=(char value);

private:
    char value;
};

#endif /* CHARACTER_HPP */

