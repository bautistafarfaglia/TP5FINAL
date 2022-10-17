#include "cColectivo.h"

unsigned long cColectivo::cantidad_de_colectivos = 0;

    
  
    cColectivo::cColectivo(string id_colectivo, cColectivero* colectivero, cSistemaDePagos* sistema_de_pagos, cRecorrido* _recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros, int num_colectivo) : id_colectivo(id_colectivo), cantidad_max_pasajeros(cantidad_max_pasajeros) {
this->estado_operativo = true;
this->fecha_ultimo_mantenimiento = new cFecha(0, 0);
this->colectivero = colectivero;
this->sistema_de_pagos = sistema_de_pagos;
this->recorrido = _recorrido;
this->pos_del_recorrido = -1;
this->GPS = GPS;
this->sentido = sentido;
this->numColectivo = num_colectivo;
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
        for (unsigned int i = 0; i < this->pos_del_recorrido;i++) {
            if (this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_nombre_parada() == _pasajero->get_destino()) {
                cout << "El pasajero tiene que ir en otro sentido" << endl;
                return false;
            }
        }
        return true;
    }

    void cColectivo::avanzar_recorrido() {
        if (this->sentido == eSentidoRecorrido::Arriba) {
            this->pos_del_recorrido++;
        }
        if (this->sentido == eSentidoRecorrido::Abajo) {
            this->pos_del_recorrido--;
        }

        cout << (this->recorrido->get_lista_paradas())[this->pos_del_recorrido]->get_nombre_parada() << endl;

        this->bajar_pasajeros(this->recorrido->get_lista_paradas()[this->pos_del_recorrido]->get_nombre_parada());
        int cant_en_parada = this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_lista_pasajeros().size();
        for (unsigned int PosPasajerosParada = 0; PosPasajerosParada < cant_en_parada; PosPasajerosParada++) {
            if (this->cantidad_actual_pasajeros < this->cantidad_max_pasajeros) {
                cPasajeros* aux = this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_lista_pasajeros()[PosPasajerosParada];
               if (true == this->control_sentido_pasajero(aux)) {
                   cParada* auxp = this->recorrido->get_lista_paradas()[pos_del_recorrido];
                   if (aux->get_hay_una_discapacidad() == true) {
                       if (aux != NULL) {
                           cout << "Se sube alguien con discapacidad" << endl;
                           subir_pasajeros(this->recorrido->get_lista_paradas()[PosPasajerosParada]->pasajeros_suben_colectivo(this->numColectivo));
                       }
                   }
                   else {
                       if (aux != NULL) {
                           cout << "Se suben pasajeros" << endl;
                               subir_pasajeros(this->recorrido->get_lista_paradas()[PosPasajerosParada]->pasajeros_suben_colectivo(this->numColectivo));
                       }
                   }
               }
            }
        }
        this->bajar_pasajeros(this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_nombre_parada());
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
        
    
   


    bool cColectivo::bajar_pasajeros(string nombreParada) {
        int cant = 0;
        for (int i = 0; i < this->cantidad_actual_pasajeros; i++) {
            if (this->listaPasajeros[i]->get_destino() == nombreParada) {
                cout << "Se baja un pasajero" << endl;
                this->listaPasajeros.erase(listaPasajeros.begin() + i);
                this->cantidad_actual_pasajeros--;
                cant++;
            }

        }
        if (cant > 0) {
            return true;
        }
        return false;

    }


    bool cColectivo::subir_pasajeros(vector<cPasajeros*> nuevos_pasajeros) {
        int dif = (this->cantidad_max_pasajeros) - (this->cantidad_actual_pasajeros);
        if (nuevos_pasajeros.size() < dif) {
            for (int i = 0; i< nuevos_pasajeros.size();i++) {
                this->cobrar_boleto(nuevos_pasajeros[i]);
                this->listaPasajeros.push_back(nuevos_pasajeros[i]);
                this->cantidad_actual_pasajeros++;
            }
            return true;
        }else if(dif > 0) {
            for (int i = 0; i < dif; i++) {
                this->cobrar_boleto(nuevos_pasajeros[i]);
                this->listaPasajeros.push_back(nuevos_pasajeros[i]);
                this->cantidad_actual_pasajeros++;
            }
            cout << "Solo entran algunos pasajeros" << endl;
            return true;
        }
        else {
            cout << "Esta muy lleno el bondi" << endl;
            return false;
        }
    }

    void cColectivo::cobrar_boleto(cPasajeros * nuevo_pasajero) {
        //calcular la cantidad de paradas con 2 strings
        this->sistema_de_pagos->generar_viaje(this->recorrido->get_lista_paradas()[this->pos_del_recorrido]->get_nombre_parada(), nuevo_pasajero->get_destino(), 3, nuevo_pasajero->get_tarjeta_pasajero());
    }

    void cColectivo::cambio_de_sentido_recorrido() {
        if (this->sentido == Arriba) {
            this->sentido = Abajo;
        }
        else {
            this->sentido = Arriba;
        }
    }

    void cColectivo::actualizar_GPS() {
        cout<<this->get_GPS()<<endl;
    }

