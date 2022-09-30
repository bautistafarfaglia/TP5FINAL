#pragma once
#include "Gbl.h"

#ifndef _CCOLECTIVODIRECCIONHIDRAULICA_H
#define _CCOLECTIVODIRECCIONHIDRAULICA_H

#include "cColectivoSinAire.h"


class cColectivoDireccionHidraulica : public cColectivoSinAire {
public:

    cColectivoDireccionHidraulica();

    cColectivoDireccionHidraulica(string id_colectivo);

    void averia();

    string to_string_colectivo();

    void imprimir();
};

#endif //_CCOLECTIVODIRECCIONHIDRAULICA_H
