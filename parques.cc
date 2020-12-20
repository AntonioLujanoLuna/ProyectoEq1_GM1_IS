//parques.cc
//proyecto IS

#include "parques.h"
#include "senderos.h"
#include "rutas.h"

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


  void parque::mostrarSenderosAsociados(){

    list<sendero> senderos=getInstance()->getSenderosParque(this->getNombre());
    for(sendero &sendero: senderos)
    {
      std::cout<<sendero.getNombre()<<endl;
      std::cout<<"\n";
    }
  }


void parque::imprimirParque()
{
  cout<<"DATOS DEL PARQUE: \n";
  cout<<"NOMBRE: "<<this->getNombre()<<endl;
  cout<<"FECHA DE NOMBRAMIENTO: "<<this->getFechaNombramientoParque()<<endl;
  cout<<"TAMANO: "<<this->getTamano()<<endl;
  cout<<"PREMIOS: "<<this->getPremios()<<endl;
  cout<<"DESCRIPCION: "<<this->getDescripcion()<<endl;
  cout<<"DISPONIBILIDAD: "<<this->getDisponibilidad()<<endl;
  cout<<"SENDEROS ASOCIADOS: \n";
  this->mostrarSenderosAsociados();

}

void parque::setDisponibilidad(bool disponibilidad) {
  disponibilidad_=disponibilidad;
  list<sendero> senderos=getInstance()->getSenderosParque(parque.getNombre());
    for(sendero &sendero: senderos)
    {
        sendero.setDisponibilidad(disponibilidad);
        list <ruta> rutas=getInstance()->getRutasSendero(parque.getnombre() + "_" + sendero.getNombre());
      for(ruta &ruta: rutas)
      {
          ruta.setDisponibilidad(disponibilidad);
      }
    }
}
