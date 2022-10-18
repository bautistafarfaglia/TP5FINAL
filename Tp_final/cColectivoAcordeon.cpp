#include "cColectivoAcordeon.h"


//chequear y cambiar porque el id_colectivo se pasa como parametro 
cColectivoAcordeon::cColectivoAcordeon(string id_Colectivo, cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros,int num_colectivo) :cColectivoConAireYDireccionElectrica(id_Colectivo, colectivero,
    sistema_de_pagos, recorrido, pos_del_recorrido, GPS, sentido, cantidad_max_pasajeros,num_colectivo)
{
    

}


void cColectivoAcordeon::averia() {
    return;
}


string cColectivoAcordeon::to_string_colectivo() {
	stringstream ss;
	ss << "colectivero: " << this->colectivero->to_string_colectivero() << endl
		<< "Recorrido: " << this->recorrido->to_string_recorrido() << endl
		<< "Posicion del recorrido: " << this->pos_del_recorrido << endl
		<< "-----------------------------" << endl
		<< "ID colectivo [" << this->id_colectivo << "]" << endl
		<< "Ubicacion: " << this->GPS << endl
		<< "Estado Operativo: " << this->estado_operativo<< endl
		<< "Cant actual de pasajeros: " << this->cantidad_actual_pasajeros<< endl
		<< "Cant Maxima de pasajeros: " << this->cantidad_max_pasajeros << endl
		<< "Cantidad De colectivos: " << this->cantidad_de_colectivos << endl; 
		return ss.str();
}

void cColectivoAcordeon::imprimir() {
    return;
}
