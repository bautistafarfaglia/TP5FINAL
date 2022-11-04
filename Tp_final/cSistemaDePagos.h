#pragma once
#include "Gbl.h"
#include "cTarjeta.h"
#ifndef _CSISTEMADEPAGOS_H
#define _CSISTEMADEPAGOS_H

class cSistemaDePagos {
public:

    cSistemaDePagos(float colecta_del_dia=0, unsigned int cantidad_pasajeros=0);
    ~cSistemaDePagos() {};

    unsigned int get_cantidad_de_pasajeros();

    float get_colecta_del_dia();

    /**
     * @param string inicio
     * @param string destino
     * @param int cantidad_de_paradas
     * @param cTarjeta* tarjeta_pasajero
     */
    bool cobrar_voleto(float* saldo,int cantParadas);

private:
    float colecto_del_dia;
    unsigned int cantidad_pasajeros;
};

#endif //_CSISTEMADEPAGOS_H