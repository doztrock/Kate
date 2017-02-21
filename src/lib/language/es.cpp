#include "es.hpp"

std::string FILE_NOT_LOADED_SUCCESSFULLY(void) {
    return "No se pudo cargar archivo";
}

std::string ERROR_VARIABLE_INITIALIZATION(int line) {
    return static_cast<std::ostringstream &> ((std::ostringstream() << "Error en inicializacion de variable en linea " << line)).str();
}

std::string ERROR_VARIABLE_ASSIGNMENT(int line) {
    return static_cast<std::ostringstream &> ((std::ostringstream() << "Error en asignacion de variable en linea " << line)).str();
}

std::string ERROR_VARIABLE_ASSIGNMENT_EMPTY_VALUE(int line) {
    return static_cast<std::ostringstream &> ((std::ostringstream() << "Error en asignacion de variable, el valor esta vacio en linea " << line)).str();
}

std::string ERROR_CONSTANT_INITIALIZATION(int line) {
    return static_cast<std::ostringstream &> ((std::ostringstream() << "Error con inicializacion de constante en linea " << line)).str();
}

std::string ERROR_CONSTANT_ASSIGNMENT(int line) {
    return static_cast<std::ostringstream &> ((std::ostringstream() << "Error! No puedes asignar un valor a una constante previamente inicializada en linea " << line)).str();
}