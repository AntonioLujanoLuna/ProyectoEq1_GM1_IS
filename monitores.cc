//monitores.cc
//proyecto IS

#include "monitores.h"

       monitor::monitor(string DNI, string nombreCompleto, string Tlfn, string fechaDeNacimiento, string condicion,
            bool disponibilidad){
		setDNI(DNI);
		setNombreCompleto(nombreCompleto);
		setNumeroDeTlfn(Tlfn);
		setFechaDeNacimiento(fechaDeNacimiento);
		setCondicion(condicion);
		setDisponibilidad(disponibilidad);

     	}

    
