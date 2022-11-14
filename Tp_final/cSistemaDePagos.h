#pragma once
#include "Gbl.h"
#ifndef _CSISTEMADEPAGOS_H
#define _CSISTEMADEPAGOS_H

class cSistemaDePagos {
public:
    //friend class cSistema;
    cSistemaDePagos(unsigned int cantidad_pasajeros=0);
    ~cSistemaDePagos() {};

    unsigned int get_cantidad_de_pasajeros();
    float get_colecta_del_dia();
    bool cobrar_boleto(float* saldo,int cantParadas);
    void sumar_boleto(int cantParadas);

    friend ostream& operator<<(ostream& is, cSistemaDePagos* sis);
    void resetDia();

    void set_cantidad_de_pasajeros(unsigned int var); //agregado
    void set_colecta_del_dia(float var);//agregado
private:
    static int max_id;
    int id;
    static float colecta_del_dia;
    float colecta_colectivo;
    unsigned int cantidad_pasajeros;

};

#endif //_CSISTEMADEPAGOS_H