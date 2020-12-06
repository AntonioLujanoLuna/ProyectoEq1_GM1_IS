//senderos.h
//proyecto IS

#ifndef SENDEROS_H
#define SENDEROS_H

#include <string>
#include <list>

using namespace std;

class senderos {
    private:
        string nombre_;
        int longitud_;
        string descripcion_;
        bool disponibilidad_;
        string parqueAsociado_;
        //list <rutas> rutas_;

    public:
        /*senderos(string nombre, int longitud=0, string descripcion="", 
            bool disponibilidad=TRUE, string parqueAsociado="", list <rutas> senderos=NULL); */
        inline string getNombre()const{return nombre_;};
        inline void setNombre(string nombre){nombre_=nombre;};
        inline int getLongitud()const{return longitud_;};
        inline void setLongitud(int longitud){longitud_=longitud;};
        inline string getDescripcion()const{return descripcion_;};
        inline void setDescripcion(string descripcion){descripcion_=descripcion;};
        inline bool getDisponibilidad()const{return disponibilidad_;};
        inline void setDisponibilidad(bool disponibilidad){disponibilidad_=disponibilidad;};
        inline string getParqueAsociado()const{return parqueAsociado_;};
        inline void setParqueAsociado(string parqueAsociado){parqueAsociado_=parqueAsociado;};
        //list <ruta> getRutas()const{return rutas_;};
        //void setRutas(list<ruta> rutas){rutas_=rutas;};
        //void addRuta(ruta newRuta){rutas_.push_back(newRuta);};

};


#endif