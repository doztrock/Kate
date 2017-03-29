#include <iostream>
#include <cstdlib>

#include "Integer.hpp"
#include "Double.hpp"
#include "Character.hpp"
#include "String.hpp"
#include "Void.hpp"
#include "Boolean.hpp"

using namespace std;

int main(int argc, char** argv) {

    Integer Ninteger;
    Double Ndouble;
    Character Nchar;
    String Nstring;
    Void Nvoid;
    Boolean Nboolean;

    Ninteger = 12;
    Ndouble = 1.5;
    Nchar = 'Z';
    Nstring = "Hola mundo";
    Nboolean = false;

    cout << "Value:" << Ninteger.getValue() << endl;
    cout << "Value:" << Ndouble.getValue() << endl;
    cout << "Value:" << Nchar.getValue() << endl;
    cout << "Value:" << Nstring.getValue() << endl;
    cout << "Value:" << (Nboolean.getValue() ? "TRUE" : "FALSE") << endl;

    return 0;
}

