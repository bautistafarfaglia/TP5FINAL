#pragma once
#include "Gbl.h"
#include "cColectivo.h"
#include "cColectivoAcordeon.h"
#include "cColectivoSinAire.h"
#include "cRecorrido.h"
class cLineaDeColectivos {

    cColectivoAcordeon* generar_cColectivo_Acordeon();
    cColectivoConAireYDireccionElectrica* generar_cColectivo_ConAire_y_DireccionElectrica();
    cColectivoSinAire* generar_cColectivo_sinAire();
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

    void generarcColectivo(string tipo);


protected:
    string IDLineaDeColectivos;
    string NombreDeLinea;
    vector<cColectivo*> listaColectivos;
    vector<cRecorrido*> listaRecorrido;
};

//#endif _CLINEADECOLECTIVOS_H
