#ifndef PARAMETERLIST_HPP
#define PARAMETERLIST_HPP

#include <string>
#include <vector>

using namespace std;

class ParameterList {
public:
    void appendParameter(string parameter);
    vector<string> getList(void);

private:
    vector<string> list;

};

#endif /* PARAMETERLIST_HPP */

