//persona.cc
//proyecto IS

#include "persona.h"

persona::persona(string DNI, string nombre, string apellidos, int Tlfn, 
            string fechaDeNacimiento, string condicion) {
        setDNI(DNI);
        setNombre(nombre);
        setApellidos(apellidos);
        setNumeroDeTlfn(Tlfn);
        setFechaDeNacimiento(fechaDeNacimiento);
        setCondicion(condicion);
    }  