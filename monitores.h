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
	string DNI_;
	string nombreCompleto_;
	string numeroDeTlfn_;
	string FechaDeNacimiento_;
	string condicion_;
	int horasTrabajadas_;        
	bool disponibilidad_;
    public:
        monitor(string DNI, string nombreCompleto = "", string Tlfn="", string fechaDeNacimiento="01/01/2000", string condicion="",
            int horasTrabajadas = 0, bool disponibilidad = true);
            };
        inline string getDNI()const{return DNI_;};
        inline void setDNI(string dni){DNI_=dni;};
        inline string getNombreCompleto()const{return nombreCompleto_;};
        inline void setNombreCompleto(string nombre){nombreCompleto_=nombre;};
        inline string getNumeroDeTlfn()const{return numeroDeTlfn_;};
        inline void setNumeroDeTlfn(string tlfn){numeroDeTlfn_=tlfn;};
        inline string getFechaDeNacimiento()const{return FechaDeNacimiento_;};
        inline void setFechaDeNacimiento(string fecha){FechaDeNacimiento_=fecha;};
        inline string getCondicion()const{return condicion_;};
        inline void setCondicion(string condicion){condicion_=condicion;};
        inline int getHorasTrabajadas()const{return horasTrabajadas_;};
        inline void setHorasTrabajadas(int horas){horasTrabajadas_=horas;};
        inline bool getDisponibilidad()const{return disponibilidad_;};
        inline void setDisponibilidad(bool disponibilidad){disponibilidad_=disponibilidad;};
};
#endif
