//persona.h
//proyecto IS

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <list>

using namespace std;

class persona {
    private:
        string DNI_;
        string nombreCompleto_;
        string numeroDeTlfn_;
        string FechaDeNacimiento_;
        string condicion_;
    public:
        persona(string DNI, string nombre = "", string apellidos = "", string Tlfn = "", 
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
};


#endif