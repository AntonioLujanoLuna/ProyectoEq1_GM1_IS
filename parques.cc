//parques.cc
//proyecto IS

#include "parques.h"
#include "senderos.h"
#include "rutas.h"

void parque::setDisponibilidad(bool disponibilidad) {
  disponibilidad_=disponibilidad;
  std::list<sendero> senderos=FileIO::getInstance()->getSenderosParque(parque.getNombre());
    for(sendero &sendero: senderos)
    {
        sendero.setDisponibilidad(disponibilidad);
        std::list <ruta> rutas=FileIO::getInstance()->getRutasSendero(parque.getNombre() + "_" + sendero.getNombre());

    }
}
