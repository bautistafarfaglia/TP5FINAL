#pragma once
#include "Gbl.h"
#include "cSistemaDePagos.h"
#include "cRecorrido.h"
#include "cColectivero.h"

#ifndef _CCOLECTIVO_H
#define _CCOLECTIVO_H

class cColectivo {
public:

    cColectivo(short int cantidad_max_pasajeros, int num_colectivo);
    ~cColectivo() {
        cantidad_de_colectivos_en_circulacion--;
        for (int i = 0; i < listaPasajeros.size(); i++)
        {
            delete& listaPasajeros[i];
        }
        delete this->recorrido;
       /* if (&this->listaPasajeros != NULL)
        delete[] & this->listaPasajeros;*/ //debido a que  porque explota aca

        /*if (this->sistema_de_pagos != NULL)
            delete this->sistema_de_pagos;*///No tenemos que eliminar el sistemas de pago porque es el mismo en toda la linea, para podes clacular la colecta de todos los colectivos
        this->colectivero->setTrabajando(false);
        delete this->fecha_ultimo_mantenimiento;
    }

    short int get_id_colectivo();
    bool get_estado_operativo();
    eSentidoRecorrido get_sentido();
    cRecorrido* get_recorrido();
    cSistemaDePagos get_sistema_de_pagos();
    string get_GPS();
    void llegarParada();
    unsigned int get_posicion_recorrido();
    void set_nuevo_recorrido(cRecorrido* nuevo_recorrido);
    void set_sentido(eSentidoRecorrido sentido);
    void set_colectivero(cColectivero* colectivero);
    void set_fecha_mantenimiento(cFecha* fecha);
    void set_recorrido(cRecorrido* r);
    void set_sistema_de_pagos(cSistemaDePagos* sdp);
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
