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
	
	cLineaDeColectivos* linea= new cLineaDeColectivos("linea");

	#pragma region recorridos, paradas y personas

	cParada* p1 = new cParada("101", "calle1", Arriba); 
	cParada* p2 = new cParada("102", "calle2", Arriba);
	cParada* p3 = new cParada("103", "calle3", Arriba);
	cParada* p4 = new cParada("104", "calle4", Arriba);
	cParada* p5 = new cParada("105", "calle5", Arriba);
	cParada* p6 = new cParada("106", "calle6", Arriba);
	cParada* p7 = new cParada("107", "calle7", Arriba);
	cParada* p8 = new cParada("108", "calle8", Arriba);
	cParada* p9 = new cParada("109", "calle9", Arriba);
	cParada* p10 = new cParada("110", "calle10", Arriba);

	cRecorrido rec1;
	rec1.agregar_paradas_recorrido(p1);
	rec1.agregar_paradas_recorrido(p2);
	rec1.agregar_paradas_recorrido(p3);
	rec1.agregar_paradas_recorrido(p4);
	rec1.agregar_paradas_recorrido(p5);
	rec1.agregar_paradas_recorrido(p6);
	rec1.agregar_paradas_recorrido(p7);
	rec1.agregar_paradas_recorrido(p8);
	rec1.agregar_paradas_recorrido(p9);
	rec1.agregar_paradas_recorrido(p10);

	cParada* p11 = new cParada("111", "calle1", Abajo);
	cParada* p12 = new cParada("112", "calle2", Abajo);
	cParada* p13 = new cParada("113", "calle3", Abajo);
	cParada* p14 = new cParada("114", "calle4", Abajo);
	cParada* p15 = new cParada("115", "calle5", Abajo);
	cParada* p16 = new cParada("116", "calle6", Abajo);
	cParada* p17 = new cParada("117", "calle7", Abajo);
	cParada* p18 = new cParada("118", "calle8", Abajo);
	cParada* p19 = new cParada("119", "calle9", Abajo);
	cParada* p20 = new cParada("120", "calle10", Abajo);

	cRecorrido rec2;
	rec2.agregar_paradas_recorrido(p11);
	rec2.agregar_paradas_recorrido(p12);
	rec2.agregar_paradas_recorrido(p13);
	rec2.agregar_paradas_recorrido(p14);
	rec2.agregar_paradas_recorrido(p15);
	rec2.agregar_paradas_recorrido(p16);
	rec2.agregar_paradas_recorrido(p17);
	rec2.agregar_paradas_recorrido(p18);
	rec2.agregar_paradas_recorrido(p19);
	rec2.agregar_paradas_recorrido(p20);

	cParada* p21 = new cParada("201", "calle51", Arriba); 
	cParada* p22 = new cParada("202", "calle52", Arriba);
	cParada* p23 = new cParada("203", "calle53", Arriba);
	cParada* p24 = new cParada("204", "calle54", Arriba);
	cParada* p25 = new cParada("205", "calle55", Arriba);
	cParada* p26 = new cParada("206", "calle56", Arriba);
	cParada* p27 = new cParada("207", "calle57", Arriba);
	cParada* p28 = new cParada("208", "calle58", Arriba);
	cParada* p29 = new cParada("209", "calle59", Arriba);
	cParada* p30 = new cParada("210", "calle60", Arriba);
										  
	cRecorrido rec3;
	rec3.agregar_paradas_recorrido(p21);
	rec3.agregar_paradas_recorrido(p22);
	rec3.agregar_paradas_recorrido(p23);
	rec3.agregar_paradas_recorrido(p24);
	rec3.agregar_paradas_recorrido(p25);
	rec3.agregar_paradas_recorrido(p26);
	rec3.agregar_paradas_recorrido(p27);
	rec3.agregar_paradas_recorrido(p28);
	rec3.agregar_paradas_recorrido(p29);
	rec3.agregar_paradas_recorrido(p30);
										  
	cParada* p31 = new cParada("211", "calle51", Abajo);
	cParada* p32 = new cParada("212", "calle52", Abajo);
	cParada* p33 = new cParada("213", "calle53", Abajo);
	cParada* p34 = new cParada("214", "calle54", Abajo);
	cParada* p35 = new cParada("215", "calle55", Abajo);
	cParada* p36 = new cParada("216", "calle56", Abajo);
	cParada* p37 = new cParada("217", "calle57", Abajo);
	cParada* p38 = new cParada("218", "calle58", Abajo);
	cParada* p39 = new cParada("219", "calle59", Abajo);
	cParada* p40 = new cParada("220", "calle60", Abajo);

	cRecorrido rec4;
	rec4.agregar_paradas_recorrido(p31);
	rec4.agregar_paradas_recorrido(p32);
	rec4.agregar_paradas_recorrido(p33);
	rec4.agregar_paradas_recorrido(p34);
	rec4.agregar_paradas_recorrido(p35);
	rec4.agregar_paradas_recorrido(p36);
	rec4.agregar_paradas_recorrido(p37);
	rec4.agregar_paradas_recorrido(p38);
	rec4.agregar_paradas_recorrido(p39);
	rec4.agregar_paradas_recorrido(p40);

	cPasajeros* h1 = new cPasajeros("humano1", "10000001", "", false, 100, NULL); //chequear asignar personas random a las paradas
	cPasajeros* h2 = new cPasajeros("humano2", "10000002", "", false, 100, NULL);
	cPasajeros* h3 = new cPasajeros("humano3", "10000003", "", false, 100, NULL);
	cPasajeros* h4 = new cPasajeros("humano4", "10000004", "", false, 100, NULL);
	cPasajeros* h5 = new cPasajeros("humano5", "10000005", "", false, 100, NULL);
	cPasajeros* h6 = new cPasajeros("humano6", "10000006", "", false, 100, NULL);
	cPasajeros* h7 = new cPasajeros("humano7", "10000007", "", false, 100, NULL);
	cPasajeros* h8 = new cPasajeros("humano8", "10000008", "", false, 100, NULL);
	cPasajeros* h9 = new cPasajeros("humano9", "10000009", "", false, 100, NULL);
	cPasajeros* h10 = new cPasajeros("humano10", "10000010", "", false, 100, NULL);
	cPasajeros* h11 = new cPasajeros("humano11", "10000011", "", false, 100, NULL);
	cPasajeros* h12 = new cPasajeros("humano12", "10000012", "", false, 100, NULL);
	cPasajeros* h13 = new cPasajeros("humano13", "10000013", "", false, 100, NULL);
	cPasajeros* h14 = new cPasajeros("humano14", "10000014", "", false, 100, NULL);
	cPasajeros* h15 = new cPasajeros("humano15", "10000015", "", false, 100, NULL);
	cPasajeros* h16 = new cPasajeros("humano16", "10000016", "", false, 100, NULL);
	cPasajeros* h17 = new cPasajeros("humano17", "10000017", "", false, 100, NULL);
	cPasajeros* h18 = new cPasajeros("humano18", "10000018", "", false, 100, NULL);
	cPasajeros* h19 = new cPasajeros("humano19", "10000019", "", false, 100, NULL);
	cPasajeros* h20 = new cPasajeros("humano20", "10000020", "", false, 100, NULL);

	linea->agregar_peronas(h1);
	linea->agregar_peronas(h2);
	linea->agregar_peronas(h3);
	linea->agregar_peronas(h4);
	linea->agregar_peronas(h5);
	linea->agregar_peronas(h6);
	linea->agregar_peronas(h7);
	linea->agregar_peronas(h8);
	linea->agregar_peronas(h9);
	linea->agregar_peronas(h10);
	linea->agregar_peronas(h11);
	linea->agregar_peronas(h12);
	linea->agregar_peronas(h13);
	linea->agregar_peronas(h14);
	linea->agregar_peronas(h15);
	linea->agregar_peronas(h16);
	linea->agregar_peronas(h17);
	linea->agregar_peronas(h18);
	linea->agregar_peronas(h19);
	linea->agregar_peronas(h20);


	#pragma endregion


	#pragma region simulacion

	unsigned int time_0;
	unsigned int time_1;
	unsigned int cantidad_segundos = 0;
	bool ciclo = true; //true para iniciar
	time_0 = clock();
	while (ciclo) {
		time_1 = clock();
		double diftime = (double(time_1 - time_0) / CLOCKS_PER_SEC);
		if (diftime >= 1) {
			//cout << "\nPasaron: " << diftime << " s" << endl; //esta linea dice cuanto tiempo pasa entre cada vuelta de while
			
			//actualizar todos los colectivos

			time_0 = clock();
			cantidad_segundos++; //sumo al contador hasta que se cumpla la condicion
			if (cantidad_segundos % 5 == 0) {
				//Actualizar GPS
			}
		}
		if (cantidad_segundos == 24) //Cantidad de segundos operativos
			ciclo = false;
	}

    #pragma endregion



	
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
    cin >> *recorrido;//personalizo el recorrido, tambien se podría realizar una busqueda por id en una funcion estatica y esta devolvería el puntero del objeto, preguntar pampa
	
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
	cin >> *recorrido;//personalizo el recorrido, tambien se podría realizar una busqueda por id en una funcion estatica y esta devolvería el puntero del objeto, preguntar pampa

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
	cin >> *recorrido;//personalizo el recorrido, tambien se podría realizar una busqueda por id en una funcion estatica y esta devolvería el puntero del objeto, preguntar pampa

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
























//cColectivero* andrew = new cColectivero("andre2", "12345678", "45");
	//cSistemaDePagos* sistem = new cSistemaDePagos(0, 0);

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
    //cLineaDeColectivos* cl = new cLineaDeColectivos("sancosur");
    //cl->generarcColectivo("Acordeon");
    //
    //cPasajeros* uno = new cPasajeros("eick", "43570175", "guatemala", false, 100, 15);
    //cPasajeros* dos = new cPasajeros("sam", "44274165", "callao", false, 100, 15);
    //cl->Imprimir();
    //delete cc;//chequear la eliminacion de datos, no esta bien la 