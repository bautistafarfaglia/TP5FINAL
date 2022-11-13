#include "cColectivoConAireYDireccionElectrica.h"

cColectivoConAireYDireccionElectrica::cColectivoConAireYDireccionElectrica(cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, short int cantidad_max_pasajeros, int num_colectivo) :cColectivo(colectivero,
    sistema_de_pagos, recorrido, pos_del_recorrido, GPS, sentido, cantidad_max_pasajeros,num_colectivo)
{
    tiene_aire_acondicionado = true;
}

bool cColectivoConAireYDireccionElectrica::aire_acondicionado() {
    return this->tiene_aire_acondicionado;
}

void cColectivoConAireYDireccionElectrica::apagar_aire() {
        if (this->tiene_aire_acondicionado== true) {
        this->tiene_aire_acondicionado = false;
    }
}
void cColectivoConAireYDireccionElectrica::averia() {
		this->estado_operativo = false;
		this->imprimir();
		cout << "Se rompio el aire del bondi" << endl;

		for (int i = 0; i < this->listaPasajeros.size(); i++) {
			cout << "Se baja un pasajero" << endl;
			this->recorrido->get_lista_paradas()[pos_del_recorrido]->agregar_pasajero(this->listaPasajeros[i]);
			this->listaPasajeros[i]->set_prioridad(true);
			this->listaPasajeros.erase(this->listaPasajeros.begin() + i);
		}
}


string cColectivoConAireYDireccionElectrica::to_string_colectivo() {
	stringstream ss;
	ss << "colectivero: " << this->colectivero->to_string_colectivero() << endl
		<< "Recorrido: " << this->recorrido->to_string_recorrido() << endl
		<< "Posicion del recorrido: " << this->pos_del_recorrido << endl
		<< "-----------------------------" << endl
		<< "ID colectivo [" << this->id_colectivo << "]" << endl
		<< "Ubicacion: " << this->GPS << endl
		<< "Estado Operativo: " << this->estado_operativo << endl
		<< "Cant actual de pasajeros: " << this->cantidad_actual_pasajeros << endl
		<< "Cant Maxima de pasajeros: " << this->cantidad_max_pasajeros << endl
		<< "Cantidad De colectivos en circulacion: " << this->cantidad_de_colectivos_en_circulacion << endl;
	return ss.str();
}

void cColectivoConAireYDireccionElectrica::imprimir() {
	cout << this->to_string_colectivo() << endl;
}
