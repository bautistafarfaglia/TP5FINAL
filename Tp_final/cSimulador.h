#pragma once
#include "Gbl.h"
#include "cParada.h"

#ifndef _CSIMULADOR_H
#define _CSIMULADOR_H

class cSimulador {
public:

    cSimulador();

    cParada generar_parada(cListaParadas* lista_global_paradas);

    void agregar_paradas_recorrido(cRecorrido* recorrido_a, cRecorrido* recorrido_b,cRecorrido* recorrido_c, cListaParadas* lista_global_paradas);
  
    void generar_colectiveros(cListaTemplate cColectivero* lista_colectiveros);

    void generar_colectivos(cListaColectivos* lista_colectiveros);

    void asignar_colectiveros(cListaColectivos* lista_global_colectiveros,cListaTemplate cColectivero* lista_colectiveros);

    void actualizar_objetivos(cListaColectivos* lista_global_colectiveros,cListaParadas* lista_global_paradas,cRecorrido* RecorridoA,cRecorrido* RecorridoB,cRecorrido* RecorridoC);

    /**
     * @param cListaColectivos* lista_global_colectivos
     */
    void actualizar_colectivos(cListaColectivos* lista_global_colectivos);
    
    void actualizar_paradas(cListaParadas* lista_global_paradas,cRecorrido* recorrido_a,cRecorrido* recorrido_b, cRecorrido* recorrido_c);

    string generador_destino(cParada* ParadaActual, cRecorrido* RecorridoA,cRecorrido* RecorridoB, cRecorrido* RecorridoC);

    string actualizar_gps_colectivos(cListaColectivos* lista_global_colectiveros);

    string resumen_del_dia(cListaColectivos* lista_global_colectivos);

    void tick();
};

#endif //_CSIMULADOR_H
