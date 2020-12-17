//senderos.h
//proyecto IS

#ifndef SENDEROS_H
#define SENDEROS_H

#include <string>
#include <list>
#include "rutas.h"

using namespace std;

class sendero {
    private:
        string nombre_;
        int longitud_;
        string descripcion_;
        int disponibilidad_;
        list <ruta> rutas_;

    public:
        sendero(string nombre, int longitud=0, string descripcion="",
            bool disponibilidad=true, list <ruta> rutas=NULL);
        inline string getNombre()const{return nombre_;};
        inline void setNombre(string nombre){nombre_=nombre;};
        inline int getLongitud()const{return longitud_;};
        inline void setLongitud(int longitud){longitud_=longitud;};
        inline string getDescripcion()const{return descripcion_;};
        inline void setDescripcion(string descripcion){descripcion_=descripcion;};
        inline int getDisponibilidad()const{return disponibilidad_;};
        inline void setDisponibilidad(int disponibilidad){disponibilidad_=disponibilidad;};
        list <ruta> getRutas()const{return rutas_;};
        void setRutas(list<ruta> rutas){rutas_=rutas;};
        void addRuta(ruta newRuta){rutas_.push_back(newRuta);};
        void imprimirSendero();

};


#endif
