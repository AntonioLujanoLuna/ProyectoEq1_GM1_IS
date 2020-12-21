//fileIO.h
//Proyecto IS

#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include "monitores.h"
#include "visitantes.h"
#include "rutas.h"
#include "senderos.h"
#include "parques.h"
#include "impresion.h"
#include "menus.h"

class FileIO {
    private:
        static FileIO* _instance; //Singleton instance
        std::string _path;

        FileIO (std::string path) {
            _path = path;
            std::ifstream ifs(_path);
            if (!ifs) {
                std::ofstream ofs(_path);
            }
        }

    public:
        static FileIO* getInstance();

        std::string getPath () const {
            return _path;
        }
        void setPath (std::string path) {
            _path = path;
        }

        int existsParque(std::string nombre);
        int existsSendero (std::string nombreSendero, std::string nombreParque);
        int existsRuta (std::string nombreRuta, std::string nombreSendero, std::string nombreParque);
        int existsVisitanteARuta (std::string dni, std::string nombreRuta, std::string nombreSendero, std::string nombreParque);
        int existsVisitante(std::string dni);
        int existsMonitor(std::string dni);

        std::list<parque> getTodosParques();
        std::list<sendero> getSenderosParque(std::string nombre);
        std::list<ruta> getRutasSendero(std::string nombre);
        std::list<visitante> getTodosVisitantes();
        std::list<visitante> getVisitantesRuta(std::string nombreruta);
        std::list<monitor> getTodosMonitores();

        void borrarParque(const parque &p);
        void borrarSendero(const sendero &s, const parque &p);
        void borrarRuta(const ruta &r, const sendero &s, const parque &p);
        void borrarMonitor(const monitor &m);
        void borrarVisitanteRuta(const visitante &v, const ruta &r, const sendero &s, const parque &p);
        void borrarVisitante(const visitante &v);


        void guardarParque(const parque &p);
        void guardarSendero(const sendero &s, std::string nombreParque);
        void guardarRuta(const ruta &r, std::string nombreSendero, std::string nombreParque);
        void guardarVisitanteARuta(const visitante &v, std::string idRuta, std::string nombreSendero, std::string nombreParque);
        void guardarVisitante(const visitante &v);
        void guardarMonitor(const monitor &m);

        parque busquedaParque(string nombre);
        sendero busquedaSendero(string nombreparque, string nombresendero);
        ruta busquedaRuta(string nombreparque, string nombresendero, string nombreruta);
        monitor busquedaMonitor(string nombre);
        visitante busquedaVisitanteRuta(string nombreparque, string nombresendero, string nombreruta, string dni);
        visitante busquedaVisitante(string dni);
};

#endif
