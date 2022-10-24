#pragma once
#include "Gbl.h"


#ifndef _CCOLECTIVOSINAIRE_H
#define _CCOLECTIVOSINAIRE_H

#include "cColectivo.h"


class cColectivoSinAire : public cColectivo {
public:

    cColectivoSinAire(cColectivero* colectivero=nullptr, cSistemaDePagos* sistema_de_pagos = nullptr, cRecorrido* recorrido = nullptr, unsigned int pos_del_recorrido=0, string GPS="none", eSentidoRecorrido sentido=DEFAULT, short int cantidad_max_pasajeros=0, int num_colectivo=0);
    ~cColectivoSinAire() {};

    void averia();

    string to_string_colectivo();

    void imprimir();
};

#endif //_CCOLECTIVOSINAIRE_H