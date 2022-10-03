#pragma once
#include "Gbl.h"
#include "cViaje.h"



#ifndef _CTARJETA_H
#define _CTARJETA_H

class cTarjeta {
public:

    cTarjeta();
    cTarjeta(float saldo);
    ~cTarjeta() {};

    float get_tarjeta();

    void agregar_viaje_lista(cViaje* nuevo_viaje);

    float carga_de_viaje(float saldo_agregar);

    float descuento_salto(float cargo);

    string to_string_tarjeta();

    void imprimir();
private:
    unsigned int long numero_de_viaje;
    float saldo;
    static unsigned int long cantidad_de_tarjetas_creadas;
    vector<cViaje*> listaViajesRealizados;
};

#endif //_CTARJETA_H

