//visitantes.cc
//proyecto IS

#include "visitantes.h"

visitante::visitante(std::string DNI, std::string nombreCompleto, std::string Tlfn,
            std::string fechaDeNacimiento, std::string condicion){
        setDNI(DNI);
	      setNombreCompleto(nombreCompleto);
        setNumeroDeTlfn(Tlfn);
        setFechaDeNacimiento(fechaDeNacimiento);
        setCondicion(condicion);
    }
