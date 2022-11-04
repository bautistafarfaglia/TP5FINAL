#include "cLineaDeColectivos.h"

int cLineaDeColectivos::Max_id = 0;

cLineaDeColectivos::cLineaDeColectivos(string NombreLinea) :IDLineaDeColectivos(Max_id++) {
    this->NombreDeLinea = NombreLinea; 
}

void cLineaDeColectivos::agregar_peronas(cPasajeros* persona) {
	this->listaPasajeros.push_back(persona);
}

void cLineaDeColectivos::TICK() {
    return;
}


string cLineaDeColectivos::ToStringLineaDeColectivos() {
    stringstream ss;
    for (int i = 0; i < this->listaColectivos.size()  ; i++) {
        ss << this->listaColectivos[i]->to_string_colectivo();
    }
    return ss.str();
}



void cLineaDeColectivos::Imprimir() {
	for (int i = 0; i < this->listaColectivos.size(); i++) {
		this->listaColectivos[i]->imprimir();
	}
}

void cLineaDeColectivos::generarcColectivo(string tipo)
{
	if (tipo == "Acordeon") {
		this->listaColectivos.push_back(this->generar_cColectivo_Acordeon());
		
	}
	else if (tipo == "Con aire") {
		this->listaColectivos.push_back(this->generar_cColectivo_ConAire_y_DireccionElectrica());
	}
	else if (tipo == "Sin aire") {
		this->listaColectivos.push_back(this->generar_cColectivo_sinAire());
	}
}

cRecorrido* cLineaDeColectivos::ObtenerRecorrido(unsigned int Longitud)
{
	return this->listaRecorrido.at(Longitud);
}

cColectivoAcordeon* cLineaDeColectivos::generar_cColectivo_Acordeon() {
	cColectivoAcordeon* cole = new cColectivoAcordeon();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	//cRecorrido* recorrido = new cRecorrido();

	cin >> *vero; //personalizo el colectivero
	//cin >> *recorrido;//personalizo el recorrido, tambien se podría realizar una busqueda por id en una funcion estatica y esta devolvería el puntero del objeto, preguntar pampa
	cout << "Que longitud de recorrido quiere, el maximo de recorridos que se tiene es de: "<<this->listaRecorrido.size();
	unsigned int pos = 100;
	// es horrible hacer esto pero es un ejemplo de como podríamos generalizar la lista de recorridos y aprovechar de tener la lista general aca en cLineaDeColectivos
	cin >> pos;
	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(this->listaRecorrido.at(pos));

	return cole;
}

cColectivoConAireYDireccionElectrica* cLineaDeColectivos::generar_cColectivo_ConAire_y_DireccionElectrica() {
	cColectivoConAireYDireccionElectrica* cole = new cColectivoConAireYDireccionElectrica();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	
	cout << "Que longitud de recorrido quiere, el maximo de recorridos que se tiene es de: " << this->listaRecorrido.size();
	unsigned int pos = 100;
	// es horrible hacer esto pero es un ejemplo de como podríamos generalizar la lista de recorridos y aprovechar de tener la lista general aca en cLineaDeColectivos
	cin >> pos;
	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(this->listaRecorrido.at(pos));


	return cole;
}

cColectivoSinAire* cLineaDeColectivos::generar_cColectivo_sinAire() {
	cColectivoSinAire* cole = new cColectivoSinAire();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	cout << "Que longitud de recorrido quiere, el maximo de recorridos que se tiene es de: " << this->listaRecorrido.size();
	unsigned int pos = 100;
	// es horrible hacer esto pero es un ejemplo de como podríamos generalizar la lista de recorridos y aprovechar de tener la lista general aca en cLineaDeColectivos
	cin >> pos;
	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(this->listaRecorrido.at(pos));


	return cole;
}


void cLineaDeColectivos::generarRecorrido() {

	cRecorrido* recorrido = new cRecorrido();
	cin >> *recorrido;
	this->listaRecorrido.push_back(recorrido);
}

void cLineaDeColectivos::cambiarRecorrido(int id_colectivo,unsigned int Longitud_max)
{
	for (int i = 0; i < this->listaColectivos.size(); i++) {
		if (this->listaColectivos[i]->get_id_colectivo() == id_colectivo) {
			for (int j = 0; j < this->listaRecorrido.size(); j++) {
				if (this->listaRecorrido[j]->getcantParadas() >= Longitud_max) {
					this->listaColectivos[i]->set_recorrido(this->listaRecorrido.at(j));
				}
				Longitud_max--;
			}
		}
	}
}
