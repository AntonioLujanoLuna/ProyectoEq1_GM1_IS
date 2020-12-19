//parques.cc
//proyecto IS

#include "parques.h"
#include "senderos.h"
parque::parque(string nombre, string fechaNombramientoParque,
            int tamano, string premios, string descripcion, bool disponibilidad, list <sendero> senderos) {
        setNombre(nombre);
        setSenderos(senderos);
        setFechaNombramientoParque(fechaNombramientoParque);
        setTamano(tamano);
        setPremios(premios);
        setDescripcion(descripcion);
        setDisponibilidad(disponibilidad);
        setSenderos(senderos);
      }

void parque::imprimirParque(const parque &p)
{
  cout<<"DATOS DEL PARQUE: \n";
  cout<<"NOMBRE: "<<this->getNombre()<<endl;
  cout<<"FECHA DE NOMBRAMIENTO: "<<this->getFechaNombramientoParque()<<endl;
  cout<<"TAMANO: "<<this->getTamano()<<endl;
  cout<<"PREMIOS: "<<this->getPremios()<<endl;
  cout<<"DESCRIPCION: "<<this->getDescripcion()<<endl;
  cout<<"DISPONIBILIDAD: "<<this->getDisponibilidad()<<endl;
  cout<<"SENDEROS ASOCIADOS: \n";
  mostrarSenderosAsociados(const parque &p);

}

void parque::mostrarSenderosAsociados(const parque &p){

  list<sendero> senderos=getInstance()->getSenderosParque(p.getNombre());
  for(sendero &sendero: senderos)
  {
    std::cout<<sendero.getNombre()<<endl;
    std::cout<<"\n";
  }
}

void parque::setDisponibilidad(bool disponibilidad)
{
  disponibilidad_=disponibilidad;
  list<parque> parques=getInstance()->GetTodosParques();
  for(parque &parque: parques)
  {
  list<sendero> senderos=getInstance()->getSenderosParque(parque.getNombre());
    for(sendero &sendero: senderos)
    {
      if(parque.getDisponibilidad()==false && sendero.getDisponibilidad()==true)
      {
        sendero.setDisponibilidad(false);
      }
      list <ruta> rutas=getInstance()->getRutasSendero(sendero.getNombre());
      for(ruta &ruta: rutas)
      {
        if(sendero.getDisponibilidad()==false && ruta.getDisponibilidad()==true)
        {
          ruta.setDisponibilidad(false);
        }
      }
    }
  }
}
