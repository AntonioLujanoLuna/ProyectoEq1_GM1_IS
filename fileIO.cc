#include "fileIO.h"

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <limits>
#include <ctime>

FileIO* FileIO::_instance = NULL;

FileIO* FileIO::getInstance () {
    if (_instance == NULL) {
        _instance = new FileIO("parques.txt"); //Archivo de pacientes default
    }

    return _instance;
}

int FileIO::existsParque (std::string nombre) {
    std::ifstream file(_path);
    if (file) {
        int count = 0;
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
            std::string aux;
            file >> aux;
            if (aux == nombre) {
                file.close();
                return count;
            }
            for (int i = 0; i < 5; i++) {
                file.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            count++;
            file.get();
        }
        file.close();
        return -1;
    }
    else {
        return -2;
    }
}

int FileIO::existsSendero (std::string nombreSendero, std::string nombreParque) {
    std::ifstream file(nombreParque + "_senderos.txt");
    if (file) {
        int count = 0;
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
            std::string aux;
            file >> aux;
            if (aux == nombreSendero) {
                file.close();
                return count;
            }
            for (int i = 0; i < 3; i++) {
                file.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            count++;
            file.get();
        }
        file.close();
        return -1;
    }
    else {
        return -2;
    }
}

int FileIO::existsRuta (std::string nombreRuta, std::string nombreSendero, std::string nombreParque){
        std::ifstream file(nombreParque + "_" + nombreSendero + "_rutas.txt");
    if (file) {
        int count = 0;
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
            std::string aux;
            file >> aux;
            if (aux == nombreRuta) {
                file.close();
                return count;
            }
            for (int i = 0; i < 7; i++) {
                file.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            count++;
            file.get();
        }
        file.close();
        return -1;
    }
    else {
        return -2;
    }
}

std::list<parque> FileIO::getTodosParques () {
    std::list<parque> parques;
    
    std::ifstream file(_path);
    if (file) {
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            parque p;
            std::string aux;

            getline(file, aux);
            p.setNombre(aux);

            getline(file, aux);
            p.setFechaNombramientoParque(aux);

            getline(file, aux);
            p.setTamano(std::stoi(aux));

            getline(file, aux);
            p.setPremios(aux);

            getline(file, aux);
            p.setDescripcion(aux);

            getline(file, aux);
            p.setDisponibilidad(aux);

            p.setSenderos(getSenderosParque(p.getNombre()));

            parques.push_back(p);
        }

        file.close();
    }
    else {
        std::cerr << "couldn't open <" << _path << ">" << std::endl;
    }
    return parques;
}

std::list<sendero> FileIO::getSenderosParque (std::string nombre) {
    std::list<sendero> senderos;
    string nombresendero = nombre +"_senderos";
    std::ifstream file(nombresendero + ".txt");
    if (file) {
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            sendero c;
            std::string aux;

            getline(file, aux);
            c.setNombre(aux);

            getline(file, aux);
            c.setLongitud(aux);

            getline(file, aux);
            c.setDescripcion(aux);

            getline(file, aux);
            c.setDisponibilidad(disponibilidad);

            c.setRutas(getRutasSendero(nombre + "_" + c.getNombre()));

            senderos.push_back(c);
        }
        file.close();
    }
    else {
        std::cerr << "couldn't open <" << _path << ">" << std::endl;
    }
    return senderos;
}

std::list<ruta> FileIO::getRutasSendero (std::string nombresendero) {
    std::list<ruta> rutas;
    string nombreruta = nombresendero + "_rutas";
    std::ifstream file(nombreruta + ".txt");
    if (file) {
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            ruta c;
            std::string aux;

            getline(file, aux);
            c.setIdentidicador(aux);
            
            getline(file, aux);
            c.setDificultad(aux);

            getline(file, aux);
            c.setMonitorAsociado(aux);

            getline(file, aux);
            c.setFecha(aux);

            getline(file, aux);        
            c.setHora(aux);

            getline(file, aux);
            c.setDuracionEstimada(aux);
            
            getline(file, aux);            
            c.setBicicleta(aux);
            
            getline(file, aux);
            c.setGrupoVisitantes(aux);

            rutas.push_back(c);
        }
        file.close();
    }
    else {
        std::cerr << "couldn't open <" << _path << ">" << std::endl;
    }
    return rutas;
}

std::list<visitante> FileIO::getTodosVisitantes(){
    std::list<visitante> visitantes;
    
    std::ifstream file("visitantes.txt");
    if (file) {
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            visitante p;
            std::string aux;

            getline(file,aux);
            setDNI(DNI);

            getline(file,aux);
            setNombreCompleto(nombreCompleto);
            
            getline(file,aux);
            setNumeroDeTlfn(Tlfn);
            
            getline(file,aux);
            setFechaDeNacimiento(fechaDeNacimiento);
            
            getline(file,aux);
            setCondicion(condicion);

            visitantes.push_back(p);
        }

        file.close();
    }
    else {
        std::cerr << "couldn't open <" << _path << ">" << std::endl;
    }
    return visitantes;
}

void FileIO::borrarParque (const parque &p) {
    string nombreParque = p.getNombre();
    string sys = "rm " + nombreParque + "*.txt";
    system(sys);

    std::list<parque> parques = getInstance()->getTodosParques();
    std::ofstream file(_path);
    if (file) {
        for (parque &parque : parques) {
            if (parque.getNombre() != p.getNombre()) {
                file << parque.getNombre()                    << std::endl;
                file << parque.getFechaNombramientoParque()   << std::endl;
                file << parque.getTamano()                    << std::endl;
                file << parque.getPremios()                   << std::endl;
                file << parque.getDescripcion()               << std::endl;
                file << parque.getDisponibilidad()            << std::endl;
            }
        }
        file.close();
    }
}
void FileIO::borrarSendero (const sendero &s, const parque &p) {
    string nombreParque = p.getNombre();
    string nombreSendero = s.getNombre();
    string sys = "rm " + nombreParque + "_" + nombreSendero + "*.txt";
    system(sys);

    std::list<sendero> senderos = getInstance()->getSenderosParque(nombreParque);
    std::ofstream file(p.getNombre() + "senderos.txt");
    if (file) {
        for (sendero &sendero : senderos) {
            if (sendero.getNombre() != s.getNombre()) {
                file << sendero.getNombre()          << std::endl;
                file << sendero.getLongitud()        << std::endl;
                file << sendero.getDescripcion()     << std::endl;
                file << sendero.getDisponibilidad()  << std::endl;
            }
        }
        file.close();
    }
}

void FileIO::borrarRuta(const ruta &r, const sendero &s, const parque &p){
    string nombreParque = p.getNombre();
    string nombreSendero = s.getNombre();
    string nommbreRuta = r.getIdentificador();
    string sys = "rm " + nombreParque + "_" + nombreSendero + "_" + nommbreRuta + ".txt";
    system(sys);

    std::list<ruta> rutas = getInstance()->getRutasSendero(nombreParque + "_senderos");
    std::ofstream file(p.getNombre() + "_" + s.getNombre + "_rutas.txt");
    if (file) {
        for (ruta &ruta : rutas) {
            if (ruta.getIdentificador() != r.getIdentificador()) {
                file << ruta.getIdentificador()          << std::endl;
                file << ruta.getDificultad()        << std::endl;
                file << ruta.getMonitorAsociado()     << std::endl;
                file << ruta.getFecha()  << std::endl;
                file << ruta.getHora()  << std::endl;
                file << ruta.getDuracionEstimada()  << std::endl;
                file << ruta.getBicicleta()  << std::endl;
                file << ruta.setGrupoVisitantes() << std::endl;
            }
        }
        file.close();
    }
}

void FileIO::guardarParque (const parque &p) {
    int result = existsParque(p.getNombre());
    if (result >= 0) {
        std::list<parque> parques = getInstance()->getTodosParques();
        std::ofstream file(_path);
        if (file) {
            for (parque &parque : parques) {
                if (parque.getNombre() == p.getNombre()) {
                    parque = p;
                }
                file << parque.getNombre()              << std::endl;
                file << parque.getFechaNombramientoParque()   << std::endl;
                file << parque.getTamano()         << std::endl;
                file << parque.getPremios()        << std::endl;
                file << parque.getDescripcion()  << std::endl;
                file << parque.getDisponibilidad() << std::endl;

                std::ofstream senderosFile;

                senderosFile.open(p.getNombre() + "_senderos.txt");
                for (sendero &s : p.getSenderos()) {
                    senderosFile << s.getNombre()    << std::endl;
                    senderosFile << s.getLongitud() << std::endl;
                    senderosFile << s.getDescripcion()     << std::endl;
                    senderosFile << s.getDisponibilidad()     << std::endl;

                    std::ofstream rutasFile;

                    rutasFile.open(p.getNombre + "_" + s.getNombre() + "_rutas.txt");
                    for(ruta &r : s.getRutas()){
                        rutasFile << r.getIdentificador() << std::endl;
                        rutasFile << r.getDificultad() << std::endl;
                        rutasFile << r.getMonitorAsociado() << std::endl;
                        rutasFile << r.getFecha() << std::endl;
                        rutasFile << r.getHora() << std::endl;
                        rutasFile << r.getDuracionEstimada() << std::endl;
                        rutasFile << r.getBicicleta() << std::endl;
                        rutasFile << r.getGrupoVisitante() << std::endl;

                    }
                    rutasFile.close();
                }
                senderosFile.close();
            }
            file.close();
        }
    }
    else {
        std::fstream file(_path, fstream::out | fstream::app);
        if (file) {
                file << parque.getNombre()              << std::endl;
                file << parque.getFechaNombramientoParque()   << std::endl;
                file << parque.getTamano()         << std::endl;
                file << parque.getPremios()        << std::endl;
                file << parque.getDescripcion()  << std::endl;
                file << parque.getDisponibilidad() << std::endl;

                std::ofstream senderosFile;

                senderosFile.open(p.getNombre() + "_senderos.txt");
                for (sendero &s : p.getSenderos()) {
                    senderosFile << s.getNombre()    << std::endl;
                    senderosFile << s.getLongitud() << std::endl;
                    senderosFile << s.getDescripcion()     << std::endl;
                    senderosFile << s.getDisponibilidad()     << std::endl;

                    std::ofstream rutasFile;

                    rutasFile.open(p.getNombre + "_" + s.getNombre() + "_rutas.txt");
                    for(ruta &r : s.getRutas()){
                        rutasFile << r.getIdentificador() << std::endl;
                        rutasFile << r.getDificultad() << std::endl;
                        rutasFile << r.getMonitorAsociado() << std::endl;
                        rutasFile << r.getFecha() << std::endl;
                        rutasFile << r.getHora() << std::endl;
                        rutasFile << r.getDuracionEstimada() << std::endl;
                        rutasFile << r.getBicicleta() << std::endl;
                        rutasFile << r.getGrupoVisitante() << std::endl;

                    }
                    rutasFile.close();
                }
                senderosFile.close();
            }
            file.close();
        }
    }
}

void FileIO::guardarSendero (const sendero &s, std::string nombreParque) {
    int result = existsSendero(s.getNombre(), nombreParque);
    if (result >=0){
        std::list<sendero> senderos = getInstance()->getSenderosParque(nombreParque);
        std::ofstream file(nombreParque + "_senderos.txt");
        if (file) {
            for (sendero &sendero : senderos) {
                if (sendero.getNombre() == s.getNombre()) {
                    sendero = s;
                }
                    file << s.getNombre()    << std::endl;
                    file << s.getLongitud() << std::endl;
                    file << s.getDescripcion()     << std::endl;
                    file << s.getDisponibilidad()     << std::endl;

                    std::ofstream rutasFile;

                    rutasFile.open(nombreParque + "_" + s.getNombre() + "_rutas.txt");
                    for(ruta &r : s.getRutas()){
                        rutasFile << r.getIdentificador() << std::endl;
                        rutasFile << r.getDificultad() << std::endl;
                        rutasFile << r.getMonitorAsociado() << std::endl;
                        rutasFile << r.getFecha() << std::endl;
                        rutasFile << r.getHora() << std::endl;
                        rutasFile << r.getDuracionEstimada() << std::endl;
                        rutasFile << r.getBicicleta() << std::endl;
                        rutasFile << r.getGrupoVisitante() << std::endl;

                    }
                    rutasFile.close();
                }
            }
            file.close();
        }
    }
    else {
        std::fstream file(nombreParque + "_senderos.txt", fstream::out | fstream::app);
        if (file){
            for (sendero &sendero : senderos) {
                    file << s.getNombre()    << std::endl;
                    file << s.getLongitud() << std::endl;
                    file << s.getDescripcion()     << std::endl;
                    file << s.getDisponibilidad()     << std::endl;

                    std::ofstream rutasFile;

                    rutasFile.open(nombreParque + "_" + s.getNombre() + "_rutas.txt");
                    for(ruta &r : s.getRutas()){
                        rutasFile << r.getIdentificador() << std::endl;
                        rutasFile << r.getDificultad() << std::endl;
                        rutasFile << r.getMonitorAsociado() << std::endl;
                        rutasFile << r.getFecha() << std::endl;
                        rutasFile << r.getHora() << std::endl;
                        rutasFile << r.getDuracionEstimada() << std::endl;
                        rutasFile << r.getBicicleta() << std::endl;
                        rutasFile << r.getGrupoVisitante() << std::endl;

                    }
                    rutasFile.close();
                }
        }
        file.close();
    }
}

void FileIO::guardarRuta(const ruta &r, std::string nombreSendero, std::string nombreParque){
int result = existsRuta(r.getIdentificador(), nombreSendero, nombreParque);
    if (result >=0){
        std::list<ruta> rutas = getInstance()->getRutasSendero(nombreParque + "_" + nombreSendero);
        std::ofstream file(nombreParque + "_" + nombreSendero + "_rutas.txt");
        if (file) {
            for (ruta &ruta : ruta) {
                if (ruta.getIdentificador() == r.getIdentificador()) {
                    ruta = r;
                }
                file << r.getIdentificador() << std::endl;
                file << r.getDificultad() << std::endl;
                file << r.getMonitorAsociado() << std::endl;
                file << r.getFecha() << std::endl;
                file << r.getHora() << std::endl;
                file << r.getDuracionEstimada() << std::endl;
                file << r.getBicicleta() << std::endl;
                file << r.getGrupoVisitante() << std::endl;
            }
        }
        file.close();
    }
    else {
        std::fstream file(nombreParque + "_" + nombreSendero + "_rutas.txt", fstream::out | fstream::app);
        if (file){
            for (ruta &ruta : ruta) {
                file << r.getIdentificador() << std::endl;
                file << r.getDificultad() << std::endl;
                file << r.getMonitorAsociado() << std::endl;
                file << r.getFecha() << std::endl;
                file << r.getHora() << std::endl;
                file << r.getDuracionEstimada() << std::endl;
                file << r.getBicicleta() << std::endl;
                file << r.getGrupoVisitante() << std::endl;
            }
        }
        file.close();
    }    
}