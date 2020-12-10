//parques.h
//proyecto IS

#ifndef PARQUES_H
#define PARQUES_H

#include <string>
#include <list>

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
        parque(string nombre, list <sendero> senderos=NULL, string fechaNombramientoParque="",
            int tamano=0, string premios="", string descripcion="", bool disponibilidad=true), list <sendero> senderos_ = NULL);
;
        inline string getNombre()const{return nombre_;};
        inline void setNombre(string nombre){nombre_=nombre;};
        inline list <sendero> getSenderos()const{return senderos_;};
        inline void setSenderos(list<senderos> senderos){senderos_=senderos;};
        inline void addSendero(sendero newSendero){senderos_.push_back(newSendero);};
        inline string getFechaNombramientoParque()const{return fechaNombramientoParque_;};
        inline void setFechaNombramientoParque(string fechaNombramiento){fechaNombramientoParque_=fechaNombramiento;};
        inline int getTamano()const{return tamano_;};
        inline void setTamano(int tamano){tamano_=tamano;};
        inline string getPremios()const{return premios_;};
        inline void setPremios(string premios){premios_=premios;};
        inline string getDescripcion()const{return descripcion_;};
        inline void setDescripcion(string descripcion){descripcion_=descripcion;};
        inline bool getDisponibilidad()const{return disponibilidad_;};
        inline void setDisponibilidad(bool disponibilidad){disponibilidad_=disponibilidad;};

};

#endif