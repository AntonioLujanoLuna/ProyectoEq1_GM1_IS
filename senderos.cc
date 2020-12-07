//senderos.cc
//proyecto IS

#include "senderos.h"

sendero::sendero(string nombre, parque parqueAsociado,int longitud, 
    string descripcion, bool disponibilidad, list <ruta> rutas){
            setNombre(nombre);
            setParqueAsociado(parqueAsociado);
            setLongitud(longitud);
            setDescripcion(descripcion);
            setDisponibilidad(disponibilidad);
            setRutas(rutas);
        }