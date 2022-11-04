#include "cColectivero.h"
#include "cPasajeros.h"
#include "cColectivoAcordeon.h"
#include "cColectivoSinAire.h"
#include "cLineaDeColectivos.h"
#include "cRecorrido.h"
#include "cSistemaDePagos.h"

//ver el tema de uso de la clase viaje
//chequear el use de cLineadeColectivos
cColectivoAcordeon* generar_cColectivo_Acordeon();
cColectivoConAireYDireccionElectrica* generar_cColectivo_ConAire_y_DireccionElectrica();
cColectivoSinAire* generar_cColectivo_sinAire();

int main() {
	//cColectivero* andrew = new cColectivero("andre2", "12345678", "45");
	//cSistemaDePagos* sistem = new cSistemaDePagos(0, 0);
	
	//cParada* p1 = new cParada("101", "calle1", Arriba); //chequear de usar el sentido de la parada para filtrar a los pasajeros
	//cParada* p2 = new cParada("102", "calle2", Arriba);
	//cParada* p3 = new cParada("103", "calle3", Arriba);
	//cParada* p4 = new cParada("104", "calle4", Arriba);
	//cParada* p5 = new cParada("105", "calle5", Arriba);
	//cParada* p6 = new cParada("106", "calle6", Arriba);
	//cParada* p7 = new cParada("107", "calle7", Arriba);
	//cParada* p8 = new cParada("108", "calle8", Arriba);
	//cParada* p9 = new cParada("109", "calle9", Arriba);
	//cParada* p10 = new cParada("110", "calle10", Arriba);

	//cParada* p11 = new cParada("111", "calle1", Abajo);
	//cParada* p12 = new cParada("112", "calle2", Abajo);
	//cParada* p13 = new cParada("113", "calle3", Abajo);
	//cParada* p14 = new cParada("114", "calle4", Abajo);
	//cParada* p15 = new cParada("115", "calle5", Abajo);
	//cParada* p16 = new cParada("116", "calle6", Abajo);
	//cParada* p17 = new cParada("117", "calle7", Abajo);
	//cParada* p18 = new cParada("118", "calle8", Abajo);
	//cParada* p19 = new cParada("119", "calle9", Abajo);
	//cParada* p20 = new cParada("120", "calle10", Abajo);

	//cParada* p21 = new cParada("101", "calle1", Arriba); //chequear de usar el sentido de la parada para filtrar a los pasajeros
	//cParada* p22 = new cParada("102", "calle2", Arriba);
	//cParada* p23 = new cParada("103", "calle3", Arriba);
	//cParada* p24 = new cParada("104", "calle4", Arriba);
	//cParada* p25 = new cParada("105", "calle5", Arriba);
	//cParada* p26 = new cParada("106", "calle6", Arriba);
	//cParada* p27 = new cParada("107", "calle7", Arriba);
	//cParada* p28 = new cParada("108", "calle8", Arriba);
	//cParada* p29 = new cParada("109", "calle9", Arriba);
	//cParada* p30 = new cParada("110", "calle10", Arriba);
	// 
	//cParada* p31 = new cParada("111", "calle1", Abajo);
	//cParada* p32 = new cParada("112", "calle2", Abajo);
	//cParada* p33 = new cParada("113", "calle3", Abajo);
	//cParada* p34 = new cParada("114", "calle4", Abajo);
	//cParada* p35 = new cParada("115", "calle5", Abajo);
	//cParada* p36 = new cParada("116", "calle6", Abajo);
	//cParada* p37 = new cParada("117", "calle7", Abajo);
	//cParada* p38 = new cParada("118", "calle8", Abajo);
	//cParada* p39 = new cParada("119", "calle9", Abajo);
	//cParada* p40 = new cParada("120", "calle10", Abajo);


	//cRecorrido* journey = new cRecorrido("1");
	/*p1->agregar_pasajero(uno);
	p1->agregar_pasajero(dos);*/

	//journey->agregar_paradas_recorrido(p1);
	//journey->agregar_paradas_recorrido(p2);
	//cColectivoAcordeon* cole = new cColectivoAcordeon("194", andrew, sistem, journey, 0, "caba", Arriba, 10, 45);

	/* este codigo dejo de ser necesario debido a que la automatizacion de los colectivos ya es efectiva
	
	cPasajeros* uno = new cPasajeros("eick", "43570175", "guatemala", false, 100, 15);
	cPasajeros* dos = new cPasajeros("sam", "44274165", "callao", false, 100, 15);
	*/
	
	//cColectivoAcordeon* cc = generar_cColectivo_Acordeon();
	//seccion de codigo para agregar un pasajero a una parada la cual es utilizada por algun colectivo
	//vector <cParada*> vec = cc->get_recorrido()->get_lista_paradas();
	//vec[0]->agregar_pasajero(uno);
	//vec[0]->agregar_pasajero(dos);

	//cc->avanzar_recorrido();
	//cc->avanzar_recorrido();
	//cc->imprimir();


	cLineaDeColectivos* cl = new cLineaDeColectivos("sancosur");
	cl->generarcColectivo("Acordeon");

	cPasajeros* uno = new cPasajeros("eick", "43570175", "guatemala", false, 100, 15);
	cPasajeros* dos = new cPasajeros("sam", "44274165", "callao", false, 100, 15);
	cl->Imprimir();
	//delete cc;//chequear la eliminacion de datos, no esta bien la 
}


/// <summary>
/// Esta funcion debe ir al simulador permite generar un colectivo acordeon con los parametros que el usuario desee
/// </summary>
/// <returns>cColectivoAcordeon</returns>
cColectivoAcordeon* generar_cColectivo_Acordeon(){
    cColectivoAcordeon* cole = new cColectivoAcordeon();
    cin >> *cole;
    cColectivero* vero = new cColectivero();
    cSistemaDePagos* pagos = new cSistemaDePagos();
    cRecorrido* recorrido = new cRecorrido();
	vector<cParada*> lista;
	
    cin >> *vero; //personalizo el colectivero
    cin >> *recorrido;//personalizo el recorrido, tambien se podr�a realizar una busqueda por id en una funcion estatica y esta devolver�a el puntero del objeto, preguntar pampa
	
	cole->set_colectivero(vero); 
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(recorrido);

    return cole;
}

cColectivoConAireYDireccionElectrica* generar_cColectivo_ConAire_y_DireccionElectrica() {
	cColectivoConAireYDireccionElectrica* cole = new cColectivoConAireYDireccionElectrica();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	cRecorrido* recorrido = new cRecorrido();
	vector<cParada*> lista;

	cin >> *vero; //personalizo el colectivero
	cin >> *recorrido;//personalizo el recorrido, tambien se podr�a realizar una busqueda por id en una funcion estatica y esta devolver�a el puntero del objeto, preguntar pampa

	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(recorrido);

	return cole;
}

cColectivoSinAire* generar_cColectivo_sinAire() {
	cColectivoSinAire* cole = new cColectivoSinAire();
	cin >> *cole;
	cColectivero* vero = new cColectivero();
	cSistemaDePagos* pagos = new cSistemaDePagos();
	cRecorrido* recorrido = new cRecorrido();
	vector<cParada*> lista;

	cin >> *vero; //personalizo el colectivero
	cin >> *recorrido;//personalizo el recorrido, tambien se podr�a realizar una busqueda por id en una funcion estatica y esta devolver�a el puntero del objeto, preguntar pampa

	cole->set_colectivero(vero);
	cole->set_sistema_de_pagos(pagos);
	cole->set_recorrido(recorrido);

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
