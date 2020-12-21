//impresion.cc
//Proyecto IS

#include "impresion.h"

void mostrarSenderosAsociados(const parque &p){

  list<sendero> senderos=getInstance()->getSenderosParque(p.getNombre());
  for(sendero &sendero: senderos)
  {
    std::cout<<sendero.getNombre()<<endl;
    std::cout<<"\n";
  }
}

void imprimirParque(const parque &p){
cout<<"DATOS DEL PARQUE: \n";
cout<<"NOMBRE: "<<p.getNombre()<<endl;
cout<<"FECHA DE NOMBRAMIENTO: "<<p.getFechaNombramientoParque()<<endl;
cout<<"TAMANO: "<<p.getTamano()<<endl;
cout<<"PREMIOS: "<<p.getPremios()<<endl;
cout<<"DESCRIPCION: "<<p.getDescripcion()<<endl;
cout<<"DISPONIBILIDAD: "<<p.getDisponibilidad()<<endl;
cout<<"SENDEROS ASOCIADOS: \n";
mostrarSenderosAsociados(p);

}


void mostrarRutasAsociadas(const sendero &s, const parque &p){
  list<ruta> rutas=getInstance()->getRutasSendero(p.getNombre() + "_" + s.getSendero());
  for(ruta &ruta: rutas)
  {
    std::cout<<ruta.getNombre()<<endl;
    std::cout<<"\n";
  }
}

void imprimirSendero(const sendero &s, const parque &p){
cout<<"DATOS DEL SENDERO: \n";
cout<<"NOMBRE: "<<s.getNombre()<<endl;
cout<<"LONGITUD: "<<s.getLongitud()<<endl;
cout<<"DESCRIPCION: "<<s.getDescripcion()<<endl;
cout<<"DISPONIBILIDAD: "<<s.getDisponibilidad()<<endl;
cout<<"RUTAS ASOCIADAS: \n";
this->mostrarRutasAsociadas(s, p);

}


void mostarVisitantesAsociados(const ruta &r, const sendero &s, const parque &p){

  list<visitante> visitantes=getInstance()->getVisitantesRuta(p.getNombre() + "_" + s.getNombre() + "_" + this->getIdentificador());
  for(visitante &visitantes: visitantes)
  {
    std::cout<<visitante.getNombreCompleto()<<endl;
    std::cout<<"\n";
   }

}

void imprimirRuta(const ruta &r, const sendero &s, const parque &p){
  cout<<"DATOS DE LA RUTA: \n";
  cout<<"IDENTIFICADOR: "<<r.getIdentificador()<<endl;
  cout<<"DIFICULTAD: "<<r.getDificultad()<<endl;
  cout<<"MONITOR ASOCIADO: "<<r.getMonitorAsociado()<<endl;
  cout<<"FECHA: "<<r.getFecha()<<endl;
  cout<<"HORA: "<<r.getHora()<<endl;
  cout<<"DURACION ESTIMADA: "<<r.getDuracionEstimada()<<endl;
  cout<<"BICICLETA: "<<r.getBicicleta() << endl;
  this->mostrarVisitantesAsociados(r, s, p);
}


void imprimirVisitante(const visitante &v){
  cout<<"DATOS DEL VISITANTE: \n";
  cout<<"DNI: "<<v.getDNI()<<endl;
  cout<<"NOMBRE: "<<c.getNombreCompleto()<<endl;
  cout<<"FECHA DE NACIMIENTO: "<<v.getFechaDeNacimiento()<<endl;
  cout<<"NUMERO DE TELEFONO: "<<v.getNumeroDeTlfn()<<endl;
  cout<<"CONDICION: "<<v.getCondicion()<<endl;
}

void mostrarTodosVisitantes(){

  list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getNombreCompleto()<<endl;
  }
}

void mostrarTodosVisitantesDNI(){

  list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getDNI()<<endl;
  }
}

void imprimirMonitor(const monitor &m){
  cout<<"DATOS DEL MONITOR: \n";
  cout<<"DNI: "<<m.getDNI()<<endl;
  cout<<"NOMBRE COMPLETO: "<<m.getNombreCompleto()<<endl;
  cout<<"FECHA DE NACIMIENTO: "<<m.getFechaDeNacimiento()<<endl;
  cout<<"NUMERO DE TELEFONO: "<<m.getNumeroDeTlfn()<<endl;
  cout<<"CONDICION: "<<m.getCondicion()<<endl;
  cout<<"DISPONIBILIDAD: "<<m.getDisponibilidad()<<endl;
}

void mostrarTodosMonitoresDNI(){

  list<monitor> monitores=getInstance()->getTodosMonitores();
  for(monitor &monitor: monitores)
  {
    std::cout<<monitor.getDNI()<<endl;
  }
}
