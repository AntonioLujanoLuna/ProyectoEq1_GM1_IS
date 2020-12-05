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
  int login;

  cout<<"--- Bienvenido al Sistema de Gestión de Parques Naturales de la Junta de Andalucia. ---\n";
  cout<<"--- Por favor, inicie sesion, seleccionado la opcion 0 o 1. ---\n";
  cout<<"--- 0) Entrar al Sistema como Administrador. ---\n";
  cout<<"--- 1) Entrar al Sistema como Monitor. ---\n";
  cout<<"--- 2) Salir del programa ---\n";
  cin<<login;

  switch(login){

  case 0:
    int opc;
    string password;
      cout<<" Por favor, introduzca su contraseña.\n";
      cin>>password;
      while(password!=admingestionJA){
        cout<<" Contraseña incorrecta. Por favor, introduzca su contraseña.\n";
        cin>>password;
      }
      cout<<" Contraseña correcta. Bienvenido al sistema. \n";
      cout<<" Por favor, seleccione a que gestion desea acceder. \n";
      cout<<"--- 0) Gestion de Parques Naturales. ---\n";
      cout<<"--- 1) Gestion de Senderos. ---\n";
      cout<<"--- 2) Gestion de Visitantes. ---\n";
      cout<<"--- 3) Gestion de Monitores. ---\n";
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
        return 0;
        break;

    break;

  case 1:
  int seleccion;
  string dni;
    cout<<" Por favor, introduzca su DNI.\n";
    cin>>DNI;
    //Funcion comprobacion DNI
    //
    //
    cout<<" DNI correcto. Bienvenido al sistema. \n";
    cout<<" Por favor, seleccione a que gestion desea acceder. \n";
    cout<<"--- 0) Gestion de Rutas. ---\n";
    cout<<"--- 1) Salir del programa ---\n";
    case 0:
    menuRutas();
    break;

    case 1:
      return 0;
      break;

  break;

  case 2:
    return 0;
    break;
  }
}
