#include "cLineaDeColectivos.h"

int cLineaDeColectivos::Max_id = 0;

cLineaDeColectivos::cLineaDeColectivos(string NombreLinea) :IDLineaDeColectivos(Max_id++) {
    this->NombreDeLinea = NombreLinea; 
    //chequear la incializacion de las listas
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

cColectivoAcordeon* cLineaDeColectivos::generar_cColectivo_Acordeon() {
	cColectivoAcordeon* cole = new cColectivoAcordeon();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	cRecorrido* recorrido = new cRecorrido();
	vector<cParada*> lista;

	cin >> *vero; //personalizo el colectivero
	cin >> *recorrido;//personalizo el recorrido, tambien se podría realizar una busqueda por id en una funcion estatica y esta devolvería el puntero del objeto, preguntar pampa

	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(recorrido);

	return cole;
}

cColectivoConAireYDireccionElectrica* cLineaDeColectivos::generar_cColectivo_ConAire_y_DireccionElectrica() {
	cColectivoConAireYDireccionElectrica* cole = new cColectivoConAireYDireccionElectrica();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	cRecorrido* recorrido = new cRecorrido();
	vector<cParada*> lista;

	cin >> *vero; //personalizo el colectivero
	cin >> *recorrido;//personalizo el recorrido, tambien se podría realizar una busqueda por id en una funcion estatica y esta devolvería el puntero del objeto, preguntar pampa

	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(recorrido);

	return cole;
}

cColectivoSinAire* cLineaDeColectivos::generar_cColectivo_sinAire() {
	cColectivoSinAire* cole = new cColectivoSinAire();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	cRecorrido* recorrido = new cRecorrido();
	vector<cParada*> lista;

	cin >> *vero; //personalizo el colectivero
	cin >> *recorrido;//personalizo el recorrido, tambien se podría realizar una busqueda por id en una funcion estatica y esta devolvería el puntero del objeto, preguntar pampa

	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(recorrido);

	return cole;
}