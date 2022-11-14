#include "cSistemaDePagos.h"
float cSistemaDePagos::colecta_del_dia = 0;
int cSistemaDePagos::cantidad_pasajeros= 0;
int cSistemaDePagos::max_id = 0;

cSistemaDePagos::cSistemaDePagos():id (max_id++) {
    this->colecta_colectivo = 0;
    this->colecta_pasajeros = 0;
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
            int cobrado = CONSTANTEPASAJE * cantParadas;
            this->colecta_del_dia += cobrado; //chequear el calculo de paradas
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
    colecta_pasajeros++;
}

void cSistemaDePagos::resetDia()
{
    this->set_cantidad_de_pasajeros(0);
    this->set_colecta_del_dia(0);
}

void cSistemaDePagos::set_cantidad_de_pasajeros(unsigned int var)
{
    this->cantidad_pasajeros = var;
}

void cSistemaDePagos::set_colecta_del_dia(float var)
{
    this->colecta_del_dia=var;
}

int cSistemaDePagos::colecta_pasajeros_colectivo()
{
    return this->colecta_pasajeros;
}

float cSistemaDePagos::colecta_plata_colectivo()
{
    return this->colecta_colectivo;
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

ostream& operator<<(ostream& os, cSistemaDePagos* sis)
{
    os << endl;
    os << "Recaudado por el sistema en el dia de hoy: " << sis->get_colecta_del_dia()<<endl;
    os << "Pasajeros que circularon: " << sis->get_cantidad_de_pasajeros()<<endl;
    os << endl;
    return os;
}
