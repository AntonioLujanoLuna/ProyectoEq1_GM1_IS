//menus.cc
//proyecto IS
#include "menus.h"
#include "parques.h"
#include "senderos.h"
#include "rutas.h"
#include "monitores.h"
#include "visitantes.h"
#include "fileIO.h"
#include "extra.h"
#include <list>

using namespace std;
using namespace FileIO;

int menuPrincipal(){
  int login;

  cout<<"     --- Bienvenido al Sistema de Gestión de Parques Naturales de la Junta de Andalucia. ---\n";
  cout<<"--- Por favor, inicie sesion, seleccionado la opcion 0 o 1. ---\n";
  cout<<"--- 0) Entrar al Sistema como Administrador. ---\n";
  cout<<"--- 1) Entrar al Sistema como Monitor. ---\n";
  cout<<"--- 2) Salir del programa ---\n";
  cin>>login;

  switch(login){
    while(login<0||login>2){
      cout<<"Opcion invalida. Por favor, seleccione una opcion valida. \n";
      cin>>login;
    }

  case 0:
    if(!comprobarAdmin()){
      cout<<"No tiene autorizacion para entrar al sistema como administrador. \n";
    }
    else{
      menuAdmin();
    }
    break;

  case 1:
    if(!comprobarMonitor()){
      cout<<"No tiene autorizacion para entrar al sistema como monitor. \n";
      cout<<"Si es usted administrador del sistema, introduzca sus credenciales. \n";
      if(!comprobarAdmin()){
        cout<<"No tiene autorizacion para entrar al sistema como administrador. \n";
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
      cout<<"--- Contraseña correcta. Bienvenido al sistema. ---\n";
      cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
      cout<<"--- 0) Gestion de Parques Naturales. ---\n";
      cout<<"--- 1) Gestion de Senderos. ---\n";
      cout<<"--- 2) Gestion de Visitantes. ---\n";
      cout<<"--- 3) Gestion de Monitores. ---\n";
      cout<<"--- 4) Salir del menu. ---\n";
      cin>>opc;

    switch(opc){
      while(opc<0||opc>4){
        cout<<" Opcion invalida. Por favor, seleccione una opcion valida. \n";
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
  cout<<"--- DNI correcto. Bienvenido al sistema. ---\n";
  cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
  cout<<"--- 0) Gestion de Rutas. ---\n";
  cout<<"--- 1) Salir del menu ---\n";
  cin>>seleccion;

    switch(seleccion){
      while(seleccion<0||seleccion>1){
        cout<<"Opcion invalida. Por favor seleccione una opcion valida \n";
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
  string password;
  for (int i = 0; i<3; i++){
    cout<<" Por favor, introduzca su contraseña.\n";
    cin>>password;
    if (password == "admingestionJA"){
        cout<<"Contraseña correcta\n";
        return true;
    }
    else {
        cout<<" Contraseña incorrecta.";
        printf("Quedan %d intentos", 3-i);
    }
  }
  cout<<"Maximo numero de intentos permitido alcanzado\n"
  return false;
}

bool comprobarMonitor(){
  string dni;
  for (int i = 0; i<3; i++){
    cout<<" Por favor, introduzca su DNI.\n";
    cin>>dni;
    list<monitor> monitores = FileIO::getInstance->getTodosMonitores();
    for(monitor &monitor : monitores){
      if(monitor.getDNI() == dni){
        cout<<"DNI correcto\n";
        return true;
      }
    }
    cout<<"DNI no encontrado, quedan " << 3-i << "%d intentos\n";
  }
  cout<<"Maximo numero de intentos permitido alcanzado\n"
  return false;
}


int menuParques(){
    int i;
    string aux;
    int tamano;
    parque p;
    while(){

    cout<<"   --- Gestion de Parques --- \n";
    cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
    cout<<"--- 0) Añadir un nuevo Parque Natural. --- \n";
    cout<<"--- 1) Modificar los datos de un Parque Natural ya introducido. --- \n";
    cout<<"--- 2) Cambiar la disponibilidad de un Parque Natural. --- \n";
    cout<<"--- 3) Eliminar un Parque Natural. --- \n";
    cout<<"--- 4) Mostrar los datos de un Parque Natural ya introducido. --- \n";
    cout<<"--- 5) Volver al menu Principal --- \n";
    cin>>i;

    while(i<0||i>5){
      cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
      cin>>i;
    }
    switch(i){

    case 0:
      mostrarNombresParques();
      cout<<"   --- Menu de Introduccion de Datos --- \n";

      cout<<"--- Por favor, introduzca el nombre del nuevo parque natural --- \n";
      cin>>aux;
      p.setNombre(aux);
      cout<<"--- Por favor, introduzca la fecha del nombramiento del parque natural --- \n";
      cin>>aux;
      p.setFechaNombramientoParque(aux);

      cout<<"--- Por favor, introduzca el tamaño del parque natural en kilometros cuadrados --- \n";
      cin>>tamano;
      p.setTamano(tamano);

      cout<<"--- Por favor, introduzca el nombre de los premios otorgados al parque natural, separado por comas --- \n";
      cin>>aux;
      p.setPremios(aux);

      cout<<"--- Por favor, introduzca una breve descripcion del nuevo parque natural --- \n";
      cin>>aux;
      p.setDescripcion(aux);

      p.setDisponibilidad(true);

      FileIO::getInstance->guardarParque(p);
      p.imprimirParque(p);

    break;

    case 1:

      mostrarNombresParques();

      cout<<"   --- Menu de Introduccion de Datos --- \n";
      cout<<"--- Por favor, introduzca el nombre del parque natural --- \n";
      getline(cin, aux);

      if(FileIO::getInstance->existsParque(aux) < 0) {
        cout<<"El parque que desea modificar no existe\n Volviendo al menú\n";
        break;
      }
      else{
        p.setNombre(aux);

        cout<<"--- Por favor, introduzca la fecha del nombramiento del parque natural --- \n";
        getline(cin, aux);
        p.setFechaNombramientoParque(aux);

        cout<<"--- Por favor, introduzca el tamaño del parque natural en kilometros cuadrados --- \n";
        cin>>tamano;
        p.setTamano(tamano);

        cout<<"--- Por favor, introduzca el nombre de los premios otorgados al parque natural, separado por comas --- \n";
        getline(cin, aux);
        p.setPremios(aux);

        cout<<"--- Por favor, introduzca una breve descripcion del parque natural --- \n";
        getline(cin, aux);
        p.setDescripcion(aux);

        p.setDisponibilidad(true);

        FileIO::getInstance->guardarParque(p);
        p.imprimirParque(p);
      }
    break;

    case 2:
      mostrarNombresParques();
      cout<<"--- Por favor, introduzca el nombre del parque natural a cambiar disponibilidad\n";
      cin>>aux;
      if(FileIO::getInstance->existsParque(aux) < 0) {
        cout<<"El parque que desea dar de baja no existe\n Volviendo al menú\n";
        break;
      }
      else{
        p.setNombre(aux);
        cout<<"Introduzca 1 si quiere que el parque este disponible y 0 en caso contrario"<<endl;
        cin>>tamano;
          while(tamano>1 || tamano<0){
            cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
            cin>>tamano;
          }

          if(tamano=1)
          {
            p.setDisponibilidad(true);
            if(p.getDisponibilidad()==false)
              {
                cout<<"ERROR al cambiar la disponibilidad del parque."<<endl;
                break;
              }
            else
              {
                cout<<"Disponibilidad cambiada con exito."<<endl;
              }
          }
          else if(tamano=0)
          {
            p.setDisponibilidad(false);
            if(p.getDisponibilidad()==true)
              {
                cout<<"ERROR al cambiar la disponibilidad del parque."<<endl;
                break;
              }
            else
              {
                cout<<"Disponibilidad cambiada con exito."<<endl;
              }
          }
        FileIO::getInstance->guardarParque(p);
        break;
      }

    case 3:

    mostrarNombresParques();
    cout<<"Introduzca el nombre del parque que quiere borrar"<<endl;
    cin>>aux;
    if(FileIO::getInstance->existsParque(aux) < 0) {
        cout<<"El parque que desea borrar no existe\n Volviendo al menú\n";
        break;
      }
    else{
      p.setNombre(aux);
      cout<<"--- ¿Esta seguro de que desea borrar el parque? ---\n";
      cout<<"--- Escriba 1 si desea confirmarlo, 0 en caso contrario ---\n";
      int decis;
      cin>>decis;
      if(decis==1){
        FileIO::getInstance->borrarParque(p);
      }
      if(decis==0){
        cout<<"Operación abortada\n";
      }
      else if{
        cout<<"Error en la confirmación, volviendo al menú\n";
      }
    }
      break;

    case 4:

      mostrarNombresParques();
      cout<<"Introduzca el nombre del parque que quiere mostrar por pantalla."<<endl;
      cin>>aux;
        if(FileIO::getInstance->existsParque(aux) < 0) {
          cout<<"El parque que desea mostrar no existe\n Volviendo al menú\n";
          break;
        }
      cout<<"--- A continuacion se mostrarán los datos del parque existente --- \n";

      list<parque> parques=getInstance()->GetTodosParques();
      for(parque &parque: parques){
        p=parque;
        if(aux==p.getNombre())
        {
          p.imprimirParque(p);
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
  string aux;
  int tamano;
  int exist;
  parque p;
  sendero s;

  while(){

    cout<<"   --- Gestion de Senderos --- \n";
    cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
    cout<<"--- 0) Añadir un nuevo Sendero a un Parque Natural. --- \n";
    cout<<"--- 1) Modificar los datos de un Sendero ya introducido. --- \n";
    cout<<"--- 2) Cambiar la disponibilidad de un Sendero. --- \n";
    cout<<"--- 3) Eliminar un Sendero. --- \n";
    cout<<"--- 4) Mostrar los datos de un Sendero ya introducido. --- \n";
    cout<<"--- 5) Volver al Menu Principal. --- \n";
    cin>>i;

    while(i<0||i>5){
      cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
      cin>>i;
    }
    switch(i){
    case 0:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    if(FileIO::getInstance->existsParque(nomParque)<0){
      cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    else{
      p.mostrarSenderosAsociados(nomParque);
      cout<<"--- Por favor, introduzca el nombre del nuevo sendero. --- \n";
      cin>>aux;
      if((exist = FileIO::getInstance->existsSendero(aux, nomParque))>=0){
      do{
        cout<<" Ya existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        cin>>aux;
        exist = FileIO::getInstance->existsSendero(aux, nomParque);
        }
      while(exist >=0);

      s.setNombre(aux);

      cout<<"--- Por favor, introduzca la longitud del nuevo sendero --- \n";
      cin>>tamano;
      s.setLongitud(tamano);

      cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
      cin>>aux;
      s.setDescripcion(aux);

      s.setDisponibilidad(true);

      FileIO::getInstance->guardarSendero(s, nomParque);
      s.imprimirSendero(s, nomParque);
    }
    break;

    case 1:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea modificar. --- \n";
    cin>>nomParque;

    if(FileIO::getInstance->existsParque(nomParque)<0){
      cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    else{
      p.mostrarSenderosAsociados(nomParque);
      cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
      cin>>aux;
      if((exist = FileIO::getInstance->existsSendero(aux, nomParque))<0){
      do{
        cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        cin>>aux;
        exist = FileIO::getInstance->existsSendero(aux, nomParque);
        }
      while(exist <0);

      s.setNombre(aux);

      cout<<"--- Por favor, introduzca la nueva longitud del sendero --- \n";
      cin>>tamano;
      s.setLongitud(tamano);

      cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
      cin>>aux;
      s.setDescripcion(aux);

      s.setDisponibilidad(true);

      FileIO::getInstance->guardarSendero(s, nomParque);
      s.imprimirSendero(s, nomParque);
    }
    break;

    case 2:
    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea modificar. --- \n";
    cin>>nomParque;

    if(FileIO::getInstance->existsParque(nomParque)<0){
      cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    else{
      p.mostrarSenderosAsociados(nomParque);
      cin>>aux;
      cout<<"--- Por favor, introduzca el nombre del sendero a dar de baja/alta. --- \n";
      cin>>aux;

      if((exist = FileIO::getInstance->existsSendero(aux, nomParque))<0){
      do{
        cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        cin>>aux;
        exist = FileIO::getInstance->existsSendero(aux, nomParque);
        }
      while(exist <0);

      s.setNombre(aux);

      cout<<"Introduzca 1 si quiere que el parque este disponible y 0 en caso contrario"<<endl;
      cin>>tamano;
        if(tamano>1 || tamano<0)
        {
          cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
          menuSenderos();
        }
        else if(tamano=1)
        {
          s.setDisponibilidad(true);
          if(s.getDisponibilidad()==false)
          {
            cout<<"ERROR al cambiar la disponibilidad del sendero."<<endl;
            menuSenderos();
          }
          else
          {
            cout<<"Disponibilidad cambiada con exito."<<endl;
          }
        }
        else if(tamano=0)
        {
          s.setDisponibilidad(false);
          if(s.getDisponibilidad()==true)
          {
            cout<<"ERROR al cambiar la disponibilidad del sendero."<<endl;
            menuSenderos();
          }
          else
          {
            cout<<"Disponibilidad cambiada con exito."<<endl;
          }
        }
      FileIO::getInstance->guardarSendero(s, nomParque);
    }

    break;

    case 3:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea modificar. --- \n";
    cin>>nomParque;

    if(FileIO::getInstance->existsParque(nomParque)<0){
      cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    else{
      p.mostrarSenderosAsociados(nomParque);
      cin>>aux;
      cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
      cin>>aux;

      if((exist = FileIO::getInstance->existsSendero(aux, nomParque))<0){
      do{
        cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        cin>>aux;
        exist = FileIO::getInstance->existsSendero(aux, nomParque);
        }
      while(exist <0);

      cout<<"--- ¿Esta seguro de que desea borrar el sendero? ---\n";
      cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
      int decis;
      cin>>decis;
      if(decis==1){
        FileIO::getInstance->borrarSenderos(aux,nomParque);
      }
      if(decis==0){
        cout<<"Operación abortada\n";
      }
      else if{
        cout<<"Error en la confirmación, volviendo al menú\n";
      }
    }
    break;

    case 4:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar. --- \n";
    cin>>nomParque;

    if(FileIO::getInstance->existsParque(nomParque)<0){
      cout<<" El parque indicado no existe. Volviendo al menu\n";
      break;
    }
    else{
      p.mostrarSenderosAsociados(nomParque);
      cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
      cin>>aux;

      if((exist = FileIO::getInstance->existsSendero(aux, nomParque))<0){
      do{
        cout<<" No existe un sendero con ese nombre. Introduzca otro nombre para el nuevo sendero. \n";
        cin>>aux;
        exist = FileIO::getInstance->existsSendero(aux, nomParque);
        }
      while(exist <0);
          parque aux;
          list<parque> parques = getInstance->getTodosParques();
          for(parque &parque : parques){
            if(nomParque == parque.getNombre()){
              aux = parque;
            }
          }
          s.imprimirSendero(s, aux);
      }
    }

    break;

    case 5:
    return(EXIT_SUCCESS);
    }
  }
}


int menuRutas(){

  int i;
  cout<<"   --- Gestion de Rutas --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir una nueva ruta a un Sendero de un Parque Natural. --- \n";
  cout<<"--- 1) Modificar los datos de una ruta ya introducida. --- \n";
  cout<<"--- 2) Finalizar una ruta. --- \n";
  cout<<"--- 3) Eliminar una ruta. --- \n";
  cout<<"--- 4) Mostrar los datos de una ruta ya introducida. --- \n";
  cout<<"--- 5) Volver al menu Principal. --- \n";
  cin>>i;

  while(i<0||i>5){
    cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin>>i;
  }
  switch(i){
    string aux="";
    int tamano=0;
    parque p;
    sendero s;
    ruta r;

    case 0:
    //
    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    FileIO::getInstance->existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      FileIO::getInstance->existsParque(nomParque);
    }
    while(FileIO::getInstance->existsParque (nomParque)<0);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    FileIO::getInstance->existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      FileIO::getInstance->existsSendero(aux, nomParque);
    }
    while(FileIO::getInstance->existsSendero(aux, nomParque)<0);
    s.setNombre(aux);


    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" Ya existe una ruta con ese nombre. Por favor, introduzca otro nombre para la ruta. \n";
      cin>>aux;
      FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    }
    while(FileIO::getInstance->existsRuta (aux, nomsendero, nomParque)=>0);
    r.setIdentidicador(aux);
    string id==aux;

    cout<<"--- Por favor, introduzca la dificultad de la nueva ruta. --- \n";
    cin>>aux;
    r.setDificultad(aux);

    cout<<"--- Por favor, introduzca el nombre del monitor que guia la ruta. --- \n";
    cin>>aux;
    r.setMonitorAsociado(aux);

    cout<<"--- Por favor, introduzca la fecha en la que se realiza la ruta. --- \n";
    cin>>aux;
    fechaValida(aux);
    do{
    cout<<"La fecha introducida no es valida. Por favor, introduzca una fecha valida. \n"
    cin>>aux;
    fechaValida(aux)
    }while(fechaValida==false);
    r.setFecha(aux);

    cout<<"--- Por favor, introduzca la hora a la que se realiza la ruta --- \n";
    cin>>aux;
    do{
    cout<<"La hora introducida no es valida. Por favor, introduzca una hora valida. \n"
    cin>>aux;
    horaValida(aux)
    }while(horaValida==false);
    r.setHora(aux);

    cout<<"--- Por favor, introduzca la duracion estimada de la ruta en minutos --- \n";
    cin>>tamano;
    r.setDuracionEstimada(tamano);

    cout<<"--- Por favor, indique si la ruta se puede realizar en bicicleta o no. --- \n";
    cin>>aux;
    r.setBicicleta(aux);

    FileIO::getInstance->guardarRuta(id, nomsendero,nomParque);
    r.imprimirRuta(id, nomsendero, nomParque);

    //
    break;

    case 1:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    FileIO::getInstance->existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      FileIO::getInstance->existsParque(nomParque);
    }
    while(FileIO::getInstance->existsParque (nomParque)<0);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    FileIO::getInstance->existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      FileIO::getInstance->existsSendero(aux, nomParque);
    }
    while(FileIO::getInstance->existsSendero(aux, nomParque)<0);
    s.setNombre(aux);


    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      cin>>aux;
      FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    }
    while(FileIO::getInstance->existsRuta (aux, nomsendero, nomParque)<0);
    r.setIdentidicador(aux);
    string id==aux;


    cout<<"--- Por favor, introduzca la dificultad de la ruta. --- \n";
    cin>>aux;
    r.setDificultad(aux);

    cout<<"--- Por favor, introduzca el nombre del monitor que guia la ruta. --- \n";
    cin>>aux;
    r.setMonitorAsociado(aux);

    cout<<"--- Por favor, introduzca la fecha en la que se realiza la ruta. --- \n";
    cin>>aux;
    fechaValida(aux);
    do{
    cout<<"La fecha introducida no es valida. Por favor, introduzca una fecha valida. \n"
    cin>>aux;
    fechaValida(aux)
    }while(fechaValida==false);
    r.setFecha(aux);

    cout<<"--- Por favor, introduzca la hora a la que se realiza la ruta --- \n";
    cin>>aux;
    do{
    cout<<"La hora introducida no es valida. Por favor, introduzca una hora valida. \n"
    cin>>aux;
    horaValida(aux)
    }while(horaValida==false);
    r.setHora(aux);

    cout<<"--- Por favor, introduzca la duracion estimada de la ruta en minutos --- \n";
    cin>>tamano;
    r.setDuracionEstimada(tamano);

    cout<<"--- Por favor, indique si la ruta se puede realizar en bicicleta o no. --- \n";
    cin>>aux;
    r.setBicicleta(aux);

    FileIO::getInstance->guardarRuta(id, nomsendero,nomParque);
    r.imprimirRuta(id, nomsendero, nomParque);

    break;

    case 2:
    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    FileIO::getInstance->existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      FileIO::getInstance->existsParque(nomParque);
    }
    while(FileIO::getInstance->existsParque (nomParque)<0);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    FileIO::getInstance->existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      FileIO::getInstance->existsSendero(aux, nomParque);
    }
    while(FileIO::getInstance->existsSendero(aux, nomParque)<0);
    s.setNombre(aux);

    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      cin>>aux;
      FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    }
    while(FileIO::getInstance->existsRuta (aux, nomsendero, nomParque)<0);
    r.setIdentidicador(aux);
    string id==aux;

    cout<<"Introduzca 1 si quiere finalizar la ruta y 0 en caso contrario"<<endl;
    cin>>tamano;
      if(tamano>1 || tamano<0)
      {
        cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
        menuSenderos();
      }
      else if(tamano=1)
      {
        r.setDisponibilidad(true);
        if(r.getDisponibilidad()==false)
         {
           cout<<"ERROR al finalizar la ruta."<<endl;
          menuSenderos();
         }
         else
         {
           cout<<"Ruta finalizada con exito."<<endl;
         }
      }
      else if(tamano=0)
      {
        r.setDisponibilidad(false);
        if(r.getDisponibilidad()==true)
         {
           cout<<"ERROR al finalizar la ruta."<<endl;
          menuSenderos();
         }
         else
         {
           cout<<"Disponibilidad cambiada con exito."<<endl;
         }
      }
    FileIO::getInstance->guardarRuta(id, nomsendero,nomParque);
    break;

    case 3:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    FileIO::getInstance->existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      FileIO::getInstance->existsParque(nomParque);
    }
    while(FileIO::getInstance->existsParque (nomParque)<0);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    FileIO::getInstance->existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      FileIO::getInstance->existsSendero(aux, nomParque);
    }
    while(FileIO::getInstance->existsSendero(aux, nomParque)<0);
    s.setNombre(aux);


    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      cin>>aux;
      FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    }
    while(FileIO::getInstance->existsRuta (aux, nomsendero, nomParque)<0);
    r.setIdentidicador(aux);
    string id==aux;

    cout<<"--- ¿Esta seguro de que desea borrar la ruta? ---\n";
    cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
    int decis;
    cin>>decis;
    if(decis==1){
      FileIO::getInstance->borrarRuta(id, nomsendero, nomParque);
    }
    if(decis==0){
      menuRutas();
    }
    break;

    case 4:
    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    FileIO::getInstance->existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      FileIO::getInstance->existsParque(nomParque);
    }
    while(FileIO::getInstance->existsParque (nomParque)<0);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    FileIO::getInstance->existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      FileIO::getInstance->existsSendero(aux, nomParque);
    }
    while(FileIO::getInstance->existsSendero(aux, nomParque)<0);
    s.setNombre(aux);

    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";

      cin>>aux;
      FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
    }
    while(FileIO::getInstance->existsRuta (aux, nomsendero, nomParque)<0);
    r.setIdentidicador(aux);
    string id==aux;
    for(ruta &ruta: rutas)
    {
      if(aux==r.getNombre())
      {
        r.imprimirRuta(id, nomsendero, nomParque);
      }
    }
    break;

    case 5:
      menuAdmin();
    break;

  }
}


int menuVisitantes(){

  int i;
  cout<<"   --- Gestion de Visitantes --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir un nuevo un visitante. --- \n";
  cout<<"--- 1) Modificar los datos de visitante ya introducido. --- \n";
  cout<<"--- 2) Cancelar visita. --- \n";
  cout<<"--- 3) Mostrar los datos de un visitante ya introducido. --- \n";
  cout<<"--- 4) Asignar visitante a una ruta. --- \n";
  cout<<"--- 5) Volver al menu principal. --- \n";
  cin>>i;

  while(i<0||i>5){
    cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin>>i;
  }
  switch(i){
    string aux="";
    int tamano=0;
    parque p;
    sendero s;
    ruta r;
    visitante v;


  case 0:

  cout<<"Por favor, introduzca el DNI del nuevo visitante";
  cin>>aux;
  FileIO::getInstance->existsVisitante(aux);

  do{
    cout<<"Ya existe un visitante con ese DNI. Por favor, introduzca otro DNI para el nuevo visitante";
    cin>>aux;
  }while(FileIO::getInstance->existsVisitante(aux)==-1);
  string dni==aux;
  v.setDNI(aux);

  cout<<"--- Por favor, introduzca el nombre completo del nuevo visitante. --- \n";
  cin>>aux;
  v.setNombreCompleto(aux);

  cout<<"--- Por favor, introduzca el numero de telefono del nuevo visitante. --- \n";
  cin>>aux;
  v.setNumeroDeTlfn(aux);

  cout<<"--- Por favor, introduzca la fecha de nacimiento del nuevo visitante. --- \n";
  cin>>aux;
  v.setFechaDeNacimiento(aux);

  cout<<"--- Por favor, introduzca cualquier condicion del visitante a tener en cuenta. --- \n";
  cin>>aux;
  v.setCondicion(aux);

  FileIO::getInstance->guardarVisitante(v);
  v.imprimirVisitante(v);

  break;

  case 1:
  v.mostrarTodosVisitantes();
  cout<<"Por favor, introduzca el DNI del visitante a Modificar";
  cin>>aux;
  FileIO::getInstance->existsVisitante(aux);

  do{
    cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    cin>>aux;
  }while(FileIO::getInstance->existsVisitante(aux)==-2);
  string dni==aux;
  v.setDNI(aux);

  cout<<"--- Por favor, introduzca el nombre completo del visitante. --- \n";
  getline(cin, aux);
  v.setNombreCompleto(aux);

  cout<<"--- Por favor, introduzca el numero de telefono del visitante. --- \n";
  getline(cin, aux);
  v.setNumeroDeTlfn(aux);

  cout<<"--- Por favor, introduzca la fecha de nacimiento del visitante. --- \n";
  getline(cin, aux);
  v.setFechaDeNacimiento(aux);

  cout<<"--- Por favor, introduzca cualquier condicion del visitante a tener en cuenta. --- \n";
  getline(cin, aux);
  v.setCondicion(aux);

  FileIO::getInstance->guardarVisitante(v);
  v.imprimirVisitante(v);


  break;

  case 2:
  v.mostrarTodosVisitantes();
  cout<<"Por favor, introduzca el DNI del visitante cuya visita quiere cancelar.";
  cin>>aux;
  FileIO::getInstance->existsVisitante(aux);

  do{
    cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    cin>>aux;
  }while(FileIO::getInstance->existsVisitante(aux)==-2);
  string dni==aux;

  cout<<"--- ¿Esta seguro de que desea cancelar la visita? ---\n";
  cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
  int decis;
  cin>>decis;
  if(decis==1){
    FileIO::getInstance->borrarVisitante(v);
  }
  if(decis==0){
    menuVisitantes();
  }

  break;

  case 3:
  v.mostrarTodosVisitantes();
  cout<<"Por favor, introduzca el DNI del visitante cuyos datos quiere ver";
  cin>>aux;
  FileIO::getInstance->existsVisitante(aux);

  do{
    cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    cin>>aux;
  }while(FileIO::getInstance->existsVisitante(aux)==-2);
  string dni==aux;

  for(visitante &visitante: visitantes)
  {
    if(aux==v.getDNI())
    {
      v.imprimirRuta(v);
    }
  }
  break;

  case 4:
  v.getTodosVisitantes()
  string nomParque;
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
  cin>>nomParque;
  FileIO::getInstance->existsParque(nomParque);
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    FileIO::getInstance->existsParque(nomParque);
  }
  while(FileIO::getInstance->existsParque (nomParque)==-2);

  p.mostrarSenderosAsociados(nomParque);
  cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
  cin>>aux;
  FileIO::getInstance->existsSendero(aux, nomParque);
  do{
    cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
    cin>>aux;
    FileIO::getInstance->existsSendero(aux, nomParque);
  }
  while(FileIO::getInstance->existsSendero(aux, nomParque)==-2);
  s.setNombre(aux);

  string nomsendero==aux;
  s.mostrarRutasAsociadas(nomsendero, nomParque);
  cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
  cin>>aux;
  FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
  do{
    cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
    cin>>aux;
    FileIO::getInstance->existsRuta (aux, nomsendero, nomParque);
  }
  while(FileIO::getInstance->existsRuta (aux, nomsendero, nomParque)==-2);
  r.setIdentidicador(aux);
  string id==aux;

  cout<<"Por favor, introduzca el DNI del visitante al que asignar a la ruta";
  cin>>aux;
  existsVisitante(aux);

  do{
    cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    cin>>aux;
  }while(existsVisitante(aux)==-2);
  string dni==aux;

  FileIO::getInstance->guardarVisitanteARuta(&v,id,nomsendero,nomParque);

  break;

  case 5:
    menuMonitor();
  break;
}
}

int menuMonitores(){

  int i;
  cout<<"   --- Gestion de Monitores --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir un nuevo monitor. --- \n";
  cout<<"--- 1) Modificar los datos de un monitor ya introducido. --- \n";
  cout<<"--- 2) Dar de baja / alta a un monitor. --- \n";
  cout<<"--- 3) Mostrar los datos de un monitor ya introducido. --- \n";
  cout<<"--- 4) Eliminar un monitor del sistema. --- \n";
  cout<<"--- 5) Volver al menu principal. --- \n";
  cin>>i;

  while(i<0||i>5){
    cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin>>i;
  }
  switch(i){
    string aux="";
    int tamano=0;
    parque p;
    sendero s;
    ruta r;
    visitante v;
    monitor m;

    case 0:

    cout<<"Por favor, introduzca el DNI del nuevo monitor";
    cin>>aux;
    FileIO::getInstance->existsMonitor(aux);

    do{
      cout<<"Ya existe un monitor con ese DNI. Por favor, introduzca otro DNI para el nuevo monitor";
      cin>>aux;
    }while(FileIO::getInstance->existsMonitor(aux)==-1);
    string dni==aux;
    m.setDNI(aux);

    cout<<"--- Por favor, introduzca el nombre completo del Monitor. --- \n";
    cin>>aux;
    m.setNombreCompleto(aux);

    cout<<"--- Por favor, introduzca el numero de telefono del Monitor. --- \n";
    cin>>aux;
    m.setNumeroDeTlfn(aux);

    cout<<"--- Por favor, introduzca la fecha de nacimiento del Monitor. --- \n";
    cin>>aux;
    m.setFechaDeNacimiento(aux);

    cout<<"--- Por favor, introduzca cualquier condicion a tener en cuenta . --- \n";
    cin>>aux;
    m.setCondicion(aux);

    m.setHorasTrabajadas(0);

    m.setDisponibilidad(true);

    FileIO::getInstance->guardarMonitor(&m);
    m.imprimirMonitor(&m);
    break;

    case 1:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    FileIO::getInstance->existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(FileIO::getInstance->existsMonitor(aux)==-2);
    string dni==aux;

    cout<<"--- Por favor, introduzca el nombre completo del Monitor. --- \n";
    getline(cin,aux);
    m.setNombreCompleto(aux);

    cout<<"--- Por favor, introduzca el numero de telefono del Monitor. --- \n";
    getline(cin,aux);
    m.setNumeroDeTlfn(aux);

    cout<<"--- Por favor, introduzca la fecha de nacimiento del Monitor. --- \n";
    getline(cin,aux);
    m.setFechaDeNacimiento(aux);

    cout<<"--- Por favor, introduzca cualquier condicion a tener en cuenta . --- \n";
    getline(cin,aux);
    m.setCondicion(aux);

    cout<<"--- Por favor, introduzca las horas trabajadas del Monitor. --- \n";
    getline(cin,tamano);
    m.setHorasTrabajadas(tamano);

    m.setDisponibilidad(true);

    FileIO::getInstance->guardarMonitor(&m);
    m.imprimirMonitor(&m);

    break;

    case 2:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    FileIO::getInstance->existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(FileIO::getInstance->existsMonitor(aux)==-2);
    string dni==aux;
    m.setDNI(dni);

    cout<<"Introduzca 1 si quiere que el monitor este disponible y 0 en caso contrario"<<endl;
    cin>>tamano;
      if(tamano>1 || tamano<0)
      {
        cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
        menuParques();
      }
      else if(tamano=1)
      {
        m.setDisponibilidad(true);
        if(m.getDisponibilidad()==false)
         {
           cout<<"ERROR al cambiar la disponibilidad del monitor."<<endl;
           menuParques();
         }
         else
         {
           cout<<"Disponibilidad cambiada con exito."<<endl;
         }
      }
      else if(tamano=0)
      {
        m.setDisponibilidad(false);
        if(m.getDisponibilidad()==true)
         {
           cout<<"ERROR al cambiar la disponibilidad del monitor."<<endl;
           menuParques();
         }
         else
         {
           cout<<"Disponibilidad cambiada con exito."<<endl;
         }
      }
    FileIO::getInstance->guardarMonitor(&m);


    break;

    case 3:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    FileIO::getInstance->existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(FileIO::getInstance->existsMonitor(aux)==-2);
    string dni==aux;

    for(monitor &monitor: monitores)
    {
      if(aux==m.getDNI())
      {
        m.imprimirMonitor(&m);
      }
    }

    break;

    case 4:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    FileIO::getInstance->existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(FileIO::getInstance->existsMonitor(aux)==-2);
    string dni==aux;

    cout<<"--- ¿Esta seguro de que desea eliminar ? ---\n";
    cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
    int decis;
    cin>>decis;
    if(decis==1){
      FileIO::getInstance->borrarMonitor(&m);
    }
    if(decis==0){
      menuMonitores();
    }


    break;

    case 5:
      menuAdmin();
    break;
}
}
