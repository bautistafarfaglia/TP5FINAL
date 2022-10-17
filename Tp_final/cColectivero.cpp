#include "cColectivero.h"

cColectivero::cColectivero(string nombre, string DNI, const string legajo) : legajo(legajo) {
    this->nombre = nombre;
    this->DNI = DNI;
}


string cColectivero::get_legajo() {
    return this->legajo;
}

string cColectivero::cargar_destino_pasajero( string destino_pasajero) {
	return "";
}

string cColectivero::to_string_colectivero() {
	stringstream ss;

	ss << "-----------------------------" << endl
		<< "Colectivero DNI [" << this->DNI << "]" << endl
		<< "Nombre: " << this->nombre<< " metros" << endl
		<< "Legajo: " << this->legajo<< " metros" << endl;
	
	return ss.str();
}
