#include "cColectivero.h"
#include "cPasajeros.h"
#include "cColectivoAcordeon.h"
#include "cLineaDeColectivos.h"
#include "cRecorrido.h"
#include "cSistemaDePagos.h"

//ver el tema de uso de la clase viaje
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

	cColectivoAcordeon* cole = new cColectivoAcordeon("194",andrew,sistem,journey,0,"caba",Arriba,10,45);
	cole->avanzar_recorrido();
	
	cole->avanzar_recorrido();
}