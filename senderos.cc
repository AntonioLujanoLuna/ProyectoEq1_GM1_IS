//senderos.cc
//proyecto IS

#include "senderos.h"

senderos::senderos(string nombre, int longitud, string descripcion, 
        bool disponibilidad, string parqueAsociado, list <ruta> rutas){
            setNombre(nombre);
            setLongitud(longitud);
            setDescripcion(descripcion);
            setDisponibilidad(disponibilidad);
            setParqueAsociado(parqueAsociado);
            setRutas(rutas);
        }