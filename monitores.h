//monitores.h
//proyecto IS

#ifndef MONITORES_H
#define MONITORES_H

#include <string>
#include <list>
#include "persona.h"

using namespace std;

class monitor : public persona{
    private:
        int horasTrabajadas_;        
        bool disponibilidad_;
    public:
        monitor(DNI, nombre, apellidos, Tlfn, fechaDeNacimiento, condicion,
            int horasTrabajadas = 0, bool disponibilidad = true) : persona(string DNI, 
            string nombre = "", string apellidos = "", int Tlfn = 0, 
            string fechaDeNacimiento = "", string condicion = ""){
                setHorasTrabajadas(horasTrabajadas);
                setDisponibilidad(disponibilidad);
            };
        inline int getHorasTrabajadas()const{return horasTrabajadas_;};
        inline void setHorasTrabajadas(int horas){horasTrabajadas_=horas;};
        inline bool getDisponibilidad()const{return disponibilidad_;};
        inline void setDisponibilidad(bool disponibilidad){disponibilidad_=disponibilidad;};
};
#endif