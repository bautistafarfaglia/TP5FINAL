#pragma once
#ifndef CFECHA_H
#define CFECHA_H
#include "gbl.h"

class cFecha
{
public:

	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_hora">: Hora a setear</param>
	/// <param name="_minuto">: Minuto a setear</param>
	cFecha(short _hora = 0, short _minuto = 0);

	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cFecha();


	static time_t getHorarioActual();

private:

	struct tm Horario;

};

inline time_t cFecha::getHorarioActual() { return time(NULL); }

#endif // !CFECHA_H
