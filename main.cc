//main.cc
//proyecto IS
#include "parques.h"
#include "senderos.h"
#include "visitantes.h"
#include "monitores.h"
#include "rutas.h"

#include <iostream>

using namespace std;

int main(){

  menuPrincipal();
}

int menuPrincipal(){
  int login;

  cout<<"     --- Bienvenido al Sistema de Gestión de Parques Naturales de la Junta de Andalucia. ---\n";
  cout<<"--- Por favor, inicie sesion, seleccionado la opcion 0 o 1. ---\n";
  cout<<"--- 0) Entrar al Sistema como Administrador. ---\n";
  cout<<"--- 1) Entrar al Sistema como Monitor. ---\n";
  cout<<"--- 2) Salir del programa ---\n";
  cin<<login;

  switch(login){
    while(login<0||login>2){
      cout<<"Opcion invalida. Por favor, seleccione una opcion valida. \n";
      cin<<login;
    }

  case 0:
    if(comprobarAdmin==false){
      cout<<"No tiene autorizacion para entrar al sistema como administrador. \n";
    }
    else{
      menuAdmin();
    }

  case 1:
  if(comprobarMonitor==false){
    cout<<"No tiene autorizacion para entrar al sistema como monitor. \n";
  }
  else{
    menuMonitor();
  }

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
      menuPrincipal;
      break;
  }
}

bool comprobarAdmin(bool es_Admin){
  string password;
  es_Admin=false;
    cout<<" Por favor, introduzca su contraseña.\n";
    cin>>password;
    while(password!=admingestionJA){
      cout<<" Contraseña incorrecta. Por favor, introduzca su contraseña.\n";
      cin>>password;
    }
es_Admin=true;
return es_Admin;
}

bool comprobarMonitor(bool es_Monitor){
  es_Monitor=false;
  string dni;
    cout<<" Por favor, introduzca su DNI.\n";
    cin>>DNI;
    //Funcion comprobacion DNI
    //
    //
return es_Monitor;
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

  case 0:
  //
  //
  //
  break;

  case 1:
  //
  //
  //
  break;

  case 2:
  //
  //
  //
  break;

  case 3:
  //
  //
  //
  break;

  case 4:
  //
  //
  //
  break;

  case 5:
    return 0;
  break;
}
