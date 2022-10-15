#include "cSistemaDePagos.h"


cSistemaDePagos::cSistemaDePagos(float colecta_del_dia, unsigned int _cantidad_pasajeros) {
    this->colecto_del_dia = colecta_del_dia;
    this->cantidad_pasajeros = _cantidad_pasajeros;
}


unsigned int cSistemaDePagos::get_cantidad_de_pasajeros() {
    return this->cantidad_pasajeros;
}

float cSistemaDePagos::get_colecta_del_dia() {
    return this->colecto_del_dia;
}

bool cSistemaDePagos::generar_viaje(string inicio, string destino,int cantidad_de_paradas,cTarjeta* tarjeta_pasajero) {
    try {
        this->colecto_del_dia = tarjeta_pasajero->descuento_salto(5 * 3); //cambiar el calculo de paradas
        this->cantidad_pasajeros++;
    }
    catch (exception e) {
        cout << e.what() << endl;
        return false;
    }
    return true;
}
