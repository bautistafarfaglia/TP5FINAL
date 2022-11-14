#include "cRecorrido.h"


cRecorrido::cRecorrido(string id_recorrido) : codigo_recorrido(codigo_recorrido) {
    vector<cParada*> re;
    re.clear();
    this->listaParada=re;
}
cRecorrido::~cRecorrido() {
    for (int i = 0; i < listaParada.size(); i++)
    {
        delete& listaParada[i];
    }
}

string cRecorrido::get_codigo_recorrido() {
    return this->codigo_recorrido;
}

vector<cParada*> cRecorrido::get_lista_paradas() {
    if (this->listaParada.size() == 0) {
        int val = 0;
    }
    return this->listaParada;
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
    stringstream ss;
    
    for (int i = 0; i < this->listaParada.size(); i++) {
        ss << endl;
        ss << this->listaParada[i]->to_string_parada();
        ss << endl;
    }
    return ss.str();
}
void cRecorrido::imprimir() {
    cout << this->to_string_recorrido();
}

int cRecorrido::getcantParadas()
{
    return this->listaParada.size();
}

istream& operator>>(istream& is, cRecorrido& re)
{
    int pos = 0;
    bool estado = false;
    cout << "Ingrese los datos del recorrido:" << endl;
    cout << "cantidad de paradas a agregar:" << endl;
    is >> pos; 
    cParada* paradaaux;
    for (int i = 0; i < pos; i++) {
        int cant = re.get_cantidad_paradas() + i;
        paradaaux = new cParada();
        is >> *paradaaux;
        re.listaParada.push_back(paradaaux); 
    }
    int cal = 0;
    return is;
}