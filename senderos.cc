//senderos.cc
//proyecto IS

#include "senderos.h"

sendero::sendero(string nombre,int longitud,
    string descripcion, int disponibilidad, list <ruta> rutas){
            setNombre(nombre);
            setLongitud(longitud);
            setDescripcion(descripcion);
            setDisponibilidad(disponibilidad);
            setRutas(rutas);
        }

  void sendero::mostrarRutasAsociadas(const parque &p){
    list<ruta> rutas=getInstance()->getRutasSendero(p.getNombre() + "_" + this->getSendero());
    for(ruta &ruta: rutas)
    {
      std::cout<<ruta.getNombre()<<endl;
      std::cout<<"\n";
    }
  }


void sendero::imprimirSendero(const parque &p){
  cout<<"DATOS DEL SENDERO: \n";
  cout<<"NOMBRE: "<<this->getNombre()<<endl;
  cout<<"LONGITUD: "<<this->getLongitud()<<endl;
  cout<<"DESCRIPCION: "<<this->getDescripcion()<<endl;
  cout<<"DISPONIBILIDAD: "<<this->getDisponibilidad()<<endl;
  cout<<"RUTAS ASOCIADAS: \n";
  this->mostrarRutasAsociadas(p);

  }
