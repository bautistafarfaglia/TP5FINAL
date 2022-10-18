#pragma once
#include "Gbl.h"
#include "cParada.h"


#ifndef _CRECORRIDO_H
#define _CRECORRIDO_H

class cRecorrido {
public:
    cRecorrido(string id_recorrido = "none");
    ~cRecorrido() {
        for (int i = 0; i < listaParada.size(); i++)
        {
            delete& listaParada[i];
        }
    };

    string get_codigo_recorrido();

    unsigned int get_cantidad_paradas();

    int cantidad_de_paradas_entre_destinos(string parada_destino,string parada_salida);

    void agregar_paradas_recorrido(cParada* parada);

    string to_string_recorrido();
    vector<cParada*> get_lista_paradas();
    friend istream& operator>>(istream& is, cRecorrido& re);
    void imprimir();
private:
    const string codigo_recorrido;
    vector<cParada*> listaParada;
};

#endif //_CRECORRIDO_H

