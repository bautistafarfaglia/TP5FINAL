#include "cColectivero.h"

cColectivero::cColectivero(string nombre, string DNI, string legajo){
    this->nombre = nombre;
    this->DNI = DNI;
	this->legajo = legajo;
}


string cColectivero::get_legajo() {
    return this->legajo;
}

string cColectivero::cargar_destino_pasajero( string destino_pasajero) {
	return "";
}

string cColectivero::to_string_colectivero() {
	stringstream ss;
	ss << endl;
	ss << "-----------------------------" << endl
		<< "Colectivero DNI [" << this->DNI << "]" << endl
		<< "Nombre: " << this->nombre << endl
		<< "Legajo: " << this->legajo << endl;
	
	return ss.str();
}

istream& operator>>(istream& is, cColectivero& cole)
{

	cout << "Ingrese los datos del colectivero:" << endl;
	cout << "Colectivero DNI" << endl;
	is >> cole.DNI;
	cout << "Nombre" << endl;
	is >> cole.nombre;
	cout << "Legajo" << endl;
	is >> cole.legajo;

	return is;
}
