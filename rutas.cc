//rutas.cc
//proyecto IS

#include "rutas.h"

ruta::ruta(string id, string dificultad, string monitor, string fecha,
            string hora, string duracion, string bici, list <visitante> visitantes){
        setIdentidicador(id);
        setDificultad(dificultad);
        setMonitorAsociado(monitor);
        setFecha(fecha);
        setHora(hora);
        setDuracionEstimada(duracion);
        setBicicleta(bici);
        setGrupoVisitantes(visitantes);
}
