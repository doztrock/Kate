#include <iostream>
#include <cstdlib>

#include "Integer.hpp"

using namespace std;

int main(int argc, char** argv) {

    Integer *i;
    const string s = "Hola mundo";
    
    i = s;
 
    
    cout << "Value:" << i->getValue();
    
    return 0;
}

