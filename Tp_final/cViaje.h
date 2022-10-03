#pragma once
#include "Gbl.h"


#ifndef _CVIAJE_H
#define _CVIAJE_H

class cViaje {
public:

    cViaje();
    cViaje(string inicio,string destino,float costo_del_viaje);
    ~cViaje() {};

    string to_string_viaje();
    void imprimir();
private:
    string id_viaje;
    static int cantidad_de_viajes_creados;
    string inicio;
    string destino;
    float costo_del_viaje;
};

#endif //_CVIAJE_H
