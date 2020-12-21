//monitores.h#include <string>
#include <list>
#include <fstream>
#include <iostream>
//proyecto IS

#ifndef MONITORES_H
#define MONITORES_H

//#include "fileIO.h"
#include <string>
#include <list>
#include <fstream>
#include <iostream>


class monitor {
    private:
	std::string DNI_;
	std::string nombreCompleto_;
	std::string numeroDeTlfn_;
	std::string FechaDeNacimiento_;
  std::string condicion_;
  bool disponibilidad_;
    public:
        monitor(std::string DNI, std::string nombreCompleto, std::string Tlfn, std::string fechaDeNacimiento, std::string condicion,
            bool disponibilidad);
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
