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
  cout<<"--- 5) Salir del programa. --- \n";
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
  //Funcion que compruebe que el nombre del parque ya exista
  //Funcion que pida nuevo nombre en caso de que exista
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

  guardarParque(p);

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
  guardarParque(p);
  //Funcion que devuelva los senderos Asociados
  p.imprimirParque();
  //
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
  guardarParque(p);
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
    borrarParque(p);
  if(decis==0){
    menuParques();
  }
  //
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
    if(aux==parque.getNombre())
    {
      parque.imprimirParque();
    }
  }

  //
  break;

  case 5:
    return 0;
  break;
}
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
  cout<<"--- 5) Salir del programa. --- \n";
  cin>>i;

  while(i<0||i>5){
    cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin>>i;
  }
  switch(i){
    string aux="";
    int tamano=0;
    sendero s;
  case 0:
  //
  string nomParque;
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos quiere ver. --- \n";
  cin>>nomParque;
  mostrarNombresParques();
  list<sendero> getSenderosParque(nomParque);
  cin>>aux;

  //Funcion que compruebe que el nombre del parque ya exista
  //Funcion que pida nuevo nombre en caso de que exista
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    existsParque(nomParque);
  }
  while(existsParque (nomParque)==-2);


  cout<<"--- Por favor, introduzca el nombre del nuevo sendero. --- \n";
  cin>>aux;
  s.setNombre(aux);

  cout<<"--- Por favor, introduzca la longitud del nuevo sendero --- \n";
  cin>>tamano;
  s.setLongitud(tamano);

  cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
  cin>>aux;
  s.setDescripcion(aux);

  guardarSendero(s, nomParque);
  s.imprimirSendero();


  //
  break;

  case 1:
  //
  string nomParque;
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar. --- \n";
  cin>>nomParque;
  mostrarNombresParques();
  list<sendero> getSenderosParque(nomParque);
  cin>>aux;

  //Funcion que compruebe que el nombre del parque ya exista
  //Funcion que pida nuevo nombre en caso de que exista
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    existsParque(nomParque);
  }
  while(existsParque (nomParque)==-2);

  list<sendero> getSenderosParque(nomParque);

  cout<<"--- Por favor, introduzca el nombre del sendero a cambiar modificar\n";
  cin>>aux;
  s.setNombre(aux);

  cout<<"--- Por favor, introduzca el nombre del sendero --- \n";
  getline(cin, aux);
  s.setNombre(aux);

  cout<<"--- Por favor, introduzca la longitud del sendero --- \n";
  cin>>tamano;
  s.setLongitud(tamano);

  cout<<"--- Por favor, introduzca una breve descripcion del sendero --- \n";
  getline(cin, aux);
  s.setDescripcion(aux);


  guardarSendero(s, nomParque)
  s.imprimirSendero();
  //

  break;

  case 2:
  mostrarNombresParques();

  string nomParque;
  cout<<"--- Por favor, introduzca el nombre del parque cuyos senderos desea modificar la disponibilidad. --- \n";
  cin>>nomParque;
  cin>>aux;

  //Funcion que compruebe que el nombre del parque ya exista
  //Funcion que pida nuevo nombre en caso de que exista
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    existsParque(nomParque);
  }
  while(existsParque (nomParque)==-2);

  list<sendero> getSenderosParque(nomParque);

  cout<<"--- Por favor, introduzca el nombre del sendero a cambiar disponibilidad\n";
  cin>>aux;
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
  guardarSendero(s, nomParque);
  break;

  case 3:
  //
  string nomParque;
  cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea eliminar. --- \n";
  cin>>nomParque;
  mostrarNombresParques();
  list<sendero> getSenderosParque(nomParque);
  cin>>aux;

  //Funcion que compruebe que el nombre del parque ya exista
  //Funcion que pida nuevo nombre en caso de que exista
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    existsParque(nomParque);
  }
  while(existsParque (nomParque)==-2);

  list<sendero> getSenderosParque(nomParque);

  cout<<"--- Por favor, introduzca el nombre del sendero a eliminar.\n";
  cin>>aux;
  s.setNombre(aux);
  cout<<"--- ¿Esta seguro de que desea borrar el parque? ---\n";
  cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
  int decis;
  cin<<decis;
  if(decis==1){
    borrarSenderos(aux,nomParque);
  if(decis==0){
    menuSenderos();
  }
  //
  break;

  case 4:
  //
  mostrarNombresParques();
  cout<<"Introduzca el nombre del parque que quiere mostrar por pantalla."<<endl;
  string nomParque;
  cout<<"--- Por favor, introduzca el nombre del parque cuyo sendero desea ver. --- \n";
  cin>>nomParque;
  mostrarNombresParques();
  list<sendero> getSenderosParque(nomParque);
  cin>>aux;

  //Funcion que compruebe que el nombre del parque ya exista
  //Funcion que pida nuevo nombre en caso de que exista
  do{
    cout<<" El parque no existe. Por favor, introduzca el nombre del parque cuyos senderos quiere ver. \n";
    cin>>nomParque;
    existsParque(nomParque);
  }
  while(existsParque (nomParque)==-2);

  list<sendero> getSenderosParque(nomParque);
  cout<<"--- A continuacion se mostrarán los datos del sendero existente --- \n";

list<sendero> getSenderosParque(nomParque);
  for(sendero &sendero: senderos)
  {
    if(aux==s.getNombre())
    {
      s.imprimerSendero();
    }
  }

  //
  break;

  case 5:
    return 0;
  break;
}
}
}
