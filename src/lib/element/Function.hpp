#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Function {
public:
  void setData(string name);
  void setData(string name, vector<string> arguments);
private:
  string name;
  vector<string> arguments;
};

#endif /* FUNCTION_HPP */
