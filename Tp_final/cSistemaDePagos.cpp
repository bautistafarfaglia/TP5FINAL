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
        this->colecto_del_dia = tarjeta_pasajero->descuento_salto(5 * 3); //chequear el calculo de paradas
        this->cantidad_pasajeros++; 
    }
    catch (exception e) {
        cout << e.what() << endl;
        return false;
    }
    return true;
}
//
//istream& operator>>(istream& is, cSistemaDePagos& sis)
//{
//    int pos = 0;
//    bool estado = false;
//    cout << "Ingrese los datos para generar el sistema de pagos:" << endl;
//    cout << "Numero:" << endl;
//    cout << "Cantidad maxima pasajeros:" << endl;
//    is >> cole.cantidad_max_pasajeros;
//    cout << "Estado operativo: 1 = Operando, 2 = Fuera de servicio" << endl;
//    is >> pos;
//    if (pos == 1) {
//        estado = true;
//    }
//    else if (pos == 2) {
//        estado = false;
//    }
//    cole.estado_operativo = estado;
//    cout << "GPS:" << endl;
//    is >> cole.GPS;
//    cout << "Establecer sentido: Arriba = 1, Abajo = 2" << endl;
//    int val = -1;
//    is >> val;
//    if (val == 0) {
//        cole.sentido = Arriba;
//    }
//    else if (val == 1) {
//        cole.sentido = Abajo;
//    }
//
//    is >> sis.generar_viaje();
//    return is;
//}