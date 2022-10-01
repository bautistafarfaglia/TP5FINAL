#pragma once
#include "Gbl.h"
#ifndef _CCOLECTIVERO_H
#define _CCOLECTIVERO_H

#include "cPersona.h"


class cColectivero : public cPersona {
public:

    cColectivero();
    cColectivero(string nombre, string DNI, const string legajo);

    string get_legajo();
    string cargar_destino_pasajero(string destino_pasajero);

    string to_string_colectivero();

private:

    string const legajo;
    static unsigned int cantidad_de_colectiveros;
};

#endif //_CCOLECTIVERO_H

