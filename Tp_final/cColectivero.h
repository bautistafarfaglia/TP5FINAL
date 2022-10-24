#pragma once
#include "Gbl.h"
#ifndef _CCOLECTIVERO_H
#define _CCOLECTIVERO_H

#include "cPersona.h"


class cColectivero : public cPersona {
public:
    cColectivero(string nombre = "ninguno", string DNI = "none", string legajo = "none");
    ~cColectivero() {};

    string get_legajo();
    string cargar_destino_pasajero(string destino_pasajero);

    string to_string_colectivero();

    friend istream& operator>>(istream& is, cColectivero& cole);
private:

    string legajo;
    static unsigned int cantidad_de_colectiveros;
};

#endif //_CCOLECTIVERO_H

