#include "cSistema.h"

int cSistema::Max_id = 0;

cSistema::cSistema(string NombreLinea) :IDLineaDeColectivos(Max_id++) {
    this->NombreDeLinea = NombreLinea; 
	this->SistemaGeneralDePagos = new cSistemaDePagos();

	this->listaRecorrido = new cRecorrido * [0];
}

void cSistema::agregar_personas(cPasajeros* persona) {
	this->listaPasajeros.push_back(persona);
	int pos_random = rand() % this->cantActual;
	//Agregar el pasajero a alguna parada random

	this->cambiarRecorridoPasajeros(persona);
	//    lista de recorridos: pos random -> obtener lista paradas -> parada random -> agregar pasajero
}

void cSistema::GenerarAveríaRandom()
{
	int ColeRandom = rand() % this->listaColectivos.size();  
	this->listaColectivos[ColeRandom]->averia();
}

void cSistema::SolucionarAveríaProducida()
{
}

void cSistema::TICK() {
	this->ImprimirColectivos(); 
	cout << "Cant de colectivos en circulacion: " << cColectivo::getcantidad_de_colectivos_en_circulacion();
}

string cSistema::ToStringLineaDeColectivos() {
    stringstream ss;
    for (int i = 0; i < this->listaColectivos.size()  ; i++) {
        ss << this->listaColectivos[i]->to_string_colectivo();
    }
    return ss.str();
}

void cSistema::ImprimirColectivos() {
	for (int i = 0; i < this->listaColectivos.size(); i++) {
		this->listaColectivos[i]->imprimir();
	}
}

void cSistema::generarcColectivo(){
	int tipo = rand() % 3;
	if (tipo == 1) {
		this->listaColectivos.push_back(this->generar_cColectivo_Acordeon());
	}else if (tipo == 2) {
		this->listaColectivos.push_back(this->generar_cColectivo_ConAire_y_DireccionElectrica());
	}else if (tipo == 3) {
		this->listaColectivos.push_back(this->generar_cColectivo_sinAire());
	}
}


void cSistema::AvanzarColectivoRandom()
{
	vector<cPasajeros*>* p = new vector<cPasajeros*>;
	if (this->listaColectivos.size()) {
		int numcole = rand() % this->listaColectivos.size();
		if (this->listaColectivos[numcole]->avanzar_recorrido(p) == false) { // si el colectivo no puede avanzar mas en el recorrido, se le cambia el recorrido
			this->cambiarRecorridoColectivos(this->listaColectivos[numcole]->get_id_colectivo()); //
		}
	}
	for (int i = 0; i < p->size(); i++) {
		cambiarRecorridoPasajeros(p->at(i));
		p->at(i) = NULL;
	}
	delete p;

}

void cSistema::generarRecorrido() {

	cRecorrido* recorrido = new cRecorrido();
	cin >> *recorrido; //chequear y revisar como generar recorridos, ya que no esta bueno que haya una lista estatica de pardas, para poder ir aumentando cuando deseamos
	this->agregar(recorrido);
}

bool cSistema::cambiarRecorridoColectivos(int id_colectivo)
{
	for (int i = 0; i < this->listaColectivos.size(); i++) {
		if (this->listaColectivos[i]->get_id_colectivo() == id_colectivo) {
			try {
				if (this->cantActual != 0) {
					this->listaColectivos[i]->set_recorrido(this->listaRecorrido[(rand() % this->cantActual)]);
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
bool cSistema::cambiarRecorridoPasajeros(cPasajeros* p)
{
	try {
		if (p != nullptr) {
			int posRecorrido = rand() % this->cantActual;
			int posParada = rand() % (this->listaRecorrido[posRecorrido]->get_lista_paradas().size() - 1) + 1;
			this->listaRecorrido[posRecorrido]->get_lista_paradas().at(posParada)->agregar_pasajero(p);
			int destino;
			if (this->listaRecorrido[posRecorrido]->get_lista_paradas()[0]->get_sentido_parada() == Arriba) {
				destino = -1;
				do {
					destino = rand() % this->listaRecorrido[posRecorrido]->get_lista_paradas().size() + 1;
				} while (destino < posParada);
				p->setDestino(this->listaRecorrido[posRecorrido]->get_lista_paradas().at(posParada));
				return true;
			}
			else if (this->listaRecorrido[posRecorrido]->get_lista_paradas()[0]->get_sentido_parada() == Abajo) {
				destino = 11;
				if (posParada == 0) {  }
				do {
					destino = rand() % this->listaRecorrido[posRecorrido]->get_lista_paradas().size();
				} while (destino > posParada);
				p->setDestino(this->listaRecorrido[posRecorrido]->get_lista_paradas().at(posParada));
				return true;
			}
		}else {
			throw exception("No se puede asignar recorrido random a un pasajero NULL");
		}
	}catch (exception e) {
				cout << "Error 03: " << e.what() << endl;
				return false;
	}
}





cColectivoAcordeon* cSistema::generar_cColectivo_Acordeon() {
	cColectivoAcordeon* cole = new cColectivoAcordeon();
	cin >> *cole;
	if (!this->asignarChoferSistemaYRecorridoAcolectivosGenerados(cole)) {
		delete cole;
		return NULL;
	}
	return cole;
}

cColectivoConAireYDireccionElectrica* cSistema::generar_cColectivo_ConAire_y_DireccionElectrica() {
	cColectivoConAireYDireccionElectrica* cole = new cColectivoConAireYDireccionElectrica();
	cin >> *cole;
	if (!this->asignarChoferSistemaYRecorridoAcolectivosGenerados(cole)) {
		delete cole;
		return NULL;
	}
	return cole;
}

cColectivoSinAire* cSistema::generar_cColectivo_sinAire() {
	cColectivoSinAire* cole = new cColectivoSinAire();
	cin >> *cole;
	if (!this->asignarChoferSistemaYRecorridoAcolectivosGenerados(cole)) {
		delete cole;
		return NULL;
	}
	return cole;
}

bool cSistema::asignarChoferSistemaYRecorridoAcolectivosGenerados(cColectivo* cole) {
	bool flag = false;
	for (int i = 0; i < this->listaColectiveros.size(); i++) {
		if (this->listaColectiveros[i]->getTrabajando() == false) { //se buscan colectiveros que no esten ahora mismo manejando
			flag = true;
			cole->set_colectivero(this->listaColectiveros[i]);
			break;
		}
	}
	if (flag == false) { //no hay suficientes colectiveros por lo que se "contrata" a mas
		cColectivero* vero = new cColectivero();
		cin >> *vero;//se personaliza el colectivero
		this->listaColectiveros.push_back(vero);//se agrega el colectivero a la fuerza trabajadora
		cole->set_colectivero(vero);
	}
	cole->set_sistema_de_pagos(this->SistemaGeneralDePagos); 

	srand(42);
	try {
		if (this->cantActual != 0) {
			cole->set_recorrido(this->listaRecorrido[rand() % this->cantActual]);
			return true;
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





#pragma region listaRecorrido

	void cSistema::agregar(cRecorrido * recorrido) {
		this->resize();
		this->listaRecorrido[cantActual++] = recorrido;
	}
	void cSistema::eliminar(cRecorrido* recorrido) {
		int i = 0;
		for (i = 0; i < this->cantActual; i++)
		{
			if (listaRecorrido[i] == recorrido)
				delete listaRecorrido[i];
			break;
		}
		listaRecorrido[i] = NULL;
		this->ordenar();
	}
	cRecorrido* cSistema::quitar(cRecorrido* recorrido) {
		int i = 0;
		for (i = 0; i < this->cantActual; i++)
		{
			if (listaRecorrido[i] == recorrido)
				break;
		}
		cRecorrido* RecAux = listaRecorrido[i];
		delete listaRecorrido[i];
		listaRecorrido[i] = NULL;
		this->ordenar();
		return RecAux;
	}

	void cSistema::operator+(cRecorrido* recorrido) { this->agregar(recorrido); }
	cRecorrido* cSistema::operator-(cRecorrido* recorrido) { cRecorrido* RecAux = NULL;  RecAux = quitar(recorrido); return RecAux; }
	cRecorrido* cSistema::operator[](short i) {
		try {
			if (i >= 0 && i < this->cantActual)
				return this->listaRecorrido[i];
			throw out_of_range("Error: Se esta intentando acceder a un elemento imposible de acceder");
		}
		catch (out_of_range& e) {
			cout << e.what() << endl;
		}
	}
	//void cTarjeta::operator++() {}


	void cSistema::resize() {
		int iOldSize = this->cantActual;
		int iNewSize = iOldSize + 1;
		cRecorrido** paTmpArray = new cRecorrido * [iOldSize];
		for (int i = 0; i < iOldSize; i++)
		{
			paTmpArray[i] = this->listaRecorrido[i];
		}
		cRecorrido** aux;
		aux = this->listaRecorrido; 
		this->listaRecorrido = NULL;
		delete aux;
		this->listaRecorrido = new cRecorrido * [iNewSize];
		for (int i = cantActual; i < iNewSize; i++)
		{
			this->listaRecorrido[i] = NULL;
		}
		for (int i = 0; i < iOldSize; i++)
		{
			this->listaRecorrido[i] = paTmpArray[i];
		}
		delete[] paTmpArray;
	}
	void cSistema::ordenar() {
		for (ushort i = 0; i < this->cantActual; i++)
			for (ushort j = i; j < this->cantActual - 1; j++)
				if (!this->listaRecorrido[i])
					swap(this->listaRecorrido[j], this->listaRecorrido[j + 1]);
	}

#pragma endregion