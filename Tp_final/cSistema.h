#pragma once
#include "Gbl.h"
#include "cColectivo.h"
#include "cColectivoAcordeon.h"
#include "cColectivoSinAire.h"
#include "cRecorrido.h"
class cSistema {

    cColectivoAcordeon* generar_cColectivo_Acordeon();
    cColectivoConAireYDireccionElectrica* generar_cColectivo_ConAire_y_DireccionElectrica();
    cColectivoSinAire* generar_cColectivo_sinAire();
public:
    cSistema(string NombreLinea="none");
    ~cSistema() {
        int cantcoles = listaColectivos.size();
        for (int i = 0; i < cantcoles; i++)
        {
            if (listaColectivos[i] != NULL) {
                delete listaColectivos[i];
            }
        }
        int cantcolectiveros = listaColectiveros.size();
        for (int i = 0; i < cantcolectiveros; i++)
        {
            if (listaColectiveros[i] != NULL) {
                delete listaColectiveros[i];
            }
        }
        for (int i = 0; i < cantActual; i++)
        {
            if (listaRecorrido[i] != NULL) {
                delete listaRecorrido[i];
            }
        }
        delete[] listaRecorrido;
    };

    void GenerarAveríaRandom();
    /// <summary>
    /// Manda un colectivo para la misma parada donde se situo el pasajero
    /// </summary>
    void SolucionarAveríaProducida();
    /// <summary>
    ///  actualiza el estado de todos los objetos
    /// </summary>
    void TICK();
    /// <summary>
    /// Pasa a texto toda la linea
    /// </summary>
    /// <returns></returns>
    string ToStringLineaDeColectivos();
    /// <summary>
    /// imprime los colectivos
    /// </summary>
    void ImprimirColectivos();
    /// <summary>
    /// Genera un colectivo de tipo random mediante consola
    /// </summary>
    /// <param name="cole"></param>
    void generarcColectivo(cColectivo* cole);
    /// <summary>
    /// Genera un recorrido mediante consola 
    /// </summary>
    void generarRecorrido();
    /// <summary>
    /// Agrega personas y las asigna a paradas random y tmb setea su destino
    /// </summary>
    /// <param name="persona"></param>
    void agregar_personas(cPasajeros* persona);
    /// <summary>
    /// Agrega los recorrido 
    /// </summary>
    /// <param name="recorrido"></param>
    void agregar(cRecorrido* recorrido);
    /// <summary>
    /// Elimina un recorrido
    /// </summary>
    /// <param name="recorrido"></param>
    void eliminar(cRecorrido* recorrido);
    cRecorrido* quitar(cRecorrido* recorrido);
    /// <summary>
    /// Agrega un recorrido
    /// </summary>
    /// <param name="recorrido"></param>
    void operator+(cRecorrido* recorrido);

    /// <summary>
    /// Quita el recorrido
    /// </summary>
    /// <param name="recorrido"></param>
    /// <returns></returns>
    cRecorrido* operator-(cRecorrido* recorrido);
    /// <summary>
    /// Obtener el elemetno i esimo
    /// </summary>
    /// <param name="i">elemento devuelto</param>
    /// <returns></returns>
    cRecorrido* operator[](short i);
    void ordenar();
    cSistemaDePagos* get_sistema_de_pagos();
    /// <summary>
    /// Chequea si el colectivo no fue ya agregado
    /// </summary>
    /// <param name="cole">Colectivo a chequear</param>
    /// <returns></returns>
    bool operator!=(cColectivo* cole);

    /// <summary>
    /// Verifica si la cantidad pasada por parametro es mayor a la cantidad de colectivos
    /// </summary>
    /// <param name="pos">Cantidad a pasar</param>
    /// <returns></returns>
    bool operator>(int pos);

    /// <summary>
    /// Verifica si la cantidad pasada por parametro es menor a la cantidad de colectivos
    /// </summary>
    /// <param name="pos">Cantidad a pasar</param>
    /// <returns></returns>
    bool operator<(int pos);

    /// <summary>
    /// Chequea si no existe ya ese recorrido
    /// </summary>
    /// <param name="rec">Recorrido a chequear</param>
    /// <returns></returns>
    bool operator==(cRecorrido* rec);

    void resize();
    //void operator++();

    /// <summary>
    /// Este metodo sirve para poder asignar a un colectivo un recorrido random
    /// </summary>
    /// <param name="id_colectivo"></param>
    /// <param name="Longitud_max"></param>
    bool cambiarRecorridoColectivos(int id_colectivo);

    /// <summary>
    /// Cambia de forma random la parada donde se situara el pasajero y su destino
    /// </summary>
    /// <param name="p">pasajero a cambiar</param>
    /// <returns>Si esta mal el pasajero devuelve falso, sino true</returns>
    bool cambiarRecorridoPasajeros(cPasajeros* p);

    /// <summary>
    /// Avanza un recorrido random y realiza todos los chequeos pertinentes
    /// </summary>
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

//#endif _CSISTEMA_H
