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
