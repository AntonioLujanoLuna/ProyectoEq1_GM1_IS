//rutas.cc
//proyecto IS

#include "rutas.h"

ruta::ruta(int id, sendero sendero, int dificultad, string monitor, string fecha,
            string hora, int duracion, bool bici, list <visitante> visitantes){
        setIdentidicador(id);
        setSenderoAsociado(sendero);
        setDificultad(dificultad);
        setMonitorAsociado(monitor);
        setFecha(fecha);
        setHora(hora);
        setDuracionEstimada(duracion);
        setBicicleta(bici);
        setGrupoVisitantes(visitantes);

}