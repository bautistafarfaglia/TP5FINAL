#include "cColectivoAcordeon.h"


cColectivoAcordeon::cColectivoAcordeon(string id_Colectivo, cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros) :cColectivoConAireYDireccionElectrica(id_Colectivo, colectivero,
    sistema_de_pagos, recorrido, pos_del_recorrido, GPS, sentido, cantidad_max_pasajeros)
{
    

}


void cColectivoAcordeon::averia() {
    return;
}


string cColectivoAcordeon::to_string_colectivo() {
    return "";
}

void cColectivoAcordeon::imprimir() {
    return;
}
