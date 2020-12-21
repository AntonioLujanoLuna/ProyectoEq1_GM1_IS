//senderos.h
//proyecto IS

#ifndef SENDEROS_H
#define SENDEROS_H

#include "fileIO.h"


class sendero {
    private:
        std::string nombre_;
        std::string longitud_;
        std::string descripcion_;
        bool disponibilidad_;
        std::list <ruta> rutas_;

    public:
        sendero();
        inline std::string getNombre()const{return nombre_;};
        inline void setNombre(std::string nombre){nombre_=nombre;};
        inline std::string getLongitud()const{return longitud_;};
        inline std::string getDescripcion()const{return descripcion_;};
        inline void setDescripcion(std::string descripcion){descripcion_=descripcion;};
        inline void setLongitud(std::string longitud){longitud_=longitud;};
        inline bool getDisponibilidad()const{return disponibilidad_;};
        inline void setDisponibilidad(bool disponibilidad){disponibilidad_=disponibilidad;};
        std::list <ruta> getRutas()const{return rutas_;};
        void setRutas(std::list<ruta> rutas){rutas_=rutas;};

};


#endif
