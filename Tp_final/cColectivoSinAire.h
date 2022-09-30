#pragma once
#include "Gbl.h"


#ifndef _CCOLECTIVOSINAIRE_H
#define _CCOLECTIVOSINAIRE_H

#include "cColectivo.h"


class cColectivoSinAire : public cColectivo {
public:

    cColectivoSinAire();

    cColectivoSinAire( string id_Colectivo);

    virtual void averia() = 0;

    virtual string to_string_colectivo() = 0;

    virtual void imprimir() = 0;
};

#endif //_CCOLECTIVOSINAIRE_H