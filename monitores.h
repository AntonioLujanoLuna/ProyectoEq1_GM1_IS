//monitores.h
//proyecto IS

#ifndef MONITORES_H
#define MONITORES_H

#include "fileIO.h"

using namespace std;

class monitor {
    private:
	string DNI_;
	string nombreCompleto_;
	string numeroDeTlfn_;
	string FechaDeNacimiento_;
	string condicion_;
	string horasTrabajadas_;
	bool disponibilidad_;
    public:
        monitor(string DNI="", string nombreCompleto = "", string Tlfn="", string fechaDeNacimiento="01/01/2000", string condicion="",
            string horasTrabajadas = "0", bool disponibilidad = true);
        inline string getDNI(){return DNI_;};
        inline void setDNI(string dni){DNI_=dni;};
        inline string getNombreCompleto(){return nombreCompleto_;};
        inline void setNombreCompleto(string nombre){nombreCompleto_=nombre;};
        inline string getNumeroDeTlfn(){return numeroDeTlfn_;};
        inline void setNumeroDeTlfn(string tlfn){numeroDeTlfn_=tlfn;};
        inline string getFechaDeNacimiento(){return FechaDeNacimiento_;};
        inline void setFechaDeNacimiento(string fecha){FechaDeNacimiento_=fecha;};
        inline string getCondicion(){return condicion_;};
        inline void setCondicion(string condicion){condicion_=condicion;};
        inline string getHorasTrabajadas(){return horasTrabajadas_;};
        inline void setHorasTrabajadas(string horas){horasTrabajadas_=horas;};
        inline bool getDisponibilidad(){return disponibilidad_;};
        inline void setDisponibilidad(bool disponibilidad){disponibilidad_=disponibilidad;};
        void imprimirMonitor(const monitor &m);
};
#endif
