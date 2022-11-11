#pragma once
#include "Gbl.h"
#include "cTarjeta.h"
#include "cPersona.h"
#include "cParada.h"

#ifndef _CPASAJEROS_H
#define _CPASAJEROS_H


class cPasajeros : public cPersona {
public:

    cPasajeros(string nombre,string DNI, cParada* destino,bool tiene_una_discapacidad,float saldo,int colectivo);
    ~cPasajeros();

    bool get_hay_una_discapacidad();

    cTarjeta* get_tarjeta_pasajero();

    cParada* get_destino();

    string get_DNI();
    float* getSaldo();

    int get_num_colectivo();

    string to_string_pasajero();

    void imprimir();

protected:
    int num_colectivo;
    cParada* destino;
    cTarjeta* tarjeta_pasajero;
    bool tiene_una_discapacidad;
    float* saldo;
};

#endif //_CPASAJEROS_H

