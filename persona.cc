//persona.cc
//proyecto IS

#include "persona.h"

persona::persona(string DNI, string nombreCompleto, string Tlfn, 
            string fechaDeNacimiento, string condicion) {
        setDNI(DNI);
        setNombreCompleto(nombreCompleto);
        setNumeroDeTlfn(Tlfn);
        setFechaDeNacimiento(fechaDeNacimiento);
        setCondicion(condicion);
    }  