#include "Constant.hpp"

void Constant::setData(string name, string value) {
	this->name  = name;
	this->value = value;
}

string Constant::getName(void){
	return this->name;
}

string Constant::getValue(void){
	return this->value;
}
