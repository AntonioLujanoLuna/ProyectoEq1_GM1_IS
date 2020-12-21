//impresion.h
//proyecto IS

#ifndef IMPRESION_H
#define IMPRESION_H

#include "parques.h"
#include "senderos.h"
#include "rutas.h"
#include "monitores.h"
#include "visitantes.h"

#include <iostream>
#include <string>
#include <list>

void imprimirParque(const parque &p);
void mostrarSenderosAsociados(const parque &p);
void imprimirSendero(const parque &p, const sendero &s);
void mostrarRutasAsociadas(const parque &p, const sendero &s);
void imprimirRuta(const ruta &r, const sendero &s, const parque &p);
void mostarVisitantesAsociados(const sendero &s, const parque &p);
void imprimirVisitante(const visitante &v);
void mostrarTodosVisitantes();
void mostrarTodosVisitantesDNI();
void imprimirMonitor(const monitor &m);
void mostrarTodosMonitoresDNI();

bool fechaValida (const std::string &str);
bool horaValida (const std::string &str);
void mostrarNombresParques();


#endif
