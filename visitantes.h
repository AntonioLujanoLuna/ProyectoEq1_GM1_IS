//visitantes.h
//proyecto IS

#ifndef VISITANTES_H
#define VISITANTES_H

#include <string>
#include <list>
#include "persona.h"

using namespace std;

class visitante {
private:
        string DNI_;
        string nombreCompleto_;
        string numeroDeTlfn_;
        string FechaDeNacimiento_;
        string condicion_;
public:
        visitante(string DNI, string nombreCompleto = "", string Tlfn = "",
            string fechaDeNacimiento = "", string condicion = "");
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
        void imprimirVisitante(const visitante &v);
        void mostrarTodosVisitantes();
};


#endif
