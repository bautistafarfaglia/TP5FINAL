#pragma once
#include "Gbl.h"
#include "cViaje.h"



#ifndef _CTARJETA_H
#define _CTARJETA_H

class cTarjeta {
public:
    cTarjeta(float saldo, bool _checkEliminar, unsigned short int _cantTotal);
    ~cTarjeta() {
        for (unsigned int i = 0; i < cantidad_de_tarjetas_creadas; i++)
        {
            delete& listaViajesRealizados[i];
        }
    };

    float get_tarjeta();

    void agregar_viaje_lista(cViaje* nuevo_viaje);

    float carga_de_viaje(float saldo_agregar);

    float descuento_salto(float cargo);

    string to_string_tarjeta();

    void imprimir();


    void agregar(cViaje* viaje);
    void eliminar(cViaje* viaje);
    void operator+(cViaje* viaje);
    void operator-(cViaje* viaje);
    cViaje* operator[](short i);
    void operator++();
    cViaje* quitar(cViaje* viaje);

private:

    void resize();
    void ordenar();
    bool noRepetido(cViaje* cViaje);

    unsigned short int cantTotal;
    unsigned short int cantActual;
    unsigned int long numero_de_viaje;
    float saldo;
    static unsigned int long cantidad_de_tarjetas_creadas;
    cViaje** listaViajesRealizados;
    bool checkEliminar;
};

#endif //_CTARJETA_H

