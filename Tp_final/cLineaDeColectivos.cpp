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

void cLineaDeColectivos::generarcColectivo(){
	int tipo = rand() % 3;
	if (tipo == 1) {
		this->listaColectivos.push_back(this->generar_cColectivo_Acordeon());
	}else if (tipo == 2) {
		this->listaColectivos.push_back(this->generar_cColectivo_ConAire_y_DireccionElectrica());
	}else if (tipo == 3) {
		this->listaColectivos.push_back(this->generar_cColectivo_sinAire());
	}
}


void cLineaDeColectivos::AvanzarColectivoRandom()
{
	if (this->listaColectivos.size()) {
		int numcole = rand() % this->listaColectivos.size();
		if (this->listaColectivos[numcole]->avanzar_recorrido() == false) { // si el colectivo no puede avanzar mas en el recorrido, se le cambia el recorrido
			this->cambiarRecorrido(this->listaColectivos[numcole]->get_id_colectivo()); //
		};
	}
	
}


cColectivoAcordeon* cLineaDeColectivos::generar_cColectivo_Acordeon() {
	cColectivoAcordeon* cole = new cColectivoAcordeon();
	cin >> *cole; 
	if (!this->asignarChoferSistemaYRecorridoAcolectivosGenerados(cole)) {
		delete cole;
		return NULL;
	}
	return cole;
}

cColectivoConAireYDireccionElectrica* cLineaDeColectivos::generar_cColectivo_ConAire_y_DireccionElectrica() {
	cColectivoConAireYDireccionElectrica* cole = new cColectivoConAireYDireccionElectrica();
	cin >> *cole;
	if (!this->asignarChoferSistemaYRecorridoAcolectivosGenerados(cole)) {
		delete cole;
		return NULL;
	}
	return cole;
}

cColectivoSinAire* cLineaDeColectivos::generar_cColectivo_sinAire() {
	cColectivoSinAire* cole = new cColectivoSinAire();
	cin >> *cole;
	if (!this->asignarChoferSistemaYRecorridoAcolectivosGenerados(cole)) {
		delete cole;
		return NULL;
	}
	return cole;
}


void cLineaDeColectivos::generarRecorrido() {

	cRecorrido* recorrido = new cRecorrido();
	cin >> *recorrido;
	this->listaRecorrido.push_back(recorrido);
}

bool cLineaDeColectivos::cambiarRecorrido(int id_colectivo)
{
	for (int i = 0; i < this->listaColectivos.size(); i++) {
		if (this->listaColectivos[i]->get_id_colectivo() == id_colectivo) {
			srand(42);
			try {
				if (this->listaRecorrido.size() != 0) {
					this->listaColectivos[i]->set_recorrido(this->listaRecorrido.at(rand() % this->listaRecorrido.size()));
					return true;
				}
				else {
					throw exception("No se puede crear colectivos sin recorrido");
				}
			}
			catch (exception e) {
				cout << "Error 01: " << e.what() << endl;
				return false;
			}
		}
	}
}



bool cLineaDeColectivos::asignarChoferSistemaYRecorridoAcolectivosGenerados(cColectivo* cole) {
	bool flag = false;
	for (int i = 0; i < this->listaColectiveros.size(); i++) { 
		if (this->listaColectiveros[i]->getTrabajando() == false) { //se buscan colectiveros que no esten ahora mismo manejando
			flag = true;
			cole->set_colectivero(this->listaColectiveros[i]);
			break;
		}
	}
	if (flag = false) { //no hay suficientes colectiveros por lo que se "contrata" a mas
		cColectivero* vero = new cColectivero();
		cin >> *vero;//se personaliza el colectivero
		this->listaColectiveros.push_back(vero);//se agrega el colectivero a la fuerza trabajadora
		cole->set_colectivero(vero);
	}
	cSistemaDePagos* pagos = new cSistemaDePagos();
	cole->set_sistema_de_pagos(pagos);

	srand(42);
	try {
		if (this->listaRecorrido.size() != 0) {
			cole->set_recorrido(this->listaRecorrido.at(rand() % this->listaRecorrido.size()));
			return false;
		}
		else {
			throw exception("No se puede crear colectivos sin recorrido");
			return false;
		}
	}
	catch (exception e) {
		cout << "Error 01: " << e.what() << endl;
	}
}