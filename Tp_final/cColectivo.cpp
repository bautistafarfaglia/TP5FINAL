#include "cColectivo.h"

unsigned long cColectivo::cantidad_de_colectivos = 0;

    
  
    cColectivo::cColectivo(string id_colectivo, cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* _recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros) : id_colectivo(id_colectivo), cantidad_max_pasajeros(cantidad_max_pasajeros) {
this->estado_operativo = true;
this->fecha_ultimo_mantenimiento = new cFecha(0, 0);
this->colectivero = colectivero;
this->sistema_de_pagos = sistema_de_pagos;
this->recorrido = _recorrido;
this->pos_del_recorrido = pos_del_recorrido;
this->GPS = GPS;
this->sentido = sentido;
    }

    string cColectivo::get_id_colectivo() {
        return this->id_colectivo;
    }

    bool cColectivo::get_estado_operativo() {
        return this->estado_operativo;
    }

    cRecorrido cColectivo::get_recorrido() {
        return *(this->recorrido);
    }

    cSistemaDePagos cColectivo::get_sistema_de_pagos() {
        return *(this->sistema_de_pagos);
    }


    string cColectivo::get_GPS() {
        return this->GPS;
    }

    void cColectivo::llegarParada()
    {
        return;
    }

    unsigned int cColectivo::get_posicion_recorrido() {
        return this->pos_del_recorrido;
    }

    void cColectivo::set_nuevo_recorrido(cRecorrido* nuevo_recorrido) {
        this->recorrido = nuevo_recorrido;
    }

    void cColectivo::set_colectivero(cColectivero* _colectivero) {
        this->colectivero = _colectivero;
    }

    void cColectivo::set_fecha_mantenimiento(cFecha* _fecha) {
        this->fecha_ultimo_mantenimiento = _fecha;
    }

    bool cColectivo::control_sentido_pasajero(cPasajeros* _pasajero) {
        return false;
    }

    void cColectivo::avanzar_recorrido() {
        if (this->sentido == eSentidoRecorrido::Arriba) {
            this->pos_del_recorrido++;
        }
        if (this->sentido == eSentidoRecorrido::Abajo) {
            this->pos_del_recorrido--;
        }

        cout << (this->recorrido->get_lista_paradas())[this->pos_del_recorrido]->get_nombre_parada() << endl;

        this->bajar_pasajeros((*this->recorrido->get_lista_paradas())[this->pos_del_recorrido]->get_nombre_parada());

        for (unsigned int PosPasajerosParada = 0; PosPasajerosParada < this->cantidad_actual_pasajeros; PosPasajerosParada++) {
            if (this->cantidad_actual_pasajeros < this->cantidad_max_pasajeros) {
                if (this->listaPasajeros[PosPasajerosParada]->get_hay_una_discapacidad() == true) {
                    if (true == this->control_sentido_pasajero(this->listaPasajeros()[pos_del_recorrido]->get_destino())) {
                        cParada* aux = this->recorrido->get_lista_paradas()[pos_del_recorrido];

                        if (aux != NULL) {
                            subir_pasajeros(this->recorrido->get_lista_paradas()[PosPasajerosParada]->pasajeros_suben_colectivos());
                        }
                    }
                }
            }
        }/* codigo sin terminar y revisar
        for (unsigned int PosPasajerosParada = 0; PosPasajerosParada < (*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->GetCantidadActual(); PosPasajerosParada++) {
            if (ListaPasajeros->GetCantidadActual() < ListaPasajeros->GetCantidadMaxima()) {
                if ((*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada]->GetSillaDeRuedas() == false) {
                    if (true == ControlSentidoPasajero((*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada])) {
                        cPasajero* PasajeroAux = ((*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros()->Quitar(
                            (*(*Recorrido->GetListaParadas())[PosDelRecorrido]->GetListaPasajeros())[PosPasajerosParada]
                        ));
                        if (PasajeroAux != NULL) {
                            SubirPasajeros(PasajeroAux);
                        }
                    }
                }
            }*/
        }
    }


    bool cColectivo::bajar_pasajeros() {
        for (int i = 0; i < this->cantidad_actual_pasajeros; i++) {
            if (this->listaPasajeros[i]->get_destino() == this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_nombre_parada()){
                this->listaPasajeros.erase(listaPasajeros.begin() + i);
            }
                
        }

    }


    bool cColectivo::subir_pasajeros(vector<cPasajeros*> nuevos_pasajeros) {
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

