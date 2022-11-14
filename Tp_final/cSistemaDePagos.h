#pragma once
#include "Gbl.h"
#ifndef _CSISTEMADEPAGOS_H
#define _CSISTEMADEPAGOS_H

class cSistemaDePagos {
public:/*
    friend class cColectivo;*/
    cSistemaDePagos();
    ~cSistemaDePagos() {};

    unsigned int get_cantidad_de_pasajeros();
    float get_colecta_del_dia();
    bool cobrar_boleto(float* saldo,int cantParadas);
    void sumar_boleto(int cantParadas);

    friend ostream& operator<<(ostream& is, cSistemaDePagos* sis);
    void resetDia();

    void set_cantidad_de_pasajeros(unsigned int var); //agregado
    void set_colecta_del_dia(float var);//agregado

    int colecta_pasajeros_colectivo();
    float colecta_plata_colectivo();
private:
    static int max_id;
    int id;
    static float colecta_del_dia;
    float colecta_colectivo;
    static int cantidad_pasajeros;
    int colecta_pasajeros;

};

#endif //_CSISTEMADEPAGOS_H