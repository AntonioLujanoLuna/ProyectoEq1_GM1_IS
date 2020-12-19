//menus.cc
//proyecto IS
#include "menus.h"
#include "parques.h"
#include "senderos.h"
#include "rutas.h"
#include "monitores.h"
#include "visitantes.h"
#include "persona.h"
#include "fileIO.h"
#include "extra.h"
#include <list>

using namespace std;
FileIO f;

int menuAdmin(){
    int opc;
      cout<<"--- Contraseña correcta. Bienvenido al sistema. ---\n";
      cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
      cout<<"--- 0) Gestion de Parques Naturales. ---\n";
      cout<<"--- 1) Gestion de Senderos. ---\n";
      cout<<"--- 2) Gestion de Visitantes. ---\n";
      cout<<"--- 3) Gestion de Monitores. ---\n";
      cout<<"--- 4) Salir del menu. ---\n";
      cin<<opc;

      while(opc<0||opc>4){
        cout<<" Opcion invalida. Por favor, seleccione una opcion valida. \n";
        cin<<opc;
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

int menuMonitor(){
  int seleccion;
  cout<<"--- DNI correcto. Bienvenido al sistema. ---\n";
  cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
  cout<<"--- 0) Gestion de Rutas. ---\n";
  cout<<"--- 1) Salir del menu ---\n";
  cin<<seleccion;

    switch(seleccion){
      while(seleccion<0||seleccion>1){
        cout<<"Opcion invalida. Por favor seleccione una opcion valida \n";
        cin<<seleccion;
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
    if (password == admingestionJA){
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
    if (){
        cout<<"DNI correcto\n";
        return true;
    }
    else {
        cout<<" DNI incorrecto.";
        printf("Quedan %d intentos", 3-i);
    }
  }
cout<<"Maximo numero de intentos permitido alcanzado\n"
return false;
}


int menuParques(){
  int i;
  cout<<"   --- Gestion de Parques --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir un nuevo Parque Natural. --- \n";
  cout<<"--- 1) Modificar los datos de un Parque Natural ya introducido. --- \n";
  cout<<"--- 2) Cambiar la disponibilidad de un Parque Natural. --- \n";
  cout<<"--- 3) Eliminar un Parque Natural. --- \n";
  cout<<"--- 4) Mostrar los datos de un Parque Natural ya introducido. --- \n";
  cout<<"--- 5) Volver al menu Principal --- \n";
  cin<<i;

  while(i<0||i>5){
    cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin<<i;
  }
  switch(i){
    string aux="";
    int tamano=0;
    parque p;
  case 0:
  //
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

  f.guardarParque(p);
  p.imprimirParque();


  //
  break;

  case 1:
  //
  mostrarNombresParques();

  cout<<"   --- Menu de Introduccion de Datos --- \n";
  cout<<"--- Por favor, introduzca el nombre del parque natural --- \n";
  getline(cin, aux);
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

  f.guardarParque(p);
  p.imprimirParque();

  break;

  case 2:
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque natural a cambiar disponibilidad\n";
  cin>>aux;
  p.setNombre(aux);
  cout<<"Introduzca 1 si quiere que el parque este disponible y 0 en caso contrario"<<endl;
  cin>>tamano;
    if(tamano>1 || tamano<0)
    {
      cout<<"ERROR, numero no valido. Debe introducir 1 o 0"<<endl;
      menuParques();
    }
    else if(tamano=1)
    {
      p.setDisponibilidad(true);
      if(p.getDisponibilidad()==false)
       {
         cout<<"ERROR al cambiar la disponibilidad del parque."<<endl;
         menuParques();
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
         menuParques();
       }
       else
       {
         cout<<"Disponibilidad cambiada con exito."<<endl;
       }
    }
  f.guardarParque(p);
  break;

  case 3:
  //
  mostrarNombresParques();
  cout<<"Introduzca el nombre del parque que quiere borrar"<<endl;
  cin>>aux;
  p.setNombre(aux);
  cout<<"--- ¿Esta seguro de que desea borrar el parque? ---\n";
  cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
  int decis;
  cin<<decis;
  if(decis==1){
    f.borrarParque(p);
  }
  if(decis==0){
    menuParques();
  }

  break;

  case 4:
  //
  mostrarNombresParques();
  cout<<"Introduzca el nombre del parque que quiere mostrar por pantalla."<<endl;
  cin>>aux;
  cout<<"--- A continuacion se mostrarán los datos del parque existente --- \n";

  list<parque> parques=getInstance()->GetTodosParques();
  for(parque &parque: parques)
  {
    if(aux==p.getNombre())
    {
      p.imprimirParque();
    }
  }

  //
  break;

  case 5:
    menuAdmin();
  break;
}
}

int menuSenderos(){
  int i;
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
    string aux="";
    int tamano=0;
    parque p;
    sendero s;

  case 0:
  //
  string nomParque;
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
  cin>>nomParque;
  f.existsParque(nomParque);
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    f.existsParque(nomParque);
  }
  while(f.existsParque (nomParque)==-2);

  p.mostrarSenderosAsociados(nomParque);
  cin>>aux;
  cout<<"--- Por favor, introduzca el nombre del nuevo sendero. --- \n";
  cin>>aux;
  f.existsSendero(aux, nomParque);
  do{
    cout<<" Ya existe un sendero con ese nombre. Introduzca otra nombre para el nuevo sendero. \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
  }
  while(f.existsSendero(aux, nomParque)==-1);

  s.setNombre(aux);

  cout<<"--- Por favor, introduzca la longitud del nuevo sendero --- \n";
  cin>>tamano;
  s.setLongitud(tamano);

  cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
  cin>>aux;
  s.setDescripcion(aux);

  s.setDisponibilidad(true);

  f.guardarSendero(s, nomParque);
  s.imprimirSendero();

  //
  break;

  case 1:
  //
  string nomParque;
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar. --- \n";
  cin>>nomParque;


  f.existsParque(nomParque);
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    f.existsParque(nomParque);
  }
  while(f.existsParque (nomParque)==-2);

  p.mostrarSenderosAsociados(nomParque);
  cin>>aux;
  cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
  cin>>aux;
  f.existsSendero(aux, nomParque);
  do{
    cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero que desea modificar. \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
  }
  while(f.existsSendero(aux, nomParque)==-2);

  s.setNombre(aux);

  cout<<"--- Por favor, introduzca la longitud del sendero --- \n";
  cin>>tamano;
  s.setLongitud(tamano);

  cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
  getline(cin, aux);
  s.setDescripcion(aux);

  s.setDisponibilidad(true);

  f.guardarSendero(s, nomParque);
  s.imprimirSendero();
  //

  break;

  case 2:
  string nomParque;
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar. --- \n";
  cin>>nomParque;


  f.existsParque(nomParque);
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    f.existsParque(nomParque);
  }
  while(f.existsParque (nomParque)==-2);

  p.mostrarSenderosAsociados(nomParque);
  cin>>aux;
  cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
  cin>>aux;
  f.existsSendero(aux, nomParque);
  do{
    cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero que desea modificar. \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
  }
  while(f.existsSendero(aux, nomParque)==-2);
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
  f.guardarSendero(s, nomParque);
  break;

  case 3:
  //
  string nomParque;
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar. --- \n";
  cin>>nomParque;


  f.existsParque(nomParque);
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    f.existsParque(nomParque);
  }
  while(f.existsParque (nomParque)==-2);

  p.mostrarSenderosAsociados(nomParque);
  cin>>aux;
  cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
  cin>>aux;
  f.existsSendero(aux, nomParque);
  do{
    cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero que desea modificar. \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
  }
  while(f.existsSendero(aux, nomParque)==-2);
  s.setNombre(aux);


  cout<<"--- ¿Esta seguro de que desea borrar el sendero? ---\n";
  cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
  int decis;
  cin<<decis;
  if(decis==1){
    f.borrarSenderos(aux,nomParque);
  }
  if(decis==0){
    menuSenderos();
  }
  break;

  case 4:

  string nomParque;
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar. --- \n";
  cin>>nomParque;

  f.existsParque(nomParque);
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    f.existsParque(nomParque);
  }
  while(f.existsParque (nomParque)==-2);

  p.mostrarSenderosAsociados(nomParque);
  cin>>aux;
  cout<<"--- Por favor, introduzca el nombre del sendero a modificar. --- \n";
  cin>>aux;
  f.existsSendero(aux, nomParque);
  do{
    cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero que desea modificar. \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
  }
  while(existsSendero(aux, nomParque)==-2);
  s.setNombre(aux);


  for(sendero &sendero: senderos)
  {
    if(aux==s.getNombre())
    {
      s.imprimirSendero();
    }
  }
  break;

  case 5:
    menuAdmin();
  break;

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
    f.existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      f.existsParque(nomParque);
    }
    while(f.existsParque (nomParque)==-2);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      f.existsSendero(aux, nomParque);
    }
    while(f.existsSendero(aux, nomParque)==-2);
    s.setNombre(aux);


    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    f.existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" Ya existe una ruta con ese nombre. Por favor, introduzca otro nombre para la ruta. \n";
      cin>>aux;
      f.existsRuta (aux, nomsendero, nomParque);
    }
    while(f.existsRuta (aux, nomsendero, nomParque)==-1);
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

    f.guardarRuta(id, nomsendero,nomParque);
    r.imprimirRuta();

    //
    break;

    case 1:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    f.existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      f.existsParque(nomParque);
    }
    while(f.existsParque (nomParque)==-2);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      f.existsSendero(aux, nomParque);
    }
    while(f.existsSendero(aux, nomParque)==-2);
    s.setNombre(aux);


    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    f.existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      cin>>aux;
      f.existsRuta (aux, nomsendero, nomParque);
    }
    while(f.existsRuta (aux, nomsendero, nomParque)==-2);
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

    f.guardarRuta(id, nomsendero,nomParque);
    r.imprimirRuta();

    break;

    case 2:
    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    f.existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      f.existsParque(nomParque);
    }
    while(f.existsParque (nomParque)==-2);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      f.existsSendero(aux, nomParque);
    }
    while(f.existsSendero(aux, nomParque)==-2);
    s.setNombre(aux);

    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    f.existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      cin>>aux;
      f.existsRuta (aux, nomsendero, nomParque);
    }
    while(f.existsRuta (aux, nomsendero, nomParque)==-2);
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
    f.guardarRuta(id, nomsendero,nomParque);
    break;

    case 3:

    string nomParque;
    mostrarNombresParques();
    cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
    cin>>nomParque;
    f.existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      f.existsParque(nomParque);
    }
    while(f.existsParque (nomParque)==-2);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      f.existsSendero(aux, nomParque);
    }
    while(f.existsSendero(aux, nomParque)==-2);
    s.setNombre(aux);


    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    f.existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      cin>>aux;
      f.existsRuta (aux, nomsendero, nomParque);
    }
    while(f.existsRuta (aux, nomsendero, nomParque)==-2);
    r.setIdentidicador(aux);
    string id==aux;

    cout<<"--- ¿Esta seguro de que desea borrar la ruta? ---\n";
    cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
    int decis;
    cin<<decis;
    if(decis==1){
      f.borrarRuta(id, nomsendero, nomParque);
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
    f.existsParque(nomParque);
    do{
      cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
      cin>>nomParque;
      f.existsParque(nomParque);
    }
    while(f.existsParque (nomParque)==-2);


    p.mostrarSenderosAsociados(nomParque);
    cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
    do{
      cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
      cin>>aux;
      f.existsSendero(aux, nomParque);
    }
    while(f.existsSendero(aux, nomParque)==-2);
    s.setNombre(aux);

    string nomsendero==aux;
    s.mostrarRutasAsociadas(nomsendero, nomParque);
    cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
    cin>>aux;
    f.existsRuta (aux, nomsendero, nomParque);
    do{
      cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
      cin>>aux;
      f.existsRuta (aux, nomsendero, nomParque);
    }
    while(f.existsRuta (aux, nomsendero, nomParque)==-2);
    r.setIdentidicador(aux);
    string id==aux;
    for(ruta &ruta: rutas)
    {
      if(aux==r.getNombre())
      {
        r.imprimirRuta();
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
  f.existsVisitante(aux);

  do{
    cout<<"Ya existe un visitante con ese DNI. Por favor, introduzca otro DNI para el nuevo visitante";
    cin>>aux;
  }while(f.existsVisitante(aux)==-1);
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

  f.guardarVisitante(&v);
  v.imprimirVisitante();

  break;

  case 1:
  v.mostrarTodosVisitantes();
  cout<<"Por favor, introduzca el DNI del visitante a Modificar";
  cin>>aux;
  f.existsVisitante(aux);

  do{
    cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    cin>>aux;
  }while(f.existsVisitante(aux)==-2);
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

  f.guardarVisitante(&v);
  v.imprimirVisitante();


  break;

  case 2:
  v.mostrarTodosVisitantes();
  cout<<"Por favor, introduzca el DNI del visitante cuya visita quiere cancelar.";
  cin>>aux;
  f.existsVisitante(aux);

  do{
    cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    cin>>aux;
  }while(f.existsVisitante(aux)==-2);
  string dni==aux;

  cout<<"--- ¿Esta seguro de que desea cancelar la visita? ---\n";
  cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
  int decis;
  cin<<decis;
  if(decis==1){
    f.borrarVisitante(&v);
  }
  if(decis==0){
    menuVisitantes();
  }

  break;

  case 3:
  v.mostrarTodosVisitantes();
  cout<<"Por favor, introduzca el DNI del visitante cuyos datos quiere ver";
  cin>>aux;
  f.existsVisitante(aux);

  do{
    cout<<"No existe ningun visitante con ese DNI. Por favor, introduzca el DNI del visitante.";
    cin>>aux;
  }while(f.existsVisitante(aux)==-2);
  string dni==aux;

  for(visitante &visitante: visitantes)
  {
    if(aux==v.getDNI())
    {
      v.imprimirRuta();
    }
  }
  break;

  case 4:
  v.getTodosVisitantes()
  string nomParque;
  mostrarNombresParques();
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
  cin>>nomParque;
  f.existsParque(nomParque);
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    f.existsParque(nomParque);
  }
  while(f.existsParque (nomParque)==-2);

  p.mostrarSenderosAsociados(nomParque);
  cout<<"--- Por favor, introduzca el nombre del sendero. --- \n";
  cin>>aux;
  f.existsSendero(aux, nomParque);
  do{
    cout<<" El sendero no existe. Por favor, introduzca el nombre del sendero cuyas rutas quiere ver. \n";
    cin>>aux;
    f.existsSendero(aux, nomParque);
  }
  while(f.existsSendero(aux, nomParque)==-2);
  s.setNombre(aux);

  string nomsendero==aux;
  s.mostrarRutasAsociadas(nomsendero, nomParque);
  cout<<"--- Por favor, introduzca el nombre de la ruta. --- \n";
  cin>>aux;
  f.existsRuta (aux, nomsendero, nomParque);
  do{
    cout<<" No existe la ruta. Por favor, introduzca el nombre de la ruta. \n";
    cin>>aux;
    f.existsRuta (aux, nomsendero, nomParque);
  }
  while(f.existsRuta (aux, nomsendero, nomParque)==-2);
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

  f.guardarVisitanteARuta(&v,id,nomsendero,nomParque);

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
    f.existsMonitor(aux);

    do{
      cout<<"Ya existe un monitor con ese DNI. Por favor, introduzca otro DNI para el nuevo monitor";
      cin>>aux;
    }while(f.existsMonitor(aux)==-1);
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

    f.guardarMonitor(&m);
    m.imprimirMonitor();
    break;

    case 1:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    f.existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(f.existsMonitor(aux)==-2);
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

    f.guardarMonitor(&m);
    m.imprimirMonitor();

    break;

    case 2:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    f.existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(f.existsMonitor(aux)==-2);
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
    f.guardarMonitor(&m);


    break;

    case 3:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    f.existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(f.existsMonitor(aux)==-2);
    string dni==aux;

    for(monitor &monitor: monitores)
    {
      if(aux==m.getDNI())
      {
        m.imprimirMonitor();
      }
    }

    break;

    case 4:

    cout<<"Por favor, introduzca el DNI del monitor";
    cin>>aux;
    f.existsMonitor(aux);

    do{
      cout<<"No existe un monitor con ese DNI. Por favor, introduzca el DNI del monitor cuyos datos quiere modificar.";
      cin>>aux;
    }while(f.existsMonitor(aux)==-2);
    string dni==aux;

    cout<<"--- ¿Esta seguro de que desea eliminar ? ---\n";
    cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
    int decis;
    cin<<decis;
    if(decis==1){
      f.borrarMonitor(&m);
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
