#include "cColectivo.h"

unsigned long cColectivo::cantidad_de_colectivos_en_circulacion = 0;
short int cColectivo::max_id = 0;

cColectivo::cColectivo(string GPS, short int cantidad_max_pasajeros, int num_colectivo) : id_colectivo(++max_id) {
    this->estado_operativo = true;
    this->fecha_ultimo_mantenimiento = new cFecha(0, 0);
    this->colectivero = NULL;
    this->sistema_de_pagos = new cSistemaDePagos();
    this->recorrido = NULL;
    this->pos_del_recorrido = NULL;
    this->sentido = DEFAULT;
    this->GPS = "estacion";
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

    eSentidoRecorrido cColectivo::get_sentido() {
        return this->sentido;
    }

    cSistemaDePagos cColectivo::get_sistema_de_pagos() {
        return *(this->sistema_de_pagos);
    }

    void cColectivo::set_recorrido(cRecorrido* r)
    {
        this->recorrido = r;
        this->set_sentido(r->get_lista_paradas()[1]->get_sentido_parada());
        if (this->get_sentido() == Abajo) { this->pos_del_recorrido = 10; }
        else if (this->get_sentido() == Arriba) this->pos_del_recorrido = -1;
    }

    void cColectivo::set_sentido(eSentidoRecorrido sentido) 
    {
        this->sentido = sentido; 
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
        this->colectivero->setTrabajando(true);
    }

    void cColectivo::set_fecha_mantenimiento(cFecha* _fecha) {
        this->fecha_ultimo_mantenimiento = _fecha;
    }

    bool cColectivo::control_sentido_pasajero(cPasajeros* _pasajero) {
        for (int i = 0; i < this->pos_del_recorrido;i++) {
            if (this->recorrido->get_lista_paradas()[i]->get_nombre_parada() == _pasajero->get_destino()->get_nombre_parada()) {
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

            if (this->recorrido->get_lista_paradas()[pos_del_recorrido] == this->recorrido->get_lista_paradas()[i])  //chequear operator y fijarse que pasa si el colectivo va en el otro sentido
            {
                flag = true;
            }

            if (flag == true) cont++;

            if (this->recorrido->get_lista_paradas()[i] == pasajero->get_destino()) 
            {
                return cont;
            }
        }
       }

    unsigned long int cColectivo::getcantidad_de_colectivos_en_circulacion()
    {
        return cantidad_de_colectivos_en_circulacion;
    }

    /// <summary>
    /// Esta funcion hace avanzar el colectivo a la siguiente parada. 
    /// Tambien suben pasajeros si: 
    /// - Hay capacidad en el micro
    /// - Si es el sentido del pasajero 
    /// - Si el mismo tiene un destino por el cual el colectivo vaya a recorrer y si ya paso,
    /// </summary>
    /// <returns>Devuelve falso si no puede avanzar mas en el recorrido, en caso contrario devuelve true</returns>
    bool cColectivo::avanzar_recorrido(vector<cPasajeros*>* Pasajeros_que_se_bajan) {
        try {
            if (this->sentido == Arriba && abs(pos_del_recorrido) + 1 == this->recorrido->get_cantidad_paradas()) { //llego al final del recorrido entonces se le asignaría otro recorrido
                return false;
            }
            else if (this->sentido == Abajo && abs(pos_del_recorrido) == 0) { //llego al final del recorrido entonces se le asignaría otro recorrido
                return false;
            }
            if (this->sentido == eSentidoRecorrido::Arriba) {
                this->pos_del_recorrido++;
            }
            if (this->sentido == eSentidoRecorrido::Abajo) {
                this->pos_del_recorrido--;
            }
            this->actualizar_GPS();
            cout << (this->recorrido->get_lista_paradas())[this->pos_del_recorrido]->get_nombre_parada() << endl;

            this->bajar_pasajeros(this->recorrido->get_lista_paradas()[this->pos_del_recorrido]->get_nombre_parada(), Pasajeros_que_se_bajan);
            int cant_en_parada = (int)this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_lista_pasajeros().size();
            cParada* auxp = this->recorrido->get_lista_paradas()[pos_del_recorrido];
            if (auxp != NULL) {
                for (int i = 0; i < cant_en_parada; i++) {
                    if (this->cantidad_actual_pasajeros < this->cantidad_max_pasajeros) {
                        cPasajeros* aux = this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_lista_pasajeros()[i];

                        if (true == this->control_sentido_pasajero(aux) && true == hay_destino(aux) && this->colectivero->AleatorioAbrirPuertas() == true) {//chequeo que el sentido del pasajero sea adecuado y si su destino futuro esta dentro del recorrido

                            if (aux->get_hay_una_discapacidad() == true) {
                                cout << "Se sube alguien con discapacidad ";
                                subir_pasajeros(this->recorrido->get_lista_paradas()[this->pos_del_recorrido]->pasajeros_suben_colectivo(this->numColectivo));
                                return true;
                            }
                            else {
                                cout << "Se suben pasajeros ";
                                subir_pasajeros(this->recorrido->get_lista_paradas()[this->pos_del_recorrido]->pasajeros_suben_colectivo(this->numColectivo));
                                return true;
                            }
                        }
                    }
                }
                if (cant_en_parada == 0) {
                    cout << "No había nadie en la parada" << endl;
                    return true;
                }
            }
        }catch (exception &e) {
            cout << "Error 06: " << e.what() << endl;
            return false;
    }
        //this->bajar_pasajeros(this->recorrido->get_lista_paradas()[pos_del_recorrido]->get_nombre_parada());
       
    }
        
    
    bool cColectivo::hay_destino(cPasajeros* p) {
        if (p->get_destino()->get_sentido_parada() == Arriba) {
            for (int i = pos_del_recorrido + 1; i < this->recorrido->getcantParadas(); i++) {
                string paradaact = this->recorrido->get_lista_paradas()[i]->get_nombre_parada();
                string paradads = p->get_destino()->get_nombre_parada();
                if (p->get_destino()->get_nombre_parada() == this->recorrido->get_lista_paradas()[i]->get_nombre_parada()) {
                    return true;
                }
            }
        }
        else {
            for (int i = this->recorrido->getcantParadas(); i > -1; i--) {
                string paradaact = this->recorrido->get_lista_paradas()[i]->get_nombre_parada();
                string paradads = p->get_destino()->get_nombre_parada();
                if (p->get_destino()->get_nombre_parada() == this->recorrido->get_lista_paradas()[i]->get_nombre_parada()) {
                    return true;
                }
            }
        }
        
        
        return false; //en caso de no encontrar que el 
    }


    bool cColectivo::bajar_pasajeros(string nombreParada, vector<cPasajeros*>* Pasajeros_que_se_bajan) {
        int cant = 0; 
        int cantEstatica = this->listaPasajeros.size();
        for (int i = 0; i < cantEstatica ; i++) {
            if (this->listaPasajeros[i]->get_destino()->get_nombre_parada() == nombreParada) {
                cout << "Se baja un pasajero" << endl;
                Pasajeros_que_se_bajan->push_back(this->listaPasajeros[i]);


                //nuevo_destino();
                this->listaPasajeros.erase(this->listaPasajeros.begin() + i);
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
        int dif = (this->cantidad_max_pasajeros) - (this->listaPasajeros.size());
        int cantSubidos = 0;
        try {
            if (nuevos_pasajeros.size() > 0) {
                if (nuevos_pasajeros.size() < dif) {
                    for (int i = 0; i < nuevos_pasajeros.size(); i++) {
                        this->cobrar_boleto(nuevos_pasajeros[i]);
                        this->listaPasajeros.push_back(nuevos_pasajeros[i]);
                        this->cantidad_actual_pasajeros++;
                        cantSubidos++;
                        nuevos_pasajeros.at(i)->set_prioridad(false);
                    }

                    cout << "Se subieron :" << cantSubidos << endl;
                    return true;
                }
                else if (dif > 0) {
                    for (int i = 0; i < dif; i++) {
                        this->cobrar_boleto(nuevos_pasajeros[i]);
                        this->listaPasajeros.push_back(nuevos_pasajeros[i]);
                        this->cantidad_actual_pasajeros++;
                        nuevos_pasajeros.at(i)->set_prioridad(false);
                        cantSubidos++;
                    }

                    cout << "Solo se subieron :" << cantSubidos << endl;
                    cout << "Solo entran algunos pasajeros" << endl;
                    return true;
                }
                else {
                    cout << "Esta muy lleno el bondi" << endl;
                    return false;
                }
            }
            else {
                throw "ERROR 04: error con la subida de algun pasajero chequear";
            }
        } catch (const char* msg) {
            cout << msg << endl;
        }
    }

    void cColectivo::cobrar_boleto(cPasajeros* nuevo_pasajero) {
        //calcular la cantidad de paradas con 2 strings
        this->sistema_de_pagos->cobrar_boleto(nuevo_pasajero->getSaldo(), calcular_distancia(nuevo_pasajero));
        this->sistema_de_pagos->sumar_boleto(calcular_distancia(nuevo_pasajero));
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