#include "cRecorrido.h"

cRecorrido::cRecorrido() {

}

cRecorrido::cRecorrido(string id_recorrido) : codigo_recorrido(codigo_recorrido) {
}

string cRecorrido::get_codigo_recorrido() {
    return this->codigo_recorrido;
}

vector<cParada*> cRecorrido::get_lista_paradas() {
    return (this->listaParada);
}

unsigned int cRecorrido::get_cantidad_paradas() {
    return unsigned int(this->listaParada.size());
}


int cRecorrido::cantidad_de_paradas_entre_destinos(string parada_destino, string parada_salida) {
    return 0;
}


void cRecorrido::agregar_paradas_recorrido(cParada* parada) {
    this->listaParada.push_back(parada);
}

string cRecorrido::to_string_recorrido() {
    this->imprimir();
    return "impreso";
}
void cRecorrido::imprimir() {
    cout << this->listaParada.data();
}
