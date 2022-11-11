#include "cColectivero.h"
#include "cPasajeros.h"
#include "cColectivoAcordeon.h"
#include "cColectivoSinAire.h"
#include "cLineaDeColectivos.h"
#include "cRecorrido.h"
#include "cSistemaDePagos.h"

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


	cPasajeros* h1 = new cPasajeros("humano1", "10000001", p1, false, 100, NULL);
	cPasajeros* h2 = new cPasajeros("humano2", "10000002", p2, false, 100, NULL);
	cPasajeros* h3 = new cPasajeros("humano3", "10000003", p3, false, 100, NULL);
	cPasajeros* h4 = new cPasajeros("humano4", "10000004", p4, false, 100, NULL);
	cPasajeros* h5 = new cPasajeros("humano5", "10000005", p5, false, 100, NULL);
	cPasajeros* h6 = new cPasajeros("humano6", "10000006", p6, false, 100, NULL);
	cPasajeros* h7 = new cPasajeros("humano7", "10000007", p7, false, 100, NULL);
	cPasajeros* h8 = new cPasajeros("humano8", "10000008", p8, false, 100, NULL);
	cPasajeros* h9 = new cPasajeros("humano9", "10000009", p9, false, 100, NULL);
	cPasajeros* h10 = new cPasajeros("humano10", "10000010", p10, false, 100, NULL);
	cPasajeros* h11 = new cPasajeros("humano11", "10000011", p11, false, 100, NULL);
	cPasajeros* h12 = new cPasajeros("humano12", "10000012", p12, false, 100, NULL);
	cPasajeros* h13 = new cPasajeros("humano13", "10000013", p13, false, 100, NULL);
	cPasajeros* h14 = new cPasajeros("humano14", "10000014", p14, false, 100, NULL);
	cPasajeros* h15 = new cPasajeros("humano15", "10000015", p15, false, 100, NULL);
	cPasajeros* h16 = new cPasajeros("humano16", "10000016", p16, false, 100, NULL);
	cPasajeros* h17 = new cPasajeros("humano17", "10000017", p17, false, 100, NULL);
	cPasajeros* h18 = new cPasajeros("humano18", "10000018", p18, false, 100, NULL);
	cPasajeros* h19 = new cPasajeros("humano19", "10000019", p19, false, 100, NULL);
	cPasajeros* h20 = new cPasajeros("humano20", "10000020", p20, false, 100, NULL);

	linea->agregar_peronas(h1); //chequear de agregar discapacitados y ahi ver si esta primero en la fila de la parada (consigna)
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

	#pragma region colectivos y colectiveros

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
			//linea->TICK()
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

	linea->generarRecorrido();
	linea->generarcColectivo();
	linea->cambiarRecorrido(1);
	linea->AvanzarColectivoRandom();

	//Chequear todos los deletes y porque explota la pc
	
#pragma region deletes de paradas
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
	delete p8;
	delete p9;
	delete p10;
	delete p11;
	delete p12;
	delete p13;
	delete p14;
	delete p15;
	delete p16;
	delete p17;
	delete p18;
	delete p19;
	delete p20;
	delete p21;	
	delete p22;
	delete p23;
	delete p24;
	delete p25;
	delete p26;
	delete p27;
	delete p28;
	delete p29;
	delete p31;
	delete p32;
	delete p33;
	delete p34;
	delete p35;
	delete p36;
	delete p37;
	delete p38;
	delete p39;
	delete p40;
#pragma endregion
	
#pragma region deletes humanos
	delete h1;
	delete h2;
	delete h3;
	delete h4;
	delete h5; 
	delete h6;
	delete h7; 
	delete h8; 
	delete h9; 
	delete h10;
	delete h11;
	delete h12;
	delete h13;
	delete h14;
	delete h15;
	delete h16;
	delete h17;
	delete h18;
	delete h19;
	delete h20;
#pragma endregion
#pragma region deletes lineas de colectivos
	delete linea;
#pragma endregion
}

