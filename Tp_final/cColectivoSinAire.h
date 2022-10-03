#pragma once
#include "Gbl.h"


#ifndef _CCOLECTIVOSINAIRE_H
#define _CCOLECTIVOSINAIRE_H

#include "cColectivo.h"


class cColectivoSinAire : public cColectivo {
public:

    cColectivoSinAire(string id_Colectivo,bool estado_operativo, cFecha fecha_ultimo_mantenimiento, cColectivero colectivero, cSistemaDePagos sistema_de_pagos, cRecorrido recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros);
    ~cColectivoSinAire() {};

    virtual void averia() = 0;

    virtual string to_string_colectivo() = 0;

    virtual void imprimir() = 0;
};

#endif //_CCOLECTIVOSINAIRE_H