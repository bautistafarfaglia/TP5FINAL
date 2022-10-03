#pragma once
#include "Gbl.h"

/**
 * Project ING-LP1-TPFinal
 */


#ifndef _CCOLECTIVOACORDEON_H
#define _CCOLECTIVOACORDEON_H

#include "cColectivoConAireYDireccionElectrica.h"


class cColectivoAcordeon : public cColectivoConAireYDireccionElectrica {
public:
    cColectivoAcordeon(string id_Colectivo, cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros);
    ~cColectivoAcordeon() {};

    void averia();

    string to_string_colectivo();

    void imprimir();

};

#endif //_CCOLECTIVOACORDEON_H