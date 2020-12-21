//monitores.cc
//proyecto IS

#include "monitores.h"

       monitor::monitor(std::string DNI, std::string nombreCompleto, std::string Tlfn, std::std::string fechaDeNacimiento, std::string condicion,
            bool disponibilidad){
		setDNI(DNI);
		setNombreCompleto(nombreCompleto);
		setNumeroDeTlfn(Tlfn);
		setFechaDeNacimiento(fechaDeNacimiento);
		setCondicion(condicion);
		setDisponibilidad(disponibilidad);

     	}
