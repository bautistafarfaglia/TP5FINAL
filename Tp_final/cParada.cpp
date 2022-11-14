#include "cParada.h"

unsigned int cParada::cant_total_paradas = 0;

cParada::cParada(string nombre_parada, eSentidoRecorrido direccion) : id_parada(cant_total_paradas), nombre_parada(nombre_parada), direccion(direccion) {
	
}

string cParada::get_nombre_parada() {
    return this->nombre_parada;
}

vector<cPasajeros*> cParada::get_lista_pasajeros()
{
	return this->listaPasajeros;
}

int cParada::get_id_parada() {
    return this->id_parada;
}

/// <summary>
/// Este metodo agrupa a los pasajeros que se suben a x coletivo
/// </summary>
/// <param name="num"></param>
/// <returns>Devuelve un con quienes se van a subir </returns>
vector<cPasajeros*> cParada::pasajeros_suben_colectivo(int num){
	vector<cPasajeros*> aux;
	int cantEstatica = this->listaPasajeros.size();
	for (int i = 0; i < cantEstatica; i++) {
		if (this->listaPasajeros[i]->get_num_colectivo() == num) {
			aux.push_back(this->listaPasajeros[i]);
			this->listaPasajeros.erase(this->listaPasajeros.begin() + i);
			i--; 
			cantEstatica--;
		}
		else {
			cout << "El pasajero: " << this->listaPasajeros[i]->get_DNI() << " Esta esperando a otro colectivo" << endl;
		}
	}
	return aux;
}

void cParada::agregar_pasajero(cPasajeros* pasajero_nuevo)
{
	try{
		if(pasajero_nuevo!=NULL){
			int cont = 0;
			if (pasajero_nuevo->get_prioridad() == true) {
				this->listaPasajeros.insert(this->listaPasajeros.begin(), pasajero_nuevo);
				cont++;
			}
			else if (pasajero_nuevo->get_hay_una_discapacidad() == true) {
				this->listaPasajeros.insert(this->listaPasajeros.begin() + cont, pasajero_nuevo); //chequear si en verdad funciona, pero le tengo fe
			}
			else {
				this->listaPasajeros.push_back(pasajero_nuevo);
			}
		}else {
		throw exception("No se puede agregar pasajero NULL"); 
		}
	}
	catch (const char* msg) {
		cout << "Error 09: " << msg << endl;
	}
	catch (exception& e) {
			cout << "Error 10: " << e.what() << endl;
	}
}

string cParada::to_string_parada() {
	stringstream ss;
		ss << "Parada ID: " << this->id_parada << endl
		<< "Nombre Parada: " << this->nombre_parada << endl
		<< "Direccion: " << this->direccion << endl
		<< "N° Total Paradas: " << this->cant_total_paradas<< endl;
		ss << "-----------------------------" << endl
			<< "lista Pasajeros en parada: " << endl;;
		for (int i = 0; i < this->listaPasajeros.size(); i++) {
			ss << endl;
			ss << this->listaPasajeros[i]->to_string_pasajero();
			ss << endl;
		}
	return ss.str();
}

void cParada::imprimir() {
    return;
}

eSentidoRecorrido cParada::get_sentido_parada() { return this->direccion; }

istream& operator>>(istream& is, cParada& pa)
{
	try {
		if (pa.id_parada != NULL) {
			int pos = 0;
			bool estado = false;
			cout << "Ingrese los datos de la parada: " << endl;
			cout << "Nombre de la parada: " << endl;
			is >> pa.nombre_parada;
			cout << "Direccion de la parada: 0=arriba, 1=abajo " << endl;
			
			int aux;
			do { cin >> aux; } while (aux != 0, aux != 1);
			pos = aux;
			is >> pos;
			if (pos == 0) {
				pa.direccion = Arriba;
			}
			else if (pos == 1) {
				pa.direccion = Abajo;
			}
			return is;
			
		}
		else {
			throw exception("No se puede customizar una parada NULL");
		}
	}
	catch (const char* msg) {
		cout << "Error 11: " << msg << endl;
	}
	catch (exception& e) {
		cout << "Error 12: " << e.what() << endl;
	}
}