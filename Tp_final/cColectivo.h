#pragma once
#include "Gbl.h"
#include "cSistemaDePagos.h"
#include "cRecorrido.h"
#include "cColectivero.h"
#include "cPasajeros.h"

#ifndef _CCOLECTIVO_H
#define _CCOLECTIVO_H

class cColectivo {
public:
    unsigned short int cantidad_actual_pasajeros;

    cColectivo();
    cColectivo(string id_colectivo);

    string get_id_colectivo();

    bool get_estado_operativo();

    cRecorrido get_recorrido();

    cSistemaDePagos get_sistema_de_pagos();

    string get_GPS();

    unsigned int get_posicion_recorrido();

    /**
     * @param cRecorrido* nuevo_recorrido
     */
    void set_nuevo_recorrido(cRecorrido* nuevo_recorrido);

    /**
     * @param cColectivero* colectivero
     */
    void set_colectivero(cColectivero* colectivero);

    /**
     * @param cFecha* fecha
     */
    void set_fecha_mantenimiento(cFecha* fecha);

    /**
     * @param cPasajero* pasajero
     */
    bool control_sentido_pasajero(cPasajeros* pasajero);

    void avanzar_recorrido();

    bool bajar_pasajeros();

    /**
     * @param cPasajero* nuevo_pasajero
     */
    bool subir_pasajeros(cPasajeros* nuevo_pasajero);

    /**
     * @param cPasajero* nuevo_pasajero
     */
    void cobrar_boleto(cPasajeros* nuevo_pasajero);

    void cambio_de_sentido_recorrido();

    void actualizar_GPS();

    virtual void averia();

    virtual string to_string_colectivo();

    virtual void imprimir();
protected:
    string const id_colectivo;
    static unsigned long int cantidad_de_colectivos;
    bool estado_operativo;
    cFecha fecha_ultimo_mantenimiento;
    cColectivero colectivero;
    cSistemaDePagos sistema_de_pagos;
    cRecorrido recorrido;
    //cListaPasajeros pasajeros;
    unsigned int pos_del_recorrido;
    string GPS;
    eSentidoRecorrido sentido;
    const unsigned short int cantidad_max_pasajeros;
};

#endif //_CCOLECTIVO_H
