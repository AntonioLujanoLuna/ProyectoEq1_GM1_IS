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
  cout<<"SENDEROS ASOCIADOS: "<<this->getSenderos()<<endl;
  list<sendero> getSenderosParque(nombre);
}
