#pragma once
#include "Gbl.h"
class cLineaDeColectivos {
public:

    cLineaDeColectivos();
    cLineaDeColectivos(string IDColectivo);

    void TICK();

    string ToStringLineaDeColectivos();

    void Imprimir();
protected:
    string IDLineaDeColectivos;
    string NombreDeLinea;
    //cListaColectivos ListaColectivos;
    //cListaRecorridos ListaRecorridos;
};

#endif //_CLINEADECOLECTIVOS_H
