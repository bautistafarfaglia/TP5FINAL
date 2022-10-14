#pragma once
#include "Gbl.h"
#include "cPasajeros.h"

#ifndef _CPARADA_H
#define _CPARADA_H

class cParada {
public:

    cParada();
    cParada(string id_parada,string nombre_parada,string direccion);
    ~cParada() {
        for (int i = 0; i < listaPasajeros.size(); i++)
        {
            delete& listaPasajeros[i];
        }
    };

    string get_nombre_parada();

    //cListaPasajeros get_lista_pasajeros();

    string get_id_parada();

    vector<cPasajeros*> pasajeros_suben_colectivos();

    string to_string_parada();

    void imprimir();  
private:
    string const id_parada;
    string const nombre_parada;
    string const direccion;
    vector<cPasajeros*> listaPasajeros;
    vector<int> listaNumerosColectivos;
    static unsigned int cant_total_paradas;
};

#endif //_CPARADA_H