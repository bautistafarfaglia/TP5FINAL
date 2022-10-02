#include "cFecha.h"

cFecha::cFecha(short _hora, short _minuto) {
	time_t aux = cFecha::getHorarioActual();
	Horario = *localtime(&aux);
	this->Horario.tm_hour = _hora;
	this->Horario.tm_min = _minuto;
}

cFecha::~cFecha() { }