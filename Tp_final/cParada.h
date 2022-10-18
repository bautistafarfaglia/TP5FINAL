#pragma once
#include "Gbl.h"
#include "cPasajeros.h"

#ifndef _CPARADA_H
#define _CPARADA_H

class cParada {
public:
    //chequear el string id_parada
    cParada(string id_parada ="none", string nombre_parada = "none", eSentidoRecorrido direccion = DEFAULT);
    ~cParada() {
        for (int i = 0; i < listaPasajeros.size(); i++)
        {
            delete& listaPasajeros[i];
        }
    };//chequear si este eliminar esta bien

    string get_nombre_parada();

    vector<cPasajeros*> get_lista_pasajeros();

    string get_id_parada();

    vector<cPasajeros*> pasajeros_suben_colectivo(int num);

    void agregar_pasajero(cPasajeros* pasajero_nuevo);
    string to_string_parada();
    friend istream& operator>>(istream& is, cParada& re);
    void imprimir();  
private:
    string const id_parada;
    string nombre_parada;
    eSentidoRecorrido direccion;
    vector<cPasajeros*> listaPasajeros;
    vector<int> listaNumerosColectivos;
    static unsigned int cant_total_paradas; //chequear este cant totalparadas
};

#endif //_CPARADA_H