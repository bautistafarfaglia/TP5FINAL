#pragma once 
#include"Gbl.h"
#ifndef _CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H
#define _CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H

#include "cColectivo.h"


class cColectivoConAireYDireccionElectrica : public cColectivo {
public:
    cColectivoConAireYDireccionElectrica();

    cColectivoConAireYDireccionElectrica(string id_colectivo);

    bool aire_acondicionado();

    void apagar_aire();

    virtual void averia();

    virtual string to_string_colectivo();

    virtual void imprimir();
protected:
    bool aire_acondicionado;
};

#endif //_CCOLECTIVOCONAIREYDIRECCIONELECTRICA_H