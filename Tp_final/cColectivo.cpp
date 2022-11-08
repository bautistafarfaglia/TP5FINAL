#include "cColectivo.h"

unsigned long cColectivo::cantidad_de_colectivos_en_circulacion = 0;
short int cColectivo::max_id = 0;

cColectivo::cColectivo(cColectivero* colectivero,
    cSistemaDePagos* sistema_de_pagos, cRecorrido* _recorrido, unsigned int pos_del_recorrido,
    string GPS, eSentidoRecorrido sentido, short int cantidad_max_pasajeros, int num_colectivo) : id_colectivo(++max_id) {
    this->estado_operativo = true;
    this->fecha_ultimo_mantenimiento = new cFecha(0, 0);
    this->colectivero = colectivero;
    this->sistema_de_pagos = sistema_de_pagos;
    this->recorrido = _recorrido;
    this->pos_del_recorrido = -1;
    this->GPS = GPS;
    this->sentido = sentido;
    this->numColectivo = num_colectivo;
    this->cantidad_max_pasajeros = cantidad_max_pasajeros;
    }

    short int cColectivo::get_id_colectivo() {
        return this->id_colectivo;
    }

    bool cColectivo::get_estado_operativo() {
        return this->estado_operativo;
    }

    cRecorrido* cColectivo::get_recorrido() {
        return this->recorrido;
    }

    cSistemaDePagos cColectivo::get_sistema_de_pagos() {
        return *(this->sistema_de_pagos);
    }

    void cColectivo::set_recorrido(cRecorrido* r)
    {
        this->recorrido = r;
    }

    void cColectivo::set_sistema_de_pagos(cSistemaDePagos* sdp)
    {
        this->sistema_de_pagos = sdp;
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
        for (int i = 0; i < this->pos_del_recorrido;i++) {
            if (this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_nombre_parada() == _pasajero->get_destino()->get_nombre_parada()) {
                cout << "El pasajero tiene que ir en otro sentido" << endl;
                return false;
            }
        }
        return true;
    }

    int cColectivo::calcular_distancia(cPasajeros* pasajero) {
        int cont = 0;
        bool flag = false;
        for (unsigned int i = 0; i < this->get_recorrido()->get_cantidad_paradas(); i++)
        {

            if (this->recorrido->get_lista_paradas()[pos_del_recorrido] == this->recorrido->get_lista_paradas()[i])  //chequear operator
            {
                flag = true;
            }

            if (flag == true) cont++;

            if (this->recorrido->get_lista_paradas()[i] == pasajero->get_destino()) 
            {
                return cont;
            }
            
            // if (cont==0) chequear el handle de la exception, porque o no esta en el recorrido, o es la misma parada
        }
       }

    void cColectivo::avanzar_recorrido() {
        if (this->sentido == eSentidoRecorrido::Arriba) {
            this->pos_del_recorrido++;
        }
        if (this->sentido == eSentidoRecorrido::Abajo) {
            this->pos_del_recorrido--;
        }
        this->actualizar_GPS();
        cout << (this->recorrido->get_lista_paradas())[this->pos_del_recorrido]->get_nombre_parada() << endl;

        this->bajar_pasajeros(this->recorrido->get_lista_paradas()[this->pos_del_recorrido]->get_nombre_parada());
        int cant_en_parada = (int) this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_lista_pasajeros().size();
        for (int i = 0; i < cant_en_parada; i++) {
            if (this->cantidad_actual_pasajeros < this->cantidad_max_pasajeros) {
                cPasajeros* aux = this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_lista_pasajeros()[i];
                
                if (true == this->control_sentido_pasajero(aux)&&true==hay_destino(aux)){//chequeo que el sentido del pasajero sea adecuado y si su destino futuro esta dentro del recorrido
                   cParada* auxp = this->recorrido->get_lista_paradas()[pos_del_recorrido];
                   if (aux->get_hay_una_discapacidad() == true) {
                       if (auxp != NULL) {
                           cout << "Se sube alguien con discapacidad" << endl;
                           subir_pasajeros(this->recorrido->get_lista_paradas()[i]->pasajeros_suben_colectivo(this->numColectivo));
                       }
                   }
                   else {
                       if (auxp != NULL) {
                           cout << "Se suben pasajeros" << endl;
                               subir_pasajeros(this->recorrido->get_lista_paradas()[i]->pasajeros_suben_colectivo(this->numColectivo));//chequear que explota cuando no se ponen las paradas en la cual se baja el pasajero
                       }
                   }
               }
            }
        }
        //this->bajar_pasajeros(this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_nombre_parada());
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
        
    
    bool cColectivo::hay_destino(cPasajeros* p) {
        for (int i = 0; pos_del_recorrido+i < this->recorrido->getcantParadas(); i++) {
            if (p->get_destino()->get_nombre_parada() == this->recorrido->get_lista_paradas()[this->pos_del_recorrido + i]->get_nombre_parada()) {
                return true;
            }
        }
        return false; //en caso de no encontrar que el 
    }


    bool cColectivo::bajar_pasajeros(string nombreParada) {
        int cant = 0;
        for (int i = 0; i < this->cantidad_actual_pasajeros; i++) {
            if (this->listaPasajeros[i]->get_destino()->get_nombre_parada() == nombreParada) {
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


    bool cColectivo::subir_pasajeros(vector<cPasajeros*> nuevos_pasajeros) { //chequear si podemos acceder sin parametros a la listapasajeros de la parada
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

    void cColectivo::cobrar_boleto(cPasajeros* nuevo_pasajero) {
        //calcular la cantidad de paradas con 2 strings
        this->sistema_de_pagos->cobrar_voleto(nuevo_pasajero->getSaldo(), calcular_distancia(nuevo_pasajero));
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
        this->GPS = this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_nombre_parada();
    }

    istream& operator>>(istream& is, cColectivo& cole)
    {
        int pos = 0;
        bool estado = false;
        cout << "Ingrese los datos del colectivo:" << endl;
        cout << "Numero:" << endl;
        is >> cole.numColectivo; 
        cout << "Cantidad maxima pasajeros:" << endl;
        is >> cole.cantidad_max_pasajeros;
        cout << "Estado operativo: 1 = Operando, 2 = Fuera de servicio" << endl;
        is >> pos;
        if (pos == 1) {
            estado = true;
        }
        else if (pos == 2) {
            estado = false;
        }
        cole.estado_operativo = estado;
        cout << "GPS:" << endl;
        is >> cole.GPS;
        cout << "Establecer sentido: Arriba = 0, Abajo = 1" << endl;
        int val = -1;
        is >> val;
        if (val == 0) {
            cole.sentido = Arriba;
        }
        else if (val == 1) {
            cole.sentido = Abajo;
        }
        return is;
    }
    //istream& operator>>(istream& is,cColectivo& cole)
    //{
    //    int pos = 0;
    //    int num_cole=0;
    //    string gps= "ga";
    //    bool estado = false;
    //    short int cantidad_max_pasajeros = 0;
    //    eSentidoRecorrido sent = DEFAULT;
    //    cout << "Ingrese los datos del colectivero:" << endl;
    //    cout << "Numero:" << endl;
    //    is >> num_cole;
    //    cout << "Cantidad maxima pasajeros:" << endl;
    //    is >> cantidad_max_pasajeros;
    //    cout << "Estado operativo:" << endl;
    //    is >> estado;
    //    cout << "GPS:" << endl;
    //    is >> gps;
    //    cout << "Establecer sentido: Arriba = 1, Abajo = 2" << endl;
    //    int val = -1;
    //    is >> val;
    //    if (val == 0) {
    //        sent = Arriba;
    //    }
    //    else if (val == 1) {
    //        sent = Abajo;
    //    }
    //    cColectivero* vero = nullptr;
    //    cSistemaDePagos* pagos = nullptr;
    //    cRecorrido* recorrido = nullptr;
    //   // cole = new cColectivo(vero, pagos, recorrido, pos, gps, sent, cantidad_max_pasajeros, num_cole);
    //    return is;
    //}