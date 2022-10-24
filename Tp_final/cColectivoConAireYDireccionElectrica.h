#pragma once 
#include"Gbl.h"
#ifndef _CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H
#define _CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H

#include "cColectivo.h"


class cColectivoConAireYDireccionElectrica : public cColectivo {
public:
    
    cColectivoConAireYDireccionElectrica(cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, short int cantidad_max_pasajeros, int num_colectivo);
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