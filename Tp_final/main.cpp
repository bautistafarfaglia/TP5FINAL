#include "cColectivero.h"
#include "cPasajeros.h"
#include "cColectivoAcordeon.h"
#include "cColectivoSinAire.h"
#include "cSistema.h"
#include "cRecorrido.h"
#include "cSistemaDePagos.h"

int main() {

	cSistema* linea = new cSistema("linea");

#pragma region recorridos, paradas, colectivos y personas

	srand(time(0));
	cParada* p1 = new cParada("calle1", Arriba);
	cParada* p2 = new cParada("calle2", Arriba);
	cParada* p3 = new cParada("calle3", Arriba);
	cParada* p4 = new cParada("calle4", Arriba);
	cParada* p5 = new cParada("calle5", Arriba);
	cParada* p6 = new cParada("calle6", Arriba);
	cParada* p7 = new cParada("calle7", Arriba);
	cParada* p8 = new cParada("calle8", Arriba);
	cParada* p9 = new cParada("calle9", Arriba);
	cParada* p10 = new cParada("calle10", Arriba);

	cRecorrido* rec1 = new cRecorrido();
	rec1->agregar_paradas_recorrido(p1);
	rec1->agregar_paradas_recorrido(p2);
	rec1->agregar_paradas_recorrido(p3);
	rec1->agregar_paradas_recorrido(p4);
	rec1->agregar_paradas_recorrido(p5);
	rec1->agregar_paradas_recorrido(p6);
	rec1->agregar_paradas_recorrido(p7);
	rec1->agregar_paradas_recorrido(p8);
	rec1->agregar_paradas_recorrido(p9);
	rec1->agregar_paradas_recorrido(p10);

	cParada* p11 = new cParada("calle1", Abajo);
	cParada* p12 = new cParada("calle2", Abajo);
	cParada* p13 = new cParada("calle3", Abajo);
	cParada* p14 = new cParada("calle4", Abajo);
	cParada* p15 = new cParada("calle5", Abajo);
	cParada* p16 = new cParada("calle6", Abajo);
	cParada* p17 = new cParada("calle7", Abajo);
	cParada* p18 = new cParada("calle8", Abajo);
	cParada* p19 = new cParada("calle9", Abajo);
	cParada* p20 = new cParada("calle10", Abajo);

	cRecorrido* rec2 = new cRecorrido();
	rec2->agregar_paradas_recorrido(p12);
	rec2->agregar_paradas_recorrido(p13);
	rec2->agregar_paradas_recorrido(p14);
	rec2->agregar_paradas_recorrido(p15);
	rec2->agregar_paradas_recorrido(p16);
	rec2->agregar_paradas_recorrido(p17);
	rec2->agregar_paradas_recorrido(p18);
	rec2->agregar_paradas_recorrido(p19);
	rec2->agregar_paradas_recorrido(p20);

	cParada* p21 = new cParada("calle51", Arriba);
	cParada* p22 = new cParada("calle52", Arriba);
	cParada* p23 = new cParada("calle53", Arriba);
	cParada* p24 = new cParada("calle54", Arriba);
	cParada* p25 = new cParada("calle55", Arriba);
	cParada* p26 = new cParada("calle56", Arriba);
	cParada* p27 = new cParada("calle57", Arriba);
	cParada* p28 = new cParada("calle58", Arriba);
	cParada* p29 = new cParada("calle59", Arriba);
	cParada* p30 = new cParada("calle60", Arriba);

	cRecorrido* rec3 = new cRecorrido();
	rec3->agregar_paradas_recorrido(p21);
	rec3->agregar_paradas_recorrido(p22);
	rec3->agregar_paradas_recorrido(p23);
	rec3->agregar_paradas_recorrido(p24);
	rec3->agregar_paradas_recorrido(p25);
	rec3->agregar_paradas_recorrido(p26);
	rec3->agregar_paradas_recorrido(p27);
	rec3->agregar_paradas_recorrido(p28);
	rec3->agregar_paradas_recorrido(p29);
	rec3->agregar_paradas_recorrido(p30);

	cParada* p31 = new cParada("calle51", Abajo);
	cParada* p32 = new cParada("calle52", Abajo);
	cParada* p33 = new cParada("calle53", Abajo);
	cParada* p34 = new cParada("calle54", Abajo);
	cParada* p35 = new cParada("calle55", Abajo);
	cParada* p36 = new cParada("calle56", Abajo);
	cParada* p37 = new cParada("calle57", Abajo);
	cParada* p38 = new cParada("calle58", Abajo);
	cParada* p39 = new cParada("calle59", Abajo);
	cParada* p40 = new cParada("calle60", Abajo);

	cRecorrido* rec4 = new cRecorrido();
	rec4->agregar_paradas_recorrido(p31);
	rec4->agregar_paradas_recorrido(p32);
	rec4->agregar_paradas_recorrido(p33);
	rec4->agregar_paradas_recorrido(p34);
	rec4->agregar_paradas_recorrido(p35);
	rec4->agregar_paradas_recorrido(p36);
	rec4->agregar_paradas_recorrido(p37);
	rec4->agregar_paradas_recorrido(p38);
	rec4->agregar_paradas_recorrido(p39);
	rec4->agregar_paradas_recorrido(p40);

	linea->agregar(rec1);
	linea->agregar(rec2);
	linea->agregar(rec3);
	linea->agregar(rec4);

	cPasajeros* h1 = new cPasajeros("humano1", "10000001", false, 100, 60);
	cPasajeros* h2 = new cPasajeros("humano2", "10000002", false, 100, 60);
	cPasajeros* h3 = new cPasajeros("humano3", "10000003", false, 100, 60);
	cPasajeros* h4 = new cPasajeros("humano4", "10000004", false, 100, 60);
	cPasajeros* h5 = new cPasajeros("humano5", "10000005", false, 100, 60);
	cPasajeros* h6 = new cPasajeros("humano6", "10000006", false, 100, 60);
	cPasajeros* h7 = new cPasajeros("humano7", "10000007", false, 100, 60);
	cPasajeros* h8 = new cPasajeros("humano8", "10000008", false, 100, 60);
	cPasajeros* h9 = new cPasajeros("humano9", "10000009", false, 100, 60);
	cPasajeros* h10 = new cPasajeros("humano10", "10000010", false, 100, 60);
	cPasajeros* h11 = new cPasajeros("humano11", "10000011", false, 100, 60);
	cPasajeros* h12 = new cPasajeros("humano12", "10000012", false, 100, 60);
	cPasajeros* h13 = new cPasajeros("humano13", "10000013", false, 100, 60);
	cPasajeros* h14 = new cPasajeros("humano14", "10000014", false, 100, 60);
	cPasajeros* h15 = new cPasajeros("humano15", "10000015", false, 100, 60);
	cPasajeros* h16 = new cPasajeros("humano16", "10000016", false, 100, 60);
	cPasajeros* h17 = new cPasajeros("humano17", "10000017", false, 100, 60);
	cPasajeros* h18 = new cPasajeros("humano18", "10000018", false, 100, 60);
	cPasajeros* h19 = new cPasajeros("humano19", "10000019", false, 100, 60);
	cPasajeros* h20 = new cPasajeros("humano20", "10000020", false, 100, 60);

	linea->agregar_personas(h1);
	linea->agregar_personas(h2);
	linea->agregar_personas(h3);
	linea->agregar_personas(h4);
	linea->agregar_personas(h5);
	linea->agregar_personas(h6);
	linea->agregar_personas(h7);
	linea->agregar_personas(h8);
	linea->agregar_personas(h9);
	linea->agregar_personas(h10);
	linea->agregar_personas(h11);
	linea->agregar_personas(h12);
	linea->agregar_personas(h13);
	linea->agregar_personas(h14);
	linea->agregar_personas(h15);
	linea->agregar_personas(h16);
	linea->agregar_personas(h17);
	linea->agregar_personas(h18);
	linea->agregar_personas(h19);
	linea->agregar_personas(h20);

	cColectivo* c1 = new cColectivoAcordeon(60);
	cColectivo* c2 = new cColectivoConAireYDireccionElectrica(60);
	cColectivo* c3 = new cColectivoSinAire(60);
	cColectivo* c4 = new cColectivoAcordeon(60);

	linea->generarcColectivo(c1);
	linea->generarcColectivo(c2);
	linea->generarcColectivo(c3);
	linea->generarcColectivo(c4);
	linea->generarcColectivo(NULL);
	

#pragma endregion

#pragma region simulacion

	unsigned long long int time_0;
	unsigned long long int time_1;
	unsigned long long int cantidad_segundos = 0;
	bool ciclo = true; //true para iniciar
	time_0 = clock();
	while (ciclo) {
		time_1 = clock();
		long double diftime = (long double(time_1 - time_0) / CLOCKS_PER_SEC);
		if (diftime >= 2) {
			cout << "\nPasaron: " << diftime << " s" << endl; //esta linea dice cuanto tiempo pasa entre cada vuelta de while

			
			linea->TICK();
			time_0 = clock();
			cantidad_segundos++; 
			if (cantidad_segundos % 5 == 0) {//El contador llega hasta 24 (que serían 24 segs 1 dia)
				cout << linea->get_sistema_de_pagos();
				linea->get_sistema_de_pagos()->resetDia();
			}
			
			//cout<<endl;
		}
		if (cantidad_segundos == 20) //Cantidad de segundos operativos
			ciclo = false;
	}

	
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

#pragma endregion
	system("exit");
}

