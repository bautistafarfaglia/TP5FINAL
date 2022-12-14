#pragma once
#include "Gbl.h"
#include "cSistemaDePagos.h"
#include "cRecorrido.h"
#include "cColectivero.h"

#ifndef _CCOLECTIVO_H
#define _CCOLECTIVO_H

class cColectivo {
public:
  
    friend class cSistemaDePagos;

    cColectivo(int num_colectivo);
    ~cColectivo() {
        cantidad_de_colectivos_en_circulacion--;
        delete this->sistema_de_pagos;
        delete this->fecha_ultimo_mantenimiento;
        this->colectivero->setTrabajando(false);
    }

    short int get_id_colectivo();
    bool get_estado_operativo();
    eSentidoRecorrido get_sentido();
    cRecorrido* get_recorrido();
    cSistemaDePagos get_sistema_de_pagos();
    cColectivero* get_colectivero();
    string get_GPS();
    void llegarParada();
    unsigned int get_posicion_recorrido();
    void set_nuevo_recorrido(cRecorrido* nuevo_recorrido);
    void set_sentido(eSentidoRecorrido sentido);
    void set_colectivero(cColectivero* colectivero);
    void set_fecha_mantenimiento(cFecha* fecha);
    void set_recorrido(cRecorrido* r);
    void set_sistema_de_pagos(cSistemaDePagos* sdp);
    void set_estado_operativo(bool val);
    bool control_sentido_pasajero(cPasajeros* pasajero);
    bool avanzar_recorrido(vector<cPasajeros*>* Pasajeros_que_se_bajan);
    bool hay_destino(cPasajeros*);
    bool bajar_pasajeros(string nombreParada, vector<cPasajeros*>* Pasajeros_que_se_bajan);
    bool subir_pasajeros(vector<cPasajeros*> nuevo_pasajero);
    void cobrar_boleto(cPasajeros* nuevo_pasajero);
    void cambio_de_sentido_recorrido();
    friend istream& operator>>(istream& is, cColectivo& cole);
    virtual void averia() = 0;
    virtual string to_string_colectivo() = 0;
    virtual void imprimir() = 0;
    int calcular_distancia(cPasajeros* pasajero);
    static unsigned long int getcantidad_de_colectivos_en_circulacion();

    unsigned int get_num_cole();

protected:
    void actualizar_GPS();

    short const id_colectivo;
    static short int max_id;
    unsigned int numColectivo;
    static unsigned long int cantidad_de_colectivos_en_circulacion;
    bool estado_operativo;
    cFecha* fecha_ultimo_mantenimiento;
    cColectivero* colectivero;
    cSistemaDePagos* sistema_de_pagos;
    cRecorrido* recorrido;
    vector<cPasajeros*> listaPasajeros;
    int pos_del_recorrido;
    string GPS;
    eSentidoRecorrido sentido;
    unsigned short int cantidad_max_pasajeros;
    unsigned short int cantidad_actual_pasajeros;

};

#endif //_CCOLECTIVO_H
