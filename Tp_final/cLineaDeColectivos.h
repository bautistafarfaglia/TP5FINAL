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
    cLineaDeColectivos(string NombreLinea="none");
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

    void agregar_peronas(cPasajeros* persona);

    void TICK();

    string ToStringLineaDeColectivos();

    void Imprimir();

    void generarcColectivo();

    void generarRecorrido();

    /// <summary>
    /// Este metodo sirve para poder asignar a un colectivo un recorrido dependiendo la cantidad de paradas
    /// </summary>
    /// <param name="id_colectivo"></param>
    /// <param name="Longitud_max"></param>
    void cambiarRecorrido(int id_colectivo,unsigned int Longitud_max);
    /// <summary>
    /// Este metodo te devuelve el recorrido solicitado segun que numoer
    /// </summary>
    /// <param name="Longitud">Se devuelve </param>
    /// <returns></returns>
    cRecorrido* ObtenerRecorrido(unsigned int Longitud);

protected:
    const int IDLineaDeColectivos;
    static int Max_id;
    string NombreDeLinea;
    vector<cColectivo*> listaColectivos;
    vector<cRecorrido*> listaRecorrido;
    vector<cPasajeros*> listaPasajeros;
};

//#endif _CLINEADECOLECTIVOS_H
