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
    return "";
}


void cLineaDeColectivos::Imprimir() {
    return;
}
