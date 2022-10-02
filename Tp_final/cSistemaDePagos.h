#pragma once
#include "Gbl.h"
#include "cTarjeta.h"
#ifndef _CSISTEMADEPAGOS_H
#define _CSISTEMADEPAGOS_H

class cSistemaDePagos {
public:

    cSistemaDePagos();
    cSistemaDePagos(float colecta_del_dia, unsigned int cantidad_pasajeros);

    unsigned int get_cantidad_de_pasajeros();

    float get_colecta_del_dia();

    /**
     * @param string inicio
     * @param string destino
     * @param int cantidad_de_paradas
     * @param cTarjeta* tarjeta_pasajero
     */
    bool generar_viaje(string inicio, string destino,int cantidad_de_paradas, cTarjeta* tarjeta_pasajero);

private:
    float colecto_del_dia;
    unsigned int cantidad_pasajeros;
};

#endif //_CSISTEMADEPAGOS_H