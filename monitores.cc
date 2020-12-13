//monitores.cc
//proyecto IS

#include "monitores.h"

       monitor::monitor(string DNI, string nombreCompleto, string Tlfn, string fechaDeNacimiento, string condicion,
            int horasTrabajadas, bool disponibilidad){
		setDNI(DNI);
		setNombreCompleto(nombreCompleto);
		setNumeroDeTlfn(Tlfn);
		setFechaDeNacimiento(fechaDeNacimiento);
		setCondicion(condicion);
		setHorasTrabajadas(horasTrabajadas);
		setDisponibilidad(disponibilidad);
            
     	}
            
