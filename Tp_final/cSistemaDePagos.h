#pragma once
#include "Gbl.h"
#ifndef _CSISTEMADEPAGOS_H
#define _CSISTEMADEPAGOS_H

class cSistemaDePagos {
public:

    cSistemaDePagos(unsigned int cantidad_pasajeros=0);
    ~cSistemaDePagos() {};

    unsigned int get_cantidad_de_pasajeros();
    float get_colecta_del_dia();
    bool cobrar_boleto(float* saldo,int cantParadas);
    void sumar_boleto(int cantParadas);

private:
    static int max_id;
    int id;
    static float colecta_del_dia;
    float colecta_colectivo;
    unsigned int cantidad_pasajeros;

};

#endif //_CSISTEMADEPAGOS_H