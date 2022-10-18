#include "cParada.h"

unsigned int cParada::cant_total_paradas = 0;

cParada::cParada(string id_parada,string nombre_parada, eSentidoRecorrido direccion) : id_parada(id_parada), nombre_parada(nombre_parada), direccion(direccion) {
	
}

string cParada::get_nombre_parada() {
    return this->nombre_parada;
}

vector<cPasajeros*> cParada::get_lista_pasajeros()
{
	return this->listaPasajeros;
}

/*cListaPasajeros cParada::get_lista_pasajeros() {
    return null;
}*/

string cParada::get_id_parada() {
    return this->id_parada;
}

vector<cPasajeros*> cParada::pasajeros_suben_colectivo(int num){
	vector<cPasajeros*> aux;
	for (int i = 0; i < this->listaPasajeros.size(); i++) {
		if (this->listaPasajeros[i]->get_num_colectivo() == num) {
			aux.push_back(this->listaPasajeros[i]);
		}
	}
	return aux;
}

/*
cPasajero cParada::pasajeros_suben_colectivos() {
    return null;
}*/

void cParada::agregar_pasajero(cPasajeros* pasajero_nuevo)
{
	this->listaPasajeros.push_back(pasajero_nuevo);
}

string cParada::to_string_parada() {
	stringstream ss;
		ss << "Parada ID: " << this->id_parada << endl
		<< "Nombre Parada: " << this->nombre_parada << endl
		<< "Direccion: " << this->direccion << endl
		<< "N° Total Paradas: " << this->cant_total_paradas<< endl;

		ss << "-----------------------------" << endl
			<< "Numeros Colectivos: " << this->listaNumerosColectivos.data();
		ss << "-----------------------------" << endl
			<< "lista Pasajeros: " << this->listaPasajeros.data();
	return ss.str();
}

void cParada::imprimir() {
    return;
}

istream& operator>>(istream& is, cParada& pa)
{
	int pos = 0;
	bool estado = false;
	cout << "Ingrese los datos de la parada:" << endl;
	cout << "Nombre de la parada:" << endl;
	is >> pa.nombre_parada;
	cout << "Direccion de la parada: 1=arriba, 2=abajo" << endl;
	is >> pos;
	if (pos == 1) {
		pa.direccion = Arriba;
	}
	else if (pos == 2) {
		pa.direccion = Abajo;
	}
	pos = 0; 
	cout << "Cuantos colectivos pasan por esta parada" << endl;
	is >> pos;
	for (int i = 0; i < pos; i++) {
		pa.listaNumerosColectivos.resize(pos);//chequear si el resize de vector, que hace
		cout << "Que numero es" << endl;
		is>>pa.listaNumerosColectivos[i];
	}

	return is;
}