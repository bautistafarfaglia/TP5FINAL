#include "cColectivero.h"
#include "cPasajeros.h"
#include "cColectivoAcordeon.h"
#include "cLineaDeColectivos.h"
#include "cRecorrido.h"
#include "cSistemaDePagos.h"

//ver el tema de uso de la clase viaje
cColectivoAcordeon* generar_cColectivo_Acordeon();
int main() {
	cColectivero* andrew = new cColectivero("andre2", "12345678", "45");
	cSistemaDePagos* sistem = new cSistemaDePagos(0,0);
	cParada* p1 = new cParada("89", "guatemala", Arriba);//chequear de usar el sentido de la parada para filtrar a los pasajeros
	cParada* p2 = new cParada("99", "Av callao", Arriba);
	cRecorrido* journey = new cRecorrido("1"); 
	cPasajeros* uno = new cPasajeros("eick", "43570175", "guatemala", false, 100, 45);
	cPasajeros* dos = new cPasajeros("sam", "44274165", "Av callao", false, 100, 45);
	
	p1->agregar_pasajero(uno);
	p1->agregar_pasajero(dos);

	journey->agregar_paradas_recorrido(p1);
	journey->agregar_paradas_recorrido(p2);

	/*cColectivoAcordeon* cole = new cColectivoAcordeon("194",andrew,sistem,journey,0,"caba",Arriba,10,45);
	cole->avanzar_recorrido();	
	cole->avanzar_recorrido();*/
    generar_cColectivo_Acordeon();
}



cColectivoAcordeon* generar_cColectivo_Acordeon(){
    cColectivoAcordeon* cole = new cColectivoAcordeon();
    cin >> *cole;
    cColectivero* vero = new cColectivero();
    cSistemaDePagos* pagos = new cSistemaDePagos();
    cRecorrido* recorrido = new cRecorrido();
	vector<cParada*> lista;
	
    cin >> *vero;
    cin >> *recorrido;


    return cole;
}

//istream& ingreso_datos(istream& is, cColectivoAcordeon& cole) {
//    int pos = 0;
//    int num_cole = 0;
//    string gps = "ga";
//    bool estado = false;
//    short int cantidad_max_pasajeros = 0;
//    eSentidoRecorrido sent = DEFAULT;
//    cout << "Ingrese los datos del colectivero:" << endl;
//    cout << "Numero:" << endl;
//    is >> num_cole;
//    cout << "Cantidad maxima pasajeros:" << endl;
//    is >> cantidad_max_pasajeros;
//    cout << "Estado operativo: 1 = Operando, 2 = Fuera de servicio" << endl;
//    is >> pos;
//    if (pos == 1) {
//        estado = true;
//    }
//    else if (pos == 2) {
//        estado = false;
//    }
//    pos = 0;
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
//    //cole = new cColectivo(vero, pagos, recorrido, pos, gps, sent, cantidad_max_pasajeros, num_cole);
//    return is;
//}
