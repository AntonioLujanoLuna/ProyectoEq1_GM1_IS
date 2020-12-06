//parques.cc
//proyecto IS

#include "parques.h"
#include "senderos.h"
parques::parques(string nombre, list <sendero> senderos, string fechaNombramientoParque,
            int tamano, string premios, string descripcion, bool disponibilidad) {
        setNombre(nombre);
        setSenderos(senderos);
        setFechaNombramientoParque(fechaNombramientoParque);
        setTamano(tamano);
        setPremios(premios);
        setDescripcion(descripcion);
        setDisponibilidad(disponibilidad);
}
