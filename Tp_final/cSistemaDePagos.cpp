#include "cSistemaDePagos.h"
float cSistemaDePagos::colecta_del_dia = 0;
int cSistemaDePagos::max_id = 0;

cSistemaDePagos::cSistemaDePagos(unsigned int _cantidad_pasajeros) : id (max_id++) {
    this->cantidad_pasajeros = _cantidad_pasajeros;
    this->colecta_colectivo = 0;
}


unsigned int cSistemaDePagos::get_cantidad_de_pasajeros() {
    return this->cantidad_pasajeros;
}

float cSistemaDePagos::get_colecta_del_dia() {
    return this->colecta_del_dia;
}

bool cSistemaDePagos::cobrar_boleto(float* saldo, int cantParadas) { //chequear puntero saldo
    try {
        if (*saldo - (CONSTANTEPASAJE * cantParadas) >0) {
            *saldo -= (CONSTANTEPASAJE * cantParadas);
            this->colecta_del_dia += *saldo - (CONSTANTEPASAJE * cantParadas); //chequear el calculo de paradas
            this->cantidad_pasajeros++;
        }
    }
    catch (exception e) {
        cout << e.what() << endl;
        cout << "Uno de los pasajeros decidio cargar su tarjeta de transporte" << endl;
        *saldo + 200;
        return false;
    }
    return true;
}

void cSistemaDePagos::sumar_boleto(int cantParadas) {
    this->colecta_del_dia = this->colecta_del_dia + (cantParadas * CONSTANTEPASAJE);
    this->colecta_colectivo = this->colecta_colectivo + (cantParadas * CONSTANTEPASAJE);
    cantidad_pasajeros++;
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