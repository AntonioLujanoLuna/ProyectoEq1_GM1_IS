std::std::list//menus.cc
//proyecto IS
#include "menus.h"
#include "parques.h"
#include "senderos.h"
#include "rutas.h"
#include "monitores.h"
#include "visitantes.h"
#include "fileIO.h"
#include <list>
#include <string>

using namespace FileIO;

int menuPrincipal(){
  int login;

  std::cout<<"     --- Bienvenido al Sistema de Gestión de Parques Naturales de la Junta de Andalucia. ---\n";
  std::cout<<"--- Por favor, inicie sesion, seleccionado la opcion 0 o 1. ---\n";
  std::cout<<"--- 0) Entrar al Sistema como Administrador. ---\n";
  std::cout<<"--- 1) Entrar al Sistema como Monitor. ---\n";
  std::cout<<"--- 2) Salir del programa ---\n";
  cin>>login;

  switch(login){
    while(login<0||login>2){
      std::cout<<"Opcion invalida. Por favor, seleccione una opcion valida. \n";
      cin>>login;
    }

  case 0:
    if(!comprobarAdmin()){
      std::cout<<"No tiene autorizacion para entrar al sistema como administrador. \n";
    }
    else{
      menuAdmin();
    }
    break;

  case 1:
    if(!comprobarMonitor()){
      std::cout<<"No tiene autorizacion para entrar al sistema como monitor. \n";
      std::cout<<"Si es usted administrador del sistema, introduzca sus credenciales. \n";
      if(!comprobarAdmin()){
        std::cout<<"No tiene autorizacion para entrar al sistema como administrador. \n";
        return 0;
      }
      else{
        menuMonitor();
      }
    }
    break;

  case 2:
    return 0;
  break;
  }
}

int menuAdmin(){
    int opc;
      std::cout<<"--- Contraseña correcta. Bienvenido al sistema. ---\n";
      std::cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
      std::cout<<"--- 0) Gestion de Parques Naturales. ---\n";
      std::cout<<"--- 1) Gestion de Senderos. ---\n";
      std::cout<<"--- 2) Gestion de Visitantes. ---\n";
      std::cout<<"--- 3) Gestion de Monitores. ---\n";
      std::cout<<"--- 4) Salir del menu. ---\n";
      cin>>opc;

    switch(opc){
      while(opc<0||opc>4){
        std::cout<<" Opcion invalida. Por favor, seleccione una opcion valida. \n";
        cin>>opc;
      }

      case 0:
        menuParques();
        break;

      case 1:
        menuSenderos();
        break;

      case 2:
        menuVisitantes();
        break;

      case 3:
        menuMonitores();
        break;

      case 4:
        menuPrincipal();
        break;

    }
}

int menuMonitor(){
  int seleccion;
  std::cout<<"--- DNI correcto. Bienvenido al sistema. ---\n";
  std::cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
  std::cout<<"--- 0) Gestion de Rutas. ---\n";
  std::cout<<"--- 1) Salir del menu ---\n";
  cin>>seleccion;

    switch(seleccion){
      while(seleccion<0||seleccion>1){
        std::cout<<"Opcion invalida. Por favor seleccione una opcion valida \n";
        cin>>seleccion;
      }

    case 0:
      menuRutas();
      break;

    case 1:
      menuPrincipal();
      break;
  }
}

bool comprobarAdmin(){
  std::string password;
  for (int i = 0; i<3; i++){
    std::cout<<" Por favor, introduzca su contraseña.\n";
    std::getline(cin,aux);
    if (password == "admingestionJA"){
        std::cout<<"Contraseña correcta\n";
        return true;
    }
    else {
        std::cout<<" Contraseña incorrecta.";
        printf("Quedan %d intentos", 3-i);
    }
  }
  std::cout<<"Maximo numero de intentos permitido alcanzado\n"
  return false;
}

bool comprobarMonitor(){
  std::string dni;
  for (int i = 0; i<3; i++){
    std::cout<<" Por favor, introduzca su DNI.\n";
    std::getline(cin,aux);
    std::list<monitor> monitores = FileIO::getInstance()->getTodosMonitores();
    for(monitor &monitor : monitores){
      if(monitor.getDNI() == dni){
        std::cout<<"DNI correcto\n";
        return true;
      }
    }
    std::cout<<"DNI no encontrado, quedan " << 3-i << "%d intentos\n";
  }
  std::cout<<"Maximo numero de intentos permitido alcanzado\n"
  return false;
}

int menuParques(){
    int i;
    std::string aux;
    int tamano;
    parque p, auxParque;
    while(){

    std::cout<<"   --- Gestion de Parques --- \n";
    std::cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
    std::cout<<"--- 0) Añadir un nuevo Parque Natural. --- \n";
    std::cout<<"--- 1) Modificar los datos de un Parque Natural ya introducido. --- \n";
    std::cout<<"--- 2) Cambiar la disponibilidad de un Parque Natural. --- \n";
    std::cout<<"--- 3) Eliminar un Parque Natural. --- \n";
    std::cout<<"--- 4) Mostrar los datos de un Parque Natural ya introducido. --- \n";
    std::cout<<"--- 5) Volver al menu Principal --- \n";
    cin>>i;

    while(i<0||i>5){
      std::cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
      cin>>i;
    }
    switch(i){

    case 0:
      mostrarNombresParques();
      std::cout<<"   --- Menu de Introduccion de Datos --- \n";

      std::cout<<"--- Por favor, introduzca el nombre del nuevo parque natural --- \n";
      std::getline(cin,aux);


      do{
          std::cout<<"Ya existe un parque con ese nombre. Por favor, introduzca otro nombre para el parque.\n"
          std::getline(cin,aux);
      }while(FileIO::getInstance()->busquedaParque(aux)<0);

      std::cout<<"--- Por favor, introduzca la fecha del nombramiento del parque natural --- \n";
      std::getline(cin,aux);
      p.setFechaNombramientoParque(aux);

      std::cout<<"--- Por favor, introduzca el tamaño del parque natural en kilometros cuadrados --- \n";
      std::getline(cin,tamano);
      p.setTamano(tamano);

      std::cout<<"--- Por favor, introduzca el nombre de los premios otorgados al parque natural, separado por comas --- \n";
      std::getline(cin,aux);
      p.setPremios(aux);

      std::cout<<"--- Por favor, introduzca una breve descripcion del nuevo parque natural --- \n";
      cstd::getline(cin,aux);
      p.setDescripcion(aux);

      p.setDisponibilidad(true);

      FileIO::getInstance()->guardarParque(p);
      imprimirParque(p);


    break;

    case 1:

      mostrarNombresParques();

      std::cout<<"   --- Menu de Introduccion de Datos --- \n";
      std::cout<<"--- Por favor, introduzca el nombre del parque natural --- \n";
      std::getline(cin, aux);

      if(FileIO::getInstance()->existsParque(aux) < 0) {
        std::cout<<"El parque que desea modificar no existe\n Volviendo al menú\n";
        break;
      }
      else{
        p.setNombre(aux);

        std::cout<<"--- Por favor, introduzca la fecha del nombramiento del parque natural --- \n";
        std::getline(cin, aux);
        p.setFechaNombramientoParque(aux);

        std::cout<<"--- Por favor, introduzca el tamaño del parque natural en kilometros cuadrados --- \n";
        cin>>tamano;
        p.setTamano(tamano);

        std::cout<<"--- Por favor, introduzca el nombre de los premios otorgados al parque natural, separado por comas --- \n";
        std::getline(cin, aux);
        p.setPremios(aux);

        std::cout<<"--- Por favor, introduzca una breve descripcion del parque natural --- \n";
        std::getline(cin, aux);
        p.setDescripcion(aux);

        p.setDisponibilidad(true);

        FileIO::getInstance()->guardarParque(p);
        imprimirParque(p);
      }
    break;

    case 2:
      mostrarNombresParques();
      std::cout<<"--- Por favor, introduzca el nombre del parque natural a cambiar disponibilidad\n";
      std::getline(cin,aux);
      if(FileIO::getInstance()->existsParque(aux) < 0) {
        std::cout<<"El parque que desea dar de baja no existe\n Volviendo al menú\n";
        break;
      }
      auxParque=FileIO::getInstance()->busquedaParque(aux);
      else{
        p.setNombre(aux);
        std::cout<<"Introduzca 1 si quiere que el parque este disponible y 0 en caso contrario"<<endl;
        std::getline(cin,tamano);
          while(tamano>1 || tamano<0){
            std::cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
            std::getline(cin,tamano);
          }

          if(tamano=1)
          {
            p.setDisponibilidad(true);
            if(p.getDisponibilidad()==false)
              {
                std::cout<<"ERROR al cambiar la disponibilidad del parque."<<endl;
                break;
              }
            else
              {
                std::cout<<"Disponibilidad cambiada con exito."<<endl;
              }
          }
          else if(tamano=0)
          {
            p.setDisponibilidad(false);
            if(p.getDisponibilidad()==true)
              {
                std::cout<<"ERROR al cambiar la disponibilidad del parque."<<endl;
                break;
              }
            else
              {
                std::cout<<"Disponibilidad cambiada con exito."<<endl;
              }
          }
        FileIO::getInstance()->guardarParque(auxParque);
        break;
      }

    case 3:

    mostrarNombresParques();
    std::cout<<"Introduzca el nombre del parque que quiere borrar"<<endl;
    std::getline(cin,aux);
    if(FileIO::getInstance()->existsParque(aux) < 0) {
        std::cout<<"El parque que desea borrar no existe\n Volviendo al menú\n";
        break;
      }
    auxParque=FileIO::getInstance()->busquedaParque(aux);
    else{
      p.setNombre(aux);
      std::cout<<"--- ¿Esta seguro de que desea borrar el parque? ---\n";
      std::cout<<"--- Escriba 1 si desea confirmarlo, 0 en caso contrario ---\n";
      int decis;
      std::getline(cin,aux);
      decis = atoi(aux);
      if(decis==1){
        FileIO::getInstance()->borrarParque(auxParque);
      }
      if(decis==0){
        std::cout<<"Operación abortada\n";
      }
      else {
        std::cout<<"Error en la confirmación, volviendo al menú\n";
      }
    }
      break;

    case 4:

      mostrarNombresParques();
      std::cout<<"Introduzca el nombre del parque que quiere mostrar por pantalla."<<endl;
      std::getline(cin,aux);
        if(FileIO::getInstance()->existsParque(aux) < 0) {
          std::cout<<"El parque que desea mostrar no existe\n Volviendo al menú\n";
          break;
        }
      auxParque=FileIO::getInstance()->busquedaParque(aux);
      std::cout<<"--- A continuacion se mostrarán los datos del parque existente --- \n";

      std::list<parque> parques=getInstance()()->GetTodosParques();
      for(parque &parque: parques){
        p=parque;
        if(aux==p.getNombre())
        {
          imprimirParque(auxParque);
        }
      }
      break;

    case 5:
      return(EXIT_SUCCESS);
    break;

    }
  }
}

int menuSenderos(){
  int i;
  std::string aux;
  int tamano;
  int exist;
  parque p, auxParque;
  sendero s, auxSendero;

  while(){

    std::cout<<"   --- Gestion de Senderos --- \n";
    std::cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
    std::cout<<"--- 0) Añadir un nuevo Sendero a un Parque Natural. --- \n";
    std::cout<<"--- 1) Modificar los datos de un Sendero ya introducido. --- \n";
    std::cout<<"--- 2) Cambiar la disponibilidad de un Sendero. --- \n";
    std::cout<<"--- 3) Eliminar un Sendero. --- \n";
    std::cout<<"--- 4) Mostrar los datos de un Sendero ya introducido. --- \n";
    std::cout<<"--- 5) Volver al Menu Principal. --- \n";
    cin>>i;

    while(i<0||i>5){
      std::cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
      cin>>i;
    }
    switch(i){
    case 0:

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    std::getline(cin,nomParque);
    if(FileIO::getInstance()->existsParque(nomParque)<0){
      std::cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);
    else{
      p = FileIO::busquedaParque(nomParque);
      mostrarSenderosAsociados();
      std::cout<<"--- Por favor, introduzca el nombre del nuevo sendero. --- \n";
      std::getline(cin,aux);
    }
      if((exist = FileIO::getInstance()->existsSendero(aux, auxParque))>=0){
      do{
        std::cout<<" Ya existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        std::getline(cin,aux);
        exist = FileIO::getInstance()->existsSendero(aux, nomParque);
        }
      while(exist >=0);

      s.setNombre(aux);

      std::cout<<"--- Por favor, introduzca la longitud del nuevo sendero --- \n";
      std::getline(cin,tamano);
      s.setLongitud(tamano);

      std::cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
      std::getline(cin,aux);
      s.setDescripcion(aux);

      s.setDisponibilidad(true);

      FileIO::getInstance()->guardarSendero(s, nomParque);
      imprimirSendero(auxParque, s);
    }
    break;

    case 1:

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea modificar. --- \n";
    std::getline(cin,nomParque);

    if(FileIO::getInstance()->existsParque(nomParque)<0){
      std::cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);
    else{
      mostrarSenderosAsociados(nomParque);
      std::cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
      std::getline(cin,aux);
      if((exist = FileIO::getInstance()->existsSendero(aux, nomParque))<0){
      do{
        std::cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        std::getline(cin,aux);
        exist = FileIO::getInstance()->existsSendero(aux, nomParque);
        }
      while(exist <0);

      s.setNombre(aux);

      std::cout<<"--- Por favor, introduzca la nueva longitud del sendero --- \n";
      std::getline(cin,tamano);
      s.setLongitud(tamano);

      std::cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
      std::getline(cin,aux);
      s.setDescripcion(aux);

      s.setDisponibilidad(true);

      FileIO::getInstance()->guardarSendero(s, nomParque);
      imprimirSendero(auxParque, s);
    }
    break;

    case 2:
    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea modificar. --- \n";
    std::getline(cin,nomParque);

    if(FileIO::getInstance()->existsParque(nomParque)<0){
      std::cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);
    else{
      mostrarSenderosAsociados(nomParque);
      std::getline(cin,aux);
      std::cout<<"--- Por favor, introduzca el nombre del sendero a dar de baja/alta. --- \n";
      std::getline(cin,aux);

      if((exist = FileIO::getInstance()->existsSendero(aux, nomParque))<0){
      do{
        std::cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        std::getline(cin,aux);
        exist = FileIO::getInstance()->existsSendero(aux, nomParque);
        }
      while(exist <0);
      auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,aux);

      s.setNombre(aux);

      std::cout<<"Introduzca 1 si quiere que el parque este disponible y 0 en caso contrario"<<endl;
      std::getline(cin,tamano);
        while(tamano>1 || tamano<0)
        {
          std::cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
          std::getline(cin,tamano);
        }
        if(tamano=1)
        {
          s.setDisponibilidad(true);
          if(s.getDisponibilidad()==false)
          {
            std::cout<<"ERROR al cambiar la disponibilidad del sendero."<<endl;
            break;
          }
          else
          {
            std::cout<<"Disponibilidad cambiada con exito."<<endl;
          }
        }
        else if(tamano=0)
        {
          s.setDisponibilidad(false);
          if(s.getDisponibilidad()==true)
          {
            std::cout<<"ERROR al cambiar la disponibilidad del sendero."<<endl;
            break;
          }
          else
          {
            std::cout<<"Disponibilidad cambiada con exito."<<endl;
          }
        }
      FileIO::getInstance()->guardarSendero(auxSendero, nomParque);
    }

    break;

    case 3:

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea modificar. --- \n";
    std::getline(cin,nomParque);

    if(FileIO::getInstance()->existsParque(nomParque)<0){
      std::cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);
    else{
      mostrarSenderosAsociados(nomParque);
      std::getline(cin,aux);
      std::cout<<"--- Por favor, introduzca el nombre del sendero a borrar. --- \n";
      std::getline(cin,aux);

      if((exist = FileIO::getInstance()->existsSendero(aux, nomParque))<0){
      do{
        std::cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        std::getline(cin,aux);
        exist = FileIO::getInstance()->existsSendero(aux, nomParque);
        }
      while(exist <0);
      auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,aux);

      std::cout<<"--- ¿Esta seguro de que desea borrar el sendero? ---\n";
      std::cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
      int decis;
      std::getline(cin,aux);
      decis = atoi(aux);
      if(decis==1){
        FileIO::getInstance()->borrarSenderos(auxSendero,auxParque);
      }
      if(decis==0){
        std::cout<<"Operación abortada\n";
      }
      else {
        std::cout<<"Error en la confirmación, volviendo al menú\n";
      }
    }
    break;

    case 4:

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar. --- \n";
    std::getline(cin,nomParque);

    if(FileIO::getInstance()->existsParque(nomParque)<0){
      std::cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);
    else{
      mostrarSenderosAsociados(nomParque);
      std::cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
      std::getline(cin,aux);

      if((exist = FileIO::getInstance()->existsSendero(aux, nomParque))<0){
      do{
        std::cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        std::getline(cin,aux);
        exist = FileIO::getInstance()->existsSendero(aux, nomParque);
        }
        auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,aux);
      while(exist <0);
          parque aux;
          std::list<parque> parques = getInstance()->getTodosParques();
          for(parque &parque : parques){
            if(nomParque == parque.getNombre()){
              aux = parque;
            }
          }
          imprimirSendero(auxParque, auxSendero);
      }
    }

    break;

    case 5:
    return(EXIT_SUCCESS);
    break;
    }
  }
}


int menuRutas(){

  std::string aux;
  int tamano;
  int exist;
  parque p,auxParque;
  sendero s,auxSendero;
  ruta r,auxRuta;
  visitante v,auxVisitante;
  int i;

  while(){

  std::cout<<"   --- Gestion de Rutas --- \n";
  std::cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  std::cout<<"--- 0) Añadir una nueva ruta a un Sendero de un Parque Natural. --- \n";
  std::cout<<"--- 1) Modificar los datos de una ruta ya introducida. --- \n";
  std::cout<<"--- 2) Finalizar una ruta. --- \n";
  std::cout<<"--- 3) Eliminar una ruta. --- \n";
  std::cout<<"--- 4) Mostrar los datos de una ruta ya introducida. --- \n";
  std::cout<<"--- 5) Asignar un visitante ya introducido a una ruta. --- \n";
  std::cout<<"--- 6) Volver al menu Principal. --- \n";
  cin>>i;

  while(i<0||i>6){
    std::cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin>>i;
  }
  switch(i){

    case 0:

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    std::getline(cin,nomParque);
    exist = FileIO::getInstance()->existsParque(nomParque);
    do{
      std::cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      std::getline(cin,nomParque);
      exist = FileIO::getInstance()->existsParque(nomParque);
    }
    while(exist<0);
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);

    mostrarSenderosAsociados(nomParque);
    std::cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    do{
      std::cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    }
    auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,aux);

    while(exist <0);
    s.setNombre(aux);
    std::string nomsendero = aux;
    mostrarRutasAsociadas(nomsendero, nomParque);
    std::cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    do{
      std::cout<<" Ya existe una ruta con ese nombre. Por favor, introduzca otro nombre para la ruta. \n";
      std::getline(cin,aux);
      FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    }
    while(FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque)=>0);
    r.setIdentidicador(aux);
    std::string id = aux;

    std::cout<<"--- Por favor, introduzca la dificultad de la nueva ruta. --- \n";
    std::getline(cin,aux);
    r.setDificultad(aux);

    mostrarTodosMonitoresDNI();

    std::cout<<"--- Por favor, introduzca el DNI del monitor que guia la ruta. --- \n";
    std::getline(cin,aux);
    if(fileIO::existsMonitor(aux) < 0){
      std::cout<<"El monitor indicado no existe, volviendo al menu\n";
      break;
    }
    r.setMonitorAsociado(aux);

    std::cout<<"--- Por favor, introduzca la fecha en la que se realiza la ruta. --- \n";
    std::getline(cin,aux);
    fechaValida(aux);
    do{
    std::cout<<"La fecha introducida no es valida. Por favor, introduzca una fecha valida. \n"
    std::getline(cin,aux);
    fechaValida(aux)
    }while(fechaValida==false);
    r.setFecha(aux);

    std::cout<<"--- Por favor, introduzca la hora a la que se realiza la ruta --- \n";
    std::getline(cin,aux);    do{
    std::cout<<"La hora introducida no es valida. Por favor, introduzca una hora valida. \n"
    std::getline(cin,aux);
    horaValida(aux)
    }while(horaValida==false);
    r.setHora(aux);

    std::cout<<"--- Por favor, introduzca la duracion estimada de la ruta en minutos --- \n";
    std::getline(cin,tamano);
    r.setDuracionEstimada(tamano);

    std::cout<<"--- Por favor, indique si la ruta se puede realizar en bicicleta o no. --- \n";
    std::getline(cin,aux);
    r.setBicicleta(aux);

    FileIO::getInstance()->guardarRuta(r, nomsendero,nomParque);
    imprimirRuta(r, nomsendero, nomParque);

    break;

    case 1:

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    std::getline(cin,nomParque);
    exist = FileIO::getInstance()->existsParque(nomParque);
    do{
      std::cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      std::getline(cin,nomParque);
      exist = FileIO::getInstance()->existsParque(nomParque);
    }
    while(exist<0);
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);

    mostrarSenderosAsociados(nomParque);
    std::cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    do{
      std::cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    }
    while(exist<0);
    s.setNombre(aux);
    auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,aux);

    std::string nomsendero=aux;
    mostrarRutasAsociadas(nomsendero, nomParque);
    std::cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    do{
      std::cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    }
    while(exist<0);
    r.setIdentidicador(aux);
    std::string id=aux;
    auxRuta=FileIO::getInstance()->busquedaRuta(nomParque,nomsendero,id);

    std::cout<<"--- Por favor, introduzca la dificultad de la ruta. --- \n";
    std::getline(cin,aux);
    r.setDificultad(aux);

    std::cout<<"--- Por favor, introduzca el nombre del monitor que guia la ruta. --- \n";
    std::getline(cin,aux);
    if(fileIO::existsMonitor(aux) < 0){
      std::cout<<"El monitor indicado no existe, volviendo al menu\n";
      break;
    }
    r.setMonitorAsociado(aux);

    std::cout<<"--- Por favor, introduzca la fecha en la que se realiza la ruta. --- \n";
    std::getline(cin,aux);
    fechaValida(aux);
    do{
    std::cout<<"La fecha introducida no es valida. Por favor, introduzca una fecha valida. \n"
    std::getline(cin,aux);
    fechaValida(aux)
    }while(fechaValida==false);
    r.setFecha(aux);

    std::cout<<"--- Por favor, introduzca la hora a la que se realiza la ruta --- \n";
    std::getline(cin,aux);
    do{
    std::cout<<"La hora introducida no es valida. Por favor, introduzca una hora valida. \n"
    std::getline(cin,aux);
    horaValida(aux)
    }while(horaValida==false);
    r.setHora(aux);

    std::cout<<"--- Por favor, introduzca la duracion estimada de la ruta en minutos --- \n";
    std::getline(cin,tamano);
    r.setDuracionEstimada(tamano);

    std::cout<<"--- Por favor, indique si la ruta se puede realizar en bicicleta o no. --- \n";
    std::getline(cin,aux);
    r.setBicicleta(aux);

    FileIO::getInstance()->guardarRuta(r, nomsendero,nomParque);
    imprimirRuta(r, auxSendero, auxParque);

    break;

    case 2:
    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    std::getline(cin,nomParque);
    exist = FileIO::getInstance()->existsParque(nomParque);
    do{
      std::cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      std::getline(cin,nomParque);
      exist = FileIO::getInstance()->existsParque(nomParque);
    }
    while(exist <0);
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);


    mostrarSenderosAsociados(nomParque);
    std::cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    do{
      std::cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    }
    while(exist <0);
    s.setNombre(aux);
    auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,aux);

    std::string nomsendero=aux;
    mostrarRutasAsociadas(nomsendero, nomParque);
    std::cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    do{
      std::cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    }
    while(exist <0);
    r.setIdentidicador(aux);
    std::string id=aux;
    auxRuta=FileIO::getInstance()->busquedaRuta(nomParque,nomsendero,id);

    std::cout<<"Introduzca 1 si quiere finalizar la ruta y 0 en caso contrario"<<endl;
    std::getline(cin,tamano);
      while(tamano>1 || tamano<0)
      {
        std::cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
        break;
      }
      if(tamano=1)
      {
        r.setDisponibilidad(true);
        if(r.getDisponibilidad()==false)
         {
           std::cout<<"ERROR al finalizar la ruta."<<endl;
          break;
         }
         else
         {
           std::cout<<"Ruta finalizada con exito."<<endl;
         }
      }
      else if(tamano=0)
      {
        r.setDisponibilidad(false);
        if(r.getDisponibilidad()==true)
         {
           std::cout<<"ERROR al finalizar la ruta."<<endl;
          break;
         }
         else
         {
           std::cout<<"Disponibilidad cambiada con exito."<<endl;
         }
      }
    FileIO::getInstance()->guardarRuta(auxRuta, nomsendero,nomParque);
    break;

    case 3:

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cstd::getline(cin,nomParque);
    exist = FileIO::getInstance()->existsParque(nomParque);
    do{
      std::cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      std::getline(cin,nomParque);
      exist = FileIO::getInstance()->existsParque(nomParque);
    }
    while(exist <0);

    auxParque=FileIO::getInstance()->busquedaParque(nomParque);


    mostrarSenderosAsociados(nomParque);
    std::cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    do{
      std::cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
    std::getline(cin,aux);
      exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    }
    while(exist<0);
    s.setNombre(aux);

    auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,aux);

    std::string nomsendero=aux;
    mostrarRutasAsociadas(nomsendero, nomParque);
    std::cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    do{
      std::cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    }
    while(exist<0);
    r.setIdentidicador(aux);
    std::string id=aux;
    auxRuta=FileIO::getInstance()->busquedaRuta(nomParque,nombreSendero,id);

    std::cout<<"--- ¿Esta seguro de que desea borrar la ruta? ---\n";
    std::cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
    int decis;
    std::getline(cin,aux);
    decis = atoi(aux);
    if(decis==1){
      FileIO::getInstance()->borrarRuta(auxRuta, auxSendero, auxParque);
      break;
    }
    if(decis==0){
      break;
    }
    else {
        std::cout<<"Error en la confirmación, volviendo al menú\n";
        break;
    }

    case 4:
    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    exist = FileIO::getInstance()->existsParque(nomParque);
    do{
      std::cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      exist = FileIO::getInstance()->existsParque(nomParque);
    }
    while(exist <0);
    auxParque=FileIO::getInstance()->busquedaParque(nomParque);

    mostrarSenderosAsociados(nomParque);
    std::cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    do{
      std::cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    }
    while(exist <0);
    s.setNombre(aux);
    auxSendero=FileIO::getInstance()->busquedaSendero(nomParque,nombreSendero);

    std::string nomsendero=aux;
    mostrarRutasAsociadas(nomsendero, nomParque);
    std::cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    do{
      std::cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";

      cin>>aux;
      exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    }
    while(exist <0);
    r.setIdentidicador(aux);
    std::string id=aux;
    auxRuta=FileIO::getInstance()->busquedaRuta(nomParque,nombreSendero,id);
    std::list<ruta> rutas = getInstance()->getRutasSendero(nomParque + "_" + nomsendero + "_" + id);
    for(ruta &ruta: rutas)
    {
      if(id==auxRuta.getIdentificador())
      {
        imprimirRuta(auxRuta, auxSendero, auxParque);
      }
    }
    break;


    case 5:

    mostrarTodosVisitantesDNI();
    std::cout<<"--- Por favor, introduzca el DNI del visitante. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsVisitante(aux);
    do{
      std::cout<<" El visitante no existe. Por favor, introduzca el DNI del visitante. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsVisitante(aux);
    }
    while(exist <0);
    v.setDNI(aux);
    std::string dni_=aux;
    auxVisitante=FileIO::getInstance()->busquedaVisitante(aux);

    std::string nomParque;
    mostrarNombresParques();
    std::cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    std::getline(cin,nomParque);
    exist = FileIO::getInstance()->existsParque(nomParque);
    do{
      std::cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      std::getline(cin,nomParque);
      exist = FileIO::getInstance()->existsParque(nomParque);
    }
    while(exist<0);

    mostrarSenderosAsociados(nomParque);
    std::cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    do{
      std::cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsSendero(aux, nomParque);
    }
    while(exist<0);
    s.setNombre(aux);

    std::string nomsendero=aux;
    mostrarRutasAsociadas(nomsendero, nomParque);
    std::cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    do{
      std::cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsRuta (aux, nomsendero, nomParque);
    }
    while(exist<0);
    r.setIdentidicador(aux);
    std::string id=aux;

    guardarVisitanteARuta(auxVisitante);

    break;


    case 6:
      return(EXIT_SUCCESS);
    break;
    }
  }
}


int menuVisitantes(){
  std::string aux;
  int tamano;
  parque p, auxParque;
  sendero s, auxSendero;
  ruta r, auxRuta;
  visitante v, auxVisitante;
  int i, exist;

  while(){

  std::cout<<"   --- Gestion de Visitantes --- \n";
  std::cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  std::cout<<"--- 0) Añadir un nuevo un visitante. --- \n";
  std::cout<<"--- 1) Modificar los datos de visitante ya introducido. --- \n";
  std::cout<<"--- 2) Cancelar visita. --- \n";
  std::cout<<"--- 3) Mostrar los datos de un visitante ya introducido. --- \n";
  std::cout<<"--- 4) Volver al menu principal. --- \n";
  cin>>i;


  while(i<0||i>5){
    std::cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin>>i;
  }
  switch(i){
  case 0:

  std::cout<<"Por favor, introduzca el DNI del nuevo visitante";
  std::getline(cin,aux);
  exist = FileIO::getInstance()->existsVisitante(aux);

  do{
    std::cout<<"Ya existe un visitante con ese DNI. Por favor, introduzca otro DNI para el nuevo visitante";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsVisitante(aux);
  }while(exist >= 0);
  std::string dni=aux;
  v.setDNI(aux);
  auxVisitante=FileIO::getInstance()->busquedaVisitante(dni);

  std::cout<<"--- Por favor, introduzca el nombre completo del nuevo visitante. --- \n";
  std::getline(cin,aux);
  v.setNombreCompleto(aux);

  std::cout<<"--- Por favor, introduzca el numero de telefono del nuevo visitante. --- \n";
  std::getline(cin,aux);
  v.setNumeroDeTlfn(aux);

  std::cout<<"--- Por favor, introduzca la fecha de nacimiento del nuevo visitante con formato DD/MM/YYYY. --- \n";
  std::getline(cin,aux);
  v.setFechaDeNacimiento(aux);

  std::cout<<"--- Por favor, introduzca cualquier condicion del visitante a tener en cuenta. --- \n";
  std::getline(cin,aux);
  v.setCondicion(aux);

  FileIO::getInstance()->guardarVisitante(v);
  imprimirVisitante(v);

  break;

  case 1:
  mostrarTodosVisitantes();
  std::cout<<"Por favor, introduzca el DNI del visitante a Modificar";
  std::getline(cin,aux);
  exist = FileIO::getInstance()->existsVisitante(aux);

  do{
    std::cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsVisitante(aux);
  }while(exist <0);
  std::string dni=aux;
  v.setDNI(aux);
  auxVisitante=FileIO::getInstance()->busquedaVisitante(dni);

  std::cout<<"--- Por favor, introduzca el nombre completo del visitante. --- \n";
  std::getline(cin, aux);
  v.setNombreCompleto(aux);

  std::cout<<"--- Por favor, introduzca el numero de telefono del visitante. --- \n";
  std::getline(cin, aux);
  v.setNumeroDeTlfn(aux);

  std::cout<<"--- Por favor, introduzca la fecha de nacimiento del visitante con formato DD/MM/YYYY. --- \n";
  std::getline(cin, aux);
  v.setFechaDeNacimiento(aux);

  std::cout<<"--- Por favor, introduzca cualquier condicion del visitante a tener en cuenta. --- \n";
  std::getline(cin, aux);
  v.setCondicion(aux);

  FileIO::getInstance()->guardarVisitante(auxVisitante);
  imprimirVisitante(auxVisitante);


  break;

  case 2:
  mostrarTodosVisitantes();
  std::cout<<"Por favor, introduzca el DNI del visitante cuya visita quiere cancelar.";
  std::getline(cin,aux);
  exist = FileIO::getInstance()->existsVisitante(aux);

  do{
    std::cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsVisitante(aux);
  }while(exist < 0);
  std::string dni=aux;
  auxVisitante=FileIO::getInstance()->busquedaVisitante(dni);

  std::cout<<"--- ¿Esta seguro de que desea cancelar la visita? ---\n";
  std::cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
  int decis;
  std::getline(cin,aux);
  decis = atoi(aux);
  if(decis==1){
    FileIO::getInstance()->borrarVisitante(auxVisitante);
  }
  if(decis==0){
    break;
  }
  else {
      std::cout<<"Error en la confirmación, volviendo al menú\n";
      break;
    }

  break;

  case 3:
  mostrarTodosVisitantes();
  std::cout<<"Por favor, introduzca el DNI del visitante cuyos datos quiere ver";
  std::getline(cin,aux);
  exist = FileIO::getInstance()->existsVisitante(aux);
  do{
    std::cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsVisitante(aux);
  }while(exist < 0);
  std::string dni=aux;
  auxVisitante=FileIO::getInstance()->busquedaVisitante(dni);

  std::list<visitante> visitantes = getInstance() ->getTodosVisitantes();
  for(visitante &visitante: visitantes)
  {
    if(aux==v.getDNI())
    {
      imprimirRuta(auxVisitante);
    }
  }
  break;

  case 4:
    return(EXIT_SUCCESS);
  break;
    }
  }
}

int menuMonitores(){
  std::string aux;
  int tamano, exist;
  parque p, auxParque;
  sendero s, auxSendero;
  ruta r, auxRuta;
  visitante v, auxVisitante;
  monitor m, auxMonitor;
  int i;

  while(){
  std::cout<<"   --- Gestion de Monitores --- \n";
  std::cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  std::cout<<"--- 0) Añadir un nuevo monitor. --- \n";
  std::cout<<"--- 1) Modificar los datos de un monitor ya introducido. --- \n";
  std::cout<<"--- 2) Dar de baja / alta a un monitor. --- \n";
  std::cout<<"--- 3) Mostrar los datos de un monitor ya introducido. --- \n";
  std::cout<<"--- 4) Eliminar un monitor del sistema. --- \n";
  std::cout<<"--- 5) Volver al menu principal. --- \n";
  cin>>i;

  while(i<0||i>5){
    std::cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin>>i;
  }
  switch(i){

    case 0:

    std::cout<<"Por favor, introduzca el DNI del nuevo monitor";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsMonitor(aux);

    do{
      std::cout<<"Ya existe un monitor con ese DNI. Por favor, introduzca otro DNI para el nuevo monitor";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsMonitor(aux);
    }while(exist >= 0);

    m.setDNI(aux);
    std::string dniMonitor=aux;
    auxMonitor=FileIO::getInstance()->busquedaMonitor(dniMonitor);

    std::cout<<"--- Por favor, introduzca el nombre completo del Monitor. --- \n";
    std::getline(cin,aux);
    m.setNombreCompleto(aux);

    std::cout<<"--- Por favor, introduzca el numero de telefono del Monitor. --- \n";
    std::getline(cin,aux);
    m.setNumeroDeTlfn(aux);

    std::cout<<"--- Por favor, introduzca la fecha de nacimiento del Monitor con formato DD/MM/YYYY. --- \n";
    std::getline(cin,aux);
    m.setFechaDeNacimiento(aux);

    std::cout<<"--- Por favor, introduzca cualquier condicion a tener en cuenta . --- \n";
    std::getline(cin,aux);
    m.setCondicion(aux);

    m.setDisponibilidad(true);

    FileIO::getInstance()->guardarMonitor(m);
    imprimirMonitor(m);
    break;

    case 1:

    std::cout<<"Por favor, introduzca el DNI del monitor";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsMonitor(aux);

    do{
      std::cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsMonitor(aux);
    }while(exist < 0);

    std::string dniMonitor=aux;
    auxMonitor=FileIO::getInstance()->busquedaMonitor(dniMonitor);

    std::cout<<"--- Por favor, introduzca el nombre completo del Monitor. --- \n";
    std::getline(cin,aux);
    m.setNombreCompleto(aux);

    std::cout<<"--- Por favor, introduzca el numero de telefono del Monitor. --- \n";
    std::getline(cin,aux);
    m.setNumeroDeTlfn(aux);

    std::cout<<"--- Por favor, introduzca la fecha de nacimiento del Monitorcon formato DD/MM/YYYY. --- \n";
    std::getline(cin,aux);
    m.setFechaDeNacimiento(aux);

    std::cout<<"--- Por favor, introduzca cualquier condicion a tener en cuenta . --- \n";
    std::getline(cin,aux);
    m.setCondicion(aux);

    m.setDisponibilidad(true);

    FileIO::getInstance()->guardarMonitor(auxMonitor);
    imprimirMonitor(auxMonitor);

    break;

    case 2:

    std::cout<<"Por favor, introduzca el DNI del monitor";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsMonitor(aux);

    do{
      std::cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsMonitor(aux);
    }while(exist < 0);
    m.setDNI(aux);
    std::string dniMonitor=aux;
    auxMonitor=FileIO::getInstance()->busquedaMonitor(dniMonitor);

    std::cout<<"Introduzca 1 si quiere que el monitor este disponible y 0 en caso contrario"<<endl;
    std::getline(cin,tamano);
      while(tamano>1 || tamano<0)
      {
        std::cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
        std::getline(cin,tamano);
      }
      if(tamano=1)
      {
        m.setDisponibilidad(true);
        if(m.getDisponibilidad()==false)
         {
           std::cout<<"ERROR al cambiar la disponibilidad del monitor."<<endl;
           break;
         }
         else
         {
           std::cout<<"Disponibilidad cambiada con exito."<<endl;
         }
      }
      else if(tamano=0)
      {
        m.setDisponibilidad(false);
        if(m.getDisponibilidad()==true)
         {
           std::cout<<"ERROR al cambiar la disponibilidad del monitor."<<endl;
           break;
         }
         else
         {
           std::cout<<"Disponibilidad cambiada con exito."<<endl;
         }
      }
      FileIO::getInstance()->guardarMonitor(auxMonitor);
      break;

    case 3:

    mostrarTodosMonitoresDNI();
    std::cout<<"Por favor, introduzca el DNI del monitor";
    std::getline(cin,aux);
    exist = FileIO::getInstance()->existsMonitor(aux);

    do{
      std::cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere mostrar.\n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()->existsMonitor(aux);
    }while(exist<0);

    std::string dniMonitor=aux;
    auxMonitor=FileIO::getInstance()->busquedaMonitor(dniMonitor);

    std::list<monitor> monitores = FileIO::getInstance()()->getTodosMonitores();
    for(monitor &monitor: monitores)
    {
      if(aux==m.getDNI())
      {
        imprimirMonitor(auxMonitor);
      }
    }
    break;

    case 4:

    mostrarTodosMonitoresDNI();
    std::cout<<"Por favor, introduzca el DNI del monitor que desea eliminar\n";
    std::getline(cin,aux);
    exist = FileIO::getInstance()()->existsMonitor(aux);

    do{
      std::cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere eliminar.\n";
      std::getline(cin,aux);
      exist = FileIO::getInstance()()->existsMonitor(aux);
    }while(exist < 0);
    std::string dniMonitor=aux;
    auxMonitor=FileIO::getInstance()()->busquedaMonitor(dniMonitor);

    std::cout<<"--- ¿Esta seguro de que desea eliminar ? ---\n";
    std::cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
    int decis;
    std::getline(cin,aux);
    decis = atoi(aux);
    if(decis==1){
      FileIO::getInstance()()->borrarMonitor(auxMonitor);

      std::list<parque> parques=FileIO::getInstance()()->getTodosParques();
    for(parque &parque: parques)
    {
      std::list<sendero> senderos=getInstance()()->getSenderosParque(parque.getNombre());
    for(sendero &sendero: senderos)
    {
        list <ruta> rutas=getInstance()()->getRutasSendero(parque.getNombre() + "_" + sendero.getNombre());
      for(ruta &ruta: rutas)
      {
	        if(ruta.getMonitorAsociado() == dniMonitor )
	        {
	        	borrarRuta(ruta, sendero, parque)
	        }
    	}
      }
    }


    }
    if(decis==0){
      break;
    }
    else {
      std::cout<<"Error en la confirmación, volviendo al menú\n";
      break;
    }
    break;

    case 5:
      return(EXIT_SUCCESS);
    break;
    }
  }
}
