#include "cColectivero.h"

cColectivero::cColectivero():legajo(nullptr) {
    this->nombre = nullptr;
    this->DNI = nullptr; 
    
}

cColectivero::cColectivero(string nombre, string DNI, const string legajo) : legajo(legajo) {
    this->nombre = nombre;
    this->DNI = DNI;
}


string cColectivero::get_legajo() {
    return "";
}

/**
 * @param string destino_pasajero
 * @return string
 */
string cColectivero::cargar_destino_pasajero( string destino_pasajero) {
    return "";
}

/**
 * @return string
 */
string cColectivero::to_string_colectivero() {
    return "";
}
