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

    cColectivo(string id_colectivo, bool estado_operativo, cFecha fecha_ultimo_mantenimiento, cColectivero colectivero, cSistemaDePagos sistema_de_pagos, cRecorrido recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros);

    string get_id_colectivo();

    bool get_estado_operativo();

    cRecorrido get_recorrido();

    cSistemaDePagos get_sistema_de_pagos();

    string get_GPS();

    void llegarParada();

    unsigned int get_posicion_recorrido();

    void set_nuevo_recorrido(cRecorrido* nuevo_recorrido);
    
   void set_colectivero(cColectivero* colectivero);

   void set_fecha_mantenimiento(cFecha* fecha);

   bool control_sentido_pasajero(cPasajeros* pasajero);

   void avanzar_recorrido();

   bool bajar_pasajeros();

   bool subir_pasajeros(cPasajeros* nuevo_pasajero);

   void cobrar_boleto(cPasajeros* nuevo_pasajero);

   void cambio_de_sentido_recorrido();

   void actualizar_GPS();

   virtual void averia() =0;

   virtual string to_string_colectivo() =0;

   virtual void imprimir()=0;

protected:
    string const id_colectivo;
    static unsigned long int cantidad_de_colectivos;
    bool estado_operativo;
    cFecha fecha_ultimo_mantenimiento;
    cColectivero colectivero;
    cSistemaDePagos sistema_de_pagos;
    cRecorrido recorrido;
    vector<cPasajeros*> listaPasajeros;
    unsigned int pos_del_recorrido;
    string GPS;
    eSentidoRecorrido sentido;
    const unsigned short int cantidad_max_pasajeros;
    unsigned short int cantidad_actual_pasajeros;

};

#endif //_CCOLECTIVO_H
