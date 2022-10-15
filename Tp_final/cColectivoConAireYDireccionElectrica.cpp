#include "cColectivoConAireYDireccionElectrica.h"

cColectivoConAireYDireccionElectrica::cColectivoConAireYDireccionElectrica(string id_Colectivo,cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros, int num_colectivo) :cColectivo(id_Colectivo, colectivero,
    sistema_de_pagos, recorrido, pos_del_recorrido, GPS, sentido, cantidad_max_pasajeros,num_colectivo)
{
    tiene_aire_acondicionado = true;
}

bool cColectivoConAireYDireccionElectrica::aire_acondicionado() {
    return this->tiene_aire_acondicionado;
}

void cColectivoConAireYDireccionElectrica::apagar_aire() {
        if (this->tiene_aire_acondicionado== true) {
        this->tiene_aire_acondicionado = false;
    }
}

