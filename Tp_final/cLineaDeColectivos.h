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
        for (int i = 0; i < cantActual; i++)
        {
            delete listaRecorrido[i];
        }
        delete[] listaRecorrido;
    };

    void GenerarAverķaRandom();
    void SolucionarAverķaProducida();
    void TICK();
    string ToStringLineaDeColectivos();
    void ImprimirColectivos();
    void generarcColectivo();
    void generarRecorrido();

    void agregar_personas(cPasajeros* persona);
    void agregar(cRecorrido* recorrido);
    void eliminar(cRecorrido* recorrido);
    cRecorrido* quitar(cRecorrido* recorrido);
    void operator+(cRecorrido* recorrido);
    cRecorrido* operator-(cRecorrido* recorrido);
    cRecorrido* operator[](short i);
    void ordenar();
    void resize();
    //void operator++();

    /// <summary>
    /// Este metodo sirve para poder asignar a un colectivo un recorrido random
    /// </summary>
    /// <param name="id_colectivo"></param>
    /// <param name="Longitud_max"></param>
    bool cambiarRecorrido(int id_colectivo);
    

    void AvanzarColectivoRandom();

protected:
    unsigned short int cantActual;
    const int IDLineaDeColectivos;
    static int Max_id;
    string NombreDeLinea;
    vector<cColectivo*> listaColectivos;
    cRecorrido** listaRecorrido;
    vector<cPasajeros*> listaPasajeros;
    vector<cColectivero*> listaColectiveros;
    cSistemaDePagos* SistemaGeneralDePagos;
    bool asignarChoferSistemaYRecorridoAcolectivosGenerados(cColectivo* cole);
};

//#endif _CLINEADECOLECTIVOS_H
