//monitores.cc
//proyecto IS

#include "monitores.h"

       monitor::monitor(string DNI, string nombreCompleto, string Tlfn, string fechaDeNacimiento, string condicion,
            string horasTrabajadas, bool disponibilidad){
		setDNI(DNI);
		setNombreCompleto(nombreCompleto);
		setNumeroDeTlfn(Tlfn);
		setFechaDeNacimiento(fechaDeNacimiento);
		setCondicion(condicion);
		setHorasTrabajadas(horasTrabajadas);
		setDisponibilidad(disponibilidad);

     	}

      void monitor::imprimirMonitor(){
        cout<<"DATOS DEL MONITOR: \n";
        cout<<"DNI: "<<this->getDNI()<<endl;
        cout<<"NOMBRE COMPLETO: "<<this->getNombreCompleto()<<endl;
        cout<<"FECHA DE NACIMIENTO: "<<this->getFechaDeNacimiento()<<endl;
        cout<<"NUMERO DE TELEFONO: "<<this->getNumeroDeTlfn()<<endl;
        cout<<"CONDICION: "<<this->getCondicion()<<endl;
        cout<<"HORAS TRABAJADAS: "<<this->getHorasTrabajadas()<<endl;
        cout<<"DISPONIBILIDAD: "<<this->getDisponibilidad()<<endl;
      }
