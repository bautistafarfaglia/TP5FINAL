#include "cColectivoAcordeon.h"


cColectivoAcordeon::cColectivoAcordeon(int num_colectivo) : cColectivoConAireYDireccionElectrica(num_colectivo)
{
	this->cantidad_max_pasajeros = 200;
}

cColectivoAcordeon::~cColectivoAcordeon(){
}


void cColectivoAcordeon::averia() {
	this->estado_operativo = false;
	this->imprimir();
	cout << "Oh no... El colectivo se separo en dos!" << endl;

	for (int i = 0; i < this->listaPasajeros.size(); i++) {
		cout << "Se baja un pasajero" << endl;
		this->recorrido->get_lista_paradas()[pos_del_recorrido]->agregar_pasajero(this->listaPasajeros[i]);
		this->listaPasajeros[i]->set_prioridad(true);
		this->listaPasajeros.erase(this->listaPasajeros.begin()+i);
	}
}


string cColectivoAcordeon::to_string_colectivo() {
	stringstream ss;
	ss
		<< "Posicion del recorrido: " << this->pos_del_recorrido << endl
		<< "ID colectivo [" << this->id_colectivo << "]" << endl
		<< "Ubicacion: " << this->GPS << endl
		<< "Estado Operativo: " << this->estado_operativo << endl
		<< "Cant actual de pasajeros subidos: " << this->cantidad_actual_pasajeros << endl
		<< "Cant Maxima de pasajeros: " << this->cantidad_max_pasajeros << endl
		<< "Cantidad de pasajeros transportados: " << this->get_sistema_de_pagos().colecta_pasajeros_colectivo()<<endl
		<< "Cantidad de plata recolectada por el colectivo; " << this->get_sistema_de_pagos().colecta_plata_colectivo() << endl
		<< "-----------------------------" << endl << "colectivero: " << this->colectivero->to_string_colectivero() << endl
		<< endl;

		return ss.str();
}

void cColectivoAcordeon::imprimir() {
	cout << this->to_string_colectivo() << endl;
}
