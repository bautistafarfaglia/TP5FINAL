#pragma once
#include "Gbl.h"
#include "cTarjeta.h"


#ifndef _CPASAJEROS_H
#define _CPASAJEROS_H

#include "cPersona.h"


class cPasajeros : public cPersona {
public:

    cPasajeros();
    cPasajeros(string nombre,unsigned int long DNI,string destino,bool tiene_una_discapacidad,float saldo);

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

