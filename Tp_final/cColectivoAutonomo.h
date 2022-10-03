#pragma once
#include "Gbl.h"

#ifndef _CCOLECTIVOAUTONOMO_H
#define _CCOLECTIVOAUTONOMO_H

#include "cColectivoSinAire.h"
#include "cColectivoConAireYDireccionElectrica.h"


class cColectivoAutonomo : public cColectivoSinAire, public cColectivoConAireYDireccionElectrica {
public:
    unsigned int Bateria;

    cColectivoAutonomo(string id_Colectivo, bool estado_operativo, cFecha fecha_ultimo_mantenimiento, cColectivero colectivero, cSistemaDePagos sistema_de_pagos, cRecorrido recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros);
    ~cColectivoAutonomo() {};

    void CargarBateria();

    void DescargarBateria();

};

#endif //_CCOLECTIVOAUTONOMO_H