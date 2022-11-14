#include "cColectivero.h"

cColectivero::cColectivero(string nombre, string DNI, string legajo){
    this->nombre = nombre;
    this->DNI = DNI;
	this->legajo = legajo;
}


void cColectivero::setTrabajando(bool var)
{
	this->trabajando = var;
}
bool cColectivero::getTrabajando()
{
	return this->trabajando;
}

string cColectivero::get_legajo() {
    return this->legajo;
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

bool cColectivero::AleatorioAbrirPuertas()
{
	int val = rand() % 2;
	if (val == 0) {
		return true;
	}
	else {
		cout << "El colectivo se saltio la parada" << endl;
		return false;
	}
	
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
