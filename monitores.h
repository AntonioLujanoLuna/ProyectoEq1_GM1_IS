//monitores.h
//proyecto IS

#ifndef MONITORES_H
#define MONITORES_H

#include "fileIO.h"


class monitor {
    private:
	std::string DNI_;
	std::string nombreCompleto_;
	std::string numeroDeTlfn_;
	std::string FechaDeNacimiento_;
  std::string condicion_;
  bool disponibilidad_;
    public:
        monitor();
        inline std::string getDNI(){return DNI_;};
        inline void setDNI(std::string dni){DNI_=dni;};
        inline std::string getNombreCompleto(){return nombreCompleto_;};
        inline void setNombreCompleto(std::string nombre){nombreCompleto_=nombre;};
        inline std::string getNumeroDeTlfn(){return numeroDeTlfn_;};
        inline void setNumeroDeTlfn(std::string tlfn){numeroDeTlfn_=tlfn;};
        inline std::string getFechaDeNacimiento(){return FechaDeNacimiento_;};
        inline void setFechaDeNacimiento(std::string fecha){FechaDeNacimiento_=fecha;};
        inline std::string getCondicion(){return condicion_;};
        inline void setCondicion(std::string condicion){condicion_=condicion;};
        inline bool getDisponibilidad(){return disponibilidad_;};
        inline void setDisponibilidad(bool disponibilidad){disponibilidad_=disponibilidad;};

};
#endif
