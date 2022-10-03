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

    cColectivoAcordeon();
    cColectivoAcordeon(string id_colectivo);
    ~cColectivoAcordeon() {};

    void averia();

    string to_string_colectivo();

    void imprimir();

};

#endif //_CCOLECTIVOACORDEON_H