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

void sendero::imprimirSendero(const sendero &s, const parque &p)
    {
  cout<<"DATOS DEL SENDERO: \n";
  cout<<"NOMBRE: "<<this->getNombre()<<endl;
  cout<<"LONGITUD: "<<this->getLongitud()<<endl;
  cout<<"DESCRIPCION: "<<this->getDescripcion()<<endl;
  cout<<"DISPONIBILIDAD: "<<this->getDisponibilidad()<<endl;
  cout<<"RUTAS ASOCIADAS: \n";
  mostrarRutasAsociadas(const sendero &s,const parque &p);

  }

  void sendero::mostrarRutasAsociadas(const sendero &s, const parque &p){

    list<ruta> rutas=getInstance()->getRutasSendero(s.getNombre());
    for(ruta &ruta: rutas)
    {
      std::cout<<ruta.getNombre()<<endl;
      std::cout<<"\n";
    }

  }
