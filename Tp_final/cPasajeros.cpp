#include "cPasajeros.h"


cPasajeros::cPasajeros(string nombre, string _DNI, cParada* destino, bool tiene_una_discapacidad, float saldo, int numcolectivo){
    this->nombre = nombre;
    this->DNI = DNI;
    this->destino = NULL;
    this->tiene_una_discapacidad = tiene_una_discapacidad;
    this->num_colectivo = numcolectivo;
    this->tarjeta_pasajero= new cTarjeta(saldo,true,20);//chequear este 100 en el constructor de cTarjeta
}

cPasajeros::~cPasajeros() {
    delete (this->tarjeta_pasajero);
}
bool cPasajeros::get_hay_una_discapacidad() {
    return this->tiene_una_discapacidad;
}

cTarjeta* cPasajeros::get_tarjeta_pasajero() {
    return (this->tarjeta_pasajero);
}

cParada* cPasajeros::get_destino() {
    return this->destino;
}
string cPasajeros::get_DNI() {
    return this->DNI;
}

float* cPasajeros::getSaldo()
{
    return this->saldo;
}

int cPasajeros::get_num_colectivo()
{
    return (this->num_colectivo);
}

string cPasajeros::to_string_pasajero() {
    stringstream ss;
    ss << "destino: " << this->destino << endl
        << "to_string_tarjeta: " << this->tarjeta_pasajero->to_string_tarjeta() << endl
        << "tiene_una_discapacidad: " << this->tiene_una_discapacidad << endl
        << "saldo: " << this->saldo << endl;
    return ss.str();
}

void cPasajeros::imprimir() {
    return;
}

