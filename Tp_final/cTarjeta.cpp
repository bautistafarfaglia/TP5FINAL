#include "cTarjeta.h"

unsigned int long cTarjeta::cantidad_de_tarjetas_creadas = 0;

cTarjeta::cTarjeta(float _saldo) {
    this->saldo = _saldo;
    this->numero_de_viaje = 0;
    this->cantidad_de_tarjetas_creadas++;
    
}

float cTarjeta::get_tarjeta() {
    return this->saldo;
}

void cTarjeta::agregar_viaje_lista(cViaje* nuevo_viaje) {
    return;
}


float cTarjeta::carga_de_viaje(float saldo_agregar) {
    return 0.0;
}

float cTarjeta::descuento_salto(float cargo) {
    return 0.0;
}

string cTarjeta::to_string_tarjeta() {
    return "";
}

void cTarjeta::imprimir() {
    return;
}

void cTarjeta::agregar(cViaje* viaje) {}
void cTarjeta::eliminar(cViaje* viaje) {}
void cTarjeta::operator+(cViaje* viaje) {}
void cTarjeta::operator-(cViaje* viaje) {}
cViaje* cTarjeta::operator[](short i) {}
void cTarjeta::operator++() {}
cViaje* cTarjeta::quitar(cViaje* viaje) {}