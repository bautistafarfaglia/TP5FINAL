#pragma once
#include "Gbl.h"


#ifndef _CCOLECTIVOSINAIRE_H
#define _CCOLECTIVOSINAIRE_H

#include "cColectivo.h"


class cColectivoSinAire : public cColectivo {
public:

    cColectivoSinAire(cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, short int cantidad_max_pasajeros, int num_colectivo);
    ~cColectivoSinAire() {};

    void averia();

    string to_string_colectivo();

    void imprimir();
};

#endif //_CCOLECTIVOSINAIRE_H