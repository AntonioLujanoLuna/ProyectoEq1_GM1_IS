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
        _instance = new FileIO("parques.txt"); //Archivo de parques default
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

int FileIO::existsMonitor (std::string dni){
        std::ifstream file("monitores.txt");
    if (file) {
        int count = 0;
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
            std::string aux;
            file >> aux;
            if (aux == dni) {
                file.close();
                return count;
            }
            for (int i = 0; i < 6; i++) {
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

int FileIO::existsVisitanteARuta (std::string dni, std::string nombreRuta, std::string nombreSendero, std::string nombreParque){
    std::ifstream file(nombreParque + "_" + nombreSendero + "_" + nombreRuta + ".txt");
    if (file) {
        int count = 0;
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
            std::string aux;
            file >> aux;
            if (aux == dni) {
                file.close();
                return count;
            }
            for (int i = 0; i < 4; i++) {
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

int FileIO::existsVisitante(std::string dni){
std::ifstream file("visitantes.txt");
    if (file) {
        int count = 0;
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
            std::string aux;
            file >> aux;
            if (aux == dni) {
                file.close();
                return count;
            }
            for (int i = 0; i < 4; i++) {
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

std::list<monitor> FileIO::getTodosMonitores(){
    std::list<monitor> monitores;

    std::ifstream file("monitores.txt");
    if (file) {
        while (!file.eof()) {
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            monitor p;
            std::string aux;

            getline(file, aux);
            p.setDNI(aux);

            getline(file, aux);
            p.setNombreCompleto(aux);

            getline(file, aux);
            p.setNumeroDeTlfn(aux);

            getline(file, aux);
            p.setFechaDeNacimiento(aux);

            getline(file, aux);
            p.setCondicion(aux);

            getline(file, aux);
            if(aux=="true"){
                p.setDisponibilidad(true);
            }else p.setDisponibilidad(false);

            monitores.push_back(p);
        }

        file.close();
    }
    else {
        std::cerr << "couldn't open <" << _path << ">" << std::endl;
    }
    return monitores;
}


std::list<sendero> FileIO::getSenderosParque (std::string nombre) {
    std::list<sendero> senderos;
    std::string nombresendero = nombre +"_senderos";
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

            c.setRutas(getRutasSendero(p.getNombre() + "_" + s.getNombre());

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
    std::string nombreruta = nombresendero + "_rutas";
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
            c.setGrupoVisitantes(getVisitantesRuta(nombresendero + "_" + c.getIdentificador));

            rutas.push_back(c);
        }
        file.close();
    }
    else {
        std::cerr << "couldn't open <" << _path << ">" << std::endl;
    }
    return rutas;
}

std::list<visitante> FileIO::getVisitantesRuta(std::string nombreruta){
    std::list<visitante> visitantes;
    std::string fichero = nombreruta + ".txt";
    std::ifstream file(fichero);
    if (file) {
        while (!file.eof()) {
            //Checks if file is empty
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }

            visitante c;
            std::string aux;

            getline(file, aux);
            c.setDNI(aux);

            for (int i = 0; i < 4; i++) {
                file.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }

            visitante.push_back(c);
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
    std::string nombreParque = p.getNombre();
    std::string sys = "rm " + nombreParque + "*.txt";
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

 void FileIO::borrarMonitor (const monitor &m){
    std::list<monitor> monitores = getInstance()->getTodosMonitores();
    std::ofstream file("monitores.txt");
    if (file) {
        for (monitor &monitor : monitor) {
            if (monitor.getDNI() != m.getDNI()) {
                file << monitor.getDNI()                << std::endl;
                file << monitor.getNombreCompleto()     << std::endl;
                file << monitor.getNumeroDeTlfn()       << std::endl;
                file << monitor.getFechaDeNacimiento()  << std::endl;
                file << monitor.getCondicion()          << std::endl;
                file << monitor.getDisponibilidad()     << std::endl;
            }
        }
        file.close();
    }
    std::list<parque> parques = getInstance()->getTodosParques();
    std::ofstream file(_path);
    if (file){
        for(parque &parque : parques){
            std::list<sendero> senderos = getInstance()->getSenderosParque(parque.getNombre());
            std::ofstream senderosfile(parque.getNombre() + "_senderos.txt");
            if (senderosfile){
                for(sendero &sendero : senderos){
                    std::list<ruta> rutas = getInstance()->getRutasSendero(parque.getNombre() + "_" + sendero.getNombre());
                    std::ofstream rutasfile(parque.getNombre() + "_" + sendero.getNombre() + "_rutas.txt");
                    if (rutasfile){
                        for(ruta &ruta : rutas){
                            if(ruta.getMonitorAsociado() != m.getDNI()){
                                rutasfile << ruta.getIdentificador()          << std::endl;
                                rutasfile << ruta.getDificultad()        << std::endl;
                                rutasfile << ruta.getMonitorAsociado()     << std::endl;
                                rutasfile << ruta.getFecha()  << std::endl;
                                rutasfile << ruta.getHora()  << std::endl;
                                rutasfile << ruta.getDuracionEstimada()  << std::endl;
                                rutasfile << ruta.getBicicleta()  << std::endl;
                                rutasfile << ruta.getGrupoVisitantes() << std::endl;
                            }
                            else{
                                rutasfile << ruta.getIdentificador()          << std::endl;
                                rutasfile << ruta.getDificultad()        << std::endl;
                                rutasfile <<     ""    << std::endl;
                                rutasfile << ruta.getFecha()  << std::endl;
                                rutasfile << ruta.getHora()  << std::endl;
                                rutasfile << ruta.getDuracionEstimada()  << std::endl;
                                rutasfile << ruta.getBicicleta()  << std::endl;
                                rutasfile << ruta.getGrupoVisitantes() << std::endl;
                            }
                        }
                        rutasfile.close();
                    }
                }
                senderosfile.close();
            }
        }
        file.close();
    }

}

void FileIO::borrarSendero (const sendero &s, const parque &p) {
    std::string nombreParque = p.getNombre();
    std::string nombreSendero = s.getNombre();
    std::string sys = "rm " + nombreParque + "_" + nombreSendero + "*.txt";
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
    std::string nombreParque = p.getNombre();
    std::string nombreSendero = s.getNombre();
    std::string nommbreRuta = r.getIdentificador();
    std::string sys = "rm " + nombreParque + "_" + nombreSendero + "_" + nommbreRuta + ".txt";
    system(sys);

    std::list<ruta> rutas = getInstance()->getRutasSendero(p.getNombre() + "_" + s.getNombre());
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
                file << ruta.getGrupoVisitantes() << std::endl;
            }
        }
        file.close();
    }
}

void FileIO::borrarVisitante(const visitante &v){
    std::list<visitante> visitantes = getInstance()->getTodosVisitantes();
    std::ofstream file("visitantes.txt");
    if (file) {
        for (visitante &visitante : visitantes) {
            if (visitante.getDNI() != v.getDNI()) {
                file << visitante.getDNI()          << std::endl;
                file << visitante.getNombreCompleto()        << std::endl;
                file << visitante.getNumeroDeTlfn()     << std::endl;
                file << visitante.getFechaDeNacimiento()  << std::endl;
                file << visitante.getCondicion()  << std::endl;
            }
        }
        file.close();
    }
    std::list<parque> parques = getInstance()->getTodosParques();
    std::ofstream file(_path);
    if (file){
        for(parque &parque : parques){
            std::list<sendero> senderos = getInstance()->getSenderosParque(parque.getNombre());
            std::ofstream senderosfile(parque.getNombre() + "_senderos.txt");
            if (senderosfile){
                for(sendero &sendero : senderos){
                    std::list<ruta> rutas = getInstance()->getRutasSendero(parque.getNombre() + "_" + sendero.getNombre());
                    std::ofstream rutasfile(parque.getNombre() + "_" + sendero.getNombre() + "_rutas.txt");
                    if (rutasfile){
                        for(ruta &ruta : rutas){
                            std::list<visitante> visitantes = getInstance()->getVisitantesRuta(parque.getNombre() + "_" + sendero.getNombre() + "_" + ruta.getIdentificador());
                            std::ofstream visitantesfile(parque.getNombre() + "_" + sendero.getNombre() + "_" + ruta.getIdentificador() + ".txt");
                            if(visitantesfile){
                                for(visitante &visitante : visitantes){
                                    if(visitante.getDNI() != v.getDNI()){
                                        file << visitante.getDNI()          << std::endl;
                                        file << visitante.getNombreCompleto()        << std::endl;
                                        file << visitante.getNumeroDeTlfn()     << std::endl;
                                        file << visitante.getFechaDeNacimiento()  << std::endl;
                                        file << visitante.getCondicion()  << std::endl;
                                    }
                                }
                                visitantesfile.close();
                            }
                        }
                        rutasfile.close();
                    }
                }
                senderosfile.close();
            }
        }
        file.close();
    }
}

void FileIO::borrarVisitanteRuta(const visitante &v, const ruta &r, const sendero &s, const parque &p){
    std::string nombreParque = p.getNombre();
    std::string nombreSendero = s.getNombre();
    std::string nommbreRuta = r.getIdentificador();
    std::string sys = nombreParque + "_" + nombreSendero + "_" + nombreRuta;
    std::list<visitante> visitantes = getInstance()->getVisitantesRuta(sys);
    std::ofstream file(sys + ".txt");
    if (file) {
        for (visitante &visitante : visitantes) {
            if (visitante.getDNI() != v.getDNI()) {
                file << visitante.getDNI()          << std::endl;
                file << visitante.getNombreCompleto()        << std::endl;
                file << visitante.getNumeroDeTlfn()     << std::endl;
                file << visitante.getFechaDeNacimiento()  << std::endl;
                file << visitante.getCondicion()  << std::endl;
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

                        std::ofstream visitantesFile;

                        visitantesFile.open(p.getNombre + "_" + s.getNombre() + "_" + r.getIdentificador() + ".txt");
                        for(visitante &v : r.getGrupoVisitante()){
                            visitantesFile << v.getDNI() << std::endl;
                            visitantesFile << v.getNombreCompleto() << std::endl;
                            visitantesFile << v.getNumeroDeTlfn() << std::endl;
                            visitantesFile << v.getFechaDeNacimiento() << std::endl;
                            visitantesFile << v.getCondicion() << std::endl;
                        }
                        visitantesFile.close();
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

                        std::ofstream visitantesFile;

                        visitantesFile.open(p.getNombre + "_" + s.getNombre() + "_" + r.getIdentificador() + ".txt");
                        for(visitante &v : r.getGrupoVisitante()){
                            visitantesFile << v.getDNI() << std::endl;
                            visitantesFile << v.getNombreCompleto() << std::endl;
                            visitantesFile << v.getNumeroDeTlfn() << std::endl;
                            visitantesFile << v.getFechaDeNacimiento() << std::endl;
                            visitantesFile << v.getCondicion() << std::endl;
                        }
                        visitantesFile.close();
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

                        std::ofstream visitantesFile;

                        visitantesFile.open(p.getNombre + "_" + s.getNombre() + "_" + r.getIdentificador() + ".txt");
                        for(visitante &v : r.getGrupoVisitante()){
                            visitantesFile << v.getDNI() << std::endl;
                            visitantesFile << v.getNombreCompleto() << std::endl;
                            visitantesFile << v.getNumeroDeTlfn() << std::endl;
                            visitantesFile << v.getFechaDeNacimiento() << std::endl;
                            visitantesFile << v.getCondicion() << std::endl;
                        }
                        visitantesFile.close();
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

                        std::ofstream visitantesFile;

                        visitantesFile.open(p.getNombre + "_" + s.getNombre() + "_" + r.getIdentificador() + ".txt");
                        for(visitante &v : r.getGrupoVisitante()){
                            visitantesFile << v.getDNI() << std::endl;
                            visitantesFile << v.getNombreCompleto() << std::endl;
                            visitantesFile << v.getNumeroDeTlfn() << std::endl;
                            visitantesFile << v.getFechaDeNacimiento() << std::endl;
                            visitantesFile << v.getCondicion() << std::endl;
                        }
                        visitantesFile.close();
                    }
                    rutasFile.close();
        }
        file.close();
    }
}

void FileIO::guardarRuta(const ruta &r, std::string nombreSendero, std::string nombreParque){
int result = existsRuta(r.getIdentificador(), nombreSendero, nombreParque);
    if (result >=0){
        std::list<ruta> rutas = getInstance()->getRutasSendero(p.getNombre() + "_" + s.getNombre());
        std::ofstream file(nombreParque + "_" + nombreSendero + "_rutas.txt");
        if (file) {
            for (ruta &ruta : rutas) {
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

                std::ofstream visitantesFile;

                visitantesFile.open(p.getNombre + "_" + s.getNombre() + "_" + r.getIdentificador() + ".txt");
                for(visitante &v : r.getGrupoVisitante()){
                    visitantesFile << v.getDNI() << std::endl;
                    visitantesFile << v.getNombreCompleto() << std::endl;
                    visitantesFile << v.getNumeroDeTlfn() << std::endl;
                    visitantesFile << v.getFechaDeNacimiento() << std::endl;
                    visitantesFile << v.getCondicion() << std::endl;
                }
                visitantesFile.close();
            }
        }
        file.close();
    }
    else {
        std::fstream file(nombreParque + "_" + nombreSendero + "_rutas.txt", fstream::out | fstream::app);
        if (file){
                file << r.getIdentificador() << std::endl;
                file << r.getDificultad() << std::endl;
                file << r.getMonitorAsociado() << std::endl;
                file << r.getFecha() << std::endl;
                file << r.getHora() << std::endl;
                file << r.getDuracionEstimada() << std::endl;
                file << r.getBicicleta() << std::endl;

                std::ofstream visitantesFile;

                visitantesFile.open(p.getNombre + "_" + s.getNombre() + "_" + r.getIdentificador() + ".txt");
                for(visitante &v : r.getGrupoVisitante()){
                    visitantesFile << v.getDNI() << std::endl;
                    visitantesFile << v.getNombreCompleto() << std::endl;
                    visitantesFile << v.getNumeroDeTlfn() << std::endl;
                    visitantesFile << v.getFechaDeNacimiento() << std::endl;
                    visitantesFile << v.getCondicion() << std::endl;
                }
                visitantesFile.close();
        }
        file.close();
    }
}

void FileIO::guardarVisitante(const visitante &v){
    int result = existsVisitante(v.getDNI());
    if (result >=0){
        std::list<visitante> visitantes = getInstance()->getTodosVisitantes();
        std::ofstream visitantesFile("visitantes.txt");
        if (visitantesFile) {
            for (visitante &visitante : visitantes) {
                if (visitante.getDNI() == v.getDNI()) {
                    visitante = v;
                    }
                    visitantesFile << v.getDNI() << std::endl;
                    visitantesFile << v.getNombreCompleto() << std::endl;
                    visitantesFile << v.getNumeroDeTlfn() << std::endl;
                    visitantesFile << v.getFechaDeNacimiento() << std::endl;
                    visitantesFile << v.getCondicion() << std::endl;
                }
                file.close();
            }
        }
    else {
        std::ofstream visitantesFile("visitantes.txt");
        if (visitantesFile) {
            visitantesFile << v.getDNI() << std::endl;
            visitantesFile << v.getNombreCompleto() << std::endl;
            visitantesFile << v.getNumeroDeTlfn() << std::endl;
            visitantesFile << v.getFechaDeNacimiento() << std::endl;
            visitantesFile << v.getCondicion() << std::endl;
        }
        file.close();
    }
}

void FileIO::guardarVisitanteARuta(const visitante &v, std::string idRuta, std::string nombreSendero, std::string nombreParque){
int result = existsVisitanteARuta(v.getDNI(), idRuta, nombreSendero, nombreParque);
    if (result >=0){
        std::list<visitante> visitantes = getInstance()->getVisitantesRuta(nombreParque + "_" + nombreSendero + "_" + idRuta);
        std::ofstream file(nombreParque + "_" + nombreSendero + "_" + idRuta + ".txt");
        if (file) {
            for (visitante &visitante : visitantes) {
                if (visitante.getDNI() == v.getDNI()) {
                    visitante = v;
                }
                visitantesFile << v.getDNI() << std::endl;
                visitantesFile << v.getNombreCompleto() << std::endl;
                visitantesFile << v.getNumeroDeTlfn() << std::endl;
                visitantesFile << v.getFechaDeNacimiento() << std::endl;
                visitantesFile << v.getCondicion() << std::endl;
            }
            file.close();
        }
    }
    else {
        std::ofstream file(nombreParque + "_" + nombreSendero + "_" + idRuta + ".txt");
        if (file) {
                visitantesFile << v.getDNI() << std::endl;
                visitantesFile << v.getNombreCompleto() << std::endl;
                visitantesFile << v.getNumeroDeTlfn() << std::endl;
                visitantesFile << v.getFechaDeNacimiento() << std::endl;
                visitantesFile << v.getCondicion() << std::endl;
        }
        file.close();
    }
}

void FileIO::guardarMonitor(const monitor &m){
    int result existsMonitor(m.getDNI());
    if(result >= 0){
        std::list<monitor> monitores = getInstance()->getTodosMonitores();
        std::ofstream file("monitores.txt");
        if (file) {
            for (monitor &monitor : monitor) {
                if (monitor.getDNI() == m.getDNI()) {
                    monitor = m;
                }
                file << m.getDNI() << std::endl;
                file << m.getNombreCompleto() << std::endl;
                file << m.getNumeroDeTlfn() << std::endl;
                file << m.getFechaDeNacimiento() << std::endl;
                file << m.getCondicion() << std::endl;
                file << m.getDisponibilidad() << std::endl;
            }
            file.close();
        }
    }
    else {
        std::ofstream file("monitores.txt");
        if (file) {
                file << m.getDNI() << std::endl;
                file << m.getNombreCompleto() << std::endl;
                file << m.getNumeroDeTlfn() << std::endl;
                file << m.getFechaDeNacimiento() << std::endl;
                file << m.getCondicion() << std::endl;
                file << m.getDisponibilidad() << std::endl;
        }
        file.close();
    }
}

parque FileIO::busquedaParque(std::string nombre){
    std::list<parque> parques = getInstance->getTodosParques();
    for(parque &parque : parques){
        if(parque.getNombre() == nombre){
            return parque;
        }
    }
}

sendero FileIO::busquedaSendero(std::string nombreparque, std::string nombresendero){
    std::list<parque> parques = getInstance->getTodosParques();
        for(parque &parque : parques){
            if(parque.getNombre() == nombreparque){
                std::list<sendero> senderos = getInstance->getSenderosParque(nombreparque);
                for(sendero &sendero : senderos){
                    if(sendero.getNombre() == nombresendero){
                        return sendero;
                    }
                }
            }
        }
}

ruta FileIO::busquedaRuta(std::string nombreparque, std::string nombresendero, std::string nombreruta) {
    std::list<parque> parques = getInstance->getTodosParques();
        for(parque &parque : parques){
            if(parque.getNombre() == nombreparque){
                std::list<sendero> senderos = getInstance->getSenderosParque(nombreparque);
                for(sendero &sendero : senderos){
                    if(sendero.getNombre() == nombresendero){
                        std::list<ruta> rutas = getInstance->getRutasSendero(nombreparque + "_" + nombresendero);
                        for(ruta &ruta : rutas){
                            if(ruta.getIdentificador() == nombreruta){
                                return ruta;
                            }
                        }
                    }
                }
            }
        }
}

monitor FileIO::busquedaMonitor(std::string dni){
    std::list<monitor> monitores = getInstance->getTodosMonitores();
    for(monitor &monitor : monitores){
        if (monitor.getDNI() == dni){
            return monitor;
        }
    }
}

visitante FileIO::busquedaVisitanteRuta(std::string nombreparque, std::string nombresendero, std::string nombreruta, std::string dni){
    std::list<parque> parques = getInstance->getTodosParques();
        for(parque &parque : parques){
            if(parque.getNombre() == nombreparque){
                std::list<sendero> senderos = getInstance->getSenderosParque(nombreparque);
                for(sendero &sendero : senderos){
                    if(sendero.getNombre() == nombresendero){
                        std::list<ruta> rutas = getInstance->getRutasSendero(nombreparque + "_" + nombresendero);
                        for(ruta &ruta : rutas){
                            if(ruta.getIdentificador() == nombreruta){
                                std::list<visitante> visitantes = getInstance->getVisitantesRuta(nombreparque + "_" + nombresendero + "_" + nombreruta)
                                for(visitante &visitante : visitantes){
                                    if(visitante.getDNI() == dni){
                                        return visitante;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
}

visitante FileIO::busquedaVisitante(std::string dni){
    std::list<visitante> visitantes = getInstance->getTodosVisitantes();
    for(visitante &visitante : visitantes){
        if (visitante.getDNI() == dni){
            return visitante;
        }
    }
}
