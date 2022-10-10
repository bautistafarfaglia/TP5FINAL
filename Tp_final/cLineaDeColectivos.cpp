#include "cLineaDeColectivos.h"


cLineaDeColectivos::cLineaDeColectivos() {
    this->IDLineaDeColectivos = "None";
    this->NombreDeLinea = "None";
}

cLineaDeColectivos::cLineaDeColectivos(string IDColectivo,string NombreLinea) {
    this->IDLineaDeColectivos = IDColectivo; 
    this->NombreDeLinea = NombreLinea; 
    //faltan las listas
}

void cLineaDeColectivos::TICK() {
    return;
}


string cLineaDeColectivos::ToStringLineaDeColectivos() {
    stringstream ss;
    for (int i = 0; i < this->listaColectivos.size()  ; i++) {
        ss << this->listaColectivos[i]->to_string_colectivo();
    }
    return ss.str();
}



void cLineaDeColectivos::Imprimir() {
    return;
}
