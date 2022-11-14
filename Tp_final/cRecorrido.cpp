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



void cRecorrido::agregar_paradas_recorrido(cParada* parada) {
    try{
        if(parada!=NULL){
            this->listaParada.push_back(parada);
        }else {
            throw exception("No se puede agregar pasajero NULL");
        }
    }catch (const char* msg) {
        cout << "Error 15: " << msg << endl;
    }catch (exception& e) {
        cout << "Error 16: " << e.what() << endl;
    }
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
    try {
        if ((&re) != NULL) {

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
        }else {
            throw exception("No se puede customizar un recorrido NULL");
        }
    }catch (const char* msg) {
    cout << "Error 13: " << msg << endl;
    }
    catch (exception& e) {
        cout << "Error 14: " << e.what() << endl;
    }
}