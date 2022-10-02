#include "cColectivo.h"

unsigned long cColectivo::cantidad_de_colectivos = 0;

    
  

    cColectivo::cColectivo(string id_colectivo, bool estado_operativo, cFecha fecha_ultimo_mantenimiento, cColectivero colectivero, cSistemaDePagos sistema_de_pagos, cRecorrido recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros) : id_colectivo(id_colectivo), cantidad_max_pasajeros(cantidad_max_pasajeros) {
        this->estado_operativo = estado_operativo;
        this->fecha_ultimo_mantenimiento = fecha_ultimo_mantenimiento;
        //this->colectivero = colectivero;
        this->sistema_de_pagos = sistema_de_pagos;
        this->recorrido = recorrido;
        this->pos_del_recorrido = pos_del_recorrido;
        this->GPS = GPS;
        this->sentido = sentido;
    }

    string cColectivo::get_id_colectivo() {
        return "";
    }

    bool cColectivo::get_estado_operativo() {
        return false;
    }

    cRecorrido cColectivo::get_recorrido() {
        return NULL;
    }

    cSistemaDePagos cColectivo::get_sistema_de_pagos() {
        return NULL;
    }


    string cColectivo::get_GPS() {
        return "";
    }

    unsigned int cColectivo::get_posicion_recorrido() {
        return null;
    }

    void cColectivo::set_nuevo_recorrido(cRecorrido * nuevo_recorrido) {
        return;
    }

    void cColectivo::set_colectivero(cColectivero * colectivero) {
        return;
    }

    void cColectivo::set_fecha_mantenimiento(cFecha * fecha) {
        return;
    }

    bool cColectivo::control_sentido_pasajero(cPasajeros * pasajero) {
        return false;
    }

    void cColectivo::avanzar_recorrido() {
        return;
    }


    bool cColectivo::bajar_pasajeros() {
        return false;
    }


    bool cColectivo::subir_pasajeros(cPasajeros * nuevo_pasajero) {
        return false;
    }

    void cColectivo::cobrar_boleto(cPasajeros * nuevo_pasajero) {
        return;
    }

    void cColectivo::cambio_de_sentido_recorrido() {
        return;
    }

    void cColectivo::actualizar_GPS() {
        return;
    }
}
