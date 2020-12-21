//impresion.cc
//Proyecto IS

#include "impresion.h"

void mostrarSenderosAsociados(const parque &p){

  std::list<sendero> senderos=getInstance()->getSenderosParque(p.getNombre());
  for(sendero &sendero: senderos)
  {
    std::cout<<sendero.getNombre()<<endl;
    std::cout<<"\n";
  }
}

void imprimirParque(const parque &p){
std::cout<<"DATOS DEL PARQUE: \n";
std::cout<<"NOMBRE: "<<p.getNombre()<<endl;
std::cout<<"FECHA DE NOMBRAMIENTO: "<<p.getFechaNombramientoParque()<<endl;
std::cout<<"TAMANO: "<<p.getTamano()<<endl;
std::cout<<"PREMIOS: "<<p.getPremios()<<endl;
std::cout<<"DESCRIPCION: "<<p.getDescripcion()<<endl;
std::cout<<"DISPONIBILIDAD: "<<p.getDisponibilidad()<<endl;
std::cout<<"SENDEROS ASOCIADOS: \n";
mostrarSenderosAsociados(p);

}


void mostrarRutasAsociadas(const sendero &s, const parque &p){
  std::list<ruta> rutas=getInstance()->getRutasSendero(p.getNombre() + "_" + s.getSendero());
  for(ruta &ruta: rutas)
  {
    std::cout<<ruta.getNombre()<<endl;
    std::cout<<"\n";
  }
}

void imprimirSendero(const sendero &s, const parque &p){
std::cout<<"DATOS DEL SENDERO: \n";
std::cout<<"NOMBRE: "<<s.getNombre()<<endl;
std::cout<<"LONGITUD: "<<s.getLongitud()<<endl;
std::cout<<"DESCRIPCION: "<<s.getDescripcion()<<endl;
std::cout<<"DISPONIBILIDAD: "<<s.getDisponibilidad()<<endl;
std::cout<<"RUTAS ASOCIADAS: \n";
this->mostrarRutasAsociadas(s, p);

}


void mostarVisitantesAsociados(const ruta &r, const sendero &s, const parque &p){

  std::list<visitante> visitantes=getInstance()->getVisitantesRuta(p.getNombre() + "_" + s.getNombre() + "_" + this->getIdentificador());
  for(visitante &visitantes: visitantes)
  {
    std::cout<<visitante.getNombreCompleto()<<endl;
    std::cout<<"\n";
   }

}

void imprimirRuta(const ruta &r, const sendero &s, const parque &p){
  std::cout<<"DATOS DE LA RUTA: \n";
  std::cout<<"IDENTIFICADOR: "<<r.getIdentificador()<<endl;
  std::cout<<"DIFICULTAD: "<<r.getDificultad()<<endl;
  std::cout<<"MONITOR ASOCIADO: "<<r.getMonitorAsociado()<<endl;
  std::cout<<"FECHA: "<<r.getFecha()<<endl;
  std::cout<<"HORA: "<<r.getHora()<<endl;
  std::cout<<"DURACION ESTIMADA: "<<r.getDuracionEstimada()<<endl;
  std::cout<<"BICICLETA: "<<r.getBicicleta() << endl;
  this->mostrarVisitantesAsociados(r, s, p);
}


void imprimirVisitante(const visitante &v){
  std::cout<<"DATOS DEL VISITANTE: \n";
  std::cout<<"DNI: "<<v.getDNI()<<endl;
  std::cout<<"NOMBRE: "<<c.getNombreCompleto()<<endl;
  std::cout<<"FECHA DE NACIMIENTO: "<<v.getFechaDeNacimiento()<<endl;
  std::cout<<"NUMERO DE TELEFONO: "<<v.getNumeroDeTlfn()<<endl;
  std::cout<<"CONDICION: "<<v.getCondicion()<<endl;
}

void mostrarTodosVisitantes(){

  std::list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getNombreCompleto()<<endl;
  }
}

void mostrarTodosVisitantesDNI(){

  std::list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getDNI()<<endl;
  }
}

void imprimirMonitor(const monitor &m){
  std::cout<<"DATOS DEL MONITOR: \n";
  std::cout<<"DNI: "<<m.getDNI()<<endl;
  std::cout<<"NOMBRE COMPLETO: "<<m.getNombreCompleto()<<endl;
  std::cout<<"FECHA DE NACIMIENTO: "<<m.getFechaDeNacimiento()<<endl;
  std::cout<<"NUMERO DE TELEFONO: "<<m.getNumeroDeTlfn()<<endl;
  std::cout<<"CONDICION: "<<m.getCondicion()<<endl;
  std::cout<<"DISPONIBILIDAD: "<<m.getDisponibilidad()<<endl;
}

void mostrarTodosMonitoresDNI(){

  std::list<monitor> monitores=getInstance()->getTodosMonitores();
  for(monitor &monitor: monitores)
  {
    std::cout<<monitor.getDNI()<<endl;
  }
}

bool fechaValida (const std::string &str) {
    if (str.size() == 10) {
        //Comprueba el formato
        for (int i = 0; i < 10; i++) {
            if (i == 2 || i == 5) {
                if (str[i] != '/') {
                    return false;
                }
            }
            else {
                if (!std::isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba el mes
        int m = std::stoi(str.substr(3, 2));
        if (m < 1 || m > 12) {
            return false;
        }

        //Comprueba el dia en funcion del mes
        int d = std::stoi(str.substr(0, 2));
        if (d < 1) { return false; }

        switch (m) {
            case  1: return d <= 31;
            case  2: return d <= 28;
            case  3: return d <= 31;
            case  4: return d <= 30;
            case  5: return d <= 31;
            case  6: return d <= 30;
            case  7: return d <= 31;
            case  8: return d <= 31;
            case  9: return d <= 30;
            case 10: return d <= 31;
            case 11: return d <= 30;
            case 12: return d <= 31;
        }
    }
    else {
        return false;
    }

    return true;
}

bool horaValida (const std::string &str) {
    if (str.size() == 5) {
        //Comprueba el formato
        for (int i = 0; i < 5; i++) {
            if (i == 2) {
                if (str[i] != ':') {
                    return false;
                }
            }
            else {
                if (!std::isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba que la hora sea valida
        int h = strGetHora(str);
        if (h < 0 || h > 23) {
            return false;
        }

        //Comprueba que los minutos sean validos
        int m = strGetMinutos(str);
        if (m < 0 || m > 59) {
            return false;
        }
    }
    else {
        return false;
    }

    return true;
}

void mostrarNombresParques(){
  std::list<parque> parques=getInstance()->GetTodosParques();
  for(parque &parque: parques)
  {
    std::cout<<parque.getNombre()<<endl;
  }
}
