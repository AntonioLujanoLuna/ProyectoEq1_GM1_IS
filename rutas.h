//rutas.h
//proyecto IS

#ifndef RUTAS_H
#define RUTAS_H

//#include "fileIO.h"

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include "visitantes.h"


class ruta {
    private:
        std::string identificador_;
        std::string dificultad_;
        std::string monitorAsociado_;
        std::string fecha_;
        std::string hora_;
        std::string duracionEstimada_;
        std::string bicicleta_;
        std::list <visitante> grupoVisitantes_;

    public:
        ruta(std::string id, std::string dificultad, std::string monitor, std::string fecha,
            std::string hora, std::string duracion, std::string bici, std::list <visitante> visitantes);
        inline std::string getIdentificador()const{return identificador_;};
        inline void setIdentidicador(std::string id){identificador_=id;};
        inline std::string getDificultad()const{return dificultad_;};
        inline void setDificultad(std::string dificultad){dificultad_=dificultad;};
        inline std::string getMonitorAsociado()const{return monitorAsociado_;};
        inline void setMonitorAsociado(std::string DNI){monitorAsociado_=DNI;};
        inline std::string getFecha()const{return fecha_;};
        inline void setFecha(std::string fecha){fecha_=fecha;};
        inline std::string getHora()const{return hora_;};
        inline void setHora(std::string hora){hora_=hora;};
        inline void setDuracionEstimada(std::string duracion){duracionEstimada_=duracion;};
        inline std::string getDuracionEstimada()const{return duracionEstimada_;};
        inline std::string getBicicleta()const{return bicicleta_;};
        inline void setBicicleta(std::string bici){bicicleta_=bici;};
        inline std::list <visitante> getGrupoVisitante()const{return grupoVisitantes_;};
        inline void setGrupoVisitantes(std::list<visitante> visitantes){grupoVisitantes_=visitantes;};

};

#endif
