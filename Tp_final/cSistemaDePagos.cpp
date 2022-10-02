#include "cSistemaDePagos.h"

cSistemaDePagos::cSistemaDePagos() {
}

cSistemaDePagos::cSistemaDePagos(float colecta_del_dia, unsigned int cantidad_pasajeros) {
    this->colecto_del_dia = colecta_del_dia;
    this->cantidad_pasajeros = cantidad_pasajeros;
}


unsigned int cSistemaDePagos::get_cantidad_de_pasajeros() {
    return null;
}

float cSistemaDePagos::get_colecta_del_dia() {
    return 0.0;
}

bool cSistemaDePagos::generar_viaje(string inicio, string destino,int cantidad_de_paradas,cTarjeta* tarjeta_pasajero) {
    return false;
}
