//parques.h
//proyecto IS

#ifndef PARQUES_H
#define PARQUES_H

#include "fileIO.h"



using namespace std;

class parque {
    private:
        string nombre_;
        string fechaNombramientoParque_;
        int tamano_;
        string premios_;
        string descripcion_;
        bool disponibilidad_;
        list <sendero> senderos_;
    public:
        parque(string nombre="", string fechaNombramientoParque="",
            int tamano=0, string premios="", string descripcion="", bool disponibilidad=true);
        inline string getNombre()const{return nombre_;};
        inline void setNombre(string nombre){nombre_=nombre;};
        inline list <sendero> getSenderos()const{return senderos_;};
        inline void setSenderos(list<sendero> senderos){senderos_=senderos;};
        inline string getFechaNombramientoParque()const{return fechaNombramientoParque_;};
        inline void setFechaNombramientoParque(string fechaNombramiento){fechaNombramientoParque_=fechaNombramiento;};
        inline int getTamano()const{return tamano_;};
        inline void setTamano(int tamano){tamano_=tamano;};
        inline string getPremios()const{return premios_;};
        inline void setPremios(string premios){premios_=premios;};
        inline string getDescripcion()const{return descripcion_;};
        inline void setDescripcion(string descripcion){descripcion_=descripcion;};
        inline bool getDisponibilidad()const{return disponibilidad_;};
        void setDisponibilidad(bool disponibilidad);

};

#endif
