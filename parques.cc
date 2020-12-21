//parques.cc
//proyecto IS

#include "parques.h"
#include "senderos.h"
#include "rutas.h"

void parque::setDisponibilidad(bool disponibilidad) {
  disponibilidad_=disponibilidad;
  std::list<sendero> senderos=getSenderosParque(parque.getNombre());
    for(sendero &sendero: senderos)
    {
        sendero.setDisponibilidad(disponibilidad);
        std::list <ruta> rutas=getRutasSendero(parque.getNombre() + "_" + sendero.getNombre());

    }
}
