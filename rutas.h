//rutas.h
//proyecto IS

#ifndef RUTAS_H
#define RUTAS_H

#include <string>
#include <list>
#include "visitantes.h"
#include "parques.h"
#include "senderos.h"
#include "monitores.h"

using namespace std;

class ruta {
    private:
        string identificador_;
        string dificultad_;
        string monitorAsociado_;
        string fecha_;
        string hora_;
        int duracionEstimada_;
        string bicicleta_;
        list <visitante> grupoVisitantes_;

    public:
        ruta(string id, string dificultad = 2, string monitor = "", 
            string fecha = "", string hora = "", int duracion = 0, bool bici = true,
            list <visitante> visitantes = NULL);
        inline string getIdentificador()const{return identificador_;};
        inline void setIdentidicador(string id){identificador_=id;};
        inline string getDificultad()const{return dificultad_;};
        inline void setDificultad(string dificultad){dificultad_=dificultad;};
        inline string getMonitorAsociado()const{return monitorAsociado_;};
        inline void setMonitorAsociado(string DNI){monitorAsociado_=DNI;};
        inline string getFecha()const{return fecha_;};
        inline void setFecha(string fecha){fecha_=fecha;};
        inline string getHora()const{return hora_;};
        inline void setHora(string hora){hora_=hora;};
        inline int getDuracionEstimada()const{return duracionEstimada_;};
        inline void setDuracionEstimada(int duracion){duracionEstimada_=duracion;};
        inline string getBicicleta()const{return bicicleta_;};
        inline void setBicicleta(string bici){bicicleta_=bici;};
        inline list <visitante> getGrupoVisitante()const{return grupoVisitantes_;};
        inline void setGrupoVisitantes(list<visitante> visitantes){grupoVisitantes_=visitantes;};
        inline void addVisitante(visitante newVisitante){grupoVisitantes_.push_back(newVisitante);};

};

#endif