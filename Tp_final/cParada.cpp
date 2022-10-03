#include "cParada.h"

unsigned int cParada::cant_total_paradas = 0;

cParada::cParada() {

}

cParada::cParada(string id_parada,string nombre_parada, string direccion) : id_parada(id_parada), nombre_parada(nombre_parada), direccion(direccion) {
}

string cParada::get_nombre_parada() {
    return "";
}

/*cListaPasajeros cParada::get_lista_pasajeros() {
    return null;
}*/

string cParada::get_id_parada() {
    return "";
}

void cParada::pasajeros_suben_colectivos()
{

}

/*
cPasajero cParada::pasajeros_suben_colectivos() {
    return null;
}*/

string cParada::to_string_parada() {
    return "";
}

void cParada::imprimir() {
    return;
}
