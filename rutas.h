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

class rutas {
    private:
        int identificador_;
        string senderoAsociado_;
        int dificultad_;
        string monitorAsociado_;
        string fecha_;
        string hora_;
        int duracionEstimada_;
        bool bicicleta_;
        list <visitante> grupoVisitantes_;

    public:
        rutas(int id, string sendero = "", int dificultad = 2, string monitor = "", 
            string fecha = "", string hora = "", int duracion = 0, bool bici = true,
            list <visitante> visitantes = NULL);
        inline int getIdentificador()const{return identificador_;};
        inline void setIdentidicador(int id){identificador_=id;};
        inline string getSenderoAsociado()const{return senderoAsociado_;};
        inline void setSenderoAsociado(string sendero){senderoAsociado_=sendero;};
        inline int getDificultad()const{return dificultad_;};
        inline void setDificultad(int dificultad){dificultad_=dificultad;};
        inline string getMonitorAsociado()const{return monitorAsociado_;};
        inline void setMonitorAsociado(string DNI){monitorAsociado_=DNI;};
        inline string getFecha()const{return fecha_;};
        inline void setFecha(string fecha){fecha_=fecha;};
        inline string getHora()const{return hora_;};
        inline void setHora(string hora){hora_=hora;};
        inline int getDuracionEstimada()const{return duracionEstimada_;};
        inline void setDuracionEstimada(int duracion){duracionEstimada_=duracion;};
        inline bool getBicicleta()const{return bicicleta_;};
        inline void setBicicleta(bool bici){bicicleta_=bici;};
        inline list <visitante> getGrupoVisitante()const{return grupoVisitantes_;};
        inline void setGrupoVisitantes(list<visitante> visitantes){grupoVisitantes_=visitantes;};
        inline void addVisitante(visitante newVisitante){grupoVisitantes_.push_back(newVisitante);};

};

#endif