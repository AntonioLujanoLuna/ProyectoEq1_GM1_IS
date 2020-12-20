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

void visitante::imprimirVisitante(){
  cout<<"DATOS DEL VISITANTE: \n";
  cout<<"DNI: "<<this->getDNI()<<endl;
  cout<<"NOMBRE: "<<this->getNombreCompleto()<<endl;
  cout<<"FECHA DE NACIMIENTO: "<<this->getFechaDeNacimiento()<<endl;
  cout<<"NUMERO DE TELEFONO: "<<this->getNumeroDeTlfn()<<endl;
  cout<<"CONDICION: "<<this->getCondicion()<<endl;
}

void visitante::mostrarTodosVisitantes(){

  list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getNombreCompleto()<<endl;
  }
}

void visitante::mostrarTodosVisitantesDNI(){

  list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getDNI()<<endl;
  }
}
