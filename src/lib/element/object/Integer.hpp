#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <cstdlib>

#include "Object.hpp"

using namespace std;

class Integer : public Object {
public:

    /* Constructor */
    Integer();

    /* Value */
    void setValue(int value);
    int getValue(void);

    /* Operator */
    Integer &operator=(int value);

    /* Parsing */
    static int parse(string value);

private:
    int value;
};

#endif /* INTEGER_HPP */

