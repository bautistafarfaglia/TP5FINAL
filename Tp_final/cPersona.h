#pragma once
#include "Gbl.h"


#ifndef _CPERSONA_H
#define _CPERSONA_H

class cPersona {
public:

    cPersona();
    cPersona(string Nombre,string DNI);
    ~cPersona() {};

protected:
    string nombre;
    string DNI;
};

#endif //_CPERSONA_H

