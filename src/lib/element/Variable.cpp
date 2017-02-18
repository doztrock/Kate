#include "Variable.hpp"

void Variable::setData(string name) {
	this->name = name;
	this->value = string("");
}

void Variable::setData(string name, string value) {
	this->name  = name;
	this->value = value;
}

string Variable::getName(void){
	return this->name;
}

string Variable::getValue(void){
	return this->value;
}
