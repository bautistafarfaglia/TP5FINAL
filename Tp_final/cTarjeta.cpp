#include "cTarjeta.h"

unsigned int long cTarjeta::cantidad_de_tarjetas_creadas = 0;

cTarjeta::cTarjeta(float _saldo, bool _checkEliminar, unsigned short int _cantTotal) {
    //chequear que es el cant total y para que sirve ???
    this->saldo = _saldo;
    this->cantActual = 0;
    this->checkEliminar = _checkEliminar;
    this->cantTotal = _cantTotal;
    try {
        this->listaViajesRealizados = new cViaje * [_cantTotal];
        for (ushort i = 0; i < this->cantTotal; i++)
            this->listaViajesRealizados[i] = NULL;
    }
    catch (bad_alloc& e) {
        cout << "Error al crear la lista: " << e.what() << endl;
    }
    
}

float cTarjeta::get_tarjeta() {
    return this->saldo;
}

void cTarjeta::agregar_viaje_lista(cViaje* nuevo_viaje) {
    return;
}

float cTarjeta::carga_de_viaje(float saldo_agregar) {
    return 0.0;
}

float cTarjeta::descuento_salto(float cargo) {
    this->saldo -= cargo;
    return cargo;
}

string cTarjeta::to_string_tarjeta() {
    return "";
}

void cTarjeta::imprimir() {
    return;
}

void cTarjeta::agregar(cViaje* viaje) {
        if (this->cantActual == this->cantTotal)
            this->resize();
        this->listaViajesRealizados[++cantActual] = viaje;
}
void cTarjeta::eliminar(cViaje* viaje) {
    int i = 0;
    for (i = 0; i < this->cantActual; i++)
    {
        if (listaViajesRealizados[i] == viaje)
            delete listaViajesRealizados[i];
        break;
    }
    listaViajesRealizados[i] = NULL;
    this->ordenar();
}
cViaje* cTarjeta::quitar(cViaje* viaje) {
    int i = 0;
    for (i = 0; i < this->cantActual; i++)
    {
        if (listaViajesRealizados[i] == viaje)
        break;
    }
    cViaje * viajeAux = listaViajesRealizados[i];
    delete listaViajesRealizados[i];
    listaViajesRealizados[i] = NULL;
    this->ordenar();
    return viajeAux;
}

void cTarjeta::operator+(cViaje* viaje) { this->agregar(viaje); }
cViaje* cTarjeta::operator-(cViaje* viaje) { cViaje* viajeAux = NULL;  viajeAux = quitar(viaje); return viajeAux; }
cViaje* cTarjeta::operator[](short i) {
    try {
        if (i >= 0 && i < this->cantActual)
            return this->listaViajesRealizados[i];
        throw out_of_range("Error: Se esta intentando acceder a un elemento imposible de acceder");
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}
//void cTarjeta::operator++() {}


void cTarjeta::resize() {
    try
    {
        this->cantTotal = this->cantTotal * 2;
        cViaje** listaResize = new cViaje * [this->cantTotal];
        for (int i = cantActual; i < cantTotal; i++)
        {
            listaResize[i] = NULL;
        }
        memcpy(listaResize, this->listaViajesRealizados, this->cantTotal * sizeof(cViaje*));
        delete[] this -> listaViajesRealizados;
        listaViajesRealizados = listaResize;

    }
    catch (const std::exception&)
    {
        cout << e.what() << endl;
    }
 
}
void cTarjeta::ordenar() {
    for (ushort i = 0; i < this->cantActual; i++)
        for (ushort j = i; j < this->cantActual - 1; j++)
            if (!this->listaViajesRealizados[i])
                swap(this->listaViajesRealizados[j], this->listaViajesRealizados[j + 1]);
}