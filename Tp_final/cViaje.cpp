#include "cViaje.h"
cViaje::cViaje() {

}
cViaje::cViaje(string inicio,string destino,float costo_del_viaje) {

}
string cViaje::to_string_viaje() {
	stringstream ss;

	ss << "-----------------------------" << endl
		<< "Viaje ID [" << this->id_viaje << "]" << endl
		<< "Inicio: " << this->inicio << endl
		<< "Destino: " << this->destino << endl;

	return ss.str();;
}
void cViaje::imprimir() {
	cout << to_string_viaje();
}