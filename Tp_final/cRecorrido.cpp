#include "cRecorrido.h"


cRecorrido::cRecorrido(string id_recorrido) : codigo_recorrido(codigo_recorrido) {
    vector<cParada*> ParadasAux; 
    this->listaParada = ParadasAux;
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

istream& operator>>(istream& is, cRecorrido& re)
{
    int pos = 0;
    bool estado = false;
    cout << "Ingrese los datos del recorrido:" << endl;
    cout << "cantidad de paradas a agregar:" << endl;
    is >> pos; 

    cParada* paradaaux;
    re.get_lista_paradas().resize(pos);//chequear el rezise
    for (int i = 0; i < pos; i++) {
        int cant = re.get_cantidad_paradas() + i;
        paradaaux = new cParada();
        is >> *paradaaux;
        re.get_lista_paradas().push_back(paradaaux); //revisar este codigo, algo estaba mal no me acuerdo
        cout << re.get_lista_paradas().data(); //chequear como que no me toma la direccion de memoria del vector lista y no puedo acceder a ningun dato del mismo, 
    }
    return is;
}