//visitantes.cc
//proyecto IS

#include "visitantes.h"

visitante::visitante(string DNI, string nombre, string apellidos, int Tlfn, 
            string fechaDeNacimiento, string condicion) : persona(string DNI, 
            string nombre, string apellidos, int Tlfn, string fechaDeNacimiento, 
            string condicion){
        setDNI(DNI);
        setNombre(nombre);
        setApellidos(apellidos);
        setNumeroDeTlfn(Tlfn);
        setFechaDeNacimiento(fechaDeNacimiento);
        setCondicion(condicion);
    } 