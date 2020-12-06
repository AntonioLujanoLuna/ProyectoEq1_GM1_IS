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
        string nombre_;
        string apellidos_;
        int numeroDeTlfn_;
        string FechaDeNacimiento_;
        string condicion_;
    public:
        persona(string DNI, string nombre = "", string apellidos = "", int Tlfn = 0, 
            string fechaDeNacimiento = "", string condicion = "");
        inline string getDNI()const{return DNI_;};
        inline void setDNI(string dni){DNI_=dni;};
        inline string getNombre()const{return nombre_;};
        inline void setNombre(string nombre){nombre_=nombre;};
        inline string getApellidos()const{return apellidos_;};
        inline void setApellidos(string apellidos){apellidos_=apellidos;};
        inline int getNumeroDeTlfn()const{return numeroDeTlfn_;};
        inline void setNumeroDeTlfn(int tlfn){numeroDeTlfn_=tlfn;};
        inline string getFechaDeNacimiento()const{return FechaDeNacimiento_;};
        inline void setFechaDeNacimiento(string fecha){FechaDeNacimiento_=fecha;};
        inline string getCondicion()const{return condicion_;};
        inline void setCondicion(string condicion){condicion_=condicion;};
};


#endif