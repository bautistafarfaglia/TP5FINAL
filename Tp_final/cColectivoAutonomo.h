#pragma once
#include "Gbl.h"

#ifndef _CCOLECTIVOAUTONOMO_H
#define _CCOLECTIVOAUTONOMO_H

#include "cColectivoSinAire.h"
#include "cColectivoConAireYDireccionElectrica.h"


class cColectivoAutonomo : public cColectivoSinAire, public cColectivoConAireYDireccionElectrica {
public:
    unsigned int Bateria;

    cColectivoAutonomo();

    void CargarBateria();

    void DescargarBateria();

};

#endif //_CCOLECTIVOAUTONOMO_H