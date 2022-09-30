#include "cColectivo.h"
cColectivo::cColectivo() {

}

cColectivo::cColectivo(string id_colectivo) {

}

string cColectivo::get_id_colectivo() {
    return "";
}

bool cColectivo::get_estado_operativo() {
    return false;
}

cRecorrido cColectivo::get_recorrido() {
    return null;
}

cSistemaDePagos cColectivo::get_sistema_de_pagos() {
    return null;
}


string cColectivo::get_GPS() {
    return "";
}

unsigned int cColectivo::get_posicion_recorrido() {
    return null;
}

void cColectivo::set_nuevo_recorrido(cRecorrido* nuevo_recorrido) {
    return;
}

void cColectivo::set_colectivero(cColectivero* colectivero) {
    return;
}

void cColectivo::set_fecha_mantenimiento(cFecha* fecha) {
    return;
}

bool cColectivo::control_sentido_pasajero(cPasajeros* pasajero) {
    return false;
}

void cColectivo::avanzar_recorrido() {
    return;
}


bool cColectivo::bajar_pasajeros() {
    return false;
}


bool cColectivo::subir_pasajeros(cPasajeros* nuevo_pasajero) {
    return false;
}

void cColectivo::cobrar_boleto(cPasajeros* nuevo_pasajero) {
    return;
}

void cColectivo::cambio_de_sentido_recorrido() {
    return;
}

void cColectivo::actualizar_GPS() {
    return;
}
