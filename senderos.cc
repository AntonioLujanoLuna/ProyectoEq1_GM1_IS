//senderos.cc
//proyecto IS

#include "senderos.h"

sendero::sendero(std::string nombre,int longitud,
    std::string descripcion, bool disponibilidad, std::list <ruta> rutas){
            setNombre(nombre);
            setLongitud(longitud);
            setDescripcion(descripcion);
            setDisponibilidad(disponibilidad);
            setRutas(rutas);
        }
