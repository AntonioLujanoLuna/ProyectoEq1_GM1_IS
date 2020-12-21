//parques.h
//proyecto IS

#ifndef PARQUES_H
#define PARQUES_H

#include "fileIO.h"


class parque {
    private:
        std::string nombre_;
        std::string fechaNombramientoParque_;
        std::string tamano_;
        std::string premios_;
        std::string descripcion_;
        bool disponibilidad_;
        std::list <sendero> senderos_;


    public:
        parque();
        inline std::string getNombre()const{return nombre_;};
        inline void setNombre(std::string nombre){nombre_=nombre;};
        inline void setSenderos(std::list<sendero> senderos){senderos_=senderos;};
        inline std::list <sendero> getSenderos()const{return senderos_;};
        inline void setFechaNombramientoParque(std::string fechaNombramiento){fechaNombramientoParque_=fechaNombramiento;};
        inline std::string getFechaNombramientoParque()const{return fechaNombramientoParque_;};
        inline int getTamano()const{return tamano_;};
        inline void setTamano(std::string tamano){tamano_=tamano;};
        inline std::string getPremios()const{return premios_;};
        inline void setPremios(std::string premios){premios_=premios;};
        inline std::string getDescripcion()const{return descripcion_;};
        inline void setDescripcion(std::string descripcion){descripcion_=descripcion;};
        inline bool getDisponibilidad()const{return disponibilidad_;};
        void setDisponibilidad(bool disponibilidad);

};

#endif
