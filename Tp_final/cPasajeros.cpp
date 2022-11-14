#include "cPasajeros.h"


cPasajeros::cPasajeros(string nombre, string _DNI, bool tiene_una_discapacidad, float saldo, int numcolectivo){
    this->nombre = nombre;
    this->DNI = DNI;
    this->destino = NULL;
    this->tiene_una_discapacidad = tiene_una_discapacidad;
    this->num_colectivo = numcolectivo;
    this->parada_actual = NULL;
    this->saldo =& saldo;
    this->prioridad = false;
}

cPasajeros::~cPasajeros() {
}
bool cPasajeros::get_hay_una_discapacidad() {
    return this->tiene_una_discapacidad;
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
    ss << endl;
    ss << "destino: " << this->destino<<endl
        << "tiene_una_discapacidad: " << this->tiene_una_discapacidad << endl
        << "saldo: " << this->saldo << endl;
    return ss.str();
}

void cPasajeros::imprimir() {
    return;
}

void cPasajeros::setDestino(cParada* p)
{
    try {
        if (p != NULL){
            this->destino = p;
            }
        else {
            throw "Error en asignacion de destino random";
        }
    }
    catch (exception e) {
        cout << "Error 02: " << e.what() << endl;
    }
}

void cPasajeros::set_prioridad(bool _prioridad) {
    this->prioridad = _prioridad;
}

bool cPasajeros::get_prioridad() {
    return this->prioridad;
}

