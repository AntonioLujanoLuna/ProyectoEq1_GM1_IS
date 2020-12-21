//parques.cc
//proyecto IS

#include "parques.h"
#include "senderos.h"
#include "rutas.h"

void parque::setDisponibilidad(bool disponibilidad) {
  disponibilidad_=disponibilidad;
  std::list<sendero> senderos=getSenderosParque(getNombre());
    for(sendero &sendero: senderos)
    {
        sendero.setDisponibilidad(disponibilidad);
        std::list <ruta> rutas=getRutasSendero(getNombre() + "_" + sendero.getNombre());
    }
}
