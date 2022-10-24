#pragma once 
#include"Gbl.h"
#ifndef _CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H
#define _CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H

#include "cColectivo.h"


class cColectivoConAireYDireccionElectrica : public cColectivo {
public:
    
    cColectivoConAireYDireccionElectrica(cColectivero* colectivero = nullptr, cSistemaDePagos* sistema_de_pagos= nullptr, cRecorrido* recorrido = nullptr, unsigned int pos_del_recorrido=0, string GPS="none", eSentidoRecorrido sentido=DEFAULT, short int cantidad_max_pasajeros=0, int num_colectivo=0);
    ~cColectivoConAireYDireccionElectrica() {};

    bool aire_acondicionado();

    void apagar_aire();

    void averia();

    string to_string_colectivo();

    void imprimir();
protected:
    bool tiene_aire_acondicionado;
};

#endif //_CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H