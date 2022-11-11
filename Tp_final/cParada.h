#pragma once
#include "Gbl.h"
#include "cPasajeros.h"

#ifndef _CPARADA_H
#define _CPARADA_H

class cParada {
public:
    cParada(string nombre_parada = "none", eSentidoRecorrido direccion = DEFAULT);
    ~cParada() {
        for (int i = 0; i < listaPasajeros.size(); i++)
        {
            delete listaPasajeros[i];
        }
       // delete[] &this->listaPasajeros; //chequear si esta bien que este comentada esta linea
    };

    string get_nombre_parada();

    vector<cPasajeros*> get_lista_pasajeros();

    int get_id_parada();

    vector<cPasajeros*> pasajeros_suben_colectivo(int num);

    void agregar_pasajero(cPasajeros* pasajero_nuevo);
    string to_string_parada();
    friend istream& operator>>(istream& is, cParada& re);
    void imprimir();  
private:
    const int id_parada;
    string nombre_parada;
    eSentidoRecorrido direccion;
    vector<cPasajeros*> listaPasajeros;
    vector<int> listaNumerosColectivos;
    static unsigned int cant_total_paradas; 
};

#endif //_CPARADA_H