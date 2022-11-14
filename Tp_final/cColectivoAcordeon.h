#pragma once
#include "Gbl.h"

/**
 * Project ING-LP1-TPFinal
 */


#ifndef _CCOLECTIVOACORDEON_H
#define _CCOLECTIVOACORDEON_H

#include "cColectivoConAireYDireccionElectrica.h"


class cColectivoAcordeon : public cColectivoConAireYDireccionElectrica {
    
public:
    cColectivoAcordeon(short int cantidad_max_pasajeros = 0, int num_colectivo = 0);
    ~cColectivoAcordeon();

    void averia();
    string to_string_colectivo();
    void imprimir();

};

#endif //_CCOLECTIVOACORDEON_H