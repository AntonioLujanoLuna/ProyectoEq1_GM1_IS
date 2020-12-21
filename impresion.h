//impresion.h
//proyecto IS

#ifndef IMPRESION_H
#define IMPRESION_H

#include <iostream>
#include <string>
#include <list>

void imprimirParque(const parque &p);
void mostrarSenderosAsociados(const parque &p);
void imprimirSendero(const parque &p, const sendero &s);
void mostrarRutasAsociadas(const parque &p, const sendero &s);
void imprimirRuta(const sendero &s, const parque &p);
void mostarVisitantesAsociados(const sendero &s, const parque &p);
void imprimirVisitante(const visitante &v);
void mostrarTodosVisitantes();
void mostrarTodosVisitantesDNI();
void imprimirMonitor(const monitor &m);
void mostrarTodosMonitoresDNI();


#endif
