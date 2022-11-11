#include "cLineaDeColectivos.h"

int cLineaDeColectivos::Max_id = 0;

cLineaDeColectivos::cLineaDeColectivos(string NombreLinea) :IDLineaDeColectivos(Max_id++) {
    this->NombreDeLinea = NombreLinea; 
	this->SistemaGeneralDePagos = new cSistemaDePagos();

	listaRecorrido = new cRecorrido * [0];
}

void cLineaDeColectivos::agregar_personas(cPasajeros* persona) {
	if (listaPasajeros.size() % 5 == 0) {
		this->generarRecorrido();
	}
	this->listaPasajeros.push_back(persona);
	//Agregar el pasajero a alguna parada random
	this->listaRecorrido[rand() % this->cantActual]->get_lista_paradas()[rand() % this->listaRecorrido[rand() % this->cantActual]->get_lista_paradas().size()]->agregar_pasajero(persona);
	//    lista de recorridos: pos random -> obtener lista paradas -> parada random -> agregar pasajero
}

void cLineaDeColectivos::GenerarAveríaRandom()
{
	int ColeRandom = rand() % this->listaColectivos.size();  
	this->listaColectivos[ColeRandom]->averia();
}

void cLineaDeColectivos::SolucionarAveríaProducida()
{
}

void cLineaDeColectivos::TICK() {
	this->ImprimirColectivos(); 
	cout << "Cant de colectivos en circulacion: " << cColectivo::getcantidad_de_colectivos_en_circulacion();
}

string cLineaDeColectivos::ToStringLineaDeColectivos() {
    stringstream ss;
    for (int i = 0; i < this->listaColectivos.size()  ; i++) {
        ss << this->listaColectivos[i]->to_string_colectivo();
    }
    return ss.str();
}

void cLineaDeColectivos::ImprimirColectivos() {
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

void cLineaDeColectivos::generarRecorrido() {

	cRecorrido* recorrido = new cRecorrido();
	cin >> *recorrido; //chequear y revisar como generar recorridos, ya que no esta bueno que haya una lista estatica de pardas, para poder ir aumentando cuando deseamos
	this->agregar(recorrido);
}

bool cLineaDeColectivos::cambiarRecorrido(int id_colectivo)
{
	for (int i = 0; i < this->listaColectivos.size(); i++) {
		if (this->listaColectivos[i]->get_id_colectivo() == id_colectivo) {
			srand(42);
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
	cole->set_sistema_de_pagos(this->SistemaGeneralDePagos); 

	srand(42);
	try {
		if (this->cantActual != 0) {
			cole->set_recorrido(this->listaRecorrido[rand() % this->cantActual]);
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





#pragma region listaRecorrido

	void cLineaDeColectivos::agregar(cRecorrido * recorrido) {
		this->resize();
		this->listaRecorrido[++cantActual] = recorrido;
	}
	void cLineaDeColectivos::eliminar(cRecorrido* recorrido) {
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
	cRecorrido* cLineaDeColectivos::quitar(cRecorrido* recorrido) {
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

	void cLineaDeColectivos::operator+(cRecorrido* recorrido) { this->agregar(recorrido); }
	cRecorrido* cLineaDeColectivos::operator-(cRecorrido* recorrido) { cRecorrido* RecAux = NULL;  RecAux = quitar(recorrido); return RecAux; }
	cRecorrido* cLineaDeColectivos::operator[](short i) {
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


	void cLineaDeColectivos::resize() {
		// aca hacer try y catch para la memoria
			cRecorrido** listaResize = new cRecorrido * [this->cantActual + 1];
			for (int i = cantActual; i < cantActual+1; i++)
			{
				listaResize[i] = NULL;
			}

			memcpy(listaResize, this->listaRecorrido, (this->cantActual + 1 )* sizeof(cRecorrido*));
			listaRecorrido = listaResize;
			delete[] listaResize;
	}
	void cLineaDeColectivos::ordenar() {
		for (ushort i = 0; i < this->cantActual; i++)
			for (ushort j = i; j < this->cantActual - 1; j++)
				if (!this->listaRecorrido[i])
					swap(this->listaRecorrido[j], this->listaRecorrido[j + 1]);
	}

#pragma endregion