#pragma once
#include "Gbl.h"
#include "cPersona.h"
//#include "cParada.h"

#ifndef _CPASAJEROS_H
#define _CPASAJEROS_H

class cParada;
class cPasajeros : public cPersona {
public:

    cPasajeros(string nombre, string DNI, bool tiene_una_discapacidad, float saldo, int colectivo);
    ~cPasajeros();

    bool get_hay_una_discapacidad();
    bool get_prioridad();
    cParada* get_destino();
    string get_DNI();
    float* getSaldo();
    int get_num_colectivo();
    string to_string_pasajero();
    void imprimir();
    void setDestino(cParada* p);
    void set_prioridad(bool _prioridad);
    void set_sentido(eSentidoRecorrido _sentido);

protected:
    int num_colectivo;
    cParada* destino;
    cParada* parada_actual;
    bool tiene_una_discapacidad;
    float* saldo;
    bool prioridad;
};
#endif //_CPASAJEROS_H

