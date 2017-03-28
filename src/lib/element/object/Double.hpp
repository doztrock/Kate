#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "Object.hpp"

using namespace std;

class Double : public Object {
public:

    /* Constructor */
    Double();

    /* Value */
    void setValue(double value);
    double getValue(void);

    /* Operator */
    Double &operator=(double value);

private:
    double value;
};

#endif /* DOUBLE_HPP */

