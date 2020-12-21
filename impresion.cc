//impresion.cc
//Proyecto IS

#include "impresion.h"

void mostrarSenderosAsociados(const parque &p){

  list<sendero> senderos=getInstance()->getSenderosParque(p.getNombre());
  for(sendero &sendero: senderos)
  {
    std::cout<<sendero.getNombre()<<endl;
    std::cout<<"\n";
  }
}

void imprimirParque(const parque &p){
cout<<"DATOS DEL PARQUE: \n";
cout<<"NOMBRE: "<<p.getNombre()<<endl;
cout<<"FECHA DE NOMBRAMIENTO: "<<p.getFechaNombramientoParque()<<endl;
cout<<"TAMANO: "<<p.getTamano()<<endl;
cout<<"PREMIOS: "<<p.getPremios()<<endl;
cout<<"DESCRIPCION: "<<p.getDescripcion()<<endl;
cout<<"DISPONIBILIDAD: "<<p.getDisponibilidad()<<endl;
cout<<"SENDEROS ASOCIADOS: \n";
mostrarSenderosAsociados(p);

}


void mostrarRutasAsociadas(const sendero &s, const parque &p){
  list<ruta> rutas=getInstance()->getRutasSendero(p.getNombre() + "_" + s.getSendero());
  for(ruta &ruta: rutas)
  {
    std::cout<<ruta.getNombre()<<endl;
    std::cout<<"\n";
  }
}

void imprimirSendero(const sendero &s, const parque &p){
cout<<"DATOS DEL SENDERO: \n";
cout<<"NOMBRE: "<<s.getNombre()<<endl;
cout<<"LONGITUD: "<<s.getLongitud()<<endl;
cout<<"DESCRIPCION: "<<s.getDescripcion()<<endl;
cout<<"DISPONIBILIDAD: "<<s.getDisponibilidad()<<endl;
cout<<"RUTAS ASOCIADAS: \n";
this->mostrarRutasAsociadas(s, p);

}


void mostarVisitantesAsociados(const ruta &r, const sendero &s, const parque &p){

  list<visitante> visitantes=getInstance()->getVisitantesRuta(p.getNombre() + "_" + s.getNombre() + "_" + this->getIdentificador());
  for(visitante &visitantes: visitantes)
  {
    std::cout<<visitante.getNombreCompleto()<<endl;
    std::cout<<"\n";
   }

}

void imprimirRuta(const ruta &r, const sendero &s, const parque &p){
  cout<<"DATOS DE LA RUTA: \n";
  cout<<"IDENTIFICADOR: "<<r.getIdentificador()<<endl;
  cout<<"DIFICULTAD: "<<r.getDificultad()<<endl;
  cout<<"MONITOR ASOCIADO: "<<r.getMonitorAsociado()<<endl;
  cout<<"FECHA: "<<r.getFecha()<<endl;
  cout<<"HORA: "<<r.getHora()<<endl;
  cout<<"DURACION ESTIMADA: "<<r.getDuracionEstimada()<<endl;
  cout<<"BICICLETA: "<<r.getBicicleta() << endl;
  this->mostrarVisitantesAsociados(r, s, p);
}


void imprimirVisitante(const visitante &v){
  cout<<"DATOS DEL VISITANTE: \n";
  cout<<"DNI: "<<v.getDNI()<<endl;
  cout<<"NOMBRE: "<<c.getNombreCompleto()<<endl;
  cout<<"FECHA DE NACIMIENTO: "<<v.getFechaDeNacimiento()<<endl;
  cout<<"NUMERO DE TELEFONO: "<<v.getNumeroDeTlfn()<<endl;
  cout<<"CONDICION: "<<v.getCondicion()<<endl;
}

void mostrarTodosVisitantes(){

  list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getNombreCompleto()<<endl;
  }
}

void mostrarTodosVisitantesDNI(){

  list<visitante> visitantes=getInstance()->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    std::cout<<visitante.getDNI()<<endl;
  }
}

void imprimirMonitor(const monitor &m){
  cout<<"DATOS DEL MONITOR: \n";
  cout<<"DNI: "<<m.getDNI()<<endl;
  cout<<"NOMBRE COMPLETO: "<<m.getNombreCompleto()<<endl;
  cout<<"FECHA DE NACIMIENTO: "<<m.getFechaDeNacimiento()<<endl;
  cout<<"NUMERO DE TELEFONO: "<<m.getNumeroDeTlfn()<<endl;
  cout<<"CONDICION: "<<m.getCondicion()<<endl;
  cout<<"DISPONIBILIDAD: "<<m.getDisponibilidad()<<endl;
}

void mostrarTodosMonitoresDNI(){

  list<monitor> monitores=getInstance()->getTodosMonitores();
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
  list<parque> parques=getInstance()->GetTodosParques();
  for(parque &parque: parques)
  {
    std::cout<<parque.getNombre()<<endl;
  }
}
