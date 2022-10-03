#pragma once
#include "Gbl.h"
#include "cColectivo.h"
#include "cRecorrido.h"
class cLineaDeColectivos {
public:

    cLineaDeColectivos();
    cLineaDeColectivos(string IDColectivo, string NombreLinea);
    ~cLineaDeColectivos() {
        for (int i = 0; i < listaColectivos.size(); i++)
        {
            delete& listaColectivos[i];
        }
        for (int i = 0; i < listaRecorrido.size(); i++)
        {
            delete& listaRecorrido[i];
        }
    };

    void TICK();

    string ToStringLineaDeColectivos();

    void Imprimir();
protected:
    string IDLineaDeColectivos;
    string NombreDeLinea;
    vector<cColectivo*> listaColectivos;
    vector<cRecorrido*> listaRecorrido;
};

//#endif _CLINEADECOLECTIVOS_H
