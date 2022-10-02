#include "cPasajeros.h"

 cPasajeros::cPasajeros() {

}
cPasajeros::cPasajeros(string nombre, unsigned int long DNI, string destino, bool tiene_una_discapacidad, float saldo) {
    this->nombre = nombre;
    this->DNI = DNI;
    this->destino = destino;
    this->tiene_una_discapacidad = tiene_una_discapacidad;
    this->saldo = saldo;
}
bool cPasajeros::get_hay_una_discapacidad() {
    return false;
}

cTarjeta cPasajeros::get_tarjeta_pasajero() {
    return null;
}

string cPasajeros::get_destino() {
    return "";
}
string cPasajeros::get_DNI() {
    return "";
}

string cPasajeros::to_string_pasajero() {
    return "";
}

void cPasajeros::imprimir() {
    return;
}
