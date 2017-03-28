#include <iostream>
#include <cstdlib>

#include "Integer.hpp"

using namespace std;

int main(int argc, char** argv) {

    Integer number;
        
    number = 44;
     
    cout << "Value:" << number.getValue();
    
    return 0;
}

