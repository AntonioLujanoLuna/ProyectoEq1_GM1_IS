//visitantes.cc
//proyecto IS

#include "visitantes.h"

visitante::visitante(string DNI, string nombreCompleto, string Tlfn, 
            string fechaDeNacimiento, string condicion){
        setDNI(DNI);
	setNombreCompleto(nombreCompleto);
        setNumeroDeTlfn(Tlfn);
        setFechaDeNacimiento(fechaDeNacimiento);
        setCondicion(condicion);
    } 
