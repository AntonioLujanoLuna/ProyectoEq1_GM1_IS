//fileIO.h
//Proyecto IS

#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <list>
#include <fstream>
#include "senderos.h"
#include "parques.h"

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

        std::list<sendero> getSenderos (std::string nombreParque);
        std::list<ruta> getRutas (std::string Nombresendero);

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
        std::list<parque> getTodosParques(); 
        std::list<sendero> getSenderosParque(std::string nombre);
        std::list<ruta> getRutasSendero(std::string nombre);
        std::list<visitante> getTodosVisitantes();
        void borrarParque(const parque &p);
        void borrarSendero(const sendero &s, const parque &p);
        void FileIO::borrarRuta(const ruta &r, const sendero &s, const parque &p);
        void guardarParque(const parque &p);         
        void guardarSendero(const sendero &p, std::string nombreParque); 
        void guardarRuta(const ruta &r, std::string nombreSendero, std::string nombreParque);

};

#endif