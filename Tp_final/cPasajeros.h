#pragma once
#include "Gbl.h"
#include "cTarjeta.h"
#include "cPersona.h"

#ifndef _CPASAJEROS_H
#define _CPASAJEROS_H



class cPasajeros : public cPersona {
public:

    cPasajeros(string nombre,string DNI,string destino,bool tiene_una_discapacidad,float saldo);
    ~cPasajeros() {};

    bool get_hay_una_discapacidad();

    cTarjeta get_tarjeta_pasajero();

    string get_destino();

    string get_DNI();

    string to_string_pasajero();

    void imprimir();

protected:
    string destino;
    cTarjeta tarjeta_pasajero;
    bool tiene_una_discapacidad;
    float saldo;
};

#endif //_CPASAJEROS_H

