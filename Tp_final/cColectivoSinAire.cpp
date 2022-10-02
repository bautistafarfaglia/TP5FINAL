
#include "cColectivoSinAire.h"




 cColectivoSinAire::cColectivoSinAire(string id_Colectivo,bool estado_operativo, cFecha fecha_ultimo_mantenimiento, cColectivero colectivero, cSistemaDePagos sistema_de_pagos, cRecorrido recorrido, unsigned int pos_del_recorrido, string GPS, eSentidoRecorrido sentido, const short int cantidad_max_pasajeros):cColectivo(id_Colectivo,estado_operativo,fecha_ultimo_mantenimiento,colectivero,sistema_de_pagos,recorrido,pos_del_recorrido,GPS,sentido,cantidad_max_pasajeros) {
	 
}

