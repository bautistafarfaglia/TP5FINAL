#pragma once
#include "Gbl.h"


#ifndef _CCOLECTIVOSINAIRE_H
#define _CCOLECTIVOSINAIRE_H

#include "cColectivo.h"


class cColectivoSinAire : public cColectivo {
public:

    cColectivoSinAire(short int cantidad_max_pasajeros = 0, int num_colectivo = 0);
    ~cColectivoSinAire() {};

    void averia();
    string to_string_colectivo();
    void imprimir();
};

#endif //_CCOLECTIVOSINAIRE_H