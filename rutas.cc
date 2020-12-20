//rutas.cc
//proyecto IS

#include "rutas.h"

ruta::ruta(string id, string dificultad, string monitor, string fecha,
            string hora, string duracion, string bici, list <visitante> visitantes){
        setIdentidicador(id);
        setDificultad(dificultad);
        setMonitorAsociado(monitor);
        setFecha(fecha);
        setHora(hora);
        setDuracionEstimada(duracion);
        setBicicleta(bici);
        setGrupoVisitantes(visitantes);

}

void ruta::mostarVisitantesAsociados(const sendero &s, const parque &p){


      list<visitante> visitantes=getInstance()->getVisitantesRuta(p.getNombre() + "_" + s.getNombre() + "_" + r.getIdentificador());
      for(visitante &visitantes: visitantes)
      {
        std::cout<<visitante.getNombreCompleto()<<endl;
        std::cout<<"\n";
      }

}

void ruta::imprimirRuta(const sendero &s, const parque &p){
  cout<<"DATOS DE LA RUTA: \n";
  cout<<"IDENTIFICADOR: "<<this->getIdentificador()<<endl;
  cout<<"DIFICULTAD: "<<this->getDificultad()<<endl;
  cout<<"MONITOR ASOCIADO: "<<this->getMonitorAsociado()<<endl;
  cout<<"FECHA: "<<this->getFecha()<<endl;
  cout<<"HORA: "<<this->getHora()<<endl;
  cout<<"DURACION ESTIMADA: "<<this->getDuracionEstimada()<<endl;
  cout<<"BICICLETA: "<<this->getBicicleta() << endl;
  this->mostrarVisitantesAsociados(s, p);
}
