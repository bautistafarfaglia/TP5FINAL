#include "cParada.h"

unsigned int cParada::cant_total_paradas = 0;

cParada::cParada() {

}

cParada::cParada(string id_parada,string nombre_parada, string direccion) : id_parada(id_parada), nombre_parada(nombre_parada), direccion(direccion) {
}

string cParada::get_nombre_parada() {
    return this->nombre_parada;
}

/*cListaPasajeros cParada::get_lista_pasajeros() {
    return null;
}*/

string cParada::get_id_parada() {
    return this->id_parada;
}

void cParada::pasajeros_suben_colectivos()
{

}

/*
cPasajero cParada::pasajeros_suben_colectivos() {
    return null;
}*/

string cParada::to_string_parada() {
	stringstream ss;
		ss << "id_parada: " << this->id_parada << endl
		<< "nombre_parada: " << this->nombre_parada << endl
		<< "direccion: " << this->direccion << endl
		<< "cant total paradas: " << this->cant_total_paradas<< endl;

		ss << "-----------------------------" << endl
			<< "Numeros Colectivos: " << this->listaNumerosColectivos.data();
		ss << "-----------------------------" << endl
			<< "lista Pasajeros: " << this->listaPasajeros.data();
	return ss.str();
}

void cParada::imprimir() {
    return;
}
