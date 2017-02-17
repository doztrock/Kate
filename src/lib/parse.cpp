#include "parse.hpp"

void parse(ifstream& stream){
    
    string line;
    
    if(stream.is_open()){
    
        while(getline(stream, line)){
            cout << trim(line) << endl;
        }
        
    }
    
    return;
}

/**
 * Check if the line contents a variable (declared and initialized) and if its syntax is valid.
 */
bool checkVariable(string line){

    return false;
    
}
