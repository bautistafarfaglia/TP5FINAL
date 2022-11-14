
#include "cColectivoSinAire.h"




 cColectivoSinAire::cColectivoSinAire(int num_colectivo):cColectivo(num_colectivo) {
	 this->cantidad_max_pasajeros = 20;
}

 void cColectivoSinAire::averia() {
	 this->estado_operativo = false;
	 this->imprimir();
	 cout << "Me declaro por las condiciones salariales" << endl;
	 
	 for (int i = 0; i < this->listaPasajeros.size(); i++) {
		 cout << "Se baja un pasajero" << endl;
		 this->recorrido->get_lista_paradas()[pos_del_recorrido]->agregar_pasajero(this->listaPasajeros[i]);
		 this->listaPasajeros[i]->set_prioridad(true);
		 this->listaPasajeros.erase(this->listaPasajeros.begin() + i);
	 }
 }


 string cColectivoSinAire::to_string_colectivo() {
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
		 << "Cantidad de pasajeros transportados: " << this->get_sistema_de_pagos().colecta_pasajeros_colectivo()<<endl
		 << "Cantidad de plata recolectada por el colectivo; " << this->get_sistema_de_pagos().colecta_plata_colectivo()<<endl;
	 return ss.str();
 }

 void cColectivoSinAire::imprimir() {
	 cout << this->to_string_colectivo() << endl;
 }