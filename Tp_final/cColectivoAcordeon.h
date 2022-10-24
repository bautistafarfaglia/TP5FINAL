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
    cColectivoAcordeon(cColectivero* colectivero= nullptr, cSistemaDePagos* sistema_de_pagos=nullptr, cRecorrido* recorrido=nullptr, unsigned int pos_del_recorrido=0, string GPS="-", eSentidoRecorrido sentido=DEFAULT, short int cantidad_max_pasajeros=0, int num_colectivo=0);
    ~cColectivoAcordeon() {};

    void averia();

    string to_string_colectivo();

    void imprimir();

};

#endif //_CCOLECTIVOACORDEON_H