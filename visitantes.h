//visitantes.h
//proyecto IS

#ifndef VISITANTES_H
#define VISITANTES_H

//#include "fileIO.h"

#include <string>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;


class visitante {
private:
      std::string DNI_;
      std::string nombreCompleto_;
      std::string numeroDeTlfn_;
      std::string FechaDeNacimiento_;
      std::string condicion_;
public:
        visitante(){}
        visitante(std::string DNI, std::string nombreCompleto, std::string Tlfn,
            std::string fechaDeNacimiento, std::string condiciong);
        inline std::string getDNI()const{return DNI_;};
        inline void setDNI(std::string dni){DNI_=dni;};
        inline std::string getNombreCompleto()const{return nombreCompleto_;};
        inline void setNombreCompleto(std::string nombre){nombreCompleto_=nombre;};
        inline std::string getNumeroDeTlfn()const{return numeroDeTlfn_;};
        inline void setNumeroDeTlfn(std::string tlfn){numeroDeTlfn_=tlfn;};
        inline std::string getFechaDeNacimiento()const{return FechaDeNacimiento_;};
        inline void setFechaDeNacimiento(std::string fecha){FechaDeNacimiento_=fecha;};
        inline std::string getCondicion()const{return condicion_;};
        inline void setCondicion(std::string condicion){condicion_=condicion;};

};


#endif
