//parques.cc
//proyecto IS

#include "parques.h"
#include "senderos.h"
#include "rutas.h"

parque::parque(std::string nombre, std::string fechaNombramientoParque,
          int tamano, std::string premios, std::string descripcion, bool disponibilidad, std::list <sendero> senderos) {
        setNombre(nombre);
        setSenderos(senderos);
        setFechaNombramientoParque(fechaNombramientoParque);
        setTamano(tamano);
        setPremios(premios);
        setDescripcion(descripcion);
        setDisponibilidad(disponibilidad);
        setSenderos(senderos);
      }

void parque::setDisponibilidad(bool disponibilidad) {
  disponibilidad_=disponibilidad;
  std::list<sendero> senderos=getInstance()->getSenderosParque(parque.getNombre());
    for(sendero &sendero: senderos)
    {
        sendero.setDisponibilidad(disponibilidad);
        std::list <ruta> rutas=getInstance()->getRutasSendero(parque.getnombre() + "_" + sendero.getNombre());
      for(ruta &ruta: rutas)
      {
          ruta.setDisponibilidad(disponibilidad);
      }
    }
}
