//rutas.cc
//proyecto IS

#include "rutas.h"

ruta::ruta(std::string id, std::string dificultad, std::string monitor, std::string fecha,
            std::string hora, std::string duracion, std::string bici, std::list <visitante> visitantes){
        setIdentidicador(id);
        setDificultad(dificultad);
        setMonitorAsociado(monitor);
        setFecha(fecha);
        setHora(hora);
        setDuracionEstimada(duracion);
        setBicicleta(bici);
        setGrupoVisitantes(visitantes);
}
